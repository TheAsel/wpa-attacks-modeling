#ifndef attack_flowADVISE_H_
#define attack_flowADVISE_H_

#include "Cpp/Simulator/UserDistributions.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/atomic/advise/ADVISEModel.h"
#include "Cpp/BaseClasses/atomic/advise/Access.h"
#include "Cpp/BaseClasses/atomic/advise/AdversaryDecision.h"
#include "Cpp/BaseClasses/atomic/advise/BeginAdversaryDecision.h"
#include "Cpp/BaseClasses/atomic/advise/Goal.h"
#include "Cpp/BaseClasses/atomic/advise/Knowledge.h"
#include "Cpp/BaseClasses/atomic/advise/Skill.h"
#include "Cpp/BaseClasses/atomic/advise/Step.h"
#include "Cpp/BaseClasses/atomic/advise/StepChosen.h"
#include "Cpp/BaseClasses/atomic/advise/StepWeight.h"
#include <limits.h>
#include <cmath>
extern UserDistributions* TheDistribution;

/*********************************************************************
               attack_flowADVISE Submodel Definition                   
*********************************************************************/

class attack_flowADVISE : public ADVISEModel {
public:

class NetworkscanningAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *NetworkscanningChosen;
  short *NetworkscanningChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkscanningAdversaryDecision();
  ~NetworkscanningAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // NetworkscanningAdversaryDecision

class EvilTwinAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *EvilTwinChosen;
  short *EvilTwinChosen_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  double *TheDistributionParameters;

  EvilTwinAdversaryDecision();
  ~EvilTwinAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // EvilTwinAdversaryDecision

class JoinNetworkAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *JoinNetworkChosen;
  short *JoinNetworkChosen_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  double *TheDistributionParameters;

  JoinNetworkAdversaryDecision();
  ~JoinNetworkAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // JoinNetworkAdversaryDecision

class RogueAPAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *RogueAPChosen;
  short *RogueAPChosen_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  double *TheDistributionParameters;

  RogueAPAdversaryDecision();
  ~RogueAPAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // RogueAPAdversaryDecision

class BlockTrafficFlowAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *BlockTrafficFlowChosen;
  short *BlockTrafficFlowChosen_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  double *TheDistributionParameters;

  BlockTrafficFlowAdversaryDecision();
  ~BlockTrafficFlowAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // BlockTrafficFlowAdversaryDecision

class ApplicationLayerAttackAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *ApplicationLayerAttackChosen;
  short *ApplicationLayerAttackChosen_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  double *TheDistributionParameters;

  ApplicationLayerAttackAdversaryDecision();
  ~ApplicationLayerAttackAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // ApplicationLayerAttackAdversaryDecision

class NetworkLayerAttackAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *NetworkLayerAttackChosen;
  short *NetworkLayerAttackChosen_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkLayerAttackAdversaryDecision();
  ~NetworkLayerAttackAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // NetworkLayerAttackAdversaryDecision

class PasswordCaptureAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *PasswordCaptureChosen;
  short *PasswordCaptureChosen_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  double *TheDistributionParameters;

  PasswordCaptureAdversaryDecision();
  ~PasswordCaptureAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // PasswordCaptureAdversaryDecision

class DoNothingAdversaryDecision : public AdversaryDecision {
public:

  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingAdversaryDecision();
  ~DoNothingAdversaryDecision();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass *Fire();
}; // DoNothingAdversaryDecision

class NetworkscanningSuccessStep : public Step {
public:

  Knowledge *SSIDMACtargetnetwork;
  short* SSIDMACtargetnetwork_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *NetworkscanningChosen;
  short *NetworkscanningChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkscanningSuccessStep();
  ~NetworkscanningSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // NetworkscanningSuccessStep

class EvilTwinFailureStep : public Step {
public:

  Access *MITM;
  short* MITM_Mobius_Mark;
  Access *APHardware;
  short* APHardware_Mobius_Mark;
  Skill *APConfiguration;
  short* APConfiguration_Mobius_Mark;
  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *EvilTwinChosen;
  short *EvilTwinChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  EvilTwinFailureStep();
  ~EvilTwinFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // EvilTwinFailureStep

class EvilTwinSuccessStep : public Step {
public:

  Access *MITM;
  short* MITM_Mobius_Mark;
  Access *APHardware;
  short* APHardware_Mobius_Mark;
  Skill *APConfiguration;
  short* APConfiguration_Mobius_Mark;
  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *EvilTwinChosen;
  short *EvilTwinChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  EvilTwinSuccessStep();
  ~EvilTwinSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // EvilTwinSuccessStep

class JoinNetworkSuccessStep : public Step {
public:

  Access *NetworkAccess;
  short* NetworkAccess_Mobius_Mark;
  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  StepChosen *JoinNetworkChosen;
  short *JoinNetworkChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  JoinNetworkSuccessStep();
  ~JoinNetworkSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // JoinNetworkSuccessStep

class RogueAPFailureStep : public Step {
public:

  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  Knowledge *SSIDMACtargetnetwork;
  short* SSIDMACtargetnetwork_Mobius_Mark;
  Access *APHardware;
  short* APHardware_Mobius_Mark;
  Skill *APConfiguration;
  short* APConfiguration_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *RogueAPChosen;
  short *RogueAPChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  RogueAPFailureStep();
  ~RogueAPFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // RogueAPFailureStep

class RogueAPSuccessStep : public Step {
public:

  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  Knowledge *SSIDMACtargetnetwork;
  short* SSIDMACtargetnetwork_Mobius_Mark;
  Access *APHardware;
  short* APHardware_Mobius_Mark;
  Skill *APConfiguration;
  short* APConfiguration_Mobius_Mark;
  Access *PhysicalAccess;
  short* PhysicalAccess_Mobius_Mark;
  StepChosen *RogueAPChosen;
  short *RogueAPChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  RogueAPSuccessStep();
  ~RogueAPSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // RogueAPSuccessStep

class BlockTrafficFlowFailureStep : public Step {
public:

  Goal *DOS;
  short* DOS_Mobius_Mark;
  Access *MITM;
  short* MITM_Mobius_Mark;
  Access *Hijacking;
  short* Hijacking_Mobius_Mark;
  StepChosen *BlockTrafficFlowChosen;
  short *BlockTrafficFlowChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  BlockTrafficFlowFailureStep();
  ~BlockTrafficFlowFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // BlockTrafficFlowFailureStep

class BlockTrafficFlowSuccessStep : public Step {
public:

  Goal *DOS;
  short* DOS_Mobius_Mark;
  Access *MITM;
  short* MITM_Mobius_Mark;
  Access *Hijacking;
  short* Hijacking_Mobius_Mark;
  StepChosen *BlockTrafficFlowChosen;
  short *BlockTrafficFlowChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  BlockTrafficFlowSuccessStep();
  ~BlockTrafficFlowSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // BlockTrafficFlowSuccessStep

class ApplicationLayerAttackFailureStep : public Step {
public:

  Goal *SensitiveInformation;
  short* SensitiveInformation_Mobius_Mark;
  Skill *NetworkHacking;
  short* NetworkHacking_Mobius_Mark;
  Access *MITM;
  short* MITM_Mobius_Mark;
  Goal *DOS;
  short* DOS_Mobius_Mark;
  StepChosen *ApplicationLayerAttackChosen;
  short *ApplicationLayerAttackChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ApplicationLayerAttackFailureStep();
  ~ApplicationLayerAttackFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ApplicationLayerAttackFailureStep

class ApplicationLayerAttackSuccessStep : public Step {
public:

  Goal *SensitiveInformation;
  short* SensitiveInformation_Mobius_Mark;
  Skill *NetworkHacking;
  short* NetworkHacking_Mobius_Mark;
  Access *MITM;
  short* MITM_Mobius_Mark;
  Goal *DOS;
  short* DOS_Mobius_Mark;
  StepChosen *ApplicationLayerAttackChosen;
  short *ApplicationLayerAttackChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  ApplicationLayerAttackSuccessStep();
  ~ApplicationLayerAttackSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // ApplicationLayerAttackSuccessStep

class NetworkLayerAttackFailureStep : public Step {
public:

  Access *Hijacking;
  short* Hijacking_Mobius_Mark;
  Skill *PacketForging;
  short* PacketForging_Mobius_Mark;
  Access *NetworkAccess;
  short* NetworkAccess_Mobius_Mark;
  StepChosen *NetworkLayerAttackChosen;
  short *NetworkLayerAttackChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkLayerAttackFailureStep();
  ~NetworkLayerAttackFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // NetworkLayerAttackFailureStep

class NetworkLayerAttackSuccessStep : public Step {
public:

  Access *Hijacking;
  short* Hijacking_Mobius_Mark;
  Skill *PacketForging;
  short* PacketForging_Mobius_Mark;
  Access *NetworkAccess;
  short* NetworkAccess_Mobius_Mark;
  StepChosen *NetworkLayerAttackChosen;
  short *NetworkLayerAttackChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  NetworkLayerAttackSuccessStep();
  ~NetworkLayerAttackSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // NetworkLayerAttackSuccessStep

class PasswordCaptureFailureStep : public Step {
public:

  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  Skill *SocialEngineering;
  short* SocialEngineering_Mobius_Mark;
  StepChosen *PasswordCaptureChosen;
  short *PasswordCaptureChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PasswordCaptureFailureStep();
  ~PasswordCaptureFailureStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // PasswordCaptureFailureStep

class PasswordCaptureSuccessStep : public Step {
public:

  Knowledge *NetworkKey;
  short* NetworkKey_Mobius_Mark;
  Skill *SocialEngineering;
  short* SocialEngineering_Mobius_Mark;
  StepChosen *PasswordCaptureChosen;
  short *PasswordCaptureChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  PasswordCaptureSuccessStep();
  ~PasswordCaptureSuccessStep();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // PasswordCaptureSuccessStep

class DoNothingOutcome1Step : public Step {
public:

  StepChosen *DoNothingChosen;
  short *DoNothingChosen_Mobius_Mark;
  StepWeight *NetworkscanningWeight;
  short *NetworkscanningWeight_Mobius_Mark;
  StepWeight *EvilTwinWeight;
  short *EvilTwinWeight_Mobius_Mark;
  StepWeight *JoinNetworkWeight;
  short *JoinNetworkWeight_Mobius_Mark;
  StepWeight *RogueAPWeight;
  short *RogueAPWeight_Mobius_Mark;
  StepWeight *BlockTrafficFlowWeight;
  short *BlockTrafficFlowWeight_Mobius_Mark;
  StepWeight *ApplicationLayerAttackWeight;
  short *ApplicationLayerAttackWeight_Mobius_Mark;
  StepWeight *NetworkLayerAttackWeight;
  short *NetworkLayerAttackWeight_Mobius_Mark;
  StepWeight *PasswordCaptureWeight;
  short *PasswordCaptureWeight_Mobius_Mark;
  StepWeight *DoNothingWeight;
  short *DoNothingWeight_Mobius_Mark;
  BeginAdversaryDecision *MakeDecision;
  short *MakeDecision_Mobius_Mark;
  double *TheDistributionParameters;

  DoNothingOutcome1Step();
  ~DoNothingOutcome1Step();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  double getCost();
  double getOutcomeProbability();
  double getDetection();
  int Rank();
  double timeDistributionParameter0();
  bool preconditionsMet();
  void executeEffects();
}; // DoNothingOutcome1Step

  //List of user-specified state variables
  Access *PhysicalAccess;
  Access *MITM;
  Access *Hijacking;
  Access *NetworkAccess;
  Access *APHardware;
  Knowledge *SSIDMACtargetnetwork;
  Knowledge *NetworkKey;
  Skill *PacketForging;
  Skill *SocialEngineering;
  Skill *APConfiguration;
  Skill *NetworkHacking;
  Goal *DOS;
  Goal *SensitiveInformation;
  //List of attack step weight state variables
  StepWeight *NetworkscanningWeight;
  StepWeight *EvilTwinWeight;
  StepWeight *JoinNetworkWeight;
  StepWeight *RogueAPWeight;
  StepWeight *BlockTrafficFlowWeight;
  StepWeight *ApplicationLayerAttackWeight;
  StepWeight *NetworkLayerAttackWeight;
  StepWeight *PasswordCaptureWeight;
  StepWeight *DoNothingWeight;
  //List of attack step chosen state variables
  StepChosen *NetworkscanningChosen;
  StepChosen *EvilTwinChosen;
  StepChosen *JoinNetworkChosen;
  StepChosen *RogueAPChosen;
  StepChosen *BlockTrafficFlowChosen;
  StepChosen *ApplicationLayerAttackChosen;
  StepChosen *NetworkLayerAttackChosen;
  StepChosen *PasswordCaptureChosen;
  StepChosen *DoNothingChosen;
  //List of attack steps
  NetworkscanningSuccessStep NetworkscanningSuccess;
  EvilTwinFailureStep EvilTwinFailure;
  EvilTwinSuccessStep EvilTwinSuccess;
  JoinNetworkSuccessStep JoinNetworkSuccess;
  RogueAPFailureStep RogueAPFailure;
  RogueAPSuccessStep RogueAPSuccess;
  BlockTrafficFlowFailureStep BlockTrafficFlowFailure;
  BlockTrafficFlowSuccessStep BlockTrafficFlowSuccess;
  ApplicationLayerAttackFailureStep ApplicationLayerAttackFailure;
  ApplicationLayerAttackSuccessStep ApplicationLayerAttackSuccess;
  NetworkLayerAttackFailureStep NetworkLayerAttackFailure;
  NetworkLayerAttackSuccessStep NetworkLayerAttackSuccess;
  PasswordCaptureFailureStep PasswordCaptureFailure;
  PasswordCaptureSuccessStep PasswordCaptureSuccess;
  DoNothingOutcome1Step DoNothingOutcome1;
  NetworkscanningAdversaryDecision NetworkscanningAD;
  EvilTwinAdversaryDecision EvilTwinAD;
  JoinNetworkAdversaryDecision JoinNetworkAD;
  RogueAPAdversaryDecision RogueAPAD;
  BlockTrafficFlowAdversaryDecision BlockTrafficFlowAD;
  ApplicationLayerAttackAdversaryDecision ApplicationLayerAttackAD;
  NetworkLayerAttackAdversaryDecision NetworkLayerAttackAD;
  PasswordCaptureAdversaryDecision PasswordCaptureAD;
  DoNothingAdversaryDecision DoNothingAD;
  //Groups for attack steps
  PreselectGroup ImmediateGroup;
  PostselectGroup EvilTwinGroup;
  PostselectGroup RogueAPGroup;
  PostselectGroup BlockTrafficFlowGroup;
  PostselectGroup ApplicationLayerAttackGroup;
  PostselectGroup NetworkLayerAttackGroup;
  PostselectGroup PasswordCaptureGroup;
  PostselectGroup AdversaryDecisionGroup;
  attack_flowADVISE();
  ~attack_flowADVISE();
  void assignSVsToAttackSteps();
  double convertCostToUtility(double cost);
  double convertDetectionToUtility(double detections);
  double convertPayoffToUtility(double payoff);
  void customInitialization();

protected:
}; // end attack_flowADVISE

#endif // attack_flowADVISE_H_
