#include <QPainter>
#include <QLayout>
#include <QPushButton>
#include <QTableWidget>

#include "DebugWidget.h"

DebugWidget::DebugWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    QTableWidget *table = new QTableWidget(200,2,this);
    table->setColumnWidth(0, 50);
    table->setColumnWidth(1, 50);
    layout->addWidget(table);

    QPushButton *bouton1 = new QPushButton("Bonjour");
    layout->addWidget(bouton1);

    setLayout(layout);


}

void DebugWidget::paintEvent(QPaintEvent *event)
{

}
