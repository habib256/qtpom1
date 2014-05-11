#ifndef DEBUGWIDGET_H
#define DEBUGWIDGET_H

#include <QWidget>
#include <QTableWidget>

class DebugWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DebugWidget(QWidget *parent = 0);

private:

     QTableWidget *table;

    void paintEvent(QPaintEvent *event);

signals:

public slots:

};

#endif // DEBUGDOCWIDGET_H
