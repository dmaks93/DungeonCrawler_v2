#include "active.h"
#include "passive.h"
#include "tile.h"

void Active::activate () {
    for (unsigned int i {0}; i < observers.size(); i++)
        observers.at(i)->notify(this);
}

Tile* Switch::onEnter(Tile* fromTile, Character* who) {
    this->activate();
    return this;
}

Tile* Switch::onLeave(Tile* destTile, Character* who) {
    return this;
}

void Switch::attach (Passive* passivObjekt) {
    bool alreadyIn {false};
    for (unsigned int i {0}; i < observers.size(); i++) {
        if (observers.at(i) == passivObjekt)
            alreadyIn = true; // HAS TO BE TESTED!
    }
    if (!alreadyIn) {
        this->observers.push_back(passivObjekt);
        passivObjekt->setSwitch(this);
    }
}

void Switch::dettach (Passive* passivObjekt) {
    for (unsigned int i {0}; i < observers.size(); i++) {
        if (observers.at(i) == passivObjekt)
            observers.erase(observers.begin() + i);
    }
}

Tile* Switch::clone () const {
    return new Switch (*this);
}
