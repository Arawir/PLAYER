#ifndef GUI_HH
#define GUI_HH

#include <QWidget>
#include <QDebug>

////////////////////////////////////////////////////////////////////////////////
class Gui : public QWidget{
Q_OBJECT
public:
  Gui(QWidget *parent = nullptr);
  void setId(QString i);
  void setName(QString n);
  void setRole(QString r);
  void setFreeRoles(QStringList L);

  void Debug();
};
////////////////////////////////////////////////////////////////////////////////
#endif
