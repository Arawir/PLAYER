#include "Inc/bank.hh"

///////////////////////////////////////////////////////////////////////////////
//FUNCTIONS
Bank::Bank(QWidget *parent) : QWidget(parent){
  gold = new Gold();
  main_layout = new QVBoxLayout();
  debug_button = new QPushButton("Debug bank");

  main_layout->addWidget(debug_button);
  main_layout->addWidget(gold);

  connect(debug_button, SIGNAL(clicked()), this, SLOT(Debug_slot()));
  
  Secret_acc *S = new Secret_acc();
  S->Set_gold(gold);
  lines.append(S);
  main_layout->addWidget(S);
  
  setLayout(main_layout);
}

void Bank::Set_free_gold(QString g){ 
  gold->Set_gold( g.toInt() );
}

void Bank::Add_line(QString ti, QString tn, QString mi, QString mn){
  Goldline *G = new Goldline();
  G->Set_to_id(ti);
  G->Set_to_name(tn);
  G->Set_my_id(mi);
  G->Set_my_name(mn);
  G->Set_gold(gold);
  // G->Refresh();

  lines.append(G);
  main_layout->addWidget(G);
}

QStringList Bank::To_send(){
  QStringList out;
  QString tmp="";
  
  foreach(Goldline *L, lines){
    tmp = L->To_send();
    if(tmp!="") out.append(tmp);
  }

  return out;
  
}

void Bank::Debug(){
  QStringList tmp = To_send();
  qDebug() << "BANK DEBUG: ";

  foreach(QString S, tmp){
    qDebug() << "   " << S;
  }
}

////////////////////////////////////////////////////////////////////////////////
//SLOTS
void Bank::Debug_slot(){
  Debug();
}
