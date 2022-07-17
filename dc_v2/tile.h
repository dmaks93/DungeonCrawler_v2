#ifndef TILE_H
#define TILE_H

#include <iostream>
#include "passive.h"

using std::string;


class Character;
class Level;
class Active;

class Tile {
public:
    explicit Tile (Level* lvl, int tileRow, int tileColumn) :
        currentLevel {lvl}, row {tileRow}, column {tileColumn} {
        characterOnTile = nullptr;
    }
    virtual ~Tile() {};

    string getTexture ();
    bool hasCharacter ();
    bool moveTo(Tile* destTile, Character* who);
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;
    int getRow () const;
    int getColumn () const;
    Level* getCurrentLevel ();
    void setCharacterOnTile (Character* character);
    Character* getCharacterOnTile ();
    virtual Tile* clone () const = 0;

protected:
    string texture;
    Character* characterOnTile;
    Level* currentLevel;
    const int row;
    const int column;
};

class Floor : virtual public Tile {
public:
    Floor (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture = "..";
    }

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    Tile* clone () const override;

};

class Wall : virtual public Tile {
public:
    Wall (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture = "##";
    }

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    Tile* clone () const override;
};

class Portal : virtual public Tile {
public:
    Portal (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture = "@@";
    }
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    void setTwinPortal (Tile* twin);
    Tile* getTwinPortal ();
    Tile* clone () const override;
private:
    Tile* twinPortal;
};

class Door : virtual public Tile, virtual public Passive {
public:
    Door (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture ="/H";
        isOpen = false;
        controlSwitch = nullptr;
    }
    ~Door() {
        //delete controlSwitch;
        controlSwitch = nullptr;
    };

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    void notify (Active* source) override;
    bool getDoorStatus ();
    Tile* clone () const override;

private:
    bool isOpen;
};

class Pit : virtual public Tile {
public:
    Pit (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture = "~~";
    }
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    Tile* clone () const override;

private:
};

class Ramp : virtual public Tile {
public:
    Ramp (Level* lvl, int tileRow, int tileColumn)
        : Tile (lvl,tileRow,tileColumn) {
        texture = "ll";
    }
    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
    Tile* clone () const override;

private:
};

#endif // TILE_H
