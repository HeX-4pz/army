#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QObject>
#include "../army/point.h"

class CustomButton : public QPushButton
{
    Q_OBJECT

    Point self;
public:
    //CustomButton(QWidget * parent = nullptr);
    CustomButton( int y, int x, QWidget * parent = nullptr);
signals:
    void leftButtonClicked(Point);
    void rightButtonClicked(Point);
    void mouseEnter(Point);
    void mouseLeave(Point);
    
protected:
    void enterEvent(QEvent *ev);
    void leaveEvent(QEvent *ev);
    void mousePressEvent(QMouseEvent *event);

};

#endif // CUSTOMBUTTON_H
