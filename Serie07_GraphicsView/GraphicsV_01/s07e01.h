#pragma once

#include <QGraphicsView>


class S07E01 : public QGraphicsView {
Q_OBJECT

public:
    explicit S07E01(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *) override;

private:
    QGraphicsScene *scene;
    QGraphicsLineItem *line;
};

