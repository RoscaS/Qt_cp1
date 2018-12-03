#pragma once

#include <QWidget>

class S06E03 : public QWidget {
Q_OBJECT

public:
    explicit S06E03(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;


private:
    void addLine();
    void texts(QPainter &painter);
    void paint(QPainter &painter);

    QList< QLine > line_list;
    QPoint         start_point, end_point;
    int            paint_event_calls;

};
