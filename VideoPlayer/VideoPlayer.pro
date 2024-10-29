QT += quick multimedia dbus widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        DBusHandler.cpp \
        LangController.cpp \
        StatusBarController.cpp \
        VideoHandler.cpp \
        VideoModel.cpp \
        main.cpp

RESOURCES += qml.qrc \
    translation.qrc
TRANSLATIONS += trans_VN.ts \
                trans_ENG.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    SourceImage/nextBtn.png \
    SourceImage/pauseBtn.png \
    SourceImage/playBtn.png \
    trans_ENG.qm

HEADERS += \
    DBusHandler.h \
    LangController.h \
    StatusBarController.h \
    StatusBar_Interface.h \
    VideoHandler.h \
    VideoModel.h



unix:!macx: LIBS += -L$$PWD/plugin/ -lStatusBar

INCLUDEPATH += $$PWD/plugin
DEPENDPATH += $$PWD/plugin

unix:!macx: LIBS += -L$$PWD/libSetting/ -lSettingLib

INCLUDEPATH += $$PWD/libSetting
DEPENDPATH += $$PWD/libSetting

unix:!macx: LIBS += -L$$PWD/libMusic/ -lMusicLib

INCLUDEPATH += $$PWD/libMusic
DEPENDPATH += $$PWD/libMusic

unix:!macx: LIBS += -L$$PWD/libHome/ -lHomeLib

INCLUDEPATH += $$PWD/libHome
DEPENDPATH += $$PWD/libHome
