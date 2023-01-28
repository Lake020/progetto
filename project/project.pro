QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    model/cafeaddvisitor.cpp \
    model/cafeinfovisitor.cpp \
    model/cafeitem.cpp \
    view/cafeitemaddwidget.cpp \
    view/cafeitemeditwidget.cpp \
    view/cafeiteminfowidget.cpp \
    view/cafewidgetvisitor.cpp \
    model/compare.cpp \
    model/drink.cpp \
    model/dvd.cpp \
    model/entaddvisitor.cpp \
    model/entinfovisitor.cpp \
    model/entertainment.cpp \
    view/entwidgetvisitor.cpp \
    model/food.cpp \
    model/library.cpp \
    view/libraryaddwidget.cpp \
    view/libraryeditwidget.cpp \
    view/libraryinfowidget.cpp \
    main.cpp \
    view/mainwindow.cpp \
    model/manga.cpp \
    model/menu.cpp \
    model/search.cpp \
    model/series.cpp \
    model/videogame.cpp

HEADERS += \
    model/cafeaddvisitor.h \
    model/cafeinfovisitor.h \
    view/cafeitemaddwidget.h \
    view/cafeitemeditwidget.h \
    view/cafeiteminfowidget.h \
    model/cafevisitor.h \
    model/cafeitem.h \
    view/cafewidgetvisitor.h \
    model/compare.h \
    model/compare.hpp \
    model/drink.h \
    model/dvd.h \
    model/entertainment.h \
    model/entaddvisitor.h \
    model/entinfovisitor.h \
    model/entvisitor.h \
    view/entwidgetvisitor.h \
    model/food.h \
    model/library.h \
    view/libraryaddwidget.h \
    view/libraryeditwidget.h \
    view/libraryinfowidget.h \
    view/mainwindow.h \
    model/manga.h \
    model/menu.h \
    model/search.h \
    model/search.hpp \
    model/series.h \
    model/vector.h \
    model/vector.hpp \
    model/videogame.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
