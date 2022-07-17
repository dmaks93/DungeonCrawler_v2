#ifndef PASSIVE_H
#define PASSIVE_H

class Active;

class Passive {
public:
    virtual void notify (Active* source) = 0;
    void setSwitch (Active* connectedSwitch);
protected:
    Active* controlSwitch;
};

#endif // PASSIVE_H
