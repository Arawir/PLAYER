#include "Gui/Gui/Inc/gui.hh"

////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
Gui::Gui(QWidget *parent) : QWidget(parent){
  MainLayout = new QVBoxLayout();

  TopLayout = new QHBoxLayout();
  BottomLayout = new QHBoxLayout();
  
  DebugButton = new QPushButton("Debug");
  TopLayout->addWidget(DebugButton);
  connect(DebugButton, SIGNAL(clicked()), this, SLOT(debugSlot()));

  L = new Log();
  BottomLayout->addWidget(L);
  connect(L, SIGNAL(somethingToSendSig()), this, SLOT(somethingToSendLogSlot()));

  B = new Bank();
  BottomLayout->addWidget(B);
  //  B->hide();

  M = new Mailbox();
  BottomLayout->addWidget(D);
  //  M->hide();

  D = new Deck();
  BottomLayout->addWidget(M);
  // D->hide();

  
  MainLayout->addLayout(TopLayout);
  MainLayout->addLayout(BottomLayout);
  
  setLayout(MainLayout);
}

void Gui::setId(QString i){
  if(L!=nullptr) L->setServer();
  //  qDebug() <<"WESZLO";
}

void Gui::setName(QString n){
  if(L!=nullptr) L->setName();
}

void Gui::setRole(QString r){
  if(L!=nullptr) L->setRole();
}
void Gui::setFreeRoles(QStringList List){
  if(L!=nullptr) L->setFreeRoles(List);
}

QString Gui::pullMessage(){
  if( ToSend.isEmpty() ) return "";
  QString tmp = ToSend.first();
  ToSend.removeFirst();
  return tmp; 
}

bool Gui::isEmpty(){ return ToSend.isEmpty(); }

void Gui::start(){
  L->hide();
  B->show();
  D->show();
  M->show();
}

void Gui::debug(){
  qDebug() << "TODO???";
}
///////////////////////////////////////////////////////////////////////////////
//SLOTS
void Gui::debugSlot(){
  debug();
  emit debugSig();
}

void Gui::somethingToSendLogSlot(){
  if(L!=nullptr) ToSend.append( L->toSend() );
  emit somethingToSendSig();
}
