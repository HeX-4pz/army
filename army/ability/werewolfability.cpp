#include "werewolfability.h"

WerewolfAbility::WerewolfAbility(Unit *owner) : Ability(owner) {

}

WerewolfAbility::~WerewolfAbility() {

}

void WerewolfAbility::makeWerewolf(Unit * target) {
    if ( dynamic_cast<WerewolfAbility*>(target->getAbility())) {
        std::cout << "Alredy werewolf" << std::endl;
        return;
    }
    if ( dynamic_cast<VampireAbility*>(target->getAbility())) {
        std::cout << "Cannot transform vampire to werewolf" << std::endl;
        return ;
    }
    std::cout << owner->getName() << " making new Werewolf from " << target->getName() << std::endl;
    std::string targetName = target->getName();
    std::string targetClassName = "Werewolf";
    int targetHP = target->getHP();
    int targetDMG = (int) UNITDMG::WEREWOLF;
    int targetLimitHP = (int) UNITHP::WEREWOLF;
    target->setMovePoints((int)UNITMOVE::WEREWOLF);

    if ( targetHP > targetLimitHP ) {
        targetHP = targetLimitHP;
    }

    target->setAbility( new WerewolfAbility(target));
    target->setAttack(new WerewolfAttack(target));
    target->setState(new State(targetName, targetClassName, targetHP, targetDMG,targetLimitHP));
    std::cout << " ";
}

void WerewolfAbility::use()
{
    if (owner->getClassName() == "Wolf") {
        std::cout << "Transform from wolf to human" << std::endl;
        std::string targetName = owner->getName();
        std::string targetClassName = "Werewolf";
        int targetLimitHP = (int) UNITHP::WEREWOLF;
        int targetHP = int (double(owner->getHP()) / double(owner->getLimitHP()) * double(targetLimitHP));
        int targetDMG = (int) UNITDMG::WEREWOLF;
        owner->setMovePoints((int)UNITMOVE::WEREWOLF);
        owner->setState(new State(targetName, targetClassName, targetHP, targetDMG,targetLimitHP));
    } else {
        std::cout << "Transform from human to wolf" << std::endl;
        std::string targetName = owner->getName();
        std::string targetClassName = "Wolf";
        int targetLimitHP = (int) UNITHP::WOLF;
        int targetHP = int (double(owner->getHP()) / double(owner->getLimitHP()) * double(targetLimitHP));
        int targetDMG = (int) UNITDMG::WOLF;
        owner->setMovePoints((int)UNITMOVE::WOLF);
        owner->setState(new State(targetName, targetClassName, targetHP, targetDMG,targetLimitHP));
    }


}



