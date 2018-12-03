#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>


class Chrono : public QWidget {
Q_OBJECT

private:
    QPushButton *startBtn, *lapsBtn, *exitBtn;
    QLCDNumber  *timeDisplay;
    QTime       *timeDelta, *time;
    bool        isRunning, isLap;

    void initView();
    void initConnections();

    void initTime();
    void tweakWidgets();

    void resetQtime();
    void display();

    void timerEvent(QTimerEvent *) override;
    void updateTime();

public:
    explicit Chrono(QWidget *parent = nullptr);

private slots:
    void start();
    void laps();

private:
};

