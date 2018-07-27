#ifndef LOG_HH
#define LOG_HH

#include <QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>
////////////////////////////////////////////////////////////////////////////////
class Log : public QWidget{
Q_OBJECT
public:
  Log(QWidget *parent = nullptr);
  QString toSend();
  void setFreeRoles(QStringList L);

  void setServer(); // to set layout
  void setName(); // set layout
  void setRole(); // set layout
  
  void debug();
  
private:
  QString ToSend;

  QVBoxLayout *MainLayout;

  QWidget *SelectServerWidget;
  QWidget *SelectNameWidget;
  QWidget *SelectRoleWidget;
  QWidget *WaitWidget;
  
  QVBoxLayout *SelectServerLayout;
  QVBoxLayout *SelectNameLayout;
  QVBoxLayout *SelectRoleLayout;
  QVBoxLayout *WaitLayout;
  
  QPushButton *SelectServerButton;
  QPushButton *GoBack1Button;
  QPushButton *SelectNameButton;
  QPushButton *GoBack2Button;
  QPushButton *SelectRoleButton;

  QLabel *WaitLabel;
  QTextEdit *NameTextEdit;
  QComboBox *FreeRolesComboBox;

signals:
  void somethingToSendSig();

private slots:
  void selectServerSlot();
  void selectNameSlot();
  void back1Slot();
  void selectRoleSlot();
  void back2Slot();
};

////////////////////////////////////////////////////////////////////////////////
#endif
