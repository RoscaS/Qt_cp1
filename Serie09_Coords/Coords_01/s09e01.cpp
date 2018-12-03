#include <QtWidgets>

#include "s09e01.h"


S09E01::S09E01(QWidget *parent) : QWidget(parent) {
    max_x = 20;
    max_y = 40;
    coeffs = { -10, 3, 0.5 };
}

void S09E01::paintEvent(QPaintEvent *) {
    initTools();
    drawAxis();
    drawCurve();
}

void S09E01::initTools() {
    paint = new QPainter(this);
    paint->setWindow(QRect(-max_x / 2, max_y / 2, max_x, -max_y));
    pen = new QPen();
    pen->setColor(Qt::blue);
    pen->setWidth(0);
}

double S09E01::solveForX(double x) {
    int degre = coeffs.size() - 1;
    double y = 0;

    for (int i = 0; i <= degre; i++) {
        y = y * x + coeffs[degre - i];
    }
    return y;
}

void S09E01::drawAxis() {
    paint->setPen(*pen);
    paint->drawLine(-max_x / 2, 0, max_x / 2, 0);
    paint->drawLine(0, max_y / 2, 0, -max_y / 2);
    paint->drawLine(0, 1, 1, 1);
    paint->drawLine(1, 0, 1, 1);
    pen->setColor(Qt::red);
    paint->setPen(*pen);
}

void S09E01::drawCurve() {
    double x = -max_x / 2.;
    double y = solveForX(x);
    QPointF start = QPointF(x, y);

    for (int i = (-max_x / 2) + 1; i <= (max_x / 2); i++) {
        x = i;
        y = solveForX(x);
        QPointF end = QPointF(x, y);

        if (y < max_y) paint->drawLine(start, end);
        start = end;
    }
}
