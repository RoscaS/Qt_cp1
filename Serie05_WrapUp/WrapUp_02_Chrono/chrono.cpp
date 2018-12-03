#include <QtWidgets>
#include "chrono.h"

Chrono::Chrono(QWidget *parent) : QWidget(parent) {
    startBtn    = new QPushButton(tr("&Démarrer"), this);
    lapsBtn     = new QPushButton(tr("&Intermédiaire"), this);
    exitBtn     = new QPushButton(tr("&Quitter"), this);
    timeDisplay = new QLCDNumber(12, this);

    initView();
    tweakWidgets();
    initConnections();
    initTime();
    display();
    startTimer(5);
}

void Chrono::initView() {
    auto *btnsLayout = new QHBoxLayout;
    auto *mainLayout = new QVBoxLayout(this);

    btnsLayout->addWidget(startBtn);
    btnsLayout->addStretch(1);
    btnsLayout->addWidget(lapsBtn);
    btnsLayout->addWidget(exitBtn);

    mainLayout->addWidget(timeDisplay);
    mainLayout->addLayout(btnsLayout);
    isRunning = isLap = false;
}

void Chrono::initTime() {
    timeDelta = new QTime();
    time = new QTime(0, 0, 0, 0);
}

void Chrono::tweakWidgets() {
    setWindowTitle("Chrono");
    exitBtn->setStyleSheet("background-color: #F92672; color: white;");
    lapsBtn->setCheckable(true);
    lapsBtn->setEnabled(false);
    timeDisplay->setSegmentStyle(QLCDNumber::Filled);
    setFixedSize(400, 150);
}

void Chrono::initConnections() {
    connect(startBtn, &QPushButton::clicked, this, &Chrono::start);
    connect(lapsBtn, &QPushButton::clicked, this, &Chrono::laps);
    connect(exitBtn, &QPushButton::clicked, this, &QApplication::quit);
}

void Chrono::display() {
    timeDisplay->display(time->toString(tr("hh:mm:ss.zzz")));
}

void Chrono::updateTime() {
    *time = time->addMSecs(timeDelta->elapsed());
    timeDelta->restart();
    if (!isLap) display();
}

void Chrono::timerEvent(QTimerEvent *) {
    if (isRunning) updateTime();
}

void Chrono::start() {
    isRunning = !isRunning;
    lapsBtn->setChecked(false);
    lapsBtn->setEnabled(isRunning);

    isRunning ? resetQtime() : startBtn->setText(tr("&Démarrer"));
}

void Chrono::resetQtime() {
    isLap = false;
    time->setHMS(0, 0, 0, 0);
    timeDelta->start();
    startBtn->setText(tr("&Arrêter"));
}

void Chrono::laps() {
    isLap = !isLap;
}
