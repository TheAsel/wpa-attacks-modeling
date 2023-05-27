
#ifndef studyRangeSTUDY_H_
#define studyRangeSTUDY_H_

#include "Reward/reward/rewardPVNodes.h"
#include "Reward/reward/rewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Short apConfigProf;
extern Bool hasHardware;
extern Short networkHackingProf;
extern Short packetForgingProf;
extern Short socialEngineeringProf;
extern Short wantsDOS;
extern Short wantsSensitiveInfo;

class studyRangeStudy : public BaseStudyClass {
public:

studyRangeStudy();
~studyRangeStudy();

private:

short *apConfigProfValues;
bool *hasHardwareValues;
short *networkHackingProfValues;
short *packetForgingProfValues;
short *socialEngineeringProfValues;
short *wantsDOSValues;
short *wantsSensitiveInfoValues;

void SetValues_apConfigProf();
void SetValues_hasHardware();
void SetValues_networkHackingProf();
void SetValues_packetForgingProf();
void SetValues_socialEngineeringProf();
void SetValues_wantsDOS();
void SetValues_wantsSensitiveInfo();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

