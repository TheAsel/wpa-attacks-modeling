
#include "Atomic/attack_flow/attack_flowADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


attack_flowADVISE::attack_flowADVISE() {
  NetworkscanningAD.setParent(this);
  EvilTwinAD.setParent(this);
  JoinNetworkAD.setParent(this);
  RogueAPAD.setParent(this);
  BlockTrafficFlowAD.setParent(this);
  ApplicationLayerAttackAD.setParent(this);
  NetworkLayerAttackAD.setParent(this);
  PasswordCaptureAD.setParent(this);
  DoNothingAD.setParent(this);
  NetworkscanningSuccess.setParent(this);
  EvilTwinFailure.setParent(this);
  EvilTwinSuccess.setParent(this);
  JoinNetworkSuccess.setParent(this);
  RogueAPFailure.setParent(this);
  RogueAPSuccess.setParent(this);
  BlockTrafficFlowFailure.setParent(this);
  BlockTrafficFlowSuccess.setParent(this);
  ApplicationLayerAttackFailure.setParent(this);
  ApplicationLayerAttackSuccess.setParent(this);
  NetworkLayerAttackFailure.setParent(this);
  NetworkLayerAttackSuccess.setParent(this);
  PasswordCaptureFailure.setParent(this);
  PasswordCaptureSuccess.setParent(this);
  DoNothingOutcome1.setParent(this);
  EvilTwinGroup.initialize(2, "EvilTwinGroup");
  EvilTwinGroup.appendGroup((BaseGroupClass*) &EvilTwinFailure);
  EvilTwinGroup.appendGroup((BaseGroupClass*) &EvilTwinSuccess);

  RogueAPGroup.initialize(2, "RogueAPGroup");
  RogueAPGroup.appendGroup((BaseGroupClass*) &RogueAPFailure);
  RogueAPGroup.appendGroup((BaseGroupClass*) &RogueAPSuccess);

  BlockTrafficFlowGroup.initialize(2, "BlockTrafficFlowGroup");
  BlockTrafficFlowGroup.appendGroup((BaseGroupClass*) &BlockTrafficFlowFailure);
  BlockTrafficFlowGroup.appendGroup((BaseGroupClass*) &BlockTrafficFlowSuccess);

  ApplicationLayerAttackGroup.initialize(2, "ApplicationLayerAttackGroup");
  ApplicationLayerAttackGroup.appendGroup((BaseGroupClass*) &ApplicationLayerAttackFailure);
  ApplicationLayerAttackGroup.appendGroup((BaseGroupClass*) &ApplicationLayerAttackSuccess);

  NetworkLayerAttackGroup.initialize(2, "NetworkLayerAttackGroup");
  NetworkLayerAttackGroup.appendGroup((BaseGroupClass*) &NetworkLayerAttackFailure);
  NetworkLayerAttackGroup.appendGroup((BaseGroupClass*) &NetworkLayerAttackSuccess);

  PasswordCaptureGroup.initialize(2, "PasswordCaptureGroup");
  PasswordCaptureGroup.appendGroup((BaseGroupClass*) &PasswordCaptureFailure);
  PasswordCaptureGroup.appendGroup((BaseGroupClass*) &PasswordCaptureSuccess);

  AdversaryDecisionGroup.initialize(9, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &NetworkscanningAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &EvilTwinAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &JoinNetworkAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &RogueAPAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &BlockTrafficFlowAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ApplicationLayerAttackAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &NetworkLayerAttackAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PasswordCaptureAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);

  BaseADVISEAction* InitialActions[24] = {
    &NetworkscanningAD, // 0
    &EvilTwinAD, // 1
    &JoinNetworkAD, // 2
    &RogueAPAD, // 3
    &BlockTrafficFlowAD, // 4
    &ApplicationLayerAttackAD, // 5
    &NetworkLayerAttackAD, // 6
    &PasswordCaptureAD, // 7
    &DoNothingAD, // 8
    &NetworkscanningSuccess, // 9
    &EvilTwinFailure, // 10
    &EvilTwinSuccess, // 11
    &JoinNetworkSuccess, // 12
    &RogueAPFailure, // 13
    &RogueAPSuccess, // 14
    &BlockTrafficFlowFailure, // 15
    &BlockTrafficFlowSuccess, // 16
    &ApplicationLayerAttackFailure, // 17
    &ApplicationLayerAttackSuccess, // 18
    &NetworkLayerAttackFailure, // 19
    &NetworkLayerAttackSuccess, // 20
    &PasswordCaptureFailure, // 21
    &PasswordCaptureSuccess, // 22
    &DoNothingOutcome1 // 23
  };

  Step* InitialSteps[15] = {
      &NetworkscanningSuccess,
      &EvilTwinFailure,
      &EvilTwinSuccess,
      &JoinNetworkSuccess,
      &RogueAPFailure,
      &RogueAPSuccess,
      &BlockTrafficFlowFailure,
      &BlockTrafficFlowSuccess,
      &ApplicationLayerAttackFailure,
      &ApplicationLayerAttackSuccess,
      &NetworkLayerAttackFailure,
      &NetworkLayerAttackSuccess,
      &PasswordCaptureFailure,
      &PasswordCaptureSuccess,
      &DoNothingOutcome1
  };

  BaseGroupClass* InitialGroups[10] = {
    (BaseGroupClass*) &NetworkscanningSuccess, // 0
    (BaseGroupClass*) &EvilTwinGroup, // 1
    (BaseGroupClass*) &JoinNetworkSuccess, // 2
    (BaseGroupClass*) &RogueAPGroup, // 3
    (BaseGroupClass*) &BlockTrafficFlowGroup, // 4
    (BaseGroupClass*) &ApplicationLayerAttackGroup, // 5
    (BaseGroupClass*) &NetworkLayerAttackGroup, // 6
    (BaseGroupClass*) &PasswordCaptureGroup, // 7
    (BaseGroupClass*) &DoNothingOutcome1, // 8
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  APHardware = new Access("APHardware", 1);
  Hijacking = new Knowledge("Hijacking", 0);
  SSIDMACtargetnetwork = new Knowledge("SSIDMACtargetnetwork", 0);
  NetworkAccess = new Knowledge("NetworkAccess", 0);
  Key = new Knowledge("Key", 1);
  NoKeyNoAccess = new Knowledge("NoKeyNoAccess", 0);
  PacketForging = new Skill("PacketForging", 10);
  SocialEngineering = new Skill("SocialEngineering", 10);
  APConfiguration = new Skill("APConfiguration", 10);
  NetworkHacking = new Skill("NetworkHacking", 10);
  DOS = new Goal("DOS", 0);
  DOS->setPayoff(1);
  MITM = new Goal("MITM", 0);
  MITM->setPayoff(500);
  SensitiveInformation = new Goal("SensitiveInformation", 0);
  SensitiveInformation->setPayoff(1000);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  NetworkscanningWeight = new StepWeight("NetworkscanningWeight", 0);
  NetworkscanningChosen = new StepChosen("NetworkscanningChosen", 0);
  EvilTwinWeight = new StepWeight("EvilTwinWeight", 0);
  EvilTwinChosen = new StepChosen("EvilTwinChosen", 0);
  JoinNetworkWeight = new StepWeight("JoinNetworkWeight", 0);
  JoinNetworkChosen = new StepChosen("JoinNetworkChosen", 0);
  RogueAPWeight = new StepWeight("RogueAPWeight", 0);
  RogueAPChosen = new StepChosen("RogueAPChosen", 0);
  BlockTrafficFlowWeight = new StepWeight("BlockTrafficFlowWeight", 0);
  BlockTrafficFlowChosen = new StepChosen("BlockTrafficFlowChosen", 0);
  ApplicationLayerAttackWeight = new StepWeight("ApplicationLayerAttackWeight", 0);
  ApplicationLayerAttackChosen = new StepChosen("ApplicationLayerAttackChosen", 0);
  NetworkLayerAttackWeight = new StepWeight("NetworkLayerAttackWeight", 0);
  NetworkLayerAttackChosen = new StepChosen("NetworkLayerAttackChosen", 0);
  PasswordCaptureWeight = new StepWeight("PasswordCaptureWeight", 0);
  PasswordCaptureChosen = new StepChosen("PasswordCaptureChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);

  Goal* InitialGoals[3] = {
      DOS,
      MITM,
      SensitiveInformation
  };

  ADVISEStateVariable* InitialSVs[32] = {
    APHardware, // 0
    Hijacking, // 1
    SSIDMACtargetnetwork, // 2
    NetworkAccess, // 3
    Key, // 4
    NoKeyNoAccess, // 5
    PacketForging, // 6
    SocialEngineering, // 7
    APConfiguration, // 8
    NetworkHacking, // 9
    DOS, // 10
    MITM, // 11
    SensitiveInformation, // 12
    NetworkscanningChosen, // 13
    EvilTwinChosen, // 14
    JoinNetworkChosen, // 15
    RogueAPChosen, // 16
    BlockTrafficFlowChosen, // 17
    ApplicationLayerAttackChosen, // 18
    NetworkLayerAttackChosen, // 19
    PasswordCaptureChosen, // 20
    DoNothingChosen, // 21
    NetworkscanningWeight, // 22
    EvilTwinWeight, // 23
    JoinNetworkWeight, // 24
    RogueAPWeight, // 25
    BlockTrafficFlowWeight, // 26
    ApplicationLayerAttackWeight, // 27
    NetworkLayerAttackWeight, // 28
    PasswordCaptureWeight, // 29
    DoNothingWeight, // 30
    MakeDecision // 31
};

  int outCounts[9] = { 1, 2, 1, 2, 2, 2, 2, 2, 1 };

  commonInit("attack_flow", 32, InitialSVs, 24, InitialActions, 10, InitialGroups, 9, outCounts, InitialSteps, 3, InitialGoals);

  advCostPref = 0.1;
  advDetectPref = 0.1;
  advPayPref = 0.8;

  planningHorizon = 5;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[226][2] = {
    {31,0}, {13,0}, {22,0}, {31,1}, {14,1}, {23,1}, {31,2}, {15,2}, 
    {24,2}, {31,3}, {16,3}, {25,3}, {31,4}, {17,4}, {26,4}, {31,5}, 
    {18,5}, {27,5}, {31,6}, {19,6}, {28,6}, {31,7}, {20,7}, {29,7}, 
    {31,8}, {21,8}, {30,8}, {31,9}, {13,9}, {22,9}, {23,9}, {24,9}, 
    {25,9}, {26,9}, {27,9}, {28,9}, {29,9}, {30,9}, {2,9}, {5,9}, 
    {31,10}, {14,10}, {22,10}, {23,10}, {24,10}, {25,10}, {26,10}, {27,10}, 
    {28,10}, {29,10}, {30,10}, {11,10}, {0,10}, {4,10}, {31,11}, {14,11}, 
    {22,11}, {23,11}, {24,11}, {25,11}, {26,11}, {27,11}, {28,11}, {29,11}, 
    {30,11}, {11,11}, {0,11}, {4,11}, {31,12}, {15,12}, {22,12}, {23,12}, 
    {24,12}, {25,12}, {26,12}, {27,12}, {28,12}, {29,12}, {30,12}, {3,12}, 
    {4,12}, {31,13}, {16,13}, {22,13}, {23,13}, {24,13}, {25,13}, {26,13}, 
    {27,13}, {28,13}, {29,13}, {30,13}, {4,13}, {0,13}, {2,13}, {31,14}, 
    {16,14}, {22,14}, {23,14}, {24,14}, {25,14}, {26,14}, {27,14}, {28,14}, 
    {29,14}, {30,14}, {4,14}, {0,14}, {2,14}, {31,15}, {17,15}, {22,15}, 
    {23,15}, {24,15}, {25,15}, {26,15}, {27,15}, {28,15}, {29,15}, {30,15}, 
    {10,15}, {11,15}, {1,15}, {31,16}, {17,16}, {22,16}, {23,16}, {24,16}, 
    {25,16}, {26,16}, {27,16}, {28,16}, {29,16}, {30,16}, {10,16}, {11,16}, 
    {1,16}, {31,17}, {18,17}, {22,17}, {23,17}, {24,17}, {25,17}, {26,17}, 
    {27,17}, {28,17}, {29,17}, {30,17}, {12,17}, {11,17}, {31,18}, {18,18}, 
    {22,18}, {23,18}, {24,18}, {25,18}, {26,18}, {27,18}, {28,18}, {29,18}, 
    {30,18}, {12,18}, {11,18}, {31,19}, {19,19}, {22,19}, {23,19}, {24,19}, 
    {25,19}, {26,19}, {27,19}, {28,19}, {29,19}, {30,19}, {1,19}, {3,19}, 
    {31,20}, {19,20}, {22,20}, {23,20}, {24,20}, {25,20}, {26,20}, {27,20}, 
    {28,20}, {29,20}, {30,20}, {1,20}, {3,20}, {31,21}, {20,21}, {22,21}, 
    {23,21}, {24,21}, {25,21}, {26,21}, {27,21}, {28,21}, {29,21}, {30,21}, 
    {4,21}, {5,21}, {31,22}, {20,22}, {22,22}, {23,22}, {24,22}, {25,22}, 
    {26,22}, {27,22}, {28,22}, {29,22}, {30,22}, {4,22}, {5,22}, {31,23}, 
    {21,23}, {22,23}, {23,23}, {24,23}, {25,23}, {26,23}, {27,23}, {28,23}, 
    {29,23}, {30,23}
};
  for(int n = 0; n < 226;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[38][2] = {
    {31,0}, {31,1}, {31,2}, {31,3}, {31,4}, {31,5}, {31,6}, {31,7}, 
    {31,8}, {13,9}, {2,9}, {14,10}, {11,10}, {14,11}, {11,11}, {15,12}, 
    {3,12}, {16,13}, {4,13}, {16,14}, {4,14}, {17,15}, {10,15}, {17,16}, 
    {10,16}, {18,17}, {12,17}, {18,18}, {12,18}, {19,19}, {1,19}, {19,20}, 
    {1,20}, {20,21}, {4,21}, {20,22}, {4,22}, {21,23}
};
  for(int n = 0; n < 38;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 24; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

attack_flowADVISE::~attack_flowADVISE() {
}

void attack_flowADVISE::assignSVsToAttackSteps() {
  NetworkscanningSuccess.SSIDMACtargetnetwork = SSIDMACtargetnetwork;
  NetworkscanningSuccess.NoKeyNoAccess = NoKeyNoAccess;
  NetworkscanningSuccess.NetworkscanningChosen = NetworkscanningChosen;
  NetworkscanningSuccess.NetworkscanningWeight = NetworkscanningWeight;
  NetworkscanningSuccess.EvilTwinWeight = EvilTwinWeight;
  NetworkscanningSuccess.JoinNetworkWeight = JoinNetworkWeight;
  NetworkscanningSuccess.RogueAPWeight = RogueAPWeight;
  NetworkscanningSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  NetworkscanningSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  NetworkscanningSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  NetworkscanningSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  NetworkscanningSuccess.DoNothingWeight = DoNothingWeight;
  NetworkscanningSuccess.MakeDecision = MakeDecision;
  NetworkscanningSuccess.setSVs(NetworkscanningChosen, NetworkscanningWeight);
  EvilTwinFailure.MITM = MITM;
  EvilTwinFailure.APHardware = APHardware;
  EvilTwinFailure.APConfiguration = APConfiguration;
  EvilTwinFailure.Key = Key;
  EvilTwinFailure.EvilTwinChosen = EvilTwinChosen;
  EvilTwinFailure.NetworkscanningWeight = NetworkscanningWeight;
  EvilTwinFailure.EvilTwinWeight = EvilTwinWeight;
  EvilTwinFailure.JoinNetworkWeight = JoinNetworkWeight;
  EvilTwinFailure.RogueAPWeight = RogueAPWeight;
  EvilTwinFailure.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  EvilTwinFailure.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  EvilTwinFailure.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  EvilTwinFailure.PasswordCaptureWeight = PasswordCaptureWeight;
  EvilTwinFailure.DoNothingWeight = DoNothingWeight;
  EvilTwinFailure.MakeDecision = MakeDecision;
  EvilTwinFailure.setSVs(EvilTwinChosen, EvilTwinWeight);
  EvilTwinSuccess.MITM = MITM;
  EvilTwinSuccess.APHardware = APHardware;
  EvilTwinSuccess.APConfiguration = APConfiguration;
  EvilTwinSuccess.Key = Key;
  EvilTwinSuccess.EvilTwinChosen = EvilTwinChosen;
  EvilTwinSuccess.NetworkscanningWeight = NetworkscanningWeight;
  EvilTwinSuccess.EvilTwinWeight = EvilTwinWeight;
  EvilTwinSuccess.JoinNetworkWeight = JoinNetworkWeight;
  EvilTwinSuccess.RogueAPWeight = RogueAPWeight;
  EvilTwinSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  EvilTwinSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  EvilTwinSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  EvilTwinSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  EvilTwinSuccess.DoNothingWeight = DoNothingWeight;
  EvilTwinSuccess.MakeDecision = MakeDecision;
  EvilTwinSuccess.setSVs(EvilTwinChosen, EvilTwinWeight);
  JoinNetworkSuccess.NetworkAccess = NetworkAccess;
  JoinNetworkSuccess.Key = Key;
  JoinNetworkSuccess.JoinNetworkChosen = JoinNetworkChosen;
  JoinNetworkSuccess.NetworkscanningWeight = NetworkscanningWeight;
  JoinNetworkSuccess.EvilTwinWeight = EvilTwinWeight;
  JoinNetworkSuccess.JoinNetworkWeight = JoinNetworkWeight;
  JoinNetworkSuccess.RogueAPWeight = RogueAPWeight;
  JoinNetworkSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  JoinNetworkSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  JoinNetworkSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  JoinNetworkSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  JoinNetworkSuccess.DoNothingWeight = DoNothingWeight;
  JoinNetworkSuccess.MakeDecision = MakeDecision;
  JoinNetworkSuccess.setSVs(JoinNetworkChosen, JoinNetworkWeight);
  RogueAPFailure.Key = Key;
  RogueAPFailure.APHardware = APHardware;
  RogueAPFailure.APConfiguration = APConfiguration;
  RogueAPFailure.SSIDMACtargetnetwork = SSIDMACtargetnetwork;
  RogueAPFailure.RogueAPChosen = RogueAPChosen;
  RogueAPFailure.NetworkscanningWeight = NetworkscanningWeight;
  RogueAPFailure.EvilTwinWeight = EvilTwinWeight;
  RogueAPFailure.JoinNetworkWeight = JoinNetworkWeight;
  RogueAPFailure.RogueAPWeight = RogueAPWeight;
  RogueAPFailure.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  RogueAPFailure.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  RogueAPFailure.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  RogueAPFailure.PasswordCaptureWeight = PasswordCaptureWeight;
  RogueAPFailure.DoNothingWeight = DoNothingWeight;
  RogueAPFailure.MakeDecision = MakeDecision;
  RogueAPFailure.setSVs(RogueAPChosen, RogueAPWeight);
  RogueAPSuccess.Key = Key;
  RogueAPSuccess.APHardware = APHardware;
  RogueAPSuccess.APConfiguration = APConfiguration;
  RogueAPSuccess.SSIDMACtargetnetwork = SSIDMACtargetnetwork;
  RogueAPSuccess.RogueAPChosen = RogueAPChosen;
  RogueAPSuccess.NetworkscanningWeight = NetworkscanningWeight;
  RogueAPSuccess.EvilTwinWeight = EvilTwinWeight;
  RogueAPSuccess.JoinNetworkWeight = JoinNetworkWeight;
  RogueAPSuccess.RogueAPWeight = RogueAPWeight;
  RogueAPSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  RogueAPSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  RogueAPSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  RogueAPSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  RogueAPSuccess.DoNothingWeight = DoNothingWeight;
  RogueAPSuccess.MakeDecision = MakeDecision;
  RogueAPSuccess.setSVs(RogueAPChosen, RogueAPWeight);
  BlockTrafficFlowFailure.DOS = DOS;
  BlockTrafficFlowFailure.MITM = MITM;
  BlockTrafficFlowFailure.Hijacking = Hijacking;
  BlockTrafficFlowFailure.BlockTrafficFlowChosen = BlockTrafficFlowChosen;
  BlockTrafficFlowFailure.NetworkscanningWeight = NetworkscanningWeight;
  BlockTrafficFlowFailure.EvilTwinWeight = EvilTwinWeight;
  BlockTrafficFlowFailure.JoinNetworkWeight = JoinNetworkWeight;
  BlockTrafficFlowFailure.RogueAPWeight = RogueAPWeight;
  BlockTrafficFlowFailure.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  BlockTrafficFlowFailure.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  BlockTrafficFlowFailure.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  BlockTrafficFlowFailure.PasswordCaptureWeight = PasswordCaptureWeight;
  BlockTrafficFlowFailure.DoNothingWeight = DoNothingWeight;
  BlockTrafficFlowFailure.MakeDecision = MakeDecision;
  BlockTrafficFlowFailure.setSVs(BlockTrafficFlowChosen, BlockTrafficFlowWeight);
  BlockTrafficFlowSuccess.DOS = DOS;
  BlockTrafficFlowSuccess.MITM = MITM;
  BlockTrafficFlowSuccess.Hijacking = Hijacking;
  BlockTrafficFlowSuccess.BlockTrafficFlowChosen = BlockTrafficFlowChosen;
  BlockTrafficFlowSuccess.NetworkscanningWeight = NetworkscanningWeight;
  BlockTrafficFlowSuccess.EvilTwinWeight = EvilTwinWeight;
  BlockTrafficFlowSuccess.JoinNetworkWeight = JoinNetworkWeight;
  BlockTrafficFlowSuccess.RogueAPWeight = RogueAPWeight;
  BlockTrafficFlowSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  BlockTrafficFlowSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  BlockTrafficFlowSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  BlockTrafficFlowSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  BlockTrafficFlowSuccess.DoNothingWeight = DoNothingWeight;
  BlockTrafficFlowSuccess.MakeDecision = MakeDecision;
  BlockTrafficFlowSuccess.setSVs(BlockTrafficFlowChosen, BlockTrafficFlowWeight);
  ApplicationLayerAttackFailure.SensitiveInformation = SensitiveInformation;
  ApplicationLayerAttackFailure.MITM = MITM;
  ApplicationLayerAttackFailure.NetworkHacking = NetworkHacking;
  ApplicationLayerAttackFailure.ApplicationLayerAttackChosen = ApplicationLayerAttackChosen;
  ApplicationLayerAttackFailure.NetworkscanningWeight = NetworkscanningWeight;
  ApplicationLayerAttackFailure.EvilTwinWeight = EvilTwinWeight;
  ApplicationLayerAttackFailure.JoinNetworkWeight = JoinNetworkWeight;
  ApplicationLayerAttackFailure.RogueAPWeight = RogueAPWeight;
  ApplicationLayerAttackFailure.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  ApplicationLayerAttackFailure.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  ApplicationLayerAttackFailure.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  ApplicationLayerAttackFailure.PasswordCaptureWeight = PasswordCaptureWeight;
  ApplicationLayerAttackFailure.DoNothingWeight = DoNothingWeight;
  ApplicationLayerAttackFailure.MakeDecision = MakeDecision;
  ApplicationLayerAttackFailure.setSVs(ApplicationLayerAttackChosen, ApplicationLayerAttackWeight);
  ApplicationLayerAttackSuccess.SensitiveInformation = SensitiveInformation;
  ApplicationLayerAttackSuccess.MITM = MITM;
  ApplicationLayerAttackSuccess.NetworkHacking = NetworkHacking;
  ApplicationLayerAttackSuccess.ApplicationLayerAttackChosen = ApplicationLayerAttackChosen;
  ApplicationLayerAttackSuccess.NetworkscanningWeight = NetworkscanningWeight;
  ApplicationLayerAttackSuccess.EvilTwinWeight = EvilTwinWeight;
  ApplicationLayerAttackSuccess.JoinNetworkWeight = JoinNetworkWeight;
  ApplicationLayerAttackSuccess.RogueAPWeight = RogueAPWeight;
  ApplicationLayerAttackSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  ApplicationLayerAttackSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  ApplicationLayerAttackSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  ApplicationLayerAttackSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  ApplicationLayerAttackSuccess.DoNothingWeight = DoNothingWeight;
  ApplicationLayerAttackSuccess.MakeDecision = MakeDecision;
  ApplicationLayerAttackSuccess.setSVs(ApplicationLayerAttackChosen, ApplicationLayerAttackWeight);
  NetworkLayerAttackFailure.Hijacking = Hijacking;
  NetworkLayerAttackFailure.NetworkAccess = NetworkAccess;
  NetworkLayerAttackFailure.PacketForging = PacketForging;
  NetworkLayerAttackFailure.NetworkLayerAttackChosen = NetworkLayerAttackChosen;
  NetworkLayerAttackFailure.NetworkscanningWeight = NetworkscanningWeight;
  NetworkLayerAttackFailure.EvilTwinWeight = EvilTwinWeight;
  NetworkLayerAttackFailure.JoinNetworkWeight = JoinNetworkWeight;
  NetworkLayerAttackFailure.RogueAPWeight = RogueAPWeight;
  NetworkLayerAttackFailure.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  NetworkLayerAttackFailure.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  NetworkLayerAttackFailure.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  NetworkLayerAttackFailure.PasswordCaptureWeight = PasswordCaptureWeight;
  NetworkLayerAttackFailure.DoNothingWeight = DoNothingWeight;
  NetworkLayerAttackFailure.MakeDecision = MakeDecision;
  NetworkLayerAttackFailure.setSVs(NetworkLayerAttackChosen, NetworkLayerAttackWeight);
  NetworkLayerAttackSuccess.Hijacking = Hijacking;
  NetworkLayerAttackSuccess.NetworkAccess = NetworkAccess;
  NetworkLayerAttackSuccess.PacketForging = PacketForging;
  NetworkLayerAttackSuccess.NetworkLayerAttackChosen = NetworkLayerAttackChosen;
  NetworkLayerAttackSuccess.NetworkscanningWeight = NetworkscanningWeight;
  NetworkLayerAttackSuccess.EvilTwinWeight = EvilTwinWeight;
  NetworkLayerAttackSuccess.JoinNetworkWeight = JoinNetworkWeight;
  NetworkLayerAttackSuccess.RogueAPWeight = RogueAPWeight;
  NetworkLayerAttackSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  NetworkLayerAttackSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  NetworkLayerAttackSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  NetworkLayerAttackSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  NetworkLayerAttackSuccess.DoNothingWeight = DoNothingWeight;
  NetworkLayerAttackSuccess.MakeDecision = MakeDecision;
  NetworkLayerAttackSuccess.setSVs(NetworkLayerAttackChosen, NetworkLayerAttackWeight);
  PasswordCaptureFailure.Key = Key;
  PasswordCaptureFailure.SocialEngineering = SocialEngineering;
  PasswordCaptureFailure.NoKeyNoAccess = NoKeyNoAccess;
  PasswordCaptureFailure.PasswordCaptureChosen = PasswordCaptureChosen;
  PasswordCaptureFailure.NetworkscanningWeight = NetworkscanningWeight;
  PasswordCaptureFailure.EvilTwinWeight = EvilTwinWeight;
  PasswordCaptureFailure.JoinNetworkWeight = JoinNetworkWeight;
  PasswordCaptureFailure.RogueAPWeight = RogueAPWeight;
  PasswordCaptureFailure.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  PasswordCaptureFailure.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  PasswordCaptureFailure.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  PasswordCaptureFailure.PasswordCaptureWeight = PasswordCaptureWeight;
  PasswordCaptureFailure.DoNothingWeight = DoNothingWeight;
  PasswordCaptureFailure.MakeDecision = MakeDecision;
  PasswordCaptureFailure.setSVs(PasswordCaptureChosen, PasswordCaptureWeight);
  PasswordCaptureSuccess.Key = Key;
  PasswordCaptureSuccess.SocialEngineering = SocialEngineering;
  PasswordCaptureSuccess.NoKeyNoAccess = NoKeyNoAccess;
  PasswordCaptureSuccess.PasswordCaptureChosen = PasswordCaptureChosen;
  PasswordCaptureSuccess.NetworkscanningWeight = NetworkscanningWeight;
  PasswordCaptureSuccess.EvilTwinWeight = EvilTwinWeight;
  PasswordCaptureSuccess.JoinNetworkWeight = JoinNetworkWeight;
  PasswordCaptureSuccess.RogueAPWeight = RogueAPWeight;
  PasswordCaptureSuccess.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  PasswordCaptureSuccess.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  PasswordCaptureSuccess.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  PasswordCaptureSuccess.PasswordCaptureWeight = PasswordCaptureWeight;
  PasswordCaptureSuccess.DoNothingWeight = DoNothingWeight;
  PasswordCaptureSuccess.MakeDecision = MakeDecision;
  PasswordCaptureSuccess.setSVs(PasswordCaptureChosen, PasswordCaptureWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  DoNothingOutcome1.EvilTwinWeight = EvilTwinWeight;
  DoNothingOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  DoNothingOutcome1.RogueAPWeight = RogueAPWeight;
  DoNothingOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  DoNothingOutcome1.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  DoNothingOutcome1.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  DoNothingOutcome1.PasswordCaptureWeight = PasswordCaptureWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);

  NetworkscanningAD.MakeDecision = MakeDecision;
  NetworkscanningAD.NetworkscanningChosen = NetworkscanningChosen;
  NetworkscanningAD.NetworkscanningWeight = NetworkscanningWeight;
  EvilTwinAD.MakeDecision = MakeDecision;
  EvilTwinAD.EvilTwinChosen = EvilTwinChosen;
  EvilTwinAD.EvilTwinWeight = EvilTwinWeight;
  JoinNetworkAD.MakeDecision = MakeDecision;
  JoinNetworkAD.JoinNetworkChosen = JoinNetworkChosen;
  JoinNetworkAD.JoinNetworkWeight = JoinNetworkWeight;
  RogueAPAD.MakeDecision = MakeDecision;
  RogueAPAD.RogueAPChosen = RogueAPChosen;
  RogueAPAD.RogueAPWeight = RogueAPWeight;
  BlockTrafficFlowAD.MakeDecision = MakeDecision;
  BlockTrafficFlowAD.BlockTrafficFlowChosen = BlockTrafficFlowChosen;
  BlockTrafficFlowAD.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  ApplicationLayerAttackAD.MakeDecision = MakeDecision;
  ApplicationLayerAttackAD.ApplicationLayerAttackChosen = ApplicationLayerAttackChosen;
  ApplicationLayerAttackAD.ApplicationLayerAttackWeight = ApplicationLayerAttackWeight;
  NetworkLayerAttackAD.MakeDecision = MakeDecision;
  NetworkLayerAttackAD.NetworkLayerAttackChosen = NetworkLayerAttackChosen;
  NetworkLayerAttackAD.NetworkLayerAttackWeight = NetworkLayerAttackWeight;
  PasswordCaptureAD.MakeDecision = MakeDecision;
  PasswordCaptureAD.PasswordCaptureChosen = PasswordCaptureChosen;
  PasswordCaptureAD.PasswordCaptureWeight = PasswordCaptureWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
}

double attack_flowADVISE::convertCostToUtility(double cost) {
  const double esquared = 7.389056099; // e^(2)
  if(cost < 0)
    return 1.0;
  else if(cost > 100)
    return 0.0;
  else {
    return (esquared - exp(cost/50))/(-1 + esquared);
  }
}

double attack_flowADVISE::convertPayoffToUtility(double payoff) {
  const double etoten = 28.031624895; // e^(10/3)
  if(payoff < 0)
    return 0;
  else if(payoff > 1000)
    return 1;
  else {
    return (etoten - (etoten/exp(payoff/300)))/(-1 + etoten);
  }
}

double attack_flowADVISE::convertDetectionToUtility(double detection) {
  const double esquared = 7.389056099; // e^(2)
  if(detection < 0)
    return 1;
  else if(detection > 1)
    return 0;
  else {
    return (1-(esquared/exp(2*detection)))/(1-esquared);
  }
}

void attack_flowADVISE::customInitialization() {

}

/*****************************************************************/
/*                   Attack Step Definitions                     */
/*****************************************************************/

/*====================== NetworkscanningSuccessStep ========================*/

attack_flowADVISE::NetworkscanningSuccessStep::NetworkscanningSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkscanningSuccessStep", 0, Deterministic, RaceEnabled, 13, 1, false);}

attack_flowADVISE::NetworkscanningSuccessStep::~NetworkscanningSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::NetworkscanningSuccessStep::LinkVariables() {
  SSIDMACtargetnetwork->Register(&SSIDMACtargetnetwork_Mobius_Mark);
  NoKeyNoAccess->Register(&NoKeyNoAccess_Mobius_Mark);
  NetworkscanningChosen->Register(&NetworkscanningChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::NetworkscanningSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkscanningChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::NetworkscanningSuccessStep::timeDistributionParameter0() {
return 2;
}

double attack_flowADVISE::NetworkscanningSuccessStep::Weight() {
  return 1;
}

bool attack_flowADVISE::NetworkscanningSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::NetworkscanningSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::NetworkscanningSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::NetworkscanningSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::NetworkscanningSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::NetworkscanningSuccessStep::preconditionsMet() {
return NoKeyNoAccess->Mark() && !SSIDMACtargetnetwork->Mark();
  return true;
}

void attack_flowADVISE::NetworkscanningSuccessStep::executeEffects() {
SSIDMACtargetnetwork->Mark() = true;
}

double attack_flowADVISE::NetworkscanningSuccessStep::getCost() {
return 0;
}

double attack_flowADVISE::NetworkscanningSuccessStep::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::NetworkscanningSuccessStep::getDetection() {
return 0;
}

/*====================== EvilTwinFailureStep ========================*/

attack_flowADVISE::EvilTwinFailureStep::EvilTwinFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("EvilTwinFailureStep", 1, Deterministic, RaceEnabled, 15, 1, false);}

attack_flowADVISE::EvilTwinFailureStep::~EvilTwinFailureStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::EvilTwinFailureStep::LinkVariables() {
  MITM->Register(&MITM_Mobius_Mark);
  APHardware->Register(&APHardware_Mobius_Mark);
  APConfiguration->Register(&APConfiguration_Mobius_Mark);
  Key->Register(&Key_Mobius_Mark);
  EvilTwinChosen->Register(&EvilTwinChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::EvilTwinFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(EvilTwinChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::EvilTwinFailureStep::timeDistributionParameter0() {
return 8;
}

double attack_flowADVISE::EvilTwinFailureStep::Weight() {
if (APConfiguration->Mark() > 8) return 0.1; else return 0.7;
}

bool attack_flowADVISE::EvilTwinFailureStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::EvilTwinFailureStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::EvilTwinFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::EvilTwinFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::EvilTwinFailureStep::Rank() {
  return 1;
}

bool attack_flowADVISE::EvilTwinFailureStep::preconditionsMet() {
return Key->Mark() && APHardware->Mark() && (APConfiguration->Mark()>6) && !MITM->Mark(); 
  return true;
}

void attack_flowADVISE::EvilTwinFailureStep::executeEffects() {
MITM->Mark() = false;
}

double attack_flowADVISE::EvilTwinFailureStep::getCost() {
return 6;
}

double attack_flowADVISE::EvilTwinFailureStep::getOutcomeProbability() {
if (APConfiguration->Mark() > 8) return 0.1; else return 0.7;
}

double attack_flowADVISE::EvilTwinFailureStep::getDetection() {
return 0.2;
}

/*====================== EvilTwinSuccessStep ========================*/

attack_flowADVISE::EvilTwinSuccessStep::EvilTwinSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("EvilTwinSuccessStep", 1, Deterministic, RaceEnabled, 15, 1, false);}

attack_flowADVISE::EvilTwinSuccessStep::~EvilTwinSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::EvilTwinSuccessStep::LinkVariables() {
  MITM->Register(&MITM_Mobius_Mark);
  APHardware->Register(&APHardware_Mobius_Mark);
  APConfiguration->Register(&APConfiguration_Mobius_Mark);
  Key->Register(&Key_Mobius_Mark);
  EvilTwinChosen->Register(&EvilTwinChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::EvilTwinSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(EvilTwinChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::EvilTwinSuccessStep::timeDistributionParameter0() {
return 8;
}

double attack_flowADVISE::EvilTwinSuccessStep::Weight() {
if (APConfiguration->Mark() > 8) return 0.9; else return 0.3;
}

bool attack_flowADVISE::EvilTwinSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::EvilTwinSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::EvilTwinSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::EvilTwinSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::EvilTwinSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::EvilTwinSuccessStep::preconditionsMet() {
return Key->Mark() && APHardware->Mark() && (APConfiguration->Mark()>6) && !MITM->Mark(); 
  return true;
}

void attack_flowADVISE::EvilTwinSuccessStep::executeEffects() {
MITM->Mark() = true;
}

double attack_flowADVISE::EvilTwinSuccessStep::getCost() {
return 6;
}

double attack_flowADVISE::EvilTwinSuccessStep::getOutcomeProbability() {
if (APConfiguration->Mark() > 8) return 0.9; else return 0.3;
}

double attack_flowADVISE::EvilTwinSuccessStep::getDetection() {
return 0.3;
}

/*====================== JoinNetworkSuccessStep ========================*/

attack_flowADVISE::JoinNetworkSuccessStep::JoinNetworkSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("JoinNetworkSuccessStep", 2, Deterministic, RaceEnabled, 13, 1, false);}

attack_flowADVISE::JoinNetworkSuccessStep::~JoinNetworkSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::JoinNetworkSuccessStep::LinkVariables() {
  NetworkAccess->Register(&NetworkAccess_Mobius_Mark);
  Key->Register(&Key_Mobius_Mark);
  JoinNetworkChosen->Register(&JoinNetworkChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::JoinNetworkSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(JoinNetworkChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::JoinNetworkSuccessStep::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::JoinNetworkSuccessStep::Weight() {
  return 1;
}

bool attack_flowADVISE::JoinNetworkSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::JoinNetworkSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::JoinNetworkSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::JoinNetworkSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::JoinNetworkSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::JoinNetworkSuccessStep::preconditionsMet() {
return Key->Mark() && !NetworkAccess->Mark();
  return true;
}

void attack_flowADVISE::JoinNetworkSuccessStep::executeEffects() {
NetworkAccess->Mark() = true;
}

double attack_flowADVISE::JoinNetworkSuccessStep::getCost() {
return 0;			
}

double attack_flowADVISE::JoinNetworkSuccessStep::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::JoinNetworkSuccessStep::getDetection() {
return 0.1;
}

/*====================== RogueAPFailureStep ========================*/

attack_flowADVISE::RogueAPFailureStep::RogueAPFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("RogueAPFailureStep", 3, Deterministic, RaceEnabled, 15, 1, false);}

attack_flowADVISE::RogueAPFailureStep::~RogueAPFailureStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::RogueAPFailureStep::LinkVariables() {
  Key->Register(&Key_Mobius_Mark);
  APHardware->Register(&APHardware_Mobius_Mark);
  APConfiguration->Register(&APConfiguration_Mobius_Mark);
  SSIDMACtargetnetwork->Register(&SSIDMACtargetnetwork_Mobius_Mark);
  RogueAPChosen->Register(&RogueAPChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::RogueAPFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(RogueAPChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::RogueAPFailureStep::timeDistributionParameter0() {
return 6;
}

double attack_flowADVISE::RogueAPFailureStep::Weight() {
if (APConfiguration->Mark()>8) return 0.2; else return 0.5;
}

bool attack_flowADVISE::RogueAPFailureStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::RogueAPFailureStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::RogueAPFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::RogueAPFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::RogueAPFailureStep::Rank() {
  return 1;
}

bool attack_flowADVISE::RogueAPFailureStep::preconditionsMet() {
return ((!Key->Mark()) && (SSIDMACtargetnetwork->Mark() && (APConfiguration->Mark()>6))&& (APHardware->Mark()));
  return true;
}

void attack_flowADVISE::RogueAPFailureStep::executeEffects() {
Key->Mark() = false;
}

double attack_flowADVISE::RogueAPFailureStep::getCost() {
return 4;
}

double attack_flowADVISE::RogueAPFailureStep::getOutcomeProbability() {
if (APConfiguration->Mark()>8) return 0.2; else return 0.5;
}

double attack_flowADVISE::RogueAPFailureStep::getDetection() {
return 0.7;
}

/*====================== RogueAPSuccessStep ========================*/

attack_flowADVISE::RogueAPSuccessStep::RogueAPSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("RogueAPSuccessStep", 3, Deterministic, RaceEnabled, 15, 1, false);}

attack_flowADVISE::RogueAPSuccessStep::~RogueAPSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::RogueAPSuccessStep::LinkVariables() {
  Key->Register(&Key_Mobius_Mark);
  APHardware->Register(&APHardware_Mobius_Mark);
  APConfiguration->Register(&APConfiguration_Mobius_Mark);
  SSIDMACtargetnetwork->Register(&SSIDMACtargetnetwork_Mobius_Mark);
  RogueAPChosen->Register(&RogueAPChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::RogueAPSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(RogueAPChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::RogueAPSuccessStep::timeDistributionParameter0() {
return 6;
}

double attack_flowADVISE::RogueAPSuccessStep::Weight() {
if (APConfiguration->Mark()>8) return 0.8; else return 0.5;
}

bool attack_flowADVISE::RogueAPSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::RogueAPSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::RogueAPSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::RogueAPSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::RogueAPSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::RogueAPSuccessStep::preconditionsMet() {
return ((!Key->Mark()) && (SSIDMACtargetnetwork->Mark() && (APConfiguration->Mark()>6))&& (APHardware->Mark()));
  return true;
}

void attack_flowADVISE::RogueAPSuccessStep::executeEffects() {
Key->Mark() = true;
}

double attack_flowADVISE::RogueAPSuccessStep::getCost() {
return 4;
}

double attack_flowADVISE::RogueAPSuccessStep::getOutcomeProbability() {
if (APConfiguration->Mark()>8) return 0.8; else return 0.5;
}

double attack_flowADVISE::RogueAPSuccessStep::getDetection() {
return 0.7;
}

/*====================== BlockTrafficFlowFailureStep ========================*/

attack_flowADVISE::BlockTrafficFlowFailureStep::BlockTrafficFlowFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("BlockTrafficFlowFailureStep", 4, Deterministic, RaceEnabled, 14, 1, false);}

attack_flowADVISE::BlockTrafficFlowFailureStep::~BlockTrafficFlowFailureStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::BlockTrafficFlowFailureStep::LinkVariables() {
  DOS->Register(&DOS_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  Hijacking->Register(&Hijacking_Mobius_Mark);
  BlockTrafficFlowChosen->Register(&BlockTrafficFlowChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::BlockTrafficFlowFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(BlockTrafficFlowChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::BlockTrafficFlowFailureStep::timeDistributionParameter0() {
return 2;
}

double attack_flowADVISE::BlockTrafficFlowFailureStep::Weight() {
return 0.1;
}

bool attack_flowADVISE::BlockTrafficFlowFailureStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::BlockTrafficFlowFailureStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::BlockTrafficFlowFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::BlockTrafficFlowFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::BlockTrafficFlowFailureStep::Rank() {
  return 1;
}

bool attack_flowADVISE::BlockTrafficFlowFailureStep::preconditionsMet() {
return ((Hijacking->Mark() || MITM->Mark()) && !DOS->Mark());
  return true;
}

void attack_flowADVISE::BlockTrafficFlowFailureStep::executeEffects() {
DOS->Mark() = false;
}

double attack_flowADVISE::BlockTrafficFlowFailureStep::getCost() {
return 3;
}

double attack_flowADVISE::BlockTrafficFlowFailureStep::getOutcomeProbability() {
return 0.1;
}

double attack_flowADVISE::BlockTrafficFlowFailureStep::getDetection() {
return 0.2;
}

/*====================== BlockTrafficFlowSuccessStep ========================*/

attack_flowADVISE::BlockTrafficFlowSuccessStep::BlockTrafficFlowSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("BlockTrafficFlowSuccessStep", 4, Deterministic, RaceEnabled, 14, 1, false);}

attack_flowADVISE::BlockTrafficFlowSuccessStep::~BlockTrafficFlowSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::BlockTrafficFlowSuccessStep::LinkVariables() {
  DOS->Register(&DOS_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  Hijacking->Register(&Hijacking_Mobius_Mark);
  BlockTrafficFlowChosen->Register(&BlockTrafficFlowChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::BlockTrafficFlowSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(BlockTrafficFlowChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::BlockTrafficFlowSuccessStep::timeDistributionParameter0() {
return 2;
}

double attack_flowADVISE::BlockTrafficFlowSuccessStep::Weight() {
return 0.9;
}

bool attack_flowADVISE::BlockTrafficFlowSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::BlockTrafficFlowSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::BlockTrafficFlowSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::BlockTrafficFlowSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::BlockTrafficFlowSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::BlockTrafficFlowSuccessStep::preconditionsMet() {
return ((Hijacking->Mark() || MITM->Mark()) && !DOS->Mark());
  return true;
}

void attack_flowADVISE::BlockTrafficFlowSuccessStep::executeEffects() {
DOS->Mark() = true;
}

double attack_flowADVISE::BlockTrafficFlowSuccessStep::getCost() {
return 3;
}

double attack_flowADVISE::BlockTrafficFlowSuccessStep::getOutcomeProbability() {
return 0.9;
}

double attack_flowADVISE::BlockTrafficFlowSuccessStep::getDetection() {
return 0.8;
}

/*====================== ApplicationLayerAttackFailureStep ========================*/

attack_flowADVISE::ApplicationLayerAttackFailureStep::ApplicationLayerAttackFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("ApplicationLayerAttackFailureStep", 5, Deterministic, RaceEnabled, 14, 1, false);}

attack_flowADVISE::ApplicationLayerAttackFailureStep::~ApplicationLayerAttackFailureStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::ApplicationLayerAttackFailureStep::LinkVariables() {
  SensitiveInformation->Register(&SensitiveInformation_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  NetworkHacking->Register(&NetworkHacking_Mobius_Mark);
  ApplicationLayerAttackChosen->Register(&ApplicationLayerAttackChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::ApplicationLayerAttackFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ApplicationLayerAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::ApplicationLayerAttackFailureStep::timeDistributionParameter0() {
return 7;
}

double attack_flowADVISE::ApplicationLayerAttackFailureStep::Weight() {
if (NetworkHacking->Mark()>9) return 0; else 0.1;
}

bool attack_flowADVISE::ApplicationLayerAttackFailureStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::ApplicationLayerAttackFailureStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::ApplicationLayerAttackFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::ApplicationLayerAttackFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::ApplicationLayerAttackFailureStep::Rank() {
  return 1;
}

bool attack_flowADVISE::ApplicationLayerAttackFailureStep::preconditionsMet() {
return (MITM->Mark() && !SensitiveInformation->Mark() && (NetworkHacking->Mark()>8));

  return true;
}

void attack_flowADVISE::ApplicationLayerAttackFailureStep::executeEffects() {
SensitiveInformation->Mark() = false;
}

double attack_flowADVISE::ApplicationLayerAttackFailureStep::getCost() {
return 10;
}

double attack_flowADVISE::ApplicationLayerAttackFailureStep::getOutcomeProbability() {
if (NetworkHacking->Mark()>9) return 0; else 0.1;
}

double attack_flowADVISE::ApplicationLayerAttackFailureStep::getDetection() {
if (NetworkHacking->Mark()>9) return 0.3; else 0.5;
}

/*====================== ApplicationLayerAttackSuccessStep ========================*/

attack_flowADVISE::ApplicationLayerAttackSuccessStep::ApplicationLayerAttackSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("ApplicationLayerAttackSuccessStep", 5, Deterministic, RaceEnabled, 14, 1, false);}

attack_flowADVISE::ApplicationLayerAttackSuccessStep::~ApplicationLayerAttackSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::ApplicationLayerAttackSuccessStep::LinkVariables() {
  SensitiveInformation->Register(&SensitiveInformation_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  NetworkHacking->Register(&NetworkHacking_Mobius_Mark);
  ApplicationLayerAttackChosen->Register(&ApplicationLayerAttackChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::ApplicationLayerAttackSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ApplicationLayerAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::ApplicationLayerAttackSuccessStep::timeDistributionParameter0() {
return 7;
}

double attack_flowADVISE::ApplicationLayerAttackSuccessStep::Weight() {
if (NetworkHacking->Mark()>9) return 1; else 0.9;
}

bool attack_flowADVISE::ApplicationLayerAttackSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::ApplicationLayerAttackSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::ApplicationLayerAttackSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::ApplicationLayerAttackSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::ApplicationLayerAttackSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::ApplicationLayerAttackSuccessStep::preconditionsMet() {
return (MITM->Mark() && !SensitiveInformation->Mark() && (NetworkHacking->Mark()>8));

  return true;
}

void attack_flowADVISE::ApplicationLayerAttackSuccessStep::executeEffects() {
SensitiveInformation->Mark() = true;
}

double attack_flowADVISE::ApplicationLayerAttackSuccessStep::getCost() {
return 10;
}

double attack_flowADVISE::ApplicationLayerAttackSuccessStep::getOutcomeProbability() {
if (NetworkHacking->Mark()>9) return 1; else 0.9;
}

double attack_flowADVISE::ApplicationLayerAttackSuccessStep::getDetection() {
if (NetworkHacking->Mark()>9) return 0; else 0.1;
}

/*====================== NetworkLayerAttackFailureStep ========================*/

attack_flowADVISE::NetworkLayerAttackFailureStep::NetworkLayerAttackFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkLayerAttackFailureStep", 6, Deterministic, RaceEnabled, 14, 1, false);}

attack_flowADVISE::NetworkLayerAttackFailureStep::~NetworkLayerAttackFailureStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::NetworkLayerAttackFailureStep::LinkVariables() {
  Hijacking->Register(&Hijacking_Mobius_Mark);
  NetworkAccess->Register(&NetworkAccess_Mobius_Mark);
  PacketForging->Register(&PacketForging_Mobius_Mark);
  NetworkLayerAttackChosen->Register(&NetworkLayerAttackChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::NetworkLayerAttackFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkLayerAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::NetworkLayerAttackFailureStep::timeDistributionParameter0() {
return 4;
}

double attack_flowADVISE::NetworkLayerAttackFailureStep::Weight() {
if( PacketForging->Mark()>9) return 0.1; else 0.3;
}

bool attack_flowADVISE::NetworkLayerAttackFailureStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::NetworkLayerAttackFailureStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::NetworkLayerAttackFailureStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::NetworkLayerAttackFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::NetworkLayerAttackFailureStep::Rank() {
  return 1;
}

bool attack_flowADVISE::NetworkLayerAttackFailureStep::preconditionsMet() {
return NetworkAccess->Mark() && !Hijacking->Mark() && (PacketForging->Mark()>7);
  return true;
}

void attack_flowADVISE::NetworkLayerAttackFailureStep::executeEffects() {
Hijacking->Mark() = true;
}

double attack_flowADVISE::NetworkLayerAttackFailureStep::getCost() {
return 4;
}

double attack_flowADVISE::NetworkLayerAttackFailureStep::getOutcomeProbability() {
if( PacketForging->Mark()>9) return 0.1; else 0.3;
}

double attack_flowADVISE::NetworkLayerAttackFailureStep::getDetection() {
return 0.3;
}

/*====================== NetworkLayerAttackSuccessStep ========================*/

attack_flowADVISE::NetworkLayerAttackSuccessStep::NetworkLayerAttackSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkLayerAttackSuccessStep", 6, Deterministic, RaceEnabled, 14, 1, false);}

attack_flowADVISE::NetworkLayerAttackSuccessStep::~NetworkLayerAttackSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::NetworkLayerAttackSuccessStep::LinkVariables() {
  Hijacking->Register(&Hijacking_Mobius_Mark);
  NetworkAccess->Register(&NetworkAccess_Mobius_Mark);
  PacketForging->Register(&PacketForging_Mobius_Mark);
  NetworkLayerAttackChosen->Register(&NetworkLayerAttackChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::NetworkLayerAttackSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkLayerAttackChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::NetworkLayerAttackSuccessStep::timeDistributionParameter0() {
return 4;
}

double attack_flowADVISE::NetworkLayerAttackSuccessStep::Weight() {
if (PacketForging->Mark()>9) return 0.9; else 0.7;
}

bool attack_flowADVISE::NetworkLayerAttackSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::NetworkLayerAttackSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::NetworkLayerAttackSuccessStep::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::NetworkLayerAttackSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::NetworkLayerAttackSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::NetworkLayerAttackSuccessStep::preconditionsMet() {
return NetworkAccess->Mark() && !Hijacking->Mark() && (PacketForging->Mark()>7);
  return true;
}

void attack_flowADVISE::NetworkLayerAttackSuccessStep::executeEffects() {
Hijacking->Mark() = false;
}

double attack_flowADVISE::NetworkLayerAttackSuccessStep::getCost() {
return 4;
}

double attack_flowADVISE::NetworkLayerAttackSuccessStep::getOutcomeProbability() {
if (PacketForging->Mark()>9) return 0.9; else 0.7;
}

double attack_flowADVISE::NetworkLayerAttackSuccessStep::getDetection() {
return 0.3;
}

/*====================== PasswordCaptureFailureStep ========================*/

attack_flowADVISE::PasswordCaptureFailureStep::PasswordCaptureFailureStep() {
  TheDistributionParameters = new double[1];
  commonInit("PasswordCaptureFailureStep", 7, Exponential, RaceEnabled, 14, 1, false);}

attack_flowADVISE::PasswordCaptureFailureStep::~PasswordCaptureFailureStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::PasswordCaptureFailureStep::LinkVariables() {
  Key->Register(&Key_Mobius_Mark);
  SocialEngineering->Register(&SocialEngineering_Mobius_Mark);
  NoKeyNoAccess->Register(&NoKeyNoAccess_Mobius_Mark);
  PasswordCaptureChosen->Register(&PasswordCaptureChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::PasswordCaptureFailureStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PasswordCaptureChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::PasswordCaptureFailureStep::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::PasswordCaptureFailureStep::Weight() {
if (SocialEngineering->Mark()>7) return 0.1; else return 0.7;
}

bool attack_flowADVISE::PasswordCaptureFailureStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::PasswordCaptureFailureStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::PasswordCaptureFailureStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::PasswordCaptureFailureStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::PasswordCaptureFailureStep::Rank() {
  return 1;
}

bool attack_flowADVISE::PasswordCaptureFailureStep::preconditionsMet() {
return ((!Key->Mark()) && (NoKeyNoAccess->Mark()) && ((SocialEngineering->Mark()>5)));
  return true;
}

void attack_flowADVISE::PasswordCaptureFailureStep::executeEffects() {
Key->Mark() = false;
}

double attack_flowADVISE::PasswordCaptureFailureStep::getCost() {
return 6;
}

double attack_flowADVISE::PasswordCaptureFailureStep::getOutcomeProbability() {
if (SocialEngineering->Mark()>7) return 0.1; else return 0.7;
}

double attack_flowADVISE::PasswordCaptureFailureStep::getDetection() {
return 0.5;
}

/*====================== PasswordCaptureSuccessStep ========================*/

attack_flowADVISE::PasswordCaptureSuccessStep::PasswordCaptureSuccessStep() {
  TheDistributionParameters = new double[1];
  commonInit("PasswordCaptureSuccessStep", 7, Exponential, RaceEnabled, 14, 1, false);}

attack_flowADVISE::PasswordCaptureSuccessStep::~PasswordCaptureSuccessStep() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::PasswordCaptureSuccessStep::LinkVariables() {
  Key->Register(&Key_Mobius_Mark);
  SocialEngineering->Register(&SocialEngineering_Mobius_Mark);
  NoKeyNoAccess->Register(&NoKeyNoAccess_Mobius_Mark);
  PasswordCaptureChosen->Register(&PasswordCaptureChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::PasswordCaptureSuccessStep::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PasswordCaptureChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::PasswordCaptureSuccessStep::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::PasswordCaptureSuccessStep::Weight() {
if (SocialEngineering->Mark()>7) return 0.9; else return 0.3;
}

bool attack_flowADVISE::PasswordCaptureSuccessStep::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::PasswordCaptureSuccessStep::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::PasswordCaptureSuccessStep::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::PasswordCaptureSuccessStep::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::PasswordCaptureSuccessStep::Rank() {
  return 1;
}

bool attack_flowADVISE::PasswordCaptureSuccessStep::preconditionsMet() {
return ((!Key->Mark()) && (NoKeyNoAccess->Mark()) && ((SocialEngineering->Mark()>5)));
  return true;
}

void attack_flowADVISE::PasswordCaptureSuccessStep::executeEffects() {
Key->Mark() = true;
}

double attack_flowADVISE::PasswordCaptureSuccessStep::getCost() {
return 6;
}

double attack_flowADVISE::PasswordCaptureSuccessStep::getOutcomeProbability() {
if (SocialEngineering->Mark()>7) return 0.9; else return 0.3;
}

double attack_flowADVISE::PasswordCaptureSuccessStep::getDetection() {
return 0.5;
}

/*====================== DoNothingOutcome1Step ========================*/

attack_flowADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 8, Deterministic, RaceEnabled, 11, 0, false);}

attack_flowADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::DoNothingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DoNothingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::DoNothingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::DoNothingOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::DoNothingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::DoNothingOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::DoNothingOutcome1Step::SampleDistribution() {
  return TheDistribution->Deterministic(timeDistributionParameter0());
}

double *attack_flowADVISE::DoNothingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::DoNothingOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::DoNothingOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::DoNothingOutcome1Step::executeEffects() {

}

double attack_flowADVISE::DoNothingOutcome1Step::getCost() {
return 0;
}

double attack_flowADVISE::DoNothingOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::DoNothingOutcome1Step::getDetection() {
return 0;
}

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== NetworkscanningAdversaryDecision ========================*/

attack_flowADVISE::NetworkscanningAdversaryDecision::NetworkscanningAdversaryDecision() {
  commonInit("NetworkscanningAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::NetworkscanningAdversaryDecision::~NetworkscanningAdversaryDecision() {
}

void attack_flowADVISE::NetworkscanningAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  NetworkscanningChosen->Register(&NetworkscanningChosen_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
}

bool attack_flowADVISE::NetworkscanningAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::NetworkscanningAdversaryDecision::Weight() {
  return NetworkscanningWeight->Mark();
}

bool attack_flowADVISE::NetworkscanningAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::NetworkscanningAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::NetworkscanningAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::NetworkscanningAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::NetworkscanningAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::NetworkscanningAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(NetworkscanningWeight_Mobius_Mark))--;
  (*(NetworkscanningChosen_Mobius_Mark))++;
  return this;
}

/*====================== EvilTwinAdversaryDecision ========================*/

attack_flowADVISE::EvilTwinAdversaryDecision::EvilTwinAdversaryDecision() {
  commonInit("EvilTwinAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::EvilTwinAdversaryDecision::~EvilTwinAdversaryDecision() {
}

void attack_flowADVISE::EvilTwinAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  EvilTwinChosen->Register(&EvilTwinChosen_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
}

bool attack_flowADVISE::EvilTwinAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::EvilTwinAdversaryDecision::Weight() {
  return EvilTwinWeight->Mark();
}

bool attack_flowADVISE::EvilTwinAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::EvilTwinAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::EvilTwinAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::EvilTwinAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::EvilTwinAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::EvilTwinAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(EvilTwinWeight_Mobius_Mark))--;
  (*(EvilTwinChosen_Mobius_Mark))++;
  return this;
}

/*====================== JoinNetworkAdversaryDecision ========================*/

attack_flowADVISE::JoinNetworkAdversaryDecision::JoinNetworkAdversaryDecision() {
  commonInit("JoinNetworkAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::JoinNetworkAdversaryDecision::~JoinNetworkAdversaryDecision() {
}

void attack_flowADVISE::JoinNetworkAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  JoinNetworkChosen->Register(&JoinNetworkChosen_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
}

bool attack_flowADVISE::JoinNetworkAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::JoinNetworkAdversaryDecision::Weight() {
  return JoinNetworkWeight->Mark();
}

bool attack_flowADVISE::JoinNetworkAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::JoinNetworkAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::JoinNetworkAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::JoinNetworkAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::JoinNetworkAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::JoinNetworkAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(JoinNetworkWeight_Mobius_Mark))--;
  (*(JoinNetworkChosen_Mobius_Mark))++;
  return this;
}

/*====================== RogueAPAdversaryDecision ========================*/

attack_flowADVISE::RogueAPAdversaryDecision::RogueAPAdversaryDecision() {
  commonInit("RogueAPAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::RogueAPAdversaryDecision::~RogueAPAdversaryDecision() {
}

void attack_flowADVISE::RogueAPAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  RogueAPChosen->Register(&RogueAPChosen_Mobius_Mark);
  RogueAPWeight->Register(&RogueAPWeight_Mobius_Mark);
}

bool attack_flowADVISE::RogueAPAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::RogueAPAdversaryDecision::Weight() {
  return RogueAPWeight->Mark();
}

bool attack_flowADVISE::RogueAPAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::RogueAPAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::RogueAPAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::RogueAPAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::RogueAPAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::RogueAPAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(RogueAPWeight_Mobius_Mark))--;
  (*(RogueAPChosen_Mobius_Mark))++;
  return this;
}

/*====================== BlockTrafficFlowAdversaryDecision ========================*/

attack_flowADVISE::BlockTrafficFlowAdversaryDecision::BlockTrafficFlowAdversaryDecision() {
  commonInit("BlockTrafficFlowAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::BlockTrafficFlowAdversaryDecision::~BlockTrafficFlowAdversaryDecision() {
}

void attack_flowADVISE::BlockTrafficFlowAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  BlockTrafficFlowChosen->Register(&BlockTrafficFlowChosen_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
}

bool attack_flowADVISE::BlockTrafficFlowAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::BlockTrafficFlowAdversaryDecision::Weight() {
  return BlockTrafficFlowWeight->Mark();
}

bool attack_flowADVISE::BlockTrafficFlowAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::BlockTrafficFlowAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::BlockTrafficFlowAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::BlockTrafficFlowAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::BlockTrafficFlowAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::BlockTrafficFlowAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(BlockTrafficFlowWeight_Mobius_Mark))--;
  (*(BlockTrafficFlowChosen_Mobius_Mark))++;
  return this;
}

/*====================== ApplicationLayerAttackAdversaryDecision ========================*/

attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::ApplicationLayerAttackAdversaryDecision() {
  commonInit("ApplicationLayerAttackAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::~ApplicationLayerAttackAdversaryDecision() {
}

void attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ApplicationLayerAttackChosen->Register(&ApplicationLayerAttackChosen_Mobius_Mark);
  ApplicationLayerAttackWeight->Register(&ApplicationLayerAttackWeight_Mobius_Mark);
}

bool attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::Weight() {
  return ApplicationLayerAttackWeight->Mark();
}

bool attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::ApplicationLayerAttackAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ApplicationLayerAttackWeight_Mobius_Mark))--;
  (*(ApplicationLayerAttackChosen_Mobius_Mark))++;
  return this;
}

/*====================== NetworkLayerAttackAdversaryDecision ========================*/

attack_flowADVISE::NetworkLayerAttackAdversaryDecision::NetworkLayerAttackAdversaryDecision() {
  commonInit("NetworkLayerAttackAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::NetworkLayerAttackAdversaryDecision::~NetworkLayerAttackAdversaryDecision() {
}

void attack_flowADVISE::NetworkLayerAttackAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  NetworkLayerAttackChosen->Register(&NetworkLayerAttackChosen_Mobius_Mark);
  NetworkLayerAttackWeight->Register(&NetworkLayerAttackWeight_Mobius_Mark);
}

bool attack_flowADVISE::NetworkLayerAttackAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::NetworkLayerAttackAdversaryDecision::Weight() {
  return NetworkLayerAttackWeight->Mark();
}

bool attack_flowADVISE::NetworkLayerAttackAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::NetworkLayerAttackAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::NetworkLayerAttackAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::NetworkLayerAttackAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::NetworkLayerAttackAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::NetworkLayerAttackAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(NetworkLayerAttackWeight_Mobius_Mark))--;
  (*(NetworkLayerAttackChosen_Mobius_Mark))++;
  return this;
}

/*====================== PasswordCaptureAdversaryDecision ========================*/

attack_flowADVISE::PasswordCaptureAdversaryDecision::PasswordCaptureAdversaryDecision() {
  commonInit("PasswordCaptureAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::PasswordCaptureAdversaryDecision::~PasswordCaptureAdversaryDecision() {
}

void attack_flowADVISE::PasswordCaptureAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  PasswordCaptureChosen->Register(&PasswordCaptureChosen_Mobius_Mark);
  PasswordCaptureWeight->Register(&PasswordCaptureWeight_Mobius_Mark);
}

bool attack_flowADVISE::PasswordCaptureAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::PasswordCaptureAdversaryDecision::Weight() {
  return PasswordCaptureWeight->Mark();
}

bool attack_flowADVISE::PasswordCaptureAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::PasswordCaptureAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::PasswordCaptureAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::PasswordCaptureAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::PasswordCaptureAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::PasswordCaptureAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(PasswordCaptureWeight_Mobius_Mark))--;
  (*(PasswordCaptureChosen_Mobius_Mark))++;
  return this;
}

/*====================== DoNothingAdversaryDecision ========================*/

attack_flowADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 9, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::DoNothingAdversaryDecision::~DoNothingAdversaryDecision() {
}

void attack_flowADVISE::DoNothingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
}

bool attack_flowADVISE::DoNothingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::DoNothingAdversaryDecision::Weight() {
  return DoNothingWeight->Mark();
}

bool attack_flowADVISE::DoNothingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::DoNothingAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::DoNothingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::DoNothingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::DoNothingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::DoNothingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DoNothingWeight_Mobius_Mark))--;
  (*(DoNothingChosen_Mobius_Mark))++;
  return this;
}

