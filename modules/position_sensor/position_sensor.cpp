//=====[Libraries]=============================================================

#include "mbed.h"

#include "position_sensor.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

DigitalIn sensorIR(PE_12);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void positionSensorInit()
{
}

void positionSensorUpdate()
{
}

bool positionSensorRead()
{
    return sensorIR;
}

//=====[Implementations of private functions]==================================

