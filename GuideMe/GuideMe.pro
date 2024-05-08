QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edge.cpp \
    edit_edge.cpp \
    file_mangment.cpp \
    graph.cpp \
    filereader.cpp \
    main.cpp \
    mainwindow.cpp \
    result_window.cpp

HEADERS += \
    edge.h \
    edit_edge.h \
    file_mangment.h \
    graph.h \
    filereader.h \
    mainwindow.h \
    result_window.h

FORMS += \
    edit_edge.ui \
    mainwindow.ui \
    result_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    input.txt
RESOURCES += \
    rec.qrc

#DISTFILES +=
 #   C:/Users/Youssef Mohsen/Desktop/edit_icon.jpg

RESOURCES +=
