//=====[Libraries]=============================================================

#include "mbed.h"

#include "ble_com.h"
#include "pour_timer.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartBle(PD_5, PD_6, 9600);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

static char bleComCharRead();

//=====[Implementations of public functions]===================================

void bleComUpdate()
{
    char receivedChar = bleComCharRead();
    if( receivedChar != '\0' ) {
        switch (receivedChar) {
            case '8': pourTimerASet(TIME8020); break;
            case '6': pourTimerASet(TIME6040); break;
            case 'L': pourTimerRinsingSet(TIME_RINSE); break;
        }
    }
}

//=====[Implementations of private functions]==================================

static char bleComCharRead()
{
    char receivedChar = '\0';
    if( uartBle.readable() ) {
        uartBle.read(&receivedChar,1);
    }
    return receivedChar;
}