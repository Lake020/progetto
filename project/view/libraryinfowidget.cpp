#include "libraryinfowidget.h"
#include "entwidgetvisitor.h"

LibraryInfoWidget::LibraryInfoWidget(Entertainment* item, QWidget *parent): QWidget{parent}{
    setWindowTitle("Info");
    setFixedSize(520, 310);
    EntWidgetVisitor visitor;
    item->accept(visitor);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(visitor.get_widget());
    setLayout(layout);
}
