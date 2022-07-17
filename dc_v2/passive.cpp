#include "passive.h"
#include "tile.h"

void Passive::setSwitch (Active* connectedSwitch) {
    controlSwitch = connectedSwitch;
}


Tile* Door::onEnter(Tile* fromTile, Character* who) {
    if (!isOpen)
        return nullptr;
    return this;
}

Tile* Door::onLeave(Tile* destTile, Character* who) {
    return this;
}

void Door::notify (Active* source) {
    if (isOpen) {
        isOpen = false;
        texture = "/H";
    }
    else {
        isOpen = true;
        texture = "||";
    }
}

bool Door::getDoorStatus () {
    return isOpen;
}

Tile* Door::clone () const {
    return new Door (*this);
}
