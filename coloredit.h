#ifndef COLOREDIT_H
#define COLOREDIT_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include "roboimage.h"

class ColorEdit : public QWidget
{
    Q_OBJECT
public:
    enum Colors { Yellow, Blue, Orange, Green, White, Pink, Navy };
    explicit ColorEdit(Colors c, RoboImage r1, QWidget *parent = 0);

signals:

public slots:
    void grabHMin(int x);
    void grabHMax(int x);
    void grabSMin(int x);
    void grabSMax(int x);
    void grabZMin(int x);
    void grabZMax(int x);

private:
    QSlider *hMin;
    QSlider *hMax;
    QSlider *sMin;
    QSlider *sMax;
    QSlider *zMin;
    QSlider *zMax;
    int hLow, hHigh, sLow, sHigh, zLow, zHigh;
    RoboImage r;
    Colors color;


};

#endif // COLOREDIT_H
