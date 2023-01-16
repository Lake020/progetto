QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cafeaddvisitor.cpp \
    cafeeditvisitor.cpp \
    cafeinfovisitor.cpp \
    cafeitem.cpp \
    cafeitemaddwidget.cpp \
    cafeitemeditwidget.cpp \
    compare.cpp \
    drink.cpp \
    dvd.cpp \
    entaddvisitor.cpp \
    entinfovisitor.cpp \
    entertainment.cpp \
    food.cpp \
    library.cpp \
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
    cafeeditvisitor.h \
    cafeinfovisitor.h \
    cafeitemaddwidget.h \
    cafeitemeditwidget.h \
    cafevisitor.h \
    cafeitem.h \
    compare.h \
    compare.hpp \
    drink.h \
    dvd.h \
    entertainment.h \
    entaddvisitor.h \
    entinfovisitor.h \
    entvisitor.h \
    food.h \
    library.h \
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
