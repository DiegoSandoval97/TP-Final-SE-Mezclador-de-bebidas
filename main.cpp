//=====[Libraries]=============================================================
#include "pour_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{   pourSystemInit();
    while (true) {
        pourSystemUpdate();
    }
}