//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pour_control.h"
#include "pour_timer.h"
#include "beaker_detection.h"
#include "ble_com.h"
//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static pourControlStatus_t pourControlStatus;

//=====[Implementations of public functions]===================================

void pourControlInit()
{
    pourControlStatus.pourState = WAITING_MODE;
    pourControlStatus.pouredTimeMustBeReset = true;
    pourControlStatus.timerAProgrammedMustBeReset = true;
    pourControlStatus.drinkAPoured = false;
    pourControlStatus.drinkBPoured = false;
}

void pourControlUpdate()
{
    pourTimer_t pourTimerLocalCopy;
    bool beakerDetectedLocalCopy;

    pourTimerLocalCopy = pourTimerRead(); 
    beakerDetectedLocalCopy = beakerDetectedRead();

    switch( pourControlStatus.pourState ) {
        
    case WAITING_MODE:
        pourControlStatus.timerAProgrammedMustBeReset = false;      
        if(pourTimerLocalCopy.timerAProgrammed == true){
            pourControlStatus.pourState = WAITING_BEAKER_DETECTION;
        }
        break;

    case WAITING_BEAKER_DETECTION:
        if( beakerDetectedLocalCopy == true ) {
            if(  pourControlStatus.drinkAPoured == false
              && pourControlStatus.drinkBPoured == false  ) {
                pourControlStatus.pourState = POURING_A;
                pourControlStatus.pouredTimeMustBeReset = true;
            }            
            else if(  pourControlStatus.drinkAPoured == true
                   && pourControlStatus.drinkBPoured == false  ) {
                pourControlStatus.pourState = POURING_B;
            }
            else if( pourControlStatus.drinkAPoured == true
                  && pourControlStatus.drinkBPoured == true ){
                pourControlStatus.pourState = RINSING;
                pourControlStatus.pouredTimeMustBeReset = true;
            }
        }
        break;

    case POURING_A:
        pourControlStatus.pouredTimeMustBeReset = false;
        if(pourTimerLocalCopy.pouredTime >= pourTimerLocalCopy.pouredTimeA){
            pourControlStatus.pourState = WAITING_BEAKER_DETECTION;
            pourControlStatus.drinkAPoured = true;
        }
        break;

    case POURING_B:        
        if( (pourTimerLocalCopy.pouredTime >= MAX_POUR_TIME)
         && (pourTimerLocalCopy.rinsing == false) ) {
            pourControlStatus.pourState = WAITING_MODE;
            pourControlStatus.timerAProgrammedMustBeReset = true;
            pourControlStatus.drinkAPoured = false;
            pourControlStatus.drinkBPoured = false;
        } 
        else if ( (pourTimerLocalCopy.pouredTime >= MAX_RINSING_TIME) 
               && (pourTimerLocalCopy.rinsing == true) ){
            pourControlStatus.pourState = WAITING_BEAKER_DETECTION;
            pourControlStatus.drinkBPoured = true;

        }
        break;

    case RINSING:
        pourControlStatus.pouredTimeMustBeReset = false;
        if(pourTimerLocalCopy.pouredTime >= MAX_RINSING_TIME){
            pourControlStatus.pourState = WAITING_MODE;
            pourControlStatus.drinkAPoured = false;
            pourControlStatus.drinkBPoured = false;
            pourControlStatus.timerAProgrammedMustBeReset = true;
        }
        break;
  default:
        pourControlInit();
        break;
    }
}

pourControlStatus_t pourControlRead()
{
    return pourControlStatus;
}