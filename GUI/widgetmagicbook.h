#ifndef WIDGETMAGICBOOK_H
#define WIDGETMAGICBOOK_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <QPoint>
#include "army/spell/spellbook.h"

class WidgetMagicBook : public QWidget
{
    Q_OBJECT

    QVector<QPushButton * > buttons;
    QPoint positionUnit;
public:
    explicit WidgetMagicBook(std::map<std::string, Spell *>, QPoint, QWidget *parent = nullptr);
    ~WidgetMagicBook();

signals:
    void choiceNewSpell(std::string);

public slots:
    void buttonWasClicked();
};

#endif // WIDGETMAGICBOOK_H
