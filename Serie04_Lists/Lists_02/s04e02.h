#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QMessageBox>
#include <QDebug>

class QDoubleSpinBox;

class S04E02 : public QWidget {
Q_OBJECT

public:
    explicit S04E02(QWidget *parent = nullptr);

private:
    QPushButton *validateBtn;
    QPushButton *exitBtn;
    QDoubleSpinBox *spinBox;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;

    void usualBtns();

private slots:
    void validate();
    void printTemperature(const QString &);

};

