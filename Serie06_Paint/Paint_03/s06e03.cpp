
#include <QtWidgets>
#include <QtMath>

#include "s06e03.h"

S06E03::S06E03(QWidget *parent) : QWidget(parent) {
    paint_event_calls = 0;
    setWindowTitle("S06E02: Lignes");
    setFixedSize(400, 300);
}

void S06E03::paintEvent(QPaintEvent *) {
    paint_event_calls++;
    QPainter painter(this);
    texts(painter);
    paint(painter);
}

void S06E03::texts(QPainter &painter) {
    auto a = QString(tr("Nombre d'appels de paintEvent: %1"));
    auto b = QString(tr("Nombre de lignes: %1"));
    painter.drawText(20, 20, a.arg(paint_event_calls));
    painter.drawText(20, 40, b.arg(line_list.length()));
}

void S06E03::paint(QPainter &painter) {
    painter.setPen(Qt::blue);
    for (auto &i : line_list) { painter.drawLine(i); }
}

void S06E03::mousePressEvent(QMouseEvent *e) {
    start_point = e->pos();
}

void S06E03::mouseMoveEvent(QMouseEvent *e) {
    end_point = e->pos();
    addLine();
}

void S06E03::addLine() {
    line_list.append(QLine(start_point, end_point));
    start_point = end_point;
    update();
}
