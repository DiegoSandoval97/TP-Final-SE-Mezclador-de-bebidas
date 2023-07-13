//=====[#include guards - begin]===============================================

#ifndef _POUR_CONTROL_H_
#define _POUR_CONTROL_H_

//=====[Declaration of public defines]=========================================

#define MAX_POUR_TIME 400
#define MAX_RINSING_TIME 1000
//=====[Declaration of public data types]======================================

typedef enum {
    WAITING_MODE,               //Espera la configuración del modo a utilizar
    WAITING_BEAKER_DETECTION,   //Espera la detección del vaso en la salida
    POURING_A,                  //Vertiendo el líquido A
    POURING_B,                  //Vertiendo el líquido B
    RINSING                     //Enjuague, vierte ambos líquidos
} pourState_t;
	
typedef struct pourControlStatus {
    pourState_t pourState;              //Estado actual de la FSM
    bool pouredTimeMustBeReset;         //Para controlar el reseteo del Timer Total
    bool timerAProgrammedMustBeReset;   //Para contorlar el reseteo del Timer A Programado
    bool drinkAPoured;                  //Centinela de que el líquido A fue vertido
    bool drinkBPoured;                  //Centinela de que el líquido B fue vertido
} pourControlStatus_t;

//=====[Declarations (prototypes) of public functions]=========================
//Configuración inicial del controlador de vertido
void pourControlInit();

//Actualización del controlador de vertido
void pourControlUpdate();

//Lectura del estado de la FSM actual
pourControlStatus_t pourControlRead();

//=====[#include guards - end]=================================================

#endif // _pour_CONTROL_H_