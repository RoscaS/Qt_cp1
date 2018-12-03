#include <QtWidgets>
#include <QtMath>

#include "s06e02.h"

S06E02::S06E02(QWidget *parent) {
    paintEventCalls = 0;
    size = 30;
    radius = qCeil(static_cast<double>(size/2));

    setWindowTitle("S06E02: Disques");
    setFixedSize(400, 300);
}

void S06E02::paintEvent(QPaintEvent *) {
    paintEventCalls++;
    QPainter painter(this);
    texts(painter);
    paint(painter);
}

void S06E02::texts(QPainter &painter) {
    auto a = QString(tr("Nombre d'appels de paintEvent: %1"));
    auto b = QString(tr("Nombre de disques: %1"));
    painter.drawText(20, 20, a.arg(paintEventCalls));
    painter.drawText(20, 40, b.arg(pointsList.length()));
}

void S06E02::drawPoint(QMouseEvent *e) {
    point = e->pos();
    point.rx() -= radius; // p.x() et p.y() sont const ...
    point.ry() -= radius; // ... utilisation de p.rx() et p.ry()
    update();
}

void S06E02::paint(QPainter &painter) {
    painter.setBrush(Qt::red);
    painter.setPen(Qt::blue);

    for (auto &i : pointsList) {
        painter.drawEllipse(i.rx(), i.ry(), size, size);
    }
    // Empeche le dessin d'un premier point à l'initialisation
    if (paintEventCalls > 2) {
        painter.drawEllipse(point.rx(), point.ry(), size, size);
    }
}

void S06E02::mousePressEvent(QMouseEvent *e) {
    drawPoint(e);
}

void S06E02::mouseMoveEvent(QMouseEvent *e) {
    drawPoint(e);
}

void S06E02::mouseReleaseEvent(QMouseEvent *e) {
    pointsList.append(point);
}

