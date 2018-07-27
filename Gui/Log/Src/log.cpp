#include "Gui/Log/Inc/log.hh"

#include <QThread>
////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
Log::Log(QWidget *parent){

  MainLayout = new QVBoxLayout();

  SelectServerWidget = new QWidget();
  SelectNameWidget = new QWidget();
  SelectRoleWidget = new QWidget();
  WaitWidget = new QWidget();
  
  SelectServerLayout = new QVBoxLayout();
  SelectNameLayout = new QVBoxLayout();
  SelectRoleLayout = new QVBoxLayout();
  WaitLayout = new QVBoxLayout();

  SelectServerButton = new QPushButton("Select server");
  SelectServerLayout->addWidget(SelectServerButton);
  connect(SelectServerButton, SIGNAL(clicked()),this, SLOT(selectServerSlot()));


  NameTextEdit = new QTextEdit("select name");
  SelectNameLayout->addWidget(NameTextEdit);
  
  SelectNameButton = new QPushButton("Accept this name");
  SelectNameLayout->addWidget(SelectNameButton);
  connect(SelectNameButton, SIGNAL(clicked()),this, SLOT(selectNameSlot()));

  GoBack1Button = new QPushButton("Go back");
  SelectNameLayout->addWidget(GoBack1Button);
  connect(GoBack1Button, SIGNAL(clicked()),this, SLOT(back1Slot()));


  FreeRolesComboBox = new QComboBox();
  SelectRoleLayout->addWidget(FreeRolesComboBox);
  
  SelectRoleButton = new QPushButton("Accept this role");
  SelectRoleLayout->addWidget(SelectRoleButton);
  connect(SelectRoleButton, SIGNAL(clicked()),this, SLOT(selectRoleSlot()));

  GoBack2Button = new QPushButton("Go back");
  SelectRoleLayout->addWidget(GoBack2Button);
  connect(GoBack2Button, SIGNAL(clicked()),this, SLOT(back2Slot()));

  
  WaitLabel = new QLabel("Waiting for other players");
  WaitLayout->addWidget(WaitLabel);


  SelectServerWidget->setLayout(SelectServerLayout);
  SelectNameWidget->setLayout(SelectNameLayout);
  SelectRoleWidget->setLayout(SelectRoleLayout);
  WaitWidget->setLayout(WaitLayout);
  
  MainLayout->addWidget(SelectServerWidget);
  MainLayout->addWidget(SelectNameWidget);
  MainLayout->addWidget(SelectRoleWidget);
  MainLayout->addWidget(WaitWidget);

  WaitWidget->hide();
  SelectRoleWidget->hide();
  SelectNameWidget->hide();
  setLayout(MainLayout);
}

QString Log::toSend(){
  QString tmp=ToSend;
  ToSend="";
  return tmp; 
}

void Log::setFreeRoles(QStringList L){
  FreeRolesComboBox->clear();
  foreach(QString S, L){
    FreeRolesComboBox->addItem(S);
  }
}

void Log::setServer(){
  SelectServerWidget->hide();
  SelectNameWidget->show();
  //  QThread::msleep(100);
  // ToSend = "SET_PHASE_|_CONFIGURE";
  // emit somethingToSendSig();
}

void Log::setName(){
  SelectNameWidget->hide();
  SelectRoleWidget->show();
  ToSend = "FREE_ROLES";
  emit somethingToSendSig();
}

void Log::setRole(){
  SelectRoleWidget->hide();
  WaitWidget->show();

  ToSend = "SET_PHASE_|_READY_TO_START";
  emit somethingToSendSig();
}

void Log::debug(){
  qDebug() << "TODO log"; 
}
////////////////////////////////////////////////////////////////////////////////
//SLOTS
void Log::selectServerSlot(){
  ToSend = "CONNECT_TO_|_127.0.0.1_|_1234";
  emit somethingToSendSig();
}

void Log::selectNameSlot(){
  ToSend = "SET_NAME_|_" + NameTextEdit->toPlainText();
  emit somethingToSendSig();
}

void Log::back1Slot(){
  //  MainLayout->removeWidget(SelectNameWidget);
  //  MainLayout->addWidget(SelectServerWidget);
  qDebug() << "Polapka";
}

void Log::selectRoleSlot(){
  ToSend = "SET_ROLE_|_" + FreeRolesComboBox->currentText();
  emit somethingToSendSig();
}

void Log::back2Slot(){
  SelectRoleWidget->hide();
  SelectNameWidget->show();
}
