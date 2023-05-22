#include "rewardPVModel.h"

rewardPVModel::rewardPVModel(bool expandTimeArrays) {
  TheModel=new attack_flowADVISE();
  DefineName("rewardPVModel");
  CreatePVList(7, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* rewardPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new rewardPV0(timeindex);
    break;
  case 1:
    return new rewardPV1(timeindex);
    break;
  case 2:
    return new rewardPV2(timeindex);
    break;
  case 3:
    return new rewardPV3(timeindex);
    break;
  case 4:
    return new rewardPV4(timeindex);
    break;
  case 5:
    return new rewardPV5(timeindex);
    break;
  case 6:
    return new rewardPV6(timeindex);
    break;
  }
  return NULL;
}
