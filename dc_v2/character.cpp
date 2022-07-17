#include "character.h"
#include "tile.h"
#include "level.h"

string Character::getTexture () {
    return texture;
}

Tile* Character::getPosOfCharacter () {
    return characterPosition;
}

void Character::setCharacterPosition (Tile* newPosition) {
    characterPosition = newPosition;
}

void Character::moveCheck(Tile* charTile, int targetRow, int targetCol) {
    Level* levelOfChar = charTile->getCurrentLevel();
    Tile* destTile = levelOfChar->getTile(targetRow,targetCol);
    charTile->moveTo(destTile,this);
}


int Character::move () {
    int control;
    int charRow;
    int charCol;

    Tile* charTile = this->getPosOfCharacter();
    charRow = charTile->getRow();
    charCol = charTile->getColumn();

    cout << "Control / Direction: "; cin >> control; cout << " \n";
    switch (control) {
    case 1: moveCheck(charTile, charRow + 1, charCol - 1); break;
    case 2: moveCheck(charTile, charRow + 1, charCol); break;
    case 3: moveCheck(charTile, charRow + 1, charCol + 1); break;
    case 4: moveCheck(charTile, charRow, charCol - 1); break;
    case 5: break;
    case 6: moveCheck(charTile, charRow, charCol + 1); break;
    case 7: moveCheck(charTile, charRow - 1, charCol - 1); break;
    case 8: moveCheck(charTile, charRow - 1, charCol); break;
    case 9: moveCheck(charTile, charRow - 1, charCol + 1); break;
    case 0: break;
    default: cout << "Wrong command \n"; break;
    }
    return control;
}

Character* Character::clone() {
    return new Character (*this);
}
