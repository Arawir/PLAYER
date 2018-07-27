#include "Mainapp/Inc/mainapp.hh"

////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS

void Mainapp::setGui(Gui *g){
  if(g==nullptr) return;
  G=g;
  connect(G, SIGNAL( somethingToSendSig()), this, SLOT( newMessageGuiSlot()));
  connect(G, SIGNAL( debugSig()), this, SLOT( debugSlot()));
}
void Mainapp::setSocket(Socket *s){
  if(s==nullptr) return;
  S = s;
  connect(S, SIGNAL( New_message()), this, SLOT( newMessageSocketSlot()));
  connect(S, SIGNAL( Connected()), this, SLOT( newMessageSocketSlot()));
}

void Mainapp::receiveMessageSocket(){
  QString msg;
  
  while(!S->Messages_empty()){
    msg = S->Pull_message();
    executeMessageSocket(msg);
  }
}

void Mainapp::receiveMessageGui(){
  QString msg;
  
  while(!G->isEmpty()){
    msg = G->pullMessage();
    executeMessageGui(msg);
  }
}

void Mainapp::sendMessage(QString msg){
  if(S==nullptr) qDebug("No server");
  else S->Send_message(msg);
}

void Mainapp::executeMessageGui(QString msg){
  if(msg=="CONNECT_TO_|_127.0.0.1_|_1234"){
    S->Connect_to_server();
  }
  else{
    QString out = MyId + "_|_" + msg;
    sendMessage(out);
  }
}

void Mainapp::executeMessageSocket(QString msg){
  QString SenderId = "";
  QString Command = "";
  
  msg.remove("\r");
  msg.remove("/r");
  msg.remove("\n");
  msg.remove("/n");
      
  QStringList Parameters = msg.split("_|_");
  if(Parameters.isEmpty()!=1){
    SenderId = Parameters[0];
    Parameters.removeFirst();
  }
  if(Parameters.isEmpty()!=1){
    Command = Parameters[0];
    Parameters.removeFirst();
  }

  
  if(Command=="NEW_ID"){ setId(Parameters[0]);  askId(Parameters[0]); }
  if(Command=="SET_NAME"){ setName(Parameters[0]); }
  if(Command=="SET_ROLE"){ setRole(Parameters[0]); }
  if(Command=="FREE_ROLES"){ setFreeRoles(Parameters); }
  if(Command=="SET_PHASE"){ setPhase(Parameters[0]); }
  if(Command=="START_GAME"){ G->start(); }
}


void Mainapp::setName(QString n){
  MyName = n;
  G->setName(MyName);
}

void Mainapp::setId(QString i){
  MyId = i;
  G->setId(MyId);
}

void Mainapp::setRole(QString r){
  MyRole = r;
  G->setRole(MyRole);
  askPhase("READY_TO_START");
}

void Mainapp::setFreeRoles(QStringList L){
  G->setFreeRoles(L);
}

void Mainapp::setPhase(QString ph){
  Phase = ph;
  //  G->setPhase(Phase);
}


void Mainapp::askId(QString i){
  QString msg = MyId + "_|_" + "SET_ID" + "_|_" + i;
  sendMessage(msg);
}

void Mainapp::askName(QString n){
  QString msg = MyId + "_|_" + "SET_NAME" + "_|_" + n;
  sendMessage(msg);
}

void Mainapp::askRole(QString r){
  QString msg = MyId + "_|_" + "SET_ROLE" + "_|_" + r;
  sendMessage(msg);
}

 void Mainapp::askPhase(QString ph){
  QString msg = MyId + "_|_" + "SET_PHASE" + "_|_" + ph;
  sendMessage(msg);
}

void Mainapp::askFreeRoles(){
  QString msg = MyId + "_|_" + "FREE_ROLES";
  sendMessage(msg);
}

void Mainapp::debug(){
  qDebug() << "DEBUG MAIN APP:";
  qDebug() << "   Gui: " << G;
  qDebug() << "   Socket: " << S;
  qDebug() << "   Id: " << MyId;
  qDebug() << "   Name: " << MyName;
  qDebug() << "   Role: " << MyRole;
  qDebug() << "   Phase: " << Phase;
}
////////////////////////////////////////////////////////////////////////////////
//SLOTS
void Mainapp::newMessageSocketSlot(){
  receiveMessageSocket();
}

void Mainapp::newMessageGuiSlot(){
  receiveMessageGui();
}

void Mainapp::debugSlot(){
  debug();
}
