#pragma once

#include <QWidget>


class S09E01 : public QWidget {
Q_OBJECT

public:
    explicit S09E01(QWidget *parent=nullptr);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    void initTools();
    double solveForX(double x);
    void drawAxis();
    void drawCurve();
    QRect centerRef();

    QPainter *paint;
    QPen *pen;

    QVector<double> coeffs;
    int max_x;
    int max_y;
};

