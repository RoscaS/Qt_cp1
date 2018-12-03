#pragma once

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>

class S04E01 : public QWidget {
Q_OBJECT

public:
    explicit S04E01(QWidget *parent = nullptr);

private slots:

    void submit();
    void newItem();

private:
    QListWidget *list;
};

