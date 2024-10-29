QT += quick dbus

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        DbusHandlerAppHome.cpp \
        ImageItem.cpp \
        StatusBarController.cpp \
        TranslaionController.cpp \
        main.cpp

RESOURCES += qml.qrc \
    trans.qrc

TRANSLATIONS += trans_EN.ts\
                trans_VN.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

HEADERS += \
    DbusHandlerAppHome.h \
    ImageItem.h \
    StatusBarController.h \
    TranslaionController.h

unix:!macx: LIBS += -L$$PWD/lib/SettingLib/ -lSettingLib

INCLUDEPATH += $$PWD/lib/SettingLib
DEPENDPATH += $$PWD/lib/SettingLib

unix:!macx: LIBS += -L$$PWD/lib/ -lStatusBar

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/MusicLib/ -lMusicLib

INCLUDEPATH += $$PWD/lib/MusicLib
DEPENDPATH += $$PWD/lib/MusicLib

unix:!macx: LIBS += -L$$PWD/lib/VideoLib/ -lVideoLib

INCLUDEPATH += $$PWD/lib/VideoLib
DEPENDPATH += $$PWD/lib/VideoLib
