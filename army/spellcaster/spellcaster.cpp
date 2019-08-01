#include "spellcaster.h"


SpellCaster::SpellCaster( std::string name, Point point, std::string * output) : Unit(name, point, output) {
    magicState = new MagicState();
    magicAbility = new MagicAbility(this);
    spellBook = new SpellBook();

    state->setLimitHP(int(UNITHP::SPELLCASTER));
    state->setHP(getLimitHP());
    state->setDamge(int(UNITDMG::SPELLCASTER));
    magicState->setLimitMN(int(UNITMN::SPELLCASTER));
    magicState->setMN(getLimitMN());
    state->setClassName("SpellCaster");
    this->movePoints = int(UNITMOVE::SPELLCASTER);
}

SpellCaster::~SpellCaster() {
    delete magicState;
    delete magicAbility;
    delete spellBook;
}

int SpellCaster::getMN() const {
    return this->magicState->getMN();
}

int SpellCaster::getLimitMN() const {
    return this->magicState->getLimitMN();
}

void SpellCaster::addMN( int add) {
    this->magicState->addMN(add);
}

bool SpellCaster::spendMN ( int spend ) {
    return this->magicState->spendMN(spend);
}

void SpellCaster::cast( Unit * unit) {
    magicAbility->castSpell(unit);
}

void SpellCaster::changeSpell(std::string spellName)
{
    magicAbility->setCurrentSpell(spellBook->getSpell(spellName));
}

std::string SpellCaster::getCurrentSpell()
{
    return  magicAbility->getCurrentSpell();
}

int SpellCaster::getManaCost()
{
    return magicAbility->getManaCost();
}

SpellBook *SpellCaster::getSpellBook()
{
    return spellBook;
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster) {
    out << "Class:  " << spellcaster.getClassName() << "\n"
        << "Name:   " << spellcaster.getName()    << "\n"
        << "HP:     " << spellcaster.getHP()      << "\n"
        << "Damage: " << spellcaster.getDamage()  << "\n"
        << "MaxHP:  " << spellcaster.getLimitHP() << "\n"
        << "MN:     " << spellcaster.getMN()      << "\n"
        << "MaxMN:  " << spellcaster.getLimitMN() << "\n";

    return out;
}
