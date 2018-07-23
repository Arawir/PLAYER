#ifndef SOCKET_HH
#define SOCKET_HH

#include <QObject>
#include <QDebug>
#include <QTcpSocket>

////////////////////////////////////////////////////////////////////////////////
class Socket : public QObject{
  Q_OBJECT
private:
  QTcpSocket *S = nullptr;
  QList<QString> messages; 
public:
  explicit Socket(QWidget *parent = nullptr);
  bool Connect_to_server();
  void Disconnect();
  void Send_message(QString msg);
  QString Pull_message();
  bool Messages_empty();
signals:
  void Connected();
  void New_message();	  
public slots:
  void Receive_message();
};
////////////////////////////////////////////////////////////////////////////////
#endif
