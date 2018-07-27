#ifndef MAINAPP_HH
#define MAINAPP_HH

#include "Gui/Gui/Inc/gui.hh"
#include "Socket/Inc/socket.hh"
#include <QObject>
#include <QDebug>

////////////////////////////////////////////////////////////////////////////////
class Mainapp : public QObject{
Q_OBJECT
public:
  Mainapp(QObject *parent = nullptr) : QObject(parent){ }

  void setGui(Gui *g);
  void setSocket(Socket *s);

  void receiveMessageSocket();
  void receiveMessageGui();
  void sendMessage(QString msg);
  
  void executeMessageSocket(QString msg);
  void executeMessageGui(QString msg);
  
  void setName(QString n);
  void setId(QString i);
  void setRole(QString r);
  void setFreeRoles(QStringList L);
  void setPhase(QString ph);
  
  void askId(QString i);
  void askName(QString n);
  void askRole(QString r);
  void askFreeRoles();
  void askPhase(QString ph);
  
  void debug();
private:
  Gui *G;
  Socket *S;

  QString MyId;
  QString MyName;
  QString MyRole;
  QString Phase="CONFIGURE";
	       
public slots:
  void newMessageSocketSlot();
  void newMessageGuiSlot();
  void debugSlot();
};
////////////////////////////////////////////////////////////////////////////////
#endif

/*PHASE: 
CONFIGURE, READY_TO_START, 
MOVE, READY_TO_SEND_DATA, SENDING_DATA, READY_TO_MOVE

*/ 
