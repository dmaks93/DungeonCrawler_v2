#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H

#include <iostream>

#include "abstractui.h"
#include "level.h"

class DungeonCrawler {
public:
    DungeonCrawler();
    void play ();
private:
    AbstractUI* abU;
    Level* lvl;
};

#endif // DUNGEONCRAWLER_H
