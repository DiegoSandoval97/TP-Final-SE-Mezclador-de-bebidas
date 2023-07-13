//=====[Libraries]=============================================================

#include "pour_system.h"

#include "non_blocking_delay.h"
#include "ble_com.h"
#include "relay.h"
#include "pour_control.h"
#include "pour_timer.h"
#include "beaker_detection.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static nonBlockingDelay_t pourSystemDelay;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void pourSystemInit()
{
    tickInit();
    relayInit();
    beakerDetectionInit();
    pourTimerInit();
    nonBlockingDelayInit( &pourSystemDelay, SYSTEM_TIME_INCREMENT_MS );
    pourControlInit();
}

void pourSystemUpdate()
{
    if( nonBlockingDelayRead(&pourSystemDelay) ) {
        bleComUpdate();
        relayUpdate();
        beakerDetectionUpdate();
        pourTimerUpdate();
        pourControlUpdate();
    }
}

//=====[Implementations of private functions]==================================
