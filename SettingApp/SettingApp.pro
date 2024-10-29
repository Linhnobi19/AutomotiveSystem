QT += quick dbus
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += translation/myapp_EN.ts \
                translation/myapp_VN.ts

INCLUDEPATH += \
        ./src \
        ./src/common \
        ./src/controller \
        ./src/model

SOURCES += \
        src/AppEngine.cpp \
        src/controller/DateController.cpp \
        src/controller/DbusHandler.cpp \
        src/controller/SettingController.cpp \
        src/controller/StatusBarController.cpp \
        src/controller/Translator.cpp \
        src/controller/VolumeController.cpp \
        src/main.cpp \
        src/model/DateModel.cpp \
        src/model/SettingsModel.cpp

RESOURCES += qml.qrc \
    images.qrc \
    translation.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/AppEngine.h \
    src/common/AppDefine.h \
    src/common/LogHelper.h \
    src/controller/DateController.h \
    src/controller/DbusHandler.h \
    src/controller/SettingController.h \
    src/controller/StatusBarController.h \
    src/controller/Translator.h \
    src/controller/VolumeController.h \
    src/model/DateModel.h \
    src/model/SettingsModel.h




# unix:!macx: LIBS += -L$$PWD/lib/ -lStatusBar

# INCLUDEPATH += $$PWD/lib
# DEPENDPATH += $$PWD/lib

# unix:!macx: LIBS += -L$$PWD/../StatusBar/build/Desktop_Qt_5_15_2_GCC_64bit-Debug/ -lStatusBar

# INCLUDEPATH += $$PWD/../StatusBar/build
# DEPENDPATH += $$PWD/../StatusBar/build

# unix:!macx: LIBS += -L$$PWD/../../../Documents/zipfile/Day15/StatusBar/build/Desktop_Qt_5_15_2_GCC_64bit-Debug/ -lStatusBar

# INCLUDEPATH += $$PWD/../../../Documents/zipfile/Day15/StatusBar/build
# DEPENDPATH += $$PWD/../../../Documents/zipfile/Day15/StatusBar/build



unix:!macx: LIBS += -L$$PWD/lib/ -lStatusBar

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

# unix:!macx: LIBS += -L$$PWD/../StatusBarPlugin/build/Desktop_Qt_5_15_2_GCC_64bit-Debug/ -lStatusBar

# INCLUDEPATH += $$PWD/../StatusBarPlugin/build
# DEPENDPATH += $$PWD/../StatusBarPlugin/build

unix:!macx: LIBS += -L$$PWD/lib/Homelib/ -lHomeLib

INCLUDEPATH += $$PWD/lib/Homelib
DEPENDPATH += $$PWD/lib/Homelib
