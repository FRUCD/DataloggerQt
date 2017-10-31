#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QWidget>
#include <QtCharts>
#include <QtMath>

class LineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit LineGraph(QWidget *parent = nullptr);
    QString graphTitle;

protected:
    void paintEvent(QPaintEvent *);


signals:

public slots:
};

#endif // LINEGRAPH_H
