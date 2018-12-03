#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QDebug>

class S04E04 : public QWidget {
Q_OBJECT

public:
    explicit S04E04(QWidget* parent = nullptr);

private:
    QLineEdit* firstNameField;
    QLineEdit* lastNameField;
    QLineEdit* passwordField;
    QLineEdit* birthdayField;

    QHBoxLayout* buttonsLayout;
    QPushButton* validateBtn;
    QPushButton* exitBtn;

    void usualBtns();

private slots:
    void onTextChange(const QString & value);
    void onSubmit();
};

