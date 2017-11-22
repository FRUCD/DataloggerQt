#include "scrollingviewtab.h"

ScrollingViewTab::ScrollingViewTab(QWidget *parent) : QWidget(parent)
{
    intialization();
    connect (applyPushButton, SLOT (pressed()), this, SIGNAL (signalApplyButton()));
}

void ScrollingViewTab::intialization()
{
    xOffsetLabel = new QLabel();
        initializeLabel(xOffsetLabel, "Offset:");
    xRangeLabel = new QLabel();
        initializeLabel(xRangeLabel, "Range:");
    xOffsetSpinBox = new QSpinBox();
        initializeSpinBox(xOffsetSpinBox, 999999999);
    xRangeSpinBox = new QSpinBox();
        initializeSpinBox(xRangeSpinBox, 999999999);
    applyPushButton = new QPushButton();
        initializePushButton(applyPushButton, "Apply");
    layout = new QGridLayout();
        layout->addWidget(xOffsetLabel, 1, 1, 1, 1, Qt::AlignCenter);
        layout->addWidget(xOffsetSpinBox, 1, 2, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeLabel, 2, 1, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeSpinBox, 2, 2, 1, 1, Qt::AlignCenter);
        layout->addWidget(applyPushButton, 3, 1, 1, 2, Qt::AlignCenter);
    this->setLayout(layout);
}

void ScrollingViewTab::initializeLabel(QLabel * labelPtr, QString labelTitle)
{
    labelPtr->setText(labelTitle);
}

void ScrollingViewTab::initializeSpinBox(QSpinBox * spinBoxPtr, int max)
{
    spinBoxPtr->setMaximum(max);
}

void ScrollingViewTab::initializePushButton(QPushButton *pushButtonPtr, QString pushButtonTitle)
{
    pushButtonPtr->setText(pushButtonTitle);
}

int ScrollingViewTab::getOffset()
{
    return xOffsetSpinBox->value();
}

int ScrollingViewTab::getRange()
{
    return xRangeSpinBox->value();
}

void ScrollingViewTab::applyPushButtonPressed()
{
    emit signalApplyButton();
}
