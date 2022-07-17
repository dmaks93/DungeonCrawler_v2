#ifndef ACTIVE_H
#define ACTIVE_H

#include <iostream>
#include <vector>
#include "tile.h"

using std::vector;

class Passive;

class Active {
public:
    virtual ~Active () {};
    virtual void attach (Passive* passivObjekt) = 0;
    virtual void dettach (Passive* passivObjekt) = 0;
    void activate (); // call notify of all passiv objects inside the vector
protected:
    vector <Passive*> observers;
};

class Switch : virtual public Tile, virtual public Active {
public:
    Switch (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture = "??";
    }

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    virtual void attach (Passive* passivObjekt) override;
    virtual void dettach (Passive* passivObjekt) override;
    Tile* clone () const override;

};

#endif // ACTIVE_H
