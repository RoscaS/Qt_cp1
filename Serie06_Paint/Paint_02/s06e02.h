#pragma once

#include <QWidget>
#include <QDebug>

class S06E02 : public QWidget {
Q_OBJECT

public:
    explicit S06E02(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    void drawPoint(QMouseEvent *e);
    void texts(QPainter &painter);
    void paint(QPainter &painter);


    QList< QPoint > pointsList;
    QPoint point;

    int paintEventCalls;
    int size;
    int radius;
};

