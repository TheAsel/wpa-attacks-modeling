#ifndef _REWARD_PVS_
#define _REWARD_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/attack_flow/attack_flowADVISE.h"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"


class rewardPV0Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV0Worker();
  ~rewardPV0Worker();
  double Reward_Function();
};

class rewardPV0:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV0Worker *rewardPV0WorkerList;

  rewardPV0(int timeindex=0);
  ~rewardPV0();
  void CreateWorkerList(void);
};

class rewardPV1Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV1Worker();
  ~rewardPV1Worker();
  double Reward_Function();
};

class rewardPV1:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV1Worker *rewardPV1WorkerList;

  rewardPV1(int timeindex=0);
  ~rewardPV1();
  void CreateWorkerList(void);
};

class rewardPV2Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV2Worker();
  ~rewardPV2Worker();
  double Reward_Function();
};

class rewardPV2:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV2Worker *rewardPV2WorkerList;

  rewardPV2(int timeindex=0);
  ~rewardPV2();
  void CreateWorkerList(void);
};

class rewardPV3Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV3Worker();
  ~rewardPV3Worker();
  double Reward_Function();
};

class rewardPV3:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV3Worker *rewardPV3WorkerList;

  rewardPV3(int timeindex=0);
  ~rewardPV3();
  void CreateWorkerList(void);
};

class rewardPV4Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV4Worker();
  ~rewardPV4Worker();
  double Reward_Function();
};

class rewardPV4:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV4Worker *rewardPV4WorkerList;

  rewardPV4(int timeindex=0);
  ~rewardPV4();
  void CreateWorkerList(void);
};

class rewardPV5Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV5Worker();
  ~rewardPV5Worker();
  double Reward_Function();
};

class rewardPV5:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV5Worker *rewardPV5WorkerList;

  rewardPV5(int timeindex=0);
  ~rewardPV5();
  void CreateWorkerList(void);
};

class rewardPV6Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV6Worker();
  ~rewardPV6Worker();
  double Reward_Function();
};

class rewardPV6:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV6Worker *rewardPV6WorkerList;

  rewardPV6(int timeindex=0);
  ~rewardPV6();
  void CreateWorkerList(void);
};

class rewardPV7Worker:public InstantOfTime
{
 public:
  attack_flowADVISE *attack_flow;
  
  rewardPV7Worker();
  ~rewardPV7Worker();
  double Reward_Function();
};

class rewardPV7:public PerformanceVariableNode
{
 public:
  attack_flowADVISE *Theattack_flowADVISE;

  rewardPV7Worker *rewardPV7WorkerList;

  rewardPV7(int timeindex=0);
  ~rewardPV7();
  void CreateWorkerList(void);
};

#endif
