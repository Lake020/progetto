#ifndef CAFEITEMINFOWIDGET_H
#define CAFEITEMINFOWIDGET_H

#include "cafeitem.h"
#include "food.h"
#include "drink.h"
#include <QWidget>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QFileDialog>
#include<QFormLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QDoubleSpinBox>

class CafeItemInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CafeItemInfoWidget(CafeItem* item, QWidget *parent = nullptr);
private:
    CafeItem* item_;

signals:
};

#endif // CAFEITEMINFOWIDGET_H
