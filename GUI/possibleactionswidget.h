#ifndef POSSIBLEACTIONSWIDGET_H
#define POSSIBLEACTIONSWIDGET_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QPoint>
#include <QEvent>

class PossibleActionsWidget : public QWidget
{
    Q_OBJECT
    
    QVector<QPushButton * > buttons;
    bool flag = 0;
public:
    PossibleActionsWidget(QVector<QString> actions, QVector<int>, QPoint point, QWidget *parent = 0);
    ~PossibleActionsWidget();
    
signals:
    void choiceIsMade(QString);
    
public slots:
    void buttonWasClicked();


};

#endif // POSSIBLEACTIONSWIDGET_H
