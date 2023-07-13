//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "relay.h"

#include "pour_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

static DigitalInOut relayControlPinA(PF_1);
static DigitalInOut relayControlPinB(PF_2);

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Implementations of public functions]===================================

void relayInit()
{
    relayControlPinA.mode(OpenDrain);
    relayControlPinB.mode(OpenDrain);
    relayControlPinA.input();
    relayControlPinB.input();
}

void relayUpdate()
{
    pourControlStatus_t pourControlStatusLocalCopy;

    pourControlStatusLocalCopy = pourControlRead();

    switch( pourControlStatusLocalCopy.pourState ) {

    case WAITING_MODE:
        relayControlPinA.input(); 
        relayControlPinB.input(); 
        break;

    case WAITING_BEAKER_DETECTION:
        relayControlPinA.input();
        relayControlPinB.input(); 
        break;            

    case POURING_A:
        relayControlPinA.output();  
        relayControlPinB.input();                                   
        relayControlPinA = LOW;
        break;    

    case POURING_B:
        relayControlPinB.output();
        relayControlPinA.input();                                     
        relayControlPinB = LOW;      
        break;

    case RINSING:
        relayControlPinA.output();  
        relayControlPinB.output();                                   
        relayControlPinA = LOW;
        relayControlPinB = LOW;        
        break;
    default:
        relayControlPinA.input();
        relayControlPinB.input(); 
        break;
    }
}

void relayRead()
{
}