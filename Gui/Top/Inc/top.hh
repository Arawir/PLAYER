#ifndef GOLD_HH
#define GOLD_HH

#include <QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>
////////////////////////////////////////////////////////////////////////////////

class Gold : public QWidget{
Q_OBJECT
public:
  void 
  
private:
  QString my_name;
  QString my_id;
  QString server_name;
  QString round;
  QString reconnect_cod;

  QHBoxLayout *main_layout;
  QLabel *data_label;
  QLabel *round_label;
  QPushButton *ready_button;
};




////////////////////////////////////////////////////////////////////////////////
#endif
