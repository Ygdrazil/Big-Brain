#ifndef DOOR_H
#define DOOR_H

#include "GameObject.hpp"
#include "Player.hpp"


class Door : public GameObject
{
    public:
        Door();
        virtual ~Door();
        bool setTrigger(bool state);

    protected:

    private:
};

#endif // DOOR_H
