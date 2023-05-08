#include "rewardPVNodes.h"

rewardPV0Worker::rewardPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV0Worker::~rewardPV0Worker() {
  delete [] TheModelPtr;
}

double rewardPV0Worker::Reward_Function(void) {

return attack_flow->NoKeyNoAccess->Mark();

return (0);



}

rewardPV0::rewardPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("NoKeyNoAccess",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("NoKeyNoAccess","attack_flow");
}

rewardPV0::~rewardPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV0Worker;
}
rewardPV1Worker::rewardPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV1Worker::~rewardPV1Worker() {
  delete [] TheModelPtr;
}

double rewardPV1Worker::Reward_Function(void) {

return attack_flow->SSIDMACtargetnetwork->Mark();

return (0);



}

rewardPV1::rewardPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("SSIDandMAC",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("SSIDMACtargetnetwork","attack_flow");
}

rewardPV1::~rewardPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV1Worker;
}
rewardPV2Worker::rewardPV2Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV2Worker::~rewardPV2Worker() {
  delete [] TheModelPtr;
}

double rewardPV2Worker::Reward_Function(void) {

return attack_flow->NetworkKey->Mark();

return (0);



}

rewardPV2::rewardPV2(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("NetworkKey",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("NetworkKey","attack_flow");
}

rewardPV2::~rewardPV2() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV2::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV2Worker;
}
rewardPV3Worker::rewardPV3Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV3Worker::~rewardPV3Worker() {
  delete [] TheModelPtr;
}

double rewardPV3Worker::Reward_Function(void) {

return attack_flow->NetworkAccess->Mark();

return (0);



}

rewardPV3::rewardPV3(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("Network Access",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("NetworkAccess","attack_flow");
}

rewardPV3::~rewardPV3() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV3::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV3Worker;
}
rewardPV4Worker::rewardPV4Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV4Worker::~rewardPV4Worker() {
  delete [] TheModelPtr;
}

double rewardPV4Worker::Reward_Function(void) {

return attack_flow->Hijacking->Mark();

return (0);



}

rewardPV4::rewardPV4(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("Hijacking",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("Hijacking","attack_flow");
}

rewardPV4::~rewardPV4() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV4::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV4Worker;
}
rewardPV5Worker::rewardPV5Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV5Worker::~rewardPV5Worker() {
  delete [] TheModelPtr;
}

double rewardPV5Worker::Reward_Function(void) {

return attack_flow->MITM->Mark();

return (0);



}

rewardPV5::rewardPV5(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("MITM",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("MITM","attack_flow");
}

rewardPV5::~rewardPV5() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV5::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV5Worker;
}
rewardPV6Worker::rewardPV6Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV6Worker::~rewardPV6Worker() {
  delete [] TheModelPtr;
}

double rewardPV6Worker::Reward_Function(void) {

return attack_flow->DOS->Mark();

return (0);



}

rewardPV6::rewardPV6(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("DOS",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("DOS","attack_flow");
}

rewardPV6::~rewardPV6() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV6::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV6Worker;
}
rewardPV7Worker::rewardPV7Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&attack_flow);
}

rewardPV7Worker::~rewardPV7Worker() {
  delete [] TheModelPtr;
}

double rewardPV7Worker::Reward_Function(void) {

return attack_flow->SensitiveInformation->Mark();

return (0);



}

rewardPV7::rewardPV7(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&Theattack_flowADVISE);
  double startpts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  double stoppts[21]={0.0, 5.0, 10.0, 15.0, 20.0, 25.0, 30.0, 35.0, 40.0, 45.0, 50.0, 55.0, 60.0, 65.0, 70.0, 75.0, 80.0, 85.0, 90.0, 95.0, 100.0};
  Initialize("Sensitive Information",(RewardType)0,21, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("SensitiveInformation","attack_flow");
}

rewardPV7::~rewardPV7() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void rewardPV7::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new rewardPV7Worker;
}
