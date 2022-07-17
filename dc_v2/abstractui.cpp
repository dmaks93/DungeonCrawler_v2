#include "abstractui.h"
#include "level.h"
#include "tile.h"

void TerminalUI::draw (Level* currentLevel) {

    for (int i {0}; i < numbOfRows; ++i) {
        for (int k {0}; k < numbOfColumns; ++k) {
            cout << currentLevel->getTile(i,k)->getTexture();
        }
        cout << " \n";
    }
}
