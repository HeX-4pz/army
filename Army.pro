#-------------------------------------------------
#
# Project created by QtCreator 2019-07-26T17:13:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Army
TEMPLATE = app


SOURCES += main.cpp \
    GUI/battlemap.cpp \
    army/ability/ability.cpp \
    army/ability/healerability.cpp \
    army/ability/magicability.cpp \
    army/ability/necromancerability.cpp \
    army/ability/vampireability.cpp \
    army/ability/warlockability.cpp \
    army/ability/werewolfability.cpp \
    army/ability/wizzardability.cpp \
    army/attack/attack.cpp \
    army/attack/rogueattack.cpp \
    army/attack/vampireattack.cpp \
    army/attack/werewolfattack.cpp \
    army/observer/observeble.cpp \
    army/observer/observer.cpp \
    army/point.cpp \
    army/spell/battlespell.cpp \
    army/spell/fireball.cpp \
    army/spell/heal.cpp \
    army/spell/healingspell.cpp \
    army/spell/lightning.cpp \
    army/spell/spell.cpp \
    army/spell/spellbook.cpp \
    army/spellcaster/healer.cpp \
    army/spellcaster/necromancer.cpp \
    army/spellcaster/spellcaster.cpp \
    army/spellcaster/warlock.cpp \
    army/spellcaster/wizard.cpp \
    army/state/magicstate.cpp \
    army/state/state.cpp \
    army/unit/berserker.cpp \
    army/unit/demon.cpp \
    army/unit/rogue.cpp \
    army/unit/soldier.cpp \
    army/unit/undead.cpp \
    army/unit/unit.cpp \
    army/unit/vampire.cpp \
    army/unit/werewolf.cpp \
    GUI/custombutton.cpp \
    GUI/mainwindow.cpp \
    GUI/possibleactionswidget.cpp \
    GUI/widgetmagicbook.cpp \
    team.cpp

HEADERS  += \
    GUI/battlemap.h \
    army/ability/ability.h \
    army/ability/healerability.h \
    army/ability/magicability.h \
    army/ability/necromancerability.h \
    army/ability/vampireability.h \
    army/ability/warlockability.h \
    army/ability/werewolfability.h \
    army/ability/wizzardability.h \
    army/attack/attack.h \
    army/attack/rogueattack.h \
    army/attack/vampireattack.h \
    army/attack/werewolfattack.h \
    army/exception/exceptions.h \
    army/observer/observeble.h \
    army/observer/observer.h \
    army/point.h \
    army/spell/battlespell.h \
    army/spell/fireball.h \
    army/spell/heal.h \
    army/spell/healingspell.h \
    army/spell/lightning.h \
    army/spell/spell.h \
    army/spell/spellbook.h \
    army/spellcaster/healer.h \
    army/spellcaster/necromancer.h \
    army/spellcaster/spellcaster.h \
    army/spellcaster/warlock.h \
    army/spellcaster/wizard.h \
    army/state/atributes.h \
    army/state/magicstate.h \
    army/state/state.h \
    army/unit/berserker.h \
    army/unit/demon.h \
    army/unit/rogue.h \
    army/unit/soldier.h \
    army/unit/undead.h \
    army/unit/unit.h \
    army/unit/vampire.h \
    army/unit/werewolf.h \
    GUI/custombutton.h \
    GUI/mainwindow.h \
    GUI/possibleactionswidget.h \
    GUI/widgetmagicbook.h \
    team.h

FORMS    +=
