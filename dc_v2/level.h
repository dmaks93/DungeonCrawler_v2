#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <array>
#include <vector>

using std::array;
using std::vector;
using std::cout;
using std::cerr;

const int numbOfRows = 20;
const int numbOfColumns = 20;

class Tile;
class Character;

class Level {
public:
    Level();
    ~Level();
    Level(const Level& newLevel);

    Tile* getTile(int row, int col);
    const Tile* getTile(int row, int col) const;
    void placeCharacter(Character* c, int row, int col);
    Character* characterOnLevel (int charNumber);
    void testAdress (const Level& lvl) const; // show adress
    Level& operator=(const Level& lvl);

private:
    array<array<Tile*, numbOfRows>,numbOfColumns> levelMap;
    vector <Character*> charactersOnLevel {};
};

#endif // LEVEL_H
