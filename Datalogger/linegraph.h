#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QWidget>
#include <QtCharts>
#include <QtMath>
#include <QtGui>
#include <QWheelEvent>

class LineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit LineGraph(QWidget *parent = nullptr);
    QString graphTitle;
    QChart * chart;
    void wheelEvent(QWheelEvent *event);

protected:
    void paintEvent(QPaintEvent *);


signals:


public slots:
};

#endif // LINEGRAPH_H
