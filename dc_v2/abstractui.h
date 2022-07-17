#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

class Level;

class AbstractUI {
public:
    AbstractUI () {};
    virtual void draw (Level* currentLevel) = 0;
};

class TerminalUI : virtual public AbstractUI {
public:
    TerminalUI () {};
    void draw (Level* currentLevel) override;
};

#endif // ABSTRACTUI_H
