#include "cafeiteminfowidget.h"
#include "cafewidgetvisitor.h"

CafeItemInfoWidget::CafeItemInfoWidget(CafeItem* item, QWidget *parent): QWidget{parent}, item_{item}{
    setWindowTitle("Info");
    setFixedSize(220, 310);
    CafeWidgetVisitor visitor;
    item_->accept(visitor);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(visitor.get_widget());
    setLayout(layout);
}
