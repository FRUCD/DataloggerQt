#include "linegraph.h"

#include <QPainter>

LineGraph::LineGraph(QWidget *parent) : QWidget(parent)
{
    graphTitle = "No Title";
}

void LineGraph::paintEvent(QPaintEvent *)
{
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->setTitle(graphTitle);
    QLineSeries *lineSeries = new QLineSeries();
    for (int i = 0; i < 500; i++)
    {
        *lineSeries << QPointF(i, qPow(i, 2));
    }

    chart->addSeries(lineSeries);
    QChartView *chartView = new QChartView(chart);
    //chartView->
    QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartView, 1, 1);
       setLayout(mainLayout);
}
