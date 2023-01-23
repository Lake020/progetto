#ifndef LIBRARYINFOWIDGET_H
#define LIBRARYINFOWIDGET_H

#include "entertainment.h"
#include <QWidget>
#include <QVBoxLayout>

class LibraryInfoWidget : public QWidget{
    Q_OBJECT
public:
    explicit LibraryInfoWidget(Entertainment* item, QWidget *parent = nullptr);
};

#endif // LIBRARYINFOWIDGET_H
