#pragma once

#include "./army/unit/berserker.h"
#include "./army/unit/soldier.h"
#include "./army/unit/vampire.h"
#include "./army/unit/rogue.h"
#include "./army/unit/demon.h"
#include "./army/unit/werewolf.h"
#include "./army/spellcaster/healer.h"
#include "./army/spellcaster/necromancer.h"
#include "./army/spellcaster/warlock.h"
#include "./army/spellcaster/wizard.h"
#include "GUI/custombutton.h"
#include "GUI/battlemap.h"
#include <QString>
#include <QVector>
#include <ctime>
#include <QPoint>
#include "GUI/widgetmagicbook.h"

class BattleMap;

class Team
{

    BattleMap * map;

public:
    Team(BattleMap * map);
    
    QSet <Unit *> units;
    
    void addSoldier(Point place, std::string * output);
    void addVampire(Point place, std::string * output);
    void addRogue(Point place, std::string * output);
    void addDemon(Point place, SpellCaster * master, std::string * output);
    void addWerewolf(Point place, std::string * output);
    void addHealer(Point place, std::string * output);
    void addNecromancer(Point place, std::string * output);
    void addWarlock(Point place, std::string * output);
    void addWizard(Point place, std::string * output);
    void addBerserker(Point place, std::string * output);
    
    bool isContains(Point place);
    QString getStatusUnit(Point place);
    QString getShortName(Point place);
    void move(Point from, Point target);
    std::string getRandName();
    QVector<QString> giveSelfActions(Point self);
    QVector<QString> giveFriendActions(Point self, Point target);
    QVector<QString> giveEnemyActions(Point self, Unit *);
    Unit * getUnit(Point place);
    void collectDieUnit();

signals:
public slots:
};

