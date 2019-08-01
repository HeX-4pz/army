#include "vampireability.h"



VampireAbility::VampireAbility(Unit *owner) : Ability(owner) {

}

VampireAbility::~VampireAbility() {

}

void VampireAbility::makeVampire(Unit * target) {
    if ( dynamic_cast<WerewolfAbility*>(target->getAbility())) {
        std::cout << "Cannot transform werewolf to vampire" << std::endl;
        return;
    }
    if ( dynamic_cast<VampireAbility*>(target->getAbility())) {
        std::cout << "Alredy vampire" << std::endl;
        return ;
    }

    std::cout << owner->getName() << " making new Vampire from " << target->getName() << std::endl;
    std::string targetName = target->getName();
    std::string targetClassName = owner->getClassName();
    int targetHP = target->getHP();
    int targetDMG = owner->getDamage();
    int targetLimitHP = owner->getLimitHP();
    owner->setMovePoints((int) UNITMOVE::VAMPIRE);

    if ( targetHP > targetLimitHP ) {
        targetHP = targetLimitHP;
    }

    target->setAbility( new VampireAbility(target));
    target->setAttack( new VampireAttack(target));
    target->setState(new State(targetName, targetClassName, targetHP, targetDMG,targetLimitHP));
}


