#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVector>
#include <QLabel>
#include <QDebug>
#include <QScrollArea>
#include "battlemap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QLabel * leftTextForm;
    QLabel * rightTextForm;
    QLabel * currentTextForm;
    QLabel * otherTextForm;
    QLabel * bottomTextForm;
    QLabel * topTextForm;
    BattleMap * map;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initTeams();
    
public slots:
    void updLeftText(QString msg);
    void updRightText(QString msg);
    void updTopText(QString msg);
signals:
};

#endif // MAINWINDOW_H
