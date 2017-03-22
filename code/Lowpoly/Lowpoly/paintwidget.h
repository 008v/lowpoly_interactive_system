#pragma once
#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H


#include<QtGui>
#include <qwidget.h>
#include<qdebug.h>
#include <qlist.h>
#include <qlabel.h>
#include <qmouseeventtransition.h>

class PaintWidget : public QLabel
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    void init();
    bool isPaintButtonClicked;
    QImage* srcImg;
    QImage* inputImg;
    QImage* paintMask;
    int brushSize;
    QPoint curPosition;
signals:
    void keyPlusPressed();
    void keyMinusPressed();
public slots:
protected:
    // �����¼����Դ��ڽ����ػ棬��repaint()��update()���ã��Դ��ڵĻ���ֻ�������������
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    // void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    bool isLeftMousePressed;
    QPen oldPenStyle;
    QPainter* painter;
    QImage display;
};

#endif // PAINTWIDGET_H
