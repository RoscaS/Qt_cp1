#pragma once

#include <QtWidgets>

class Table : public QWidget {
Q_OBJECT

public:
    explicit Table(QWidget *parent=nullptr);

private:
    QList< double > liste;
    QListWidget *lwListe;
    QLineEdit *leNouveau;
    QPushButton *btAjouter, *btSuppr, *btReset;

signals:
    void changed(QList< double > &);

public slots:
    void ajouter();
    void retirer();
    void refresh();
    void reset();
};
