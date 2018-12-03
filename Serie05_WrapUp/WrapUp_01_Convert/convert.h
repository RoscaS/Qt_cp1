#pragma once

#include <QWidget>

#include <QGridLayout>
#include <QVBoxLayout>

#include <QPushButton>
#include <QRadioButton>
#include <QLCDNumber>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>

#include <QDebug>
#include <QMap>

class Convert : public QWidget {
Q_OBJECT

public:
    explicit Convert(QWidget *parent = nullptr);

private:
    QRadioButton *cfRadio, *fcRadio;
    QPushButton *resetBtn, *exitBtn;
    QPushButton *computeBtn;
    QLineEdit *tempField;
    QLCDNumber *display;
    QLabel *unitLabel;

    void initConnections();
    void tweakWidgets();
    void initView();

    double cfConvert();
    double fcConvert();
    double fieldValue();

    void updateDisplay();
    void updateUnit();

    QString round(double value);

private slots:
    void reset();
    void updateData();
};

