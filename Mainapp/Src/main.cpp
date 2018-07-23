#include <QApplication>
#include <QCoreApplication>


#include "Gui/Gui/Inc/gui.hh"
#include "Mainapp/Inc/mainapp.hh"
#include "Socket/Inc/socket.hh"

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]){
  QApplication app(argc, argv);
  
  Gui *G = new Gui();
  Socket *S = new Socket();
  Mainapp *M = new Mainapp();

  M->setGui(G);
  M->setSocket(S);

  G->show();
  
  return app.exec();
}
