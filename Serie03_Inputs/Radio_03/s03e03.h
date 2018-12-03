#pragma once

#include <QWidget>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>

class S03E03 : public QWidget {
Q_OBJECT

private:
    QCheckBox *checkBox;
    QPushButton *button;
    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;

public:
    explicit S03E03(QWidget *parent = nullptr);

public slots:
    void displayChoice();
};


