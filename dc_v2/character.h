#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using std::string;
using std::cin;
using std::cout;

class Tile;
class Level;

class Character {
public:
    Character() {
        texture = "DC";
    }
    string getTexture();
    Tile* getPosOfCharacter ();
    void setCharacterPosition (Tile* newPosition);
    void moveCheck(Tile* charTile, int targetRow, int targetCol);
    int move();
    Character* clone ();

private:
    Tile* characterPosition;
    string texture;
};

#endif // CHARACTER_H
