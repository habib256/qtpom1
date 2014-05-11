#ifndef DEBUGDOCWIDGET_H
#define DEBUGDOCWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QTableWidget>

class DebugDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit DebugDockWidget(QWidget *parent = 0);

private:

     QTableWidget *table;

    void paintEvent(QPaintEvent *event);

signals:

public slots:

};

#endif // DEBUGDOCWIDGET_H
