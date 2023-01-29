#include "cafeiteminfowidget.h"
#include "cafewidgetvisitor.h"

CafeItemInfoWidget::CafeItemInfoWidget(CafeItem* item, QWidget *parent): QWidget{parent}, item_{item}{
    setWindowTitle("Info");
    setFixedSize(QSize(400, 310));
    CafeWidgetVisitor visitor;
    item_->accept(visitor);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(visitor.get_widget());
    setStyleSheet("background-color: rgb(202, 240, 248); font: bold;");
    setLayout(layout);
}
