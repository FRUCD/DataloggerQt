#include "linegraph.h"

#include <QPainter>

LineGraph::LineGraph(QWidget *parent) : QWidget(parent)
{
    initializeClassElements();
    graphSetUp();
}

void LineGraph::graphSetUp()
{
    connect(testInput, SIGNAL (givePoint(QPointF)), this, SLOT (recieveData(QPointF)));

    chart->legend()->hide();
    chart->setTitle(graphTitle); //Whole Chart setup
    chart->addSeries(lineSeries);

    axisX->setTitleText("Time (Seconds)");
    chart->addAxis(axisX, Qt::AlignBottom); //axisX setup
    lineSeries->attachAxis(axisX);
    axisX->setTickCount(1);

    axisY->setTitleText("Percent Usage");
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft); //axisY setup
    lineSeries->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QGridLayout *mainLayout = new QGridLayout;
       mainLayout->addWidget(chartView, 1, 1);
       setLayout(mainLayout);

    chartView->setRubberBand(QChartView::HorizontalRubberBand);
    chartView->lower();
}

void LineGraph::initializeClassElements()
{
    graphTitle = "No Title";
    chart = new QChart();
    lineSeries = new QLineSeries();
    testInput = new TestInput();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    spinBox = new QSpinBox(this);
}

void LineGraph::updateGraph(int count)
{
    int rangeMin = count - trackingX;
    int rangeMax = count;

    if (trackingX < 5) rangeMin = count - 100;

    if (rangeMin < 0) rangeMin = 0;

    chart->setTitle(QString::number(rangeMin) + "  |  " + QString::number(rangeMax));
    axisX->setRange(rangeMin, rangeMax);
    chart->update();
}

//---------------------Slots---------------------

void LineGraph::recieveData (QPointF point)
{
//    if (lineSeries->count() == 60) //Removes the oldest point
//        lineSeries->remove(0);
    *lineSeries << point;
    updateGraph(lineSeries->count());
}

void LineGraph::wheelEvent(QWheelEvent *event) //Zooms in
{
    if(event->delta() > 0) trackingX -= lineSeries->count() / 10;
    else if(event->delta() < 0) trackingX += lineSeries->count() / 10;

    event->accept();
}

void LineGraph::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter)
        trackingX = spinBox->value();
}
