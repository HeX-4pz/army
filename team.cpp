#include "team.h"

Team::Team( BattleMap * map)
{
    this->map = map;
}

void Team::addSoldier(Point place, std::string * output) {
    units.insert(new Soldier(getRandName(), place, output));
}

void Team::addVampire(Point place, std::string * output) {
    units.insert(new Vampire(getRandName(), place, output));
}

void Team::addRogue(Point place, std::string * output) {
    units.insert(new Rogue(getRandName(), place, output));
}

void Team::addDemon(Point place, SpellCaster * master, std::string * output) {
    units.insert(new Demon(getRandName(), master, place, output));
}

void Team::addWerewolf(Point place, std::string * output) {
    units.insert(new Werewolf(getRandName(), place, output));
}

void Team::addHealer(Point place, std::string * output) {
    units.insert(new Healer(getRandName(), place, output));
}

void Team::addNecromancer(Point place, std::string * output) {
    units.insert(new Necromancer(getRandName(), place, output));
}

void Team::addWarlock(Point place, std::string * output) {
    units.insert(new Warlock(getRandName(), place, output));
}

void Team::addWizard(Point place, std::string * output) {
    units.insert(new Wizard(getRandName(), place, output));
}

void Team::addBerserker(Point place, std::string * output) {
    units.insert(new Berserker(getRandName(), place,output));
}

bool Team::isContains(Point place)
{
    for (QSet<Unit *>::iterator it = units.begin(); it != units.end(); ++it) {
        if ( (*it)->getLocation() == place ) {
            return true;
        }
    }
    
    return false;
}

QString Team::getStatusUnit(Point place)
{
    QString out = "";
    Unit * unit = getUnit(place);

    if ( unit ) {
        out = out + "Class:   " + QString::fromStdString(unit->getClassName()) + "\n\n"
            + "Name:    " + QString::fromStdString(unit->getName())      + "\n\n"
            + "HP:      " + QString::number(unit->getHP()) + " / "+ QString::number(unit->getLimitHP()) + "\n\n"
            + "Damage:  " + QString::number(unit->getDamage())    + "\n\n";

        if (dynamic_cast<SpellCaster *>(unit)) {
            out = out + "Mana   " + QString::number(dynamic_cast<SpellCaster *>(unit)->getMN()) + " / "
                    +QString::number(dynamic_cast<SpellCaster *>(unit)->getLimitMN())+ "\n\n"
                    + "Spell:    " + QString::fromStdString(dynamic_cast<SpellCaster *>(unit)->getCurrentSpell())      + "\n\n";
        }
    }

    return out;
}

QString Team::getShortName(Point place)
{
    QString out = "";
    Unit * unit = getUnit(place);
    if ( unit ) {
        out = QString::fromStdString(unit->getClassName()).mid(0,3).toUpper();
    }

    return out;
}

void Team::move(Point from, Point target) {
    getUnit(from)->setLocation(target);
}

std::string Team::getRandName()
{
    std::vector<std::string> names = {"Valera", "Ihor", "Vasya", "Sanya", "Kolya", "Dima", "Petya",
                                      "Vitya", "Vitalya", "Kostya", "Slava", "Gora", "Maksim",
                                     "Oleg", "Iluha"};
    srand(clock());
    int choice = rand() % names.size();
    return names[choice];
}

QVector<QString> Team::giveSelfActions(Point point)
{
    QVector<QString> actions;
    std::string className = getUnit(point)->getClassName();

    if ( className == "Werewolf" ||
          className == "Wolf") {
        actions = {"transform"};
    } else if (className == "Warlock" ||
               className == "Healer"  ||
               className == "Necromancer" ||
               className == "Wizard") {
        actions = {"Heal", "Change spell"};
    }
    if ( className == "Warlock" ) {
        actions.push_back("Summon the demon");
    }

    return actions;
}

QVector<QString> Team::giveFriendActions(Point self, Point target)
{
    QVector<QString> actions;
    std::string classNameSelf = getUnit(self)->getClassName();
    std::string classNameTarget = getUnit(target)->getClassName();

    if (classNameSelf == "Warlock" ||
            classNameSelf == "Healer"  ||
            classNameSelf == "Necromancer" ||
            classNameSelf == "Wizard") {
        actions = {"Heal"};
    }

    return actions;
}

QVector<QString> Team::giveEnemyActions(Point self, Unit * enemy)
{
    QVector<QString> actions;
    std::string classNameSelf = getUnit(self)->getClassName();
    std::string classNameTarget = enemy->getClassName();

    actions.push_back("Attack");

    if (classNameSelf == "Warlock" ||
        classNameSelf == "Healer"  ||
        classNameSelf == "Necromancer" ||
        classNameSelf == "Wizard") {
        actions.push_back("Cast spell");
    }
    return actions;
}

Unit *Team::getUnit(Point point) {
    for (QSet<Unit *>::iterator it = units.begin(); it != units.end(); ++it) {
        if ( (*it)->getLocation() == point ) {
            return (*it);
        }
    }
    return nullptr;
}

void Team::collectDieUnit()
{
    QSet<Unit *> copy = units;
    for (QSet<Unit *>::iterator it = copy.begin(); it != copy.end(); ++it) {
        if ( (*it)->getHP() == 0 ) {
            delete  (*it);
            units.remove((*it));
        }
    }
}
