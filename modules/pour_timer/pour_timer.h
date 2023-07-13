//=====[#include guards - begin]===============================================

#ifndef _POUR_TIMER_H_
#define _POUR_TIMER_H_

//=====[Declaration of public defines]=========================================

#define TIME8020 100
#define TIME6040 200
#define TIME_RINSE 500

//=====[Declaration of public data types]======================================

typedef struct pourTimer {
    int pouredTime;             //Temporizador del vertido Total
    int pouredTimeA;            //Temporizador del vertido del líquido A
    bool timerAProgrammed;      //Centinela de que el timer A fue programado
    bool rinsing;               //Centinela de que se programó el enjuague
} pourTimer_t;

//=====[Declarations (prototypes) of public functions]=========================
//Inicialización del timer de vertido
void pourTimerInit();

//Actualización del timer de vertido
void pourTimerUpdate();

//Lectura del timer total
pourTimer_t pourTimerRead();

//Seteo del timer A, para el vertido 80-20 y 60-40
void pourTimerASet(int);

//Seteo del timer A para enjuague
void pourTimerRinsingSet(int);
//=====[#include guards - end]=================================================

#endif // _POUR_TIMER_H_