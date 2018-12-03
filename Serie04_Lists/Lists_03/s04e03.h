#pragma once

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>


class S04E03 : public QWidget {
Q_OBJECT

public:
    explicit S04E03(QWidget *parent = nullptr);

private:
    QList< QString > data;
    QComboBox *comboBox;
    QPushButton *validateBtn;
    QPushButton *exitBtn;
    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;

    void usualBtns();

private slots:
    void validate();
    void validate(const QString &text);

};

