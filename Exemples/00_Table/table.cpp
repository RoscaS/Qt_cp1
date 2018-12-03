#include "table.h"

Table::Table(QWidget *parent) : QWidget(parent) {
    lwListe = new QListWidget(this);
    leNouveau = new QLineEdit(this);
    btAjouter = new QPushButton("&+", this);
    btSuppr = new QPushButton("&-", this);
    btReset = new QPushButton("&x", this);

    auto *ltMain = new QVBoxLayout(this);
    auto *ltBas = new QHBoxLayout;

    ltBas->addWidget(btAjouter);
    ltBas->addWidget(btSuppr);
    ltBas->addWidget(btReset);
    ltMain->addWidget(lwListe);
    ltMain->addWidget(leNouveau);
    ltMain->addLayout(ltBas);

    connect(btAjouter, SIGNAL(clicked()), this, SLOT(ajouter()));
    connect(btSuppr, SIGNAL(clicked()), this, SLOT(retirer()));
    connect(btReset, SIGNAL(clicked()), this, SLOT(reset()));
    connect(leNouveau, SIGNAL(editingFinished()), this, SLOT(ajouter()));

    setFixedSize(100, 200);
    liste << 10 << 25 << 40 << 25;
}

void Table::refresh() {
    double v;
    lwListe->clear();
        foreach(v, liste) lwListe->addItem(QString::number(v));
    emit changed(liste);
}

void Table::ajouter() {
    if (!leNouveau->text().isEmpty())
        liste << leNouveau->text().toDouble();
    leNouveau->clear();
    refresh();
}

void Table::retirer() {
    if (lwListe->selectedItems().count() > 0)
        liste.removeAt(lwListe->currentRow());
    refresh();
}

void Table::reset() {
    liste.clear();
    refresh();
}
