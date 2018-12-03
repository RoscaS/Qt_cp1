#include <QtWidgets>

#include "s03e04.h"


S03E04::S03E04(QWidget *parent) : QWidget(parent) {
    checkBox = new QCheckBox(tr("&Uniquement en cas de choix 3"), this);
    button = new QPushButton(tr("&Valider"), this);
    radio1 = new QRadioButton(tr("Choix &1"));
    radio2 = new QRadioButton(tr("Choix &2"));
    radio3 = new QRadioButton(tr("Choix &3"));

    checkBox->setDisabled(true);
    button->setIcon(QIcon("chercher.png"));
    radio1->setIcon(QPixmap("options.xpm"));
    radio2->setIcon(QPixmap("screen.xpm"));
    radio3->setIcon(QPixmap("spherelime.xpm"));

    // permet de rendre non-exclusif les radios
    auto *buttonGrp = new QButtonGroup(this);
    buttonGrp->addButton(radio1);
    buttonGrp->addButton(radio2);
    buttonGrp->addButton(radio3);
    buttonGrp->setExclusive(false);

    auto *groupBox = new QGroupBox(tr("Radio non-exclusifs"), this);
    // Ajoute une case à cocher pour activer les élements du grp
    groupBox->setCheckable(true);
    groupBox->setChecked(true);

    auto *vLayout = new QVBoxLayout;
    vLayout->addWidget(radio1);
    vLayout->addWidget(radio2);
    vLayout->addWidget(radio3);
    groupBox->setLayout(vLayout);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    mainLayout->addWidget(checkBox);
    mainLayout->addWidget(button);

    setLayout(mainLayout);
    setFixedSize(400, 150);

    connect(button, &QPushButton::clicked, this, &S03E04::displayChoice);
    connect(radio3, &QRadioButton::toggled, checkBox, &QCheckBox::setEnabled);

}

void S03E04::displayChoice() {
    for (auto const i : QVector< QRadioButton * >{ radio1, radio2, radio3 }) {
        if (i->isChecked()) {
            QMessageBox::information(this, "Info", i->text());
        }
    }
}
