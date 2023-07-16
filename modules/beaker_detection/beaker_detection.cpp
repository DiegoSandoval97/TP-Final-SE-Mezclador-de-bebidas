//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "beaker_detection.h"

#include "position_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static bool beakerDetected                  = OFF;
static bool positionDetectorState           = OFF;

//=====[Declarations (prototypes) of private functions]========================

static void beakerDetectionDeactivate();

//=====[Implementations of public functions]===================================

void beakerDetectionInit()
{
    positionSensorInit();
}

void beakerDetectionUpdate()
{
    positionSensorUpdate();

    positionDetectorState = !positionSensorRead();
    if ( positionDetectorState ) {
        beakerDetected = ON;
    }
    else beakerDetectionDeactivate();

}

bool positionDetectorStateRead()
{
    return positionDetectorState;
}

bool beakerDetectedRead()
{
    return beakerDetected;
}



//=====[Implementations of private functions]==================================
static void beakerDetectionDeactivate()
{
    beakerDetected = OFF;    
}