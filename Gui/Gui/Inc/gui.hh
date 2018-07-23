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

////////////////////////////////////////////////////////////////////////////////
class Gui : public QWidget{
Q_OBJECT
public:
  explicit Gui(QWidget *parent = nullptr);

  void setId(QString i);
  void setName(QString n);
  void setRole(QString r);
  void setFreeRoles(QStringList List);

  QString toSend();
  
  void debug();

private:
  Log *L = nullptr;
  
  QPushButton *DebugButton;
  QVBoxLayout *MainLayout;

  QString ToSend; // mainly for Log::

signals:
  void somethingToSendSig();
		
private slots:
  void debugSlot();
  void somethingToSendSlot();
};
////////////////////////////////////////////////////////////////////////////////
#endif
