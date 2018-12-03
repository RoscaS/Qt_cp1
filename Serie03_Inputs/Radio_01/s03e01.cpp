#include <QtWidgets>

#include "s03e01.h"

S03E01::S03E01(QWidget *parent) : QWidget(parent) {

    button = new QPushButton(tr("&Valider"), this);
    radio1 = new QRadioButton(tr("Choix &1"), this);
    radio2 = new QRadioButton(tr("Choix &2"), this);
    radio3 = new QRadioButton(tr("Choix &3"), this);

    auto *groupBox = new QGroupBox(tr("Boutons radio exclusifs"), this);

    auto *vLayout = new QVBoxLayout;
    vLayout->addWidget(radio1);
    vLayout->addWidget(radio2);
    vLayout->addWidget(radio3);
    groupBox->setLayout(vLayout);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(button);

    setLayout(mainLayout);

    connect(radio1, &QRadioButton::toggled, this, &S03E01::displayChoice);
    connect(radio2, &QRadioButton::toggled, this, &S03E01::displayChoice);
    connect(radio3, &QRadioButton::toggled, this, &S03E01::displayChoice);
}


void S03E01::displayChoice() {
    if (radio1->isChecked()) button->setText("Choix 1");
    else if (radio2->isChecked()) button->setText("Choix 2");
    else if (radio3->isChecked()) button->setText("Choix 3");
}
