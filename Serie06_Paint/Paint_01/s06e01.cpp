#include <QtWidgets>
#include "s06e01.h"

S06E01::S06E01(QWidget *parent) : QWidget(parent) {
    pixmap = new QPixmap("Smiley.jpg");
    image = new QImage("Smiley.jpg");
    setWindowTitle("S06E01: Formes");
    setFixedSize(800, 800);
}

void S06E01::paintEvent(QPaintEvent *) {
    painter = new QPainter(this);

    // Header
    painter->setPen(Qt::black);
    painter->drawText(100, 20, "Les différentes formes avec Qt");

    // Line
    painter->setPen(Qt::black);
    painter->drawLine(0, 0, width(), height());

    // Pie section
    painter->setBrush(Qt::blue);
    painter->drawPie(
        QRect{ 10, 40, 200, 100 }, // container position
        (16 * 10),                 // start
        (16 * 160)                 // span
    );

    // Rectangle
    painter->setBrush(Qt::red);
    painter->drawRect(10, 100, 200, 100);

    // Polygon
    const QPoint polyPoints[] = {
        QPoint{100, 210},
        QPoint{120, 280},
        QPoint{180, 220},
        QPoint{190, 240},
    };
    painter->setBrush(Qt::yellow);
    painter->drawPolygon(polyPoints, 4);

    // Pixmap
    painter->drawPixmap(10, 280, 50, 50, *pixmap);

    // Image
    painter->drawImage(QRect{10, 350, 50, 50}, *image);

    // Rounded Rect
    painter->drawRoundedRect(10, 420, 200, 100, 20., 20.);

    // Ellipse
    painter->setBrush(Qt::green);
    painter->drawEllipse(10, 540, 100, 50);

    // Texts
    painter->setPen(Qt::black);
    painter->drawText(300, 70, "drawPie");
    painter->drawText(300, 170, "drawRect");
    painter->drawText(300, 250, "drawPolygon");
    painter->drawText(300, 300, "drawPixmap");
    painter->drawText(300, 380, "drawImage");
    painter->drawText(300, 470, "drawRoundedRect");
    painter->drawText(300, 570, "drawEllipse");
}

