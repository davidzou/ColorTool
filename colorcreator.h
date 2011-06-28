#ifndef COLORCREATOR_H
#define COLORCREATOR_H

#include <QWidget>
#include <QMouseEvent>
#include "roboimage.h"
#include "coloredit.h"
#include "colortable.h"
#define  NEWFRAMES
#ifdef   NEWFRAMES
#define  COLORS 8
#define  SOFT 3
#define  WIDTH 640
#define  HEIGHT 480
#define  EXTENSION ".frm"
#define  EXTENSIONLENGTH = 4
#else
#define  COLORS 8
#define  WIDTH 320
#define  HEIGHT 240
#define  EXTENSION ".NBFRM"
#define  EXTENSIONLENGTH = 6
#endif
#define GREY_COL 0x00
#define WHITE_COL 0x01
#define GREEN_COL 0x02
#define BLUE_COL 0x04
#define YELLOW_COL 0x08
#define ORANGE_COL 0x10
#define YELLOWWHITE_COL 0x09
#define BLUEGREEN_COL 0x06
#define ORANGERED_COL 0x30
#define ORANGEYELLOW_COL 0x18
#define RED_COL 0x20
#define NAVY_COL 0x40

#define IMAGE_X  50  // where the large image x is
#define IMAGE_Y  60
#define IMAGE_WIDTH  640
#define IMAGE_HEIGHT  480



namespace Ui {
    class ColorCreator;
}

class ColorCreator : public QWidget
{
    Q_OBJECT

public:
    enum Colors {Orange, Blue, Yellow, Green, White, Pink, Navy, Black, BlueGreen, BlueNavy, OrangeRed};
    enum Choices {Single, Multiple};
    enum Shape { Y, U, V, Bluec, Redc, Greenc, H, S, Z, EDGE, Table};
    explicit ColorCreator(QWidget *parent = 0);
    ~ColorCreator();
    void updateDisplays();
    void updateColors();
    void updateThresh(bool imageChanged, bool choiceChanged, bool colorsChanged);
    void initStats();
    void collectStats(int x, int y);
    void outputStats();
    float min(float a, float b) {if (a < b) return a; return b;}
    float max(float a, float b) {if (a > b) return a; return b;}
    int min(int a, int b) {if (a < b) return a; return b;}
    int max(int a, int b) {if (a > b) return a; return b;}
    void writeNewFormat(QString filename);
    void writeOldFormat(QString filename);
    QColor getChannelView(int i, int j);
    void largeDisplay();
    QColor displayColorTable(int i, int j);
    bool testValue(float h, float s, float z, int y, int u, int v, int color);

protected:
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_previousButton_clicked();

    void on_nextButton_clicked();

    void on_hMin_valueChanged(int value);

    void on_hMax_valueChanged(int value);

    void on_sMin_valueChanged(int value);

    void on_sMax_valueChanged(int value);

    void on_yMin_valueChanged(int value);

    void on_yMax_valueChanged(int value);

    void on_zSlice_valueChanged(int value);

    void on_colorSelect_currentIndexChanged(int index);

    void on_viewChoice_currentIndexChanged(int index);

    void on_zMin_valueChanged(int value);

    void on_zMax_valueChanged(int value);

    void on_getColorTable_clicked();

    void on_writeNew_clicked();

    void on_plusTen_clicked();

    void on_minusTen_clicked();

    void on_channel_currentIndexChanged(int index);

    void on_getOldTable_clicked();

    void on_edgeDiff_actionTriggered(int action);

    void on_edgeDiff_valueChanged(int value);

    void on_vMin_valueChanged(int value);

    void on_vMax_valueChanged(int value);

    void on_radioButton_clicked();

    void on_ColorChange_clicked();

    void on_cornerDefine_clicked();

    void on_changeColor_clicked();

private:
    Ui::ColorCreator *ui;
    RoboImage roboimage;
    ColorTable *table;
    QString baseDirectory;
    QString currentDirectory;
    QString baseColorTable;
    QString currentColorDirectory;
    QString nextFrame;
    QString previousFrame;
    QString tenthFrame;
    QString minusTenthFrame;
    QImage *img;
    QImage *img2;
    QImage *img3;
    QImage *img4;
    QImage *wheel;
    int shape;
    int currentFrameNumber;
    int edgediff;
    int mode;
    QColor *cols;
    float *hMin;
    float *hMax;
    float *sMin;
    float *sMax;
    float *zMin;
    float *zMax;
    float zSlice;
    int *yMin;
    int *yMax;
    int *vMin;
    int *vMax;
    float statsHMin, statsHMax, statsSMin, statsSMax, statsZMin, statsZMax;
    int statsYMin, statsYMax, statsUMin, statsUMax, statsVMin, statsVMax;
    int currentColor;
    ColorEdit *green;
    unsigned *bitColor;
    bool haveFile;
    bool viewerEnabled;
    bool tableMode;
    bool defineMode;
    bool cornerStatus;
    QPoint firstPoint;
    QPoint lastPoint;
};

#endif // COLORCREATOR_H
