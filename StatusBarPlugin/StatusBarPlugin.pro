QT += gui quick

TEMPLATE = lib
DEFINES += STATUSBAR_LIBRARY

CONFIG += c++17
CONFIG += plugin

TARGET = StatusBar

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    StatusBar.cpp

HEADERS += \
    StatusBar.h \
    StatusBar_Interface.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    test.qrc
