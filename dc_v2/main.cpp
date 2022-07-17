#include "tile.h"
#include "level.h"
#include "character.h"
#include "abstractui.h"
#include "dungeoncrawler.h"
#include "active.h"
#include "passive.h"

int main() try {

     DungeonCrawler game;
     game.play();

    /* TEST COPY CONSTRUCTOR AND ZUWEISUNGSOPERATOR */
    // Level* l1 = new Level;
    // Level* l2 = new Level (*l1);
    // l2->testAdress(*l1);

    //  Character* p1 = new Character;

    //  Level l3;
    //  l3.placeCharacter(p1,1,18);
    //  Level l4 = l3;
    //  l4.testAdress(l3);

    //  Character* p2 = new Character;
    //  Character* p3 = new Character;

    //  Level l5;
    //  l5.placeCharacter(p2, 1,18);
    //  Level l6;
    //  l6.placeCharacter(p3, 1,18);
    //  l6 = l5;
    //  l5.testAdress(l6);


    return 0;
}
catch (std::exception& e) {
    cerr << e.what() << " \n";
    return -2;
}

catch(...) {
cerr << "Unknown Error \n";
return -1;
}
