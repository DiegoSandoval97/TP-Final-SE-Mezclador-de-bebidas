//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pour_timer.h"

#include "pour_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static pourTimer_t pourTimer;

//=====[Implementations of public functions]===================================

void pourTimerInit()
{
    pourTimer.pouredTime = 0;
    pourTimer.pouredTimeA = 0;
    pourTimer.timerAProgrammed = false;
    pourTimer.rinsing = false;
}

void pourTimerUpdate()
{
    pourControlStatus_t pourControlStatusLocalCopy;

    pourControlStatusLocalCopy = pourControlRead();

    if ( pourControlStatusLocalCopy.pouredTimeMustBeReset ) {
        pourTimer.pouredTime = 0;
    }    

    if ( pourControlStatusLocalCopy.timerAProgrammedMustBeReset ) {
        pourTimer.pouredTimeA = 0;
        pourTimer.timerAProgrammed = false;
        pourTimer.rinsing = false;
    }    

    if ( pourControlStatusLocalCopy.pourState == POURING_A ||
         pourControlStatusLocalCopy.pourState == POURING_B ||
         pourControlStatusLocalCopy.pourState == RINSING) {
        pourTimer.pouredTime++;
    }
}

pourTimer_t pourTimerRead()
{
    return pourTimer;
}

void pourTimerASet(int limitTimeA)
{
    pourTimer.pouredTimeA = limitTimeA;
    pourTimer.timerAProgrammed = true;
    pourTimer.rinsing = false;
}

void pourTimerRinsingSet(int limitTimeA)
{
    pourTimer.pouredTimeA = limitTimeA;
    pourTimer.timerAProgrammed = true;
    pourTimer.rinsing = true;
}