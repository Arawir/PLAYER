#include "Socket/Inc/socket.hh"

#include <QThread>
////////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
Socket::Socket(QWidget *parent){
  S = new QTcpSocket();
  connect(S, SIGNAL(readyRead()), this, SLOT(Receive_message()));
}

bool Socket::Connect_to_server(){
  S->connectToHost("127.0.0.1", 1234);
  if(S->waitForConnected(3000)){
    emit Connected();
    return 1;
  }
  else{
    qDebug() << "No connected";
    return 0;
  }


  return 0;
}

void Socket::Disconnect(){
  S->close();
}

void Socket::Send_message(QString msg){
  S->write(msg.toStdString().c_str());
  S->flush();
  S->waitForBytesWritten(3000);
  qDebug() << "Sen: " << msg;
  // QThread::msleep(100);
}

QString Socket::Pull_message(){
  if(messages.isEmpty()) return "";
  QString tmp = messages.first();
  qDebug() << "Rec: " << tmp;
  messages.removeFirst();
  return tmp;
}

bool Socket::Messages_empty(){
  return messages.isEmpty();
}

////////////////////////////////////////////////////////////////////////////////
//SLOTS

void Socket::Receive_message(){
  QString buffer;
  buffer = S->readAll();
  messages.append(buffer);
  // qDebug() << "Nmsg from socket: " << buffer;
  emit New_message();  
}
