QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChangeBallParamsDlg.cpp \
    Log.cpp \
    MyBall.cpp \
    Utility.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    ChangeBallParamsDlg.h \
    Log.h \
    MainWindow.h \
    MyBall.h \
    Utility.h

FORMS += \
    ChangeBallParamsDlg.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    log_file.txt \
    xml_file.txt
