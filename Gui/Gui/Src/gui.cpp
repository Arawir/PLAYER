#include "Gui/Gui/Inc/gui.hh"

////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
Gui::Gui(QWidget *parent) : QWidget(parent){
  MainLayout = new QVBoxLayout();
  
  DebugButton = new QPushButton("Debug");
  MainLayout->addWidget(DebugButton);
  connect(DebugButton, SIGNAL(clicked()), this, SLOT(debugSlot()));

  L = new Log();
  MainLayout->addWidget(L);
  connect(L, SIGNAL(somethingToSendSig()), this, SLOT(somethingToSendSlot()));

  
  setLayout(MainLayout);
}

void Gui::setId(QString i){
  if(L!=nullptr) L->setServer();
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

QString Gui::toSend(){
  QString tmp=ToSend;
  ToSend="";
  return tmp; 
}

void Gui::debug(){
  qDebug() << "TODO";
}
///////////////////////////////////////////////////////////////////////////////
//SLOTS
void Gui::debugSlot(){
  debug();
}

void Gui::somethingToSendSlot(){
  if(L!=nullptr) ToSend = L->toSend();
}
