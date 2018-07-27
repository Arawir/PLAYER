#ifndef GUI_HH
#define GUI_HH

#include <QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>

#include "Gui/Log/Inc/log.hh"
#include "Gui/Bank/Inc/bank.hh"
#include "Gui/Deck/Inc/deck.hh"
#include "Gui/Mailbox/Inc/mailbox.hh"

////////////////////////////////////////////////////////////////////////////////
class Gui : public QWidget{
Q_OBJECT
public:
  explicit Gui(QWidget *parent = nullptr);

  void setId(QString i); // setServer()
  void setName(QString n);
  void setRole(QString r);
  void setFreeRoles(QStringList List);

  QString pullMessage();
  bool isEmpty();

  void start();
  
  void debug();

private:
  Log *L = nullptr;
  Bank *B = nullptr;
  Deck *D = nullptr;
  Mailbox *M = nullptr;
  
  QPushButton *DebugButton;
  QVBoxLayout *MainLayout;
  QHBoxLayout *TopLayout;
  QHBoxLayout *BottomLayout;
  
  QStringList ToSend;

signals:
  void somethingToSendSig();
  void debugSig();	
private slots:
  void debugSlot();
  void somethingToSendLogSlot();
};
////////////////////////////////////////////////////////////////////////////////
#endif
