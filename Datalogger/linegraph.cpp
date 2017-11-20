#include "linegraph.h"

#include <QPainter>

LineGraph::LineGraph(QWidget *parent) : QWidget(parent)
{
    graphTitle = "No Title";

    chart = new QChart();
    chart->legend()->hide();
    chart->setTitle(graphTitle);
    QLineSeries *lineSeries = new QLineSeries();

    //Make random data
    int test = 0;
    for (int i = 0; i <= 60; i++)
    {
        if(test < 1) test += rand() % 2;
        else if (test > 5) test += 5 - rand() % 10;
        else test += 1 - rand() % 3;
        *lineSeries << QPointF(i,test);
    }


    chart->addSeries(lineSeries);
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Time (Seconds)");
    //axisX->setRange(0,60);
    chart->addAxis(axisX, Qt::AlignBottom);
    lineSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Percent Usage");
    //axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft);
    lineSeries->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartView, 1, 1);
       setLayout(mainLayout);

    chartView->setRubberBand(QChartView::HorizontalRubberBand);
}

void LineGraph::wheelEvent(QWheelEvent *event) //Zooms in
{
    if(event->delta() > 0) chart->zoom(2);
    else if(event->delta() < 0) chart->zoom(.5);

    event->accept();
}

void LineGraph::revieveData (QObject * object)
{

}
