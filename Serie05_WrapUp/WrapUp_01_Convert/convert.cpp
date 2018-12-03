#include "convert.h"
#include <QtWidgets>

Convert::Convert(QWidget* parent) : QWidget(parent) {
    fcRadio    = new QRadioButton(tr("&Farenheit -> Celcius"), this);
    cfRadio    = new QRadioButton(tr("&Celcius -> Farenheit"), this);
    resetBtn   = new QPushButton(tr("&Ré-initialiser"), this);
    computeBtn = new QPushButton(tr("C&alculer"), this);
    exitBtn    = new QPushButton(tr("&Quitter"), this);
    tempField  = new QLineEdit("0", this);
    display    = new QLCDNumber(this);
    unitLabel  = new QLabel("°F");

    initConnections();
    initView();
}

void Convert::initView() {
    auto* grid = new QGridLayout;

    grid->addWidget(cfRadio, 0, 0);
    grid->addWidget(fcRadio, 1, 0);

    grid->addWidget(tempField, 2, 0);
    grid->addWidget(resetBtn, 3, 0);

    grid->addWidget(unitLabel, 2, 1);
    grid->addWidget(exitBtn, 3, 1);

    grid->addWidget(display, 0, 1, 2, 2);
    grid->addWidget(computeBtn, 3, 2);

    setLayout(grid);
    tweakWidgets();
    updateData();
}

void Convert::tweakWidgets() {
    setWindowTitle(tr("Conversion de températures"));
    tempField->setValidator(new QDoubleValidator(-100, 100, 2, tempField));
    cfRadio->setChecked(true);
    tempField->setAlignment(Qt::AlignRight);
    display->setSmallDecimalPoint(true);
    display->setDigitCount(7);
    display->setSegmentStyle(QLCDNumber::Flat);
    setFixedSize(400, 150);
}

void Convert::initConnections() {
    connect(computeBtn, &QPushButton::clicked, this, &Convert::updateData);
    connect(cfRadio, &QRadioButton::toggled, this, &Convert::updateData);
    connect(exitBtn, &QPushButton::clicked, this, &QApplication::quit);
    connect(resetBtn, &QPushButton::clicked, this, &Convert::reset);
}

QString Convert::round(double value) {
    return QString::number(value, 'f', 1);
}

double Convert::fieldValue() {
    return tempField->text().toDouble();
}

double Convert::cfConvert() {
    return (fieldValue() * 9 / 5) + 32;
}

double Convert::fcConvert() {
    return 5* (fieldValue() - 32) / 9;
}

void Convert::updateData() {
    updateDisplay();
    updateUnit();
}

void Convert::updateDisplay() {
    double value = cfRadio->isChecked() ? cfConvert() : fcConvert();
    QString unit = cfRadio->isChecked() ? "F" : "C";
    display->display(QString("%1'%2").arg(round(value)).arg(unit));
}

void Convert::updateUnit() {
    unitLabel->setText(QString("°%1").arg(cfRadio->isChecked() ? "C" : "F"));
}

void Convert::reset() {
    fcRadio->setChecked(false);
    cfRadio->setChecked(true);
    tempField->setText("0");
    updateData();
}










