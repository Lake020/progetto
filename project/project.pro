QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cafeaddvisitor.cpp \
    cafeinfovisitor.cpp \
    cafeitem.cpp \
    cafeitemaddwidget.cpp \
    cafeitemeditwidget.cpp \
    cafeiteminfowidget.cpp \
    cafewidgetvisitor.cpp \
    compare.cpp \
    drink.cpp \
    dvd.cpp \
    entaddvisitor.cpp \
    entinfovisitor.cpp \
    entertainment.cpp \
    entwidgetvisitor.cpp \
    food.cpp \
    library.cpp \
    libraryaddwidget.cpp \
    libraryeditwidget.cpp \
    libraryinfowidget.cpp \
    main.cpp \
    mainwindow.cpp \
    manga.cpp \
    menu.cpp \
    room.cpp \
    search.cpp \
    series.cpp \
    videogame.cpp

HEADERS += \
    cafeaddvisitor.h \
    cafeinfovisitor.h \
    cafeitemaddwidget.h \
    cafeitemeditwidget.h \
    cafeiteminfowidget.h \
    cafevisitor.h \
    cafeitem.h \
    cafewidgetvisitor.h \
    compare.h \
    compare.hpp \
    drink.h \
    dvd.h \
    entertainment.h \
    entaddvisitor.h \
    entinfovisitor.h \
    entvisitor.h \
    entwidgetvisitor.h \
    food.h \
    library.h \
    libraryaddwidget.h \
    libraryeditwidget.h \
    libraryinfowidget.h \
    mainwindow.h \
    manga.h \
    menu.h \
    modify.h \
    room.h \
    search.h \
    search.hpp \
    series.h \
    vector.h \
    vector.hpp \
    videogame.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
