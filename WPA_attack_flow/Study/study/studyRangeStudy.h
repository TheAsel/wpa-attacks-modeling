
#ifndef studyRangeSTUDY_H_
#define studyRangeSTUDY_H_

#include "Reward/reward/rewardPVNodes.h"
#include "Reward/reward/rewardPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"


class studyRangeStudy : public BaseStudyClass {
public:

studyRangeStudy();
~studyRangeStudy();

private:



void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

