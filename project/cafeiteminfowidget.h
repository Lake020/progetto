#ifndef CAFEITEMINFOWIDGET_H
#define CAFEITEMINFOWIDGET_H

#include "cafeitem.h"
#include <QWidget>
#include <QVBoxLayout>

class CafeItemInfoWidget : public QWidget{
    Q_OBJECT
public:
    explicit CafeItemInfoWidget(CafeItem* item, QWidget *parent = nullptr);
private:
    CafeItem* item_;
};

#endif // CAFEITEMINFOWIDGET_H
