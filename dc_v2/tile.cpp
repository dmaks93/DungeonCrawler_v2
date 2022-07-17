#include "tile.h"
#include "character.h"

/* ---------- Tile ---------- */

string Tile::getTexture() {
    if (hasCharacter())
        return this->characterOnTile->getTexture();
    return texture;
}

bool Tile::hasCharacter () {
    if (characterOnTile == nullptr)
        return false;
    return true;
}

bool Tile::moveTo(Tile* destTile, Character* who) {
    // this --> Tile of Character which wants to move

    // first check if Teil verlassen werden kann (onLeave)
    Tile* actualPosition = this->onLeave(destTile,who);

    if (actualPosition == nullptr)
        return false;

    // check if Teil-Target can be acessed from starting position
    Tile* targetPosition = destTile->onEnter(this,who);

    if (targetPosition == nullptr)
        return false;

    // if movement is possible
    actualPosition->characterOnTile = nullptr;
    // targetPosition->setCharacterOnTile(who);
    targetPosition->characterOnTile = who;
    who->setCharacterPosition(targetPosition);

    return true;
}

int Tile::getRow() const {
    return row;
}

int Tile::getColumn() const {
    return column;
}

Level* Tile::getCurrentLevel() {
    return currentLevel;
}

void Tile::setCharacterOnTile(Character* character) {
    characterOnTile = character;
}

Character* Tile::getCharacterOnTile() {
    return this->characterOnTile;
}


/* ---------- Floor ---------- */

Tile* Floor::onEnter(Tile* fromTile, Character* who) {
    return this;
}

Tile* Floor::onLeave(Tile* destTile, Character* who) {
    return this;
}

Tile* Floor::clone () const {
    return new Floor (*this);
}


/* ---------- Wall ---------- */

Tile* Wall::onEnter(Tile* fromTile, Character* who) {
    return nullptr;
}

Tile* Wall::onLeave(Tile* destTile, Character* who) {
    return this;
}

Tile* Wall::clone () const {
    return new Wall (*this);
}


/* ---------- Portal ---------- */

Tile* Portal::onEnter(Tile* fromTile, Character* who) {
    return twinPortal;
}

Tile* Portal::onLeave(Tile* destTile, Character* who) {
    return this;
}

void Portal::setTwinPortal(Tile* twin) {
    twinPortal = twin;
}

Tile* Portal::getTwinPortal() {
    return twinPortal;
}

Tile* Portal::clone () const {
    return new Portal (*this);
}


/* ---------- Pit ---------- */

Tile* Pit::onEnter(Tile* fromTile, Character* who) {
    return this;
}

Tile* Pit::onLeave(Tile* destTile, Character* who) {
    // add only if its pit or a ramp
    if (typeid(*destTile) == typeid(Ramp) || typeid (*destTile) == typeid(Pit))
        return this;
    return nullptr;
}

Tile* Pit::clone () const {
    return new Pit (*this);
}


/* ---------- Ramp ---------- */

Tile* Ramp::onEnter(Tile* fromTile, Character* who) {
    return this;
}

Tile* Ramp::onLeave(Tile* destTile, Character* who) {
    return this;
}

Tile* Ramp::clone () const {
    return new Ramp (*this);
}
