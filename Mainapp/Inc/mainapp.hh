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

  void receiveMessage();
  void sendMessage(QString msg);
  
  void executeMessage(QString msg);
  void setName(QString n);
  void setId(QString i);
  void setRole(QString r);
  void setFreeRoles(QStringList L);

  void askId(QString i);
  void askName(QString n);
  void askRole(QString r);
  void askFreeRoles();

private:
  Gui *G;
  Socket *S;

  QString MyId;
  QString MyName;
  QString MyRole;

public slots:
  void newMessageSlot();
};
////////////////////////////////////////////////////////////////////////////////
#endif
