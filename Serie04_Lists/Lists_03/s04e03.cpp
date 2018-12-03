#include <QtWidgets>
#include "s04e03.h"


S04E03::S04E03(QWidget *parent) : QWidget(parent) {

    comboBox = new QComboBox(this);
    comboBox->setInsertPolicy(QComboBox::InsertAlphabetically);
    comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    comboBox->addItem("Berne");
    comboBox->addItem("La Chaux-de-Fonds");
    comboBox->addItem("Lausanne");
    comboBox->addItem("Le Locle");
    comboBox->addItem("St-Imier");
    comboBox->setCurrentIndex(0);
    comboBox->setEditable(true);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(comboBox);
    usualBtns();

    setLayout(mainLayout);
    setFixedSize(400, 150);

    connect(
        comboBox, SIGNAL(editTextChanged(const QString &)),
        this, SLOT(validate(const QString &))
    );
}


void S04E03::validate() {
    QMessageBox::information(this, "Ville choisie", comboBox->currentText());
    qDebug() << comboBox->currentText();
}

void S04E03::validate(const QString &text) {
    qDebug() << text;
}

void S04E03::usualBtns(){
    buttonsLayout = new QHBoxLayout;
    exitBtn = new QPushButton("&Exit", this);
    validateBtn = new QPushButton("&Validate", this);
    buttonsLayout->addWidget(validateBtn);
    buttonsLayout->addWidget(exitBtn);

    mainLayout->addLayout(buttonsLayout);

    connect(validateBtn, SIGNAL(clicked()), this, SLOT(validate()));
    connect(exitBtn, &QPushButton::clicked, this, &QApplication::quit);
}
