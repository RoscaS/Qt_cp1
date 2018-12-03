#include <QtWidgets>

#include "s03e02.h"


S03E02::S03E02(QWidget *parent) : QWidget(parent) {
    button = new QPushButton(tr("&Valider"), this);
    radio1 = new QRadioButton(tr("Choix &1"), this);
    radio2 = new QRadioButton(tr("Choix &2"), this);
    radio3 = new QRadioButton(tr("Choix &3"), this);

    button->setIcon(QIcon("chercher.png"));
    radio1->setIcon(QPixmap("options.xpm"));
    radio2->setIcon(QPixmap("screen.xpm"));
    radio3->setIcon(QPixmap("spherelime.xpm"));

    auto *groupBox = new QGroupBox(tr("Radio exclusifs"), this);

    auto *vLayout = new QVBoxLayout;
    vLayout->addWidget(radio1);
    vLayout->addWidget(radio2);
    vLayout->addWidget(radio3);
    groupBox->setLayout(vLayout);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(button);

    setLayout(mainLayout);
    setFixedSize(400, 150);

    connect(button, &QPushButton::clicked, this, &S03E02::displayChoice);
}

void S03E02::displayChoice() {
    if (radio1->isChecked()) {
        QMessageBox::information(this, "Info", "Cas 1");
    }
    else if (radio2->isChecked()) {
        QMessageBox::information(this, "Info", "Cas 2");
    }
    else if (radio3->isChecked()) {
        QMessageBox::information(this, "Info", "Cas 3");
    }
}
