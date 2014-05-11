#include <QPainter>
#include <QLayout>

#include "DebugDockWidget.h"

DebugDockWidget::DebugDockWidget(QWidget *parent) :
    QDockWidget(parent)
{
    setFixedWidth(200);

    table = new QTableWidget(10,2,this);
    table->setFixedSize(150,300);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);
    this->setLayout(layout);
}

void DebugDockWidget::paintEvent(QPaintEvent *event)
{

}
