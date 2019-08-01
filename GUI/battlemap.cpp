#include "battlemap.h"



BattleMap::BattleMap(int sizeX, int sizeY, QWidget *parent) : QWidget(parent) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    cells.resize(sizeY);
    QGridLayout * grid = new QGridLayout(this);
    grid->setSpacing(0);
    for ( int y = 0; y < sizeY; ++y ) {
        cells[y].resize(sizeX);
        for (int x = 0; x < sizeX; ++x ) {
            cells[y][x] = new CustomButton(y, x);
            cells[y][x]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            grid->addWidget(cells[y][x], x, y);
            connect(cells[y][x], SIGNAL(leftButtonClicked(Point)),  this, SLOT(clickButtonLeftMouse(Point)));
            connect(cells[y][x], SIGNAL(rightButtonClicked(Point)), this, SLOT(clickButtonRightMouse(Point)));
            connect(cells[y][x], SIGNAL(mouseEnter(Point)),         this, SLOT(mouseMoveIn(Point)));
            connect(cells[y][x], SIGNAL(mouseLeave(Point)),         this, SLOT(mouseMoveOut(Point)));
        }
    }
    this->setLayout(grid);
    this->resize(600, 600);

    colorMauseInField =             "255, 250, 205";
    colorMauseOutField =            "225, 220, 160";
    colorMouseInAccessibleCells =   "174, 255, 174";
    colorMouseOutAccessibleCells =  "140, 210, 140";
    colorMouseInLeftTeam =          "250, 128, 114";
    colorMouseInRightTeam =         "90, 150, 210";
    colorMouseOutLeftTeam =         "205, 104, 92";
    colorMouseOutRightTeam =        "70, 130, 180";
    possibleActions = nullptr;
    widgetmagicbook = nullptr;


    initTeams();
    updateBattleMap();
}

BattleMap::~BattleMap() {
    closeChildWindows();
}

Point BattleMap::getAccesiblePointToAttack(Unit *unit, Point point) {
    int movePoints = unit->getMovePoints();
    int move = 0;
    QVector<int> xMoves = {-1,  0, 1, 0};
    QVector<int> yMoves = { 0, -1, 0, 1};
    QSet<Point> borders;
    QSet<Point> alredyVisit;

    borders.insert(unit->getLocation());
    alredyVisit.insert(unit->getLocation());

    while( move < movePoints ) {
        move += 1;
        QSet<Point> newBorders;
        Point move(0,0);

        for ( QSet<Point>::iterator it = borders.begin(); it != borders.end(); ++it ) {
            for ( int i = 0; i < 4; ++i ) {
                move = *it;
                move.setX( move.getX() + xMoves[i]);
                move.setY( move.getY() + yMoves[i]);
                move = validatePoint(move);

                if ( move == point ) {
                    return (*it);
                }

                if ( isCellFree(move) && !alredyVisit.contains(move) ) {
                    alredyVisit.insert(move);
                    newBorders.insert(move);
                }
            }
        }
        borders = newBorders;
    }

    return Point(-1,-1);
}

Point BattleMap::getCellForDeamon(Unit *summoner)
{
    int move = 0;
    QVector<int> xMoves = {-1,  0, 1, 0};
    QVector<int> yMoves = { 0, -1, 0, 1};
    QSet<Point> borders;
    QSet<Point> alredyVisit;

    borders.insert(summoner->getLocation());
    alredyVisit.insert(summoner->getLocation());

    while( !borders.empty() ) {
        move += 1;
        QSet<Point> newBorders;
        Point move(0,0);

        for ( QSet<Point>::iterator it = borders.begin(); it != borders.end(); ++it ) {
            for ( int i = 0; i < 4; ++i ) {
                move = *it;
                move.setX( move.getX() + xMoves[i]);
                move.setY( move.getY() + yMoves[i]);
                move = validatePoint(move);

                if ( isCellFree(move) ) {
                    return (move);
                }

                if ( isCellFree(move) && !alredyVisit.contains(move) ) {
                    alredyVisit.insert(move);
                    newBorders.insert(move);
                }
            }
        }
        borders = newBorders;
    }

    return Point(-1,-1);
}

void BattleMap::initTeams() {
    leftTeam = new Team(this);
    rightTeam = new Team(this);

    leftTeam->addSoldier(Point(1,3), &output);
    leftTeam->addSoldier(Point(1,4), &output);
    leftTeam->addRogue(Point(1,5), &output);
    leftTeam->addBerserker(Point(1,2), &output);
    leftTeam->addVampire(Point(1,7), &output);
    leftTeam->addWerewolf(Point(1,0), &output);

    leftTeam->addWizard(Point(0,3), &output);
    leftTeam->addHealer(Point(0,4), &output);
    leftTeam->addNecromancer(Point(0,7), &output);
    leftTeam->addWarlock(Point(0,0), &output);

    rightTeam->addSoldier(Point(6,3), &output);
    rightTeam->addSoldier(Point(6,4), &output);
    rightTeam->addRogue(Point(6,5), &output);
    rightTeam->addBerserker(Point(6,2), &output);
    rightTeam->addVampire(Point(6,7), &output);
    rightTeam->addWerewolf(Point(6,0), &output);

    rightTeam->addWizard(Point(7,3), &output);
    rightTeam->addHealer(Point(7,4), &output);
    rightTeam->addNecromancer(Point(7,7), &output);
    rightTeam->addWarlock(Point(7,0), &output);


    curTeam = leftTeam;
    othTeam = rightTeam;
    emit turnInfo("LEFT TEAM TURN");
}

void BattleMap::updateBattleMap() {
    for ( int y = 0; y < sizeY; ++y ) {
        for ( int x = 0; x < sizeX; ++x ) {
            mouseMoveOut(Point(y,x));
        }
    }
}

QSet<Point> BattleMap::getAccessibleCells(Unit * unit) {
    int movePoints = unit->getMovePoints();
    int iter = 0;
    QVector<int> xMoves = {-1,  0, 1, 0};
    QVector<int> yMoves = { 0, -1, 0, 1};
    QSet<Point> borders;
    QSet<Point> alredyVisit;

    borders.insert(unit->getLocation());
    alredyVisit.insert(unit->getLocation());

    while( iter < movePoints ) {
        iter += 1;
        QSet<Point> newBorders;
        Point move(0,0);

        for ( QSet<Point>::iterator it = borders.begin(); it != borders.end(); ++it ) {
            for ( int i = 0; i < 4; ++i ) {
                move = *it;
                move.setX( move.getX() + xMoves[i]);
                move.setY( move.getY() + yMoves[i]);
                move = validatePoint(move);

                if ( isCellFree(move) && !alredyVisit.contains(move) ) {
                    alredyVisit.insert(move);
                    newBorders.insert(move);
                }
            }
        }
        borders = newBorders;
    }
    return alredyVisit;

}

Point BattleMap::validatePoint(Point point ) {
    Point validatePoint = point;



    if (validatePoint.getX() >= sizeX ) {
        validatePoint.setX(sizeX - 1);
    } else if ( validatePoint.getX() < 0 ) {
        validatePoint.setX(0);
    }

    if (validatePoint.getY() >= sizeY ) {
        validatePoint.setY(sizeY - 1);
    } else if ( validatePoint.getY() < 0 ) {
        validatePoint.setY(0);
    }

    return validatePoint;
}

bool BattleMap::isCellFree(Point target) {
    if (leftTeam->isContains(target) || rightTeam->isContains(target) ) {
        return false;
    }
    return true;
}

bool BattleMap::checkAbilityAttack(Unit *unit, Point target) {
    int movePoints = unit->getMovePoints();
    int iter = 0;
    QVector<int> xMoves = {-1,  0, 1, 0};
    QVector<int> yMoves = { 0, -1, 0, 1};
    QSet<Point> borders;
    QSet<Point> alredyVisit;

    borders.insert(unit->getLocation());
    alredyVisit.insert(unit->getLocation());

    while( iter < movePoints ) {
        iter += 1;
        QSet<Point> newBorders;
        Point move(0,0);

        for ( QSet<Point>::iterator it = borders.begin(); it != borders.end(); ++it ) {
            for ( int i = 0; i < 4; ++i ) {
                move = *it;
                move.setX( move.getX() + xMoves[i]);
                move.setY( move.getY() + yMoves[i]);
                move = validatePoint(move);

                std::cout << iter << " " <<  move << " " << target << std::endl;
                if ( (isCellFree(*it) || iter == 1) && !alredyVisit.contains(move) ) {
                    if ( move == target ) {
                        return true;
                    }
                    alredyVisit.insert(move);
                    newBorders.insert(move);
                }
            }
        }
        std::cout << newBorders.size() << std::endl;
        borders = newBorders;
    }
    return false;
}

void BattleMap::changeMovingTeam() {
    if ( curTeam == leftTeam ) {
        curTeam = rightTeam;
        othTeam = leftTeam;
        emit turnInfo("RIGHT TEAM TURN");
    } else {
        curTeam = leftTeam;
        othTeam = rightTeam;
        emit turnInfo("LEFT TEAM TURN");
    }
}

void BattleMap::closeChildWindows()
{
    if ( possibleActions ) {
        possibleActions->close();
        delete possibleActions;
        possibleActions = nullptr;
    }

    if ( widgetmagicbook ) {
        widgetmagicbook->close();
        delete widgetmagicbook;
        widgetmagicbook = nullptr;
    }
}

void BattleMap::clickButtonLeftMouse(Point click) {
    if ( curTeam->isContains(click)) {
        moveCells = getAccessibleCells(curTeam->getUnit(click));
        pressed = click;

    } else {
        pressed = Point(-1, -1);
        target = Point(-1, -1);
        moveCells.clear();
    }
    closeChildWindows();
    updateBattleMap();
}

void BattleMap::clickButtonRightMouse(Point click) {
    target = click;
    QVector<QString> acts;

    if ( curTeam->isContains(pressed) ) {
        if (othTeam->isContains(target)) {
            acts = curTeam->giveEnemyActions(pressed, othTeam->getUnit(target));

        } else if (curTeam->isContains(target)) {
            if (pressed == target ) {
                acts = curTeam->giveSelfActions(target);
            } else {
                acts = curTeam->giveFriendActions(pressed, target);
            }
        } else if ( moveCells.contains(target) ) {
            curTeam->move(pressed, target);
            pressed = Point(-1,-1);
            target = Point(-1,-1);
            moveCells.clear();
            changeMovingTeam();
        }

        if (acts.size() > 0) {
            QVector<int> visible(acts.size(),1);
            if ( acts.contains("Attack") ) {
                visible[0] = checkAbilityAttack(curTeam->getUnit(pressed), click);
            }
            if ( acts.contains("Cast spell") ) {
                SpellCaster * spellcaster = dynamic_cast<SpellCaster *> (curTeam->getUnit(pressed));
                if ( spellcaster->getMN() < spellcaster->getManaCost() ) {
                    visible[1] = 0;
                }
            }
            closeChildWindows();
            possibleActions = new PossibleActionsWidget(acts, visible, QCursor::pos());
            connect(possibleActions, SIGNAL(choiceIsMade(QString)), this, SLOT(actionSelected(QString)));
            possibleActions->show();
        }
    }
    updateBattleMap();
}

void BattleMap::mouseMoveIn(Point point) {
    int y = point.getY();
    int x = point.getX();
    if ( leftTeam->isContains(point)) {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMouseInLeftTeam+") }");
        cells[y][x]->setText(leftTeam->getShortName(point));
        emit leftTeamInfo(leftTeam->getStatusUnit(point));
    } else if ( rightTeam->isContains(point)) {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMouseInRightTeam+") }");
        cells[y][x]->setText(rightTeam->getShortName(point));
        emit rightTeamInfo(rightTeam->getStatusUnit(point));
    } else if (moveCells.contains(point)) {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMouseInAccessibleCells+") }");
        cells[y][x]->setText("");
    } else {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMauseInField+") }");
        cells[y][x]->setText("");
    }
}

void BattleMap::mouseMoveOut(Point point) {
    int y = point.getY();
    int x = point.getX();
    if ( leftTeam->isContains(point)) {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMouseOutLeftTeam+") }");
        cells[y][x]->setText(leftTeam->getShortName(point));
    } else if ( rightTeam->isContains(point)) {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMouseOutRightTeam+") }");
        cells[y][x]->setText(rightTeam->getShortName(point));
    } else if (moveCells.contains(point)) {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMouseOutAccessibleCells+") }");
        cells[y][x]->setText("");
    } else {
        cells[y][x]->setStyleSheet("* { background-color: rgb("+colorMauseOutField+") }");
        cells[y][x]->setText("");
    }
}

void BattleMap::actionSelected(QString msg)
{
    if ( msg.isEmpty() ) {
        return;
    }
    closeChildWindows();
    qDebug() << msg;
    Unit * doer = curTeam->getUnit(pressed);
    Unit * enemy = othTeam->getUnit(target);
    Unit * teammate = curTeam->getUnit(target);

    if ( msg == "Attack" ) {
        curTeam->move(pressed, getAccesiblePointToAttack(doer, target));
        doer->attackEnemy(enemy);
    } else if ( msg == "Cast spell") {
        dynamic_cast<SpellCaster *> (doer)->cast(enemy);
    } else if ( msg == "transform") {
        doer->useAbility();
    } else if ( msg == "Heal") {
        SpellCaster * spellcaster = dynamic_cast<SpellCaster *>(doer);
        if ( spellcaster ) {
            std::string currentspell = spellcaster->getCurrentSpell();
            spellcaster->changeSpell("heal");
            spellcaster->cast(teammate);
            spellcaster->changeSpell(currentspell);
        }
    } else if (msg == "Change spell") {
        SpellCaster * spellcaster = dynamic_cast<SpellCaster *>(doer);
        if ( spellcaster ) {
            closeChildWindows();
            widgetmagicbook = new WidgetMagicBook(spellcaster->getSpellBook()->getBook(), QCursor::pos());
            connect(widgetmagicbook, SIGNAL(choiceNewSpell(std::string)), this, SLOT(chengeSpell(std::string)));
            widgetmagicbook->show();

        }
    } else if ( msg == "Summon the demon") {
         Point place = getCellForDeamon( doer );
         Warlock * warlock = dynamic_cast<Warlock *>(doer);
         if ( warlock ) {
            curTeam->addDemon(place, warlock, warlock->getOutput());
         }
    }

    othTeam->collectDieUnit();
    curTeam->collectDieUnit();

    if (msg != "Change spell") {
        pressed = Point(-1,-1);
        target = Point(-1,-1);
        moveCells.clear();
        changeMovingTeam();
    }

    updateBattleMap();
}

void BattleMap::chengeSpell(std::string spell)
{
    closeChildWindows();
    if ( spell.size() == 0 ) {
        delete  widgetmagicbook;
    } else {
        dynamic_cast<SpellCaster *> (curTeam->getUnit(pressed))->changeSpell(spell);
    }
}
