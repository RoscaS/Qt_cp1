#pragma once

#include <QWidget>
#include <QRadioButton>
#include <QPushButton>

class S03E02 : public QWidget {
Q_OBJECT

private:
    QPushButton *button;
    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;

public:
    explicit S03E02(QWidget *parent = nullptr);

private slots:
    void displayChoice();
};

