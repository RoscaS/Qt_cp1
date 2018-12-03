#include <QtWidgets>
#include "s04e01.h"

S04E01::S04E01(QWidget *parent) : QWidget(parent) {
    auto* mainLayout = new QVBoxLayout;
    auto* buttonsLayout = new QHBoxLayout;

    auto *newBtn = new QPushButton("&Nouveau", this);
    auto *exitBtn = new QPushButton("&Quitter", this);
    auto* groupBox = new QGroupBox("", this);

    buttonsLayout->addWidget(newBtn);
    buttonsLayout->addWidget(exitBtn);
    groupBox->setLayout(buttonsLayout);

    list = new QListWidget(this);
    new QListWidgetItem("un", list);
    new QListWidgetItem("deux", list);
    new QListWidgetItem("trois", list);

    // Insérer un item à un index spécifique
    auto *newItem = new QListWidgetItem;
    newItem->setText("nouveau");
    list->insertItem(2, newItem);

    mainLayout->addWidget(list);
    mainLayout->addWidget(groupBox);

    setLayout(mainLayout);
    setFixedSize(400, 150);

    connect(list, &QListWidget::itemSelectionChanged, this, &S04E01::submit);
    connect(newBtn, &QPushButton::clicked, this, &S04E01::newItem);
    connect(exitBtn, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
}

void S04E01::submit() {
    QMessageBox::information(this, "Info", "Nouvelle selection");
}

void S04E01::newItem() {
    bool ok;
    QString text = QInputDialog::getText(
        this,
        tr("Nouvel item"),
        tr("Item"),
        QLineEdit::Normal,
        "Nouveau",
        &ok
    );

    if (ok && !text.isEmpty()) {
        list->addItem(new QListWidgetItem(text));
    }
}
