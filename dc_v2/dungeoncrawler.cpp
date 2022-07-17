#include "dungeoncrawler.h"
#include "character.h"

DungeonCrawler::DungeonCrawler() {
    abU = new TerminalUI ();
    lvl = new Level ();
}

void DungeonCrawler::play() {
    Character* player = new Character;
    int result {10};
    lvl->placeCharacter(player, 1, 18);
    while (result != 0) {
        Character* tmpCharacter = lvl->characterOnLevel(0);
        abU->draw(lvl);
        result = tmpCharacter->move();
    }
    cout << "Thank you for Playing \n";
}
