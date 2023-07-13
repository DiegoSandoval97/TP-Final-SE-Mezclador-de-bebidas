//=====[#include guards - begin]===============================================

#ifndef _BEAKER_DETECTION_H_
#define _BEAKER_DETECTION_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void beakerDetectionInit();
void beakerDetectionUpdate();
void beakerDetectionDeactivate();

bool positionDetectorStateRead();
bool beakerDetectedRead();


//=====[#include guards - end]=================================================

#endif // _BEAKER_DETECTION_H_
