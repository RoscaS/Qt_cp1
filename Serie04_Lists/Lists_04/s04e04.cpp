#include <QtWidgets>
#include "s04e04.h"

S04E04::S04E04(QWidget *parent) : QWidget(parent) {

    auto *mainLayout = new QVBoxLayout;
    auto *formLayout = new QFormLayout;

    firstNameField = new QLineEdit(this);
    lastNameField = new QLineEdit(this);
    passwordField = new QLineEdit(this);
    birthdayField = new QLineEdit(this);

    firstNameField->setMaxLength(15);
    lastNameField->setMaxLength(20);
    birthdayField->setInputMask("00-00-0000");
    passwordField->setEchoMode(QLineEdit::Password);

    formLayout->addRow("&First name:", firstNameField);
    formLayout->addRow("&Last name:", lastNameField);
    formLayout->addRow("&Birthday:", birthdayField);
    formLayout->addRow("&Password:", passwordField);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonsLayout);

    connect(lastNameField, &QLineEdit::textChanged,
            this, &S04E04::onTextChange);

    connect(firstNameField, &QLineEdit::returnPressed,
            this, &S04E04::onSubmit);

    setLayout(mainLayout);
    usualBtns();
    setFixedSize(400, 150);
}

void S04E04::onTextChange(const QString &value) {
    qDebug() << value;
}

void S04E04::onSubmit() {
    if (firstNameField->text() == QString("JP")) {
        firstNameField->setText("Jean-Pedro");
    }
}

void S04E04::usualBtns() {
    buttonsLayout = new QHBoxLayout;
    exitBtn = new QPushButton("&Exit", this);
    validateBtn = new QPushButton("&Validate", this);
    buttonsLayout->addWidget(validateBtn);
    buttonsLayout->addWidget(exitBtn);
    connect(exitBtn, &QPushButton::clicked, this, &QApplication::quit);
}
