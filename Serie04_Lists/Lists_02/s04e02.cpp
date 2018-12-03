#include <QtWidgets>
#include "s04e02.h"


S04E02::S04E02(QWidget *parent) : QWidget(parent) {

    auto* mainLayout = new QVBoxLayout;
    auto* spinBoxLayout = new QHBoxLayout;

    spinBox = new QDoubleSpinBox(this);
    spinBox->setMaximumWidth(250);
    spinBox->setMinimum(-50);
    spinBox->setMaximum(50);
    spinBox->setSingleStep(.1);

    spinBoxLayout->addWidget(spinBox);
    mainLayout->addLayout(spinBoxLayout);
    usualBtns();
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
    setFixedSize(400, 150);

    connect(validateBtn, &QPushButton::clicked, this, &S04E02::validate);
    connect(
        spinBox, SIGNAL(valueChanged(const QString&)),
        this, SLOT(printTemperature(const QString&))
    );
}


void S04E02::validate() {
    QString text = QString("Value: %1").arg(spinBox->text());
    QMessageBox::information(this, "Value set", text);
}

void S04E02::printTemperature(const QString &text) {
    qDebug() << text;
}


void S04E02::usualBtns(){
    buttonsLayout = new QHBoxLayout;
    exitBtn = new QPushButton("&Exit", this);
    validateBtn = new QPushButton("&Validate", this);
    buttonsLayout->addWidget(validateBtn);
    buttonsLayout->addWidget(exitBtn);
    connect(exitBtn, &QPushButton::clicked, this, &QApplication::quit);
}

