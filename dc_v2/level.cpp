#include "level.h"
#include "tile.h"
#include "character.h"
#include "active.h"
#include "passive.h"

Level::Level () {
    for (int i {0}; i < numbOfRows; ++i) {
        for (int k {0}; k < numbOfColumns; ++k) {
            if (i == 0 || i == numbOfRows - 1 || k == 0 || k == numbOfColumns - 1
                    || (k == 10 && i != 17) || (i == 6 && k >= 12)
                    || (i == 15 && (k >= 10 && k < numbOfColumns - 2))
                    || (i == 13 && k <= 10))
                levelMap[i][k] = new Wall (this,i,k);
            else
                levelMap[i][k] = new Floor (this,i,k);
        }
    }

    int p1_row = 4;
    int p1_col = 4;
    int p2_row = 16;
    int p2_col = 16;
    int p3_row = 3;
    int p3_col = 18;
    int p4_row = 18;
    int p4_col = 1;

    Portal* p1 = new Portal (this,p1_row,p1_col);
    Portal* p2 = new Portal (this,p2_row,p2_col);
    Portal* p3 = new Portal (this,p3_row,p3_col);
    Portal* p4 = new Portal (this,p4_row,p4_col);

    p1->setTwinPortal(p2);
    p2->setTwinPortal(p1);
    p3->setTwinPortal(p4);
    p4->setTwinPortal(p3);

    levelMap[p1_row][p1_col] = p1;
    levelMap[p2_row][p2_col] = p2;
    levelMap[p3_row][p3_col] = p3;
    levelMap[p4_row][p4_col] = p4;

    Switch* sw1 = new Switch (this,3,11);
    levelMap[3][11] = sw1;
    Door* d1 = new Door (this,4,18);
    levelMap[4][18] = d1;
    d1->setSwitch(sw1);
    sw1->attach(d1);

    for (int i {0}; i < numbOfRows ; i++) {
        for (int k {0}; k < numbOfColumns; k++) {
            if (i == 1 && k == 12) {
                Ramp* ramp = new Ramp (this,i,k);
                levelMap[i][k] = ramp;
            }
            if (i == 1 && k > 12 && k < 18) {
                Pit* pit = new Pit (this,i,k);
                levelMap[i][k] = pit;
            }
            if (i == 2 && k > 13 && k < 19) {
                Pit* pit = new Pit (this,i,k);
                levelMap[i][k] = pit;
            }
            if ((i == 3 || i == 4) && k >= 17 && k < 18) {
                Pit* pit = new Pit (this,i,k);
                levelMap[i][k] = pit;
            }
        }
    }
}

Level::~Level() {
    for (int i {0}; i < numbOfRows; i++) {
        for (int k {0}; k < numbOfColumns; k++) {
            if (levelMap[i][k]->hasCharacter()) {
                delete levelMap[i][k]->getCharacterOnTile();
            }
            delete levelMap[i][k];
            levelMap[i][k] = nullptr;
        }
    }
    this->charactersOnLevel.clear();
}

Level::Level(const Level& other) {   
    for (int i {0}; i < numbOfRows; i++) {
        for (int k {0}; k < numbOfColumns; k++) {
            Tile* tl = other.levelMap[i][k]->clone();
            this->levelMap[i][k] = tl;
        }
    }

    if (other.charactersOnLevel.size() > 0) {
        for (unsigned int i {0}; i < other.charactersOnLevel.size(); i++) {
            if (other.charactersOnLevel.at(i) != nullptr) {
                Tile* ch = other.charactersOnLevel.at(i)->getPosOfCharacter();
                int r = ch->getRow();
                int c = ch->getColumn();
                this->charactersOnLevel.push_back(other.charactersOnLevel.at(i)->clone()); // save character in vector
                this->levelMap[r][c]->setCharacterOnTile(other.charactersOnLevel.at(i)->clone()); // set character on tile
            }
        }
    }
}

void Level::testAdress(const Level& lvl) const { // test Kopiekonstruktor/Zuweisungsoperator
    for (int i {0}; i < numbOfRows; i++) {
        for (int k {0}; k <numbOfColumns; k++) {
            Tile* tl_this = this->levelMap[i][k];
            Tile* tl_other = lvl.levelMap[i][k];
          //  cout << tl_this << "\n";
          //  cout << tl_other << "\n";
            if (tl_this == tl_other)
                throw std::runtime_error("ADRESS FAIL \n");
        }
    }
    cout<< "Adress Test PASSED \n";
}


Tile* Level::getTile(int row, int col) {
    return levelMap[row][col];
}

const Tile* Level::getTile(int row, int col) const {
    return levelMap[row][col];
}

void Level::placeCharacter(Character* c, int row, int col) {
    Tile* newPosition = levelMap[row][col];
    c->setCharacterPosition(newPosition);
    newPosition->setCharacterOnTile(c);
    charactersOnLevel.push_back(c);
}

Character* Level::characterOnLevel(int charNumb) {
    int size = charactersOnLevel.size();
    if (charNumb >= size || charNumb < 0)
        return nullptr;
    return charactersOnLevel.at(charNumb);
}

Level& Level::operator=(const Level& other) {
    for (unsigned int i {0}; i < numbOfRows; i++) {
        for (unsigned int k {0}; k < numbOfColumns; k++) {
            if (levelMap[i][k] != nullptr) {
                if (levelMap[i][k]->hasCharacter())
                    delete levelMap[i][k]->getCharacterOnTile();
                delete levelMap[i][k];
            }
        }
    }
    for (unsigned int i {0}; i < numbOfRows; i++) {
        for (unsigned int k {0}; k < numbOfColumns; k++) {
            this->levelMap[i][k] = other.levelMap[i][k]->clone();
        }
    }
    this->charactersOnLevel.clear();

    for (unsigned int i {0}; i < other.charactersOnLevel.size(); i++) {
        if (other.charactersOnLevel.at(i) != nullptr) {
            Tile* ch = other.charactersOnLevel.at(i)->getPosOfCharacter();
            int r = ch->getRow();
            int c = ch->getColumn();
            this->charactersOnLevel.push_back(other.charactersOnLevel.at(i)->clone()); // save character in vector
            this->levelMap[r][c]->setCharacterOnTile(other.charactersOnLevel.at(i)->clone()); // set character on tile
        }
    }
    return *this;
}
