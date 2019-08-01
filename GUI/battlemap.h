#ifndef BATTLEMAP_H
#define BATTLEMAP_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "custombutton.h"
#include <QVector>
#include "../army/unit/unit.h"
#include "team.h"
#include "possibleactionswidget.h"
#include "widgetmagicbook.h"
#include <iostream>


inline uint qHash( const Point &point) {
    return qHash( QString::number(point.getX())+"_"+QString::number(point.getY()) , 0xa03f); // arbitrary value
}

class Team;

class BattleMap : public QWidget
{
    Q_OBJECT

    int sizeY;
    int sizeX;
    QVector < QVector<CustomButton *> > cells;
    QSet<Point> moveCells;
    Team * leftTeam;
    Team * rightTeam;
    Team * curTeam;
    Team * othTeam;
    Point pressed;
    Point target;

    QString colorMauseInField;
    QString colorMauseOutField;
    QString colorMouseInAccessibleCells;
    QString colorMouseOutAccessibleCells;
    QString colorMouseInLeftTeam;
    QString colorMouseOutLeftTeam;
    QString colorMouseInRightTeam;
    QString colorMouseOutRightTeam;
    std::string output;
    PossibleActionsWidget * possibleActions;
    WidgetMagicBook * widgetmagicbook;

    void updateBattleMap();
    QSet<Point> getAccessibleCells( Unit *);
    Point validatePoint(Point );
    bool isCellFree(Point target);
    bool checkAbilityAttack(Unit * unit, Point target);
    void changeMovingTeam();
    void closeChildWindows();


public:
    explicit BattleMap(int sizeX, int sizeY, QWidget *parent = nullptr);
    ~BattleMap();

    Point getAccesiblePointToAttack( Unit * unit, Point point);
    Point getCellForDeamon( Unit * summoner);
    void initTeams();

signals:
    void leftTeamInfo(QString msg);
    void rightTeamInfo(QString msg);
    void turnInfo(QString msg);

public slots:
    void clickButtonLeftMouse(Point);
    void clickButtonRightMouse(Point);
    void mouseMoveIn(Point);
    void mouseMoveOut(Point);
    void actionSelected( QString msg );
    void chengeSpell(std::string spell);
};

#endif // BATTLEMAP_H
