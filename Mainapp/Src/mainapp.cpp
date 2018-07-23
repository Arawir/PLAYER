#include "Mainapp/Inc/mainapp.hh"

////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS

void Mainapp::setGui(Gui *g){ G=g; }
void Mainapp::setSocket(Socket *s){ S = s; }

void Mainapp::receiveMessage(){
  QString msg;
  
  while(!S->Messages_empty()){
    msg = S->Pull_message();
    executeMessage(msg);
  }
}

void Mainapp::sendMessage(QString msg){
  if(S==nullptr) qDebug("No server");
  else S->Send_message(msg);
}
  
void Mainapp::executeMessage(QString msg){
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
}


void Mainapp::setName(QString n){
  MyName = n;
  //  G->setName(MyName);
}

void Mainapp::setId(QString i){
  MyId = i;
  // G->setId(MyId);
}

void Mainapp::setRole(QString r){
  MyRole = r;
  // G->setRole(MyRole);
}

void Mainapp::setFreeRoles(QStringList L){
  // G->setFreeRoles(L);
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

void Mainapp::askFreeRoles(){
  QString msg = MyId + "_|_" + "FREE_ROLES";
  sendMessage(msg);
}
////////////////////////////////////////////////////////////////////////////////
//SLOTS
void Mainapp::newMessageSlot(){
  receiveMessage();
}
