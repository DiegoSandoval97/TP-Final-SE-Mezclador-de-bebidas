//=====[#include guards - begin]===============================================

#ifndef _BLE_COM_H_
#define _BLE_COM_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================
//Elije el timer a utilizar según el caracter recibido por Bluetooth
void bleComUpdate();
//Lee un caracter por Bluetooth
void bleComStringWrite( const char* str );

//=====[#include guards - end]=================================================

#endif // _BLE_COM_H_