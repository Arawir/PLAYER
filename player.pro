QT += core widgets network
requires(qtConfig(combobox))

HEADERS       = Socket/Inc/socket.hh \
                Gui/Gui/Inc/gui.hh \
                Mainapp/Inc/mainapp.hh 

                
SOURCES       = Socket/Src/socket.cpp \
                Gui/Gui/Src/gui.cpp \                
                Mainapp/Src/mainapp.cpp \
                Mainapp/Src/main.cpp 


release: DESTDIR = Bin
OBJECTS_DIR = .obj        
MOC_DIR = .moc
RCC_DIR = .qrc
UI_DIR = .ui


# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/fortuneclient
INSTALLS += target
