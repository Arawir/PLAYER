QT += core widgets network
requires(qtConfig(combobox))

HEADERS       = Socket/Inc/socket.hh \
                Gui/Gui/Inc/gui.hh \
                Gui/Log/Inc/log.hh \
                Gui/Bank/Inc/gold.hh \
                Gui/Bank/Inc/goldline.hh \
                Gui/Bank/Inc/secret_acc.hh \
                Gui/Bank/Inc/bank.hh \
                Gui/Deck/Inc/card.hh \
                Gui/Deck/Inc/cardline.hh \
                Gui/Deck/Inc/panel.hh \
                Gui/Deck/Inc/preview.hh \
                Gui/Deck/Inc/deck.hh \
                Gui/Mailbox/Inc/letter.hh \
                Gui/Mailbox/Inc/comline.hh \
                Gui/Mailbox/Inc/mailbox.hh \                         
                Mainapp/Inc/mainapp.hh 

                
SOURCES       = Socket/Src/socket.cpp \
                Gui/Log/Src/log.cpp \
                Gui/Bank/Src/gold.cpp \
                Gui/Bank/Src/goldline.cpp \
                Gui/Bank/Src/secret_acc.cpp \
                Gui/Bank/Src/bank.cpp \
                Gui/Deck/Src/card.cpp \
                Gui/Deck/Src/cardline.cpp\
                Gui/Deck/Src/panel.cpp \
                Gui/Deck/Src/preview.cpp \
                Gui/Deck/Src/deck.cpp \
                Gui/Mailbox/Src/letter.cpp \
                Gui/Mailbox/Src/comline.cpp \
                Gui/Mailbox/Src/mailbox.cpp \                
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
