#include "custombutton.h"

//CustomButton::CustomButton(QWidget *parent) : QPushButton(parent)
//{

//}

CustomButton::CustomButton( int y, int x, QWidget *parent) : QPushButton(parent)
{
    this->setFocusPolicy(Qt::NoFocus);
    self = Point(y, x);
}

void CustomButton::enterEvent(QEvent *ev)
{
    emit mouseEnter(self);
}

void CustomButton::leaveEvent(QEvent *ev)
{
    emit mouseLeave(self);
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::RightButton) {
        emit rightButtonClicked(self);
    } else if ( event->button() == Qt::LeftButton) {
        emit leftButtonClicked(self);
    }
}
