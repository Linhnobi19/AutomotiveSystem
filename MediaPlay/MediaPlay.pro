QT += quick multimedia dbus

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TRANSLATIONS += \
            language/Media_EN.ts \
            language/Media_VN.ts
SOURCES += \
        Controller.cpp \
        DBusHandler.cpp \
        LanguageController.cpp \
        Model.cpp \
        SettingController.cpp \
        Song.cpp \
        StatusBarController.cpp \
        main.cpp

RESOURCES += qml.qrc \
    imageResource.qrc \
    language.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Controller.h \
    DBusHandler.h \
    LanguageController.h \
    Model.h \
    SettingController.h \
    Song.h \
    StatusBarController.h





unix:!macx: LIBS += -L$$PWD/lib/homeLib/ -lHomeLib

INCLUDEPATH += $$PWD/lib/homeLib
DEPENDPATH += $$PWD/lib/homeLib

unix:!macx: LIBS += -L$$PWD/lib/settingLib/ -lSettingLib

INCLUDEPATH += $$PWD/lib/settingLib
DEPENDPATH += $$PWD/lib/settingLib

unix:!macx: LIBS += -L$$PWD/lib/ -lStatusBar

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx: LIBS += -L$$PWD/lib/VideoLib/ -lVideoLib

INCLUDEPATH += $$PWD/lib/VideoLib
DEPENDPATH += $$PWD/lib/VideoLib
