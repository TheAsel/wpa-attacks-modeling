
#include "Atomic/attack_flow/attack_flowADVISE.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


attack_flowADVISE::attack_flowADVISE() {
  DNSSpoofingAD.setParent(this);
  ARPSpoofingAD.setParent(this);
  DecryptionAD.setParent(this);
  NetworkscanningAD.setParent(this);
  SSLStrippingAD.setParent(this);
  DoNothingAD.setParent(this);
  JoinNetworkAD.setParent(this);
  RogueAccessPointAD.setParent(this);
  EvilTwinAD.setParent(this);
  BlockTrafficFlowAD.setParent(this);
  PhishingAD.setParent(this);
  DNSSpoofingOutcome1.setParent(this);
  ARPSpoofingOutcome1.setParent(this);
  DecryptionOutcome1.setParent(this);
  NetworkscanningOutcome1.setParent(this);
  SSLStrippingOutcome1.setParent(this);
  DoNothingOutcome1.setParent(this);
  JoinNetworkOutcome1.setParent(this);
  RogueAccessPointOutcome1.setParent(this);
  EvilTwinOutcome1.setParent(this);
  BlockTrafficFlowOutcome1.setParent(this);
  PhishingOutcome1.setParent(this);
  AdversaryDecisionGroup.initialize(11, "AdversaryDecisionGroup");
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DNSSpoofingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &ARPSpoofingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DecryptionAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &NetworkscanningAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &SSLStrippingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &DoNothingAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &JoinNetworkAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &RogueAccessPointAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &EvilTwinAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &BlockTrafficFlowAD);
  AdversaryDecisionGroup.appendGroup((BaseGroupClass*) &PhishingAD);

  BaseADVISEAction* InitialActions[22] = {
    &DNSSpoofingAD, // 0
    &ARPSpoofingAD, // 1
    &DecryptionAD, // 2
    &NetworkscanningAD, // 3
    &SSLStrippingAD, // 4
    &DoNothingAD, // 5
    &JoinNetworkAD, // 6
    &RogueAccessPointAD, // 7
    &EvilTwinAD, // 8
    &BlockTrafficFlowAD, // 9
    &PhishingAD, // 10
    &DNSSpoofingOutcome1, // 11
    &ARPSpoofingOutcome1, // 12
    &DecryptionOutcome1, // 13
    &NetworkscanningOutcome1, // 14
    &SSLStrippingOutcome1, // 15
    &DoNothingOutcome1, // 16
    &JoinNetworkOutcome1, // 17
    &RogueAccessPointOutcome1, // 18
    &EvilTwinOutcome1, // 19
    &BlockTrafficFlowOutcome1, // 20
    &PhishingOutcome1 // 21
  };

  Step* InitialSteps[11] = {
      &DNSSpoofingOutcome1,
      &ARPSpoofingOutcome1,
      &DecryptionOutcome1,
      &NetworkscanningOutcome1,
      &SSLStrippingOutcome1,
      &DoNothingOutcome1,
      &JoinNetworkOutcome1,
      &RogueAccessPointOutcome1,
      &EvilTwinOutcome1,
      &BlockTrafficFlowOutcome1,
      &PhishingOutcome1
  };

  BaseGroupClass* InitialGroups[12] = {
    (BaseGroupClass*) &DNSSpoofingOutcome1, // 0
    (BaseGroupClass*) &ARPSpoofingOutcome1, // 1
    (BaseGroupClass*) &DecryptionOutcome1, // 2
    (BaseGroupClass*) &NetworkscanningOutcome1, // 3
    (BaseGroupClass*) &SSLStrippingOutcome1, // 4
    (BaseGroupClass*) &DoNothingOutcome1, // 5
    (BaseGroupClass*) &JoinNetworkOutcome1, // 6
    (BaseGroupClass*) &RogueAccessPointOutcome1, // 7
    (BaseGroupClass*) &EvilTwinOutcome1, // 8
    (BaseGroupClass*) &BlockTrafficFlowOutcome1, // 9
    (BaseGroupClass*) &PhishingOutcome1, // 10
    (BaseGroupClass*) &AdversaryDecisionGroup
  };

  APHardware = new Access("APHardware", 0);
  NoKey/NoAccess = new Knowledge("NoKey/NoAccess", 0);
  KeyedClientSessionHijacking = new Knowledge("KeyedClientSessionHijacking", 0);
  MITM = new Knowledge("MITM", 0);
  NetworkJoined = new Knowledge("NetworkJoined", 0);
  KeyAcquisition = new Knowledge("KeyAcquisition", 0);
  SSIDMACtargetnetwork = new Knowledge("SSIDMACtargetnetwork", 0);
  DNSpacketforging = new Skill("DNSpacketforging", 0);
  ARPpacketforging = new Skill("ARPpacketforging", 0);
  Phishing = new Skill("Phishing", 0);
  NetworkScanning = new Skill("NetworkScanning", 0);
  Deception = new Goal("Deception", 0);
  Deception->setPayoff(0);
  StolenInformation = new Goal("StolenInformation", 0);
  StolenInformation->setPayoff(0);
  DoS = new Goal("DoS", 0);
  DoS->setPayoff(0);
  MakeDecision = new BeginAdversaryDecision("MakeDecision", 0);
  DNSSpoofingWeight = new StepWeight("DNSSpoofingWeight", 0);
  DNSSpoofingChosen = new StepChosen("DNSSpoofingChosen", 0);
  ARPSpoofingWeight = new StepWeight("ARPSpoofingWeight", 0);
  ARPSpoofingChosen = new StepChosen("ARPSpoofingChosen", 0);
  DecryptionWeight = new StepWeight("DecryptionWeight", 0);
  DecryptionChosen = new StepChosen("DecryptionChosen", 0);
  NetworkscanningWeight = new StepWeight("NetworkscanningWeight", 0);
  NetworkscanningChosen = new StepChosen("NetworkscanningChosen", 0);
  SSLStrippingWeight = new StepWeight("SSLStrippingWeight", 0);
  SSLStrippingChosen = new StepChosen("SSLStrippingChosen", 0);
  DoNothingWeight = new StepWeight("DoNothingWeight", 0);
  DoNothingChosen = new StepChosen("DoNothingChosen", 0);
  JoinNetworkWeight = new StepWeight("JoinNetworkWeight", 0);
  JoinNetworkChosen = new StepChosen("JoinNetworkChosen", 0);
  RogueAccessPointWeight = new StepWeight("RogueAccessPointWeight", 0);
  RogueAccessPointChosen = new StepChosen("RogueAccessPointChosen", 0);
  EvilTwinWeight = new StepWeight("EvilTwinWeight", 0);
  EvilTwinChosen = new StepChosen("EvilTwinChosen", 0);
  BlockTrafficFlowWeight = new StepWeight("BlockTrafficFlowWeight", 0);
  BlockTrafficFlowChosen = new StepChosen("BlockTrafficFlowChosen", 0);
  PhishingWeight = new StepWeight("PhishingWeight", 0);
  PhishingChosen = new StepChosen("PhishingChosen", 0);

  Goal* InitialGoals[3] = {
      Deception,
      StolenInformation,
      DoS
  };

  ADVISEStateVariable* InitialSVs[37] = {
    APHardware, // 0
    NoKey/NoAccess, // 1
    KeyedClientSessionHijacking, // 2
    MITM, // 3
    NetworkJoined, // 4
    KeyAcquisition, // 5
    SSIDMACtargetnetwork, // 6
    DNSpacketforging, // 7
    ARPpacketforging, // 8
    Phishing, // 9
    NetworkScanning, // 10
    Deception, // 11
    StolenInformation, // 12
    DoS, // 13
    DNSSpoofingChosen, // 14
    ARPSpoofingChosen, // 15
    DecryptionChosen, // 16
    NetworkscanningChosen, // 17
    SSLStrippingChosen, // 18
    DoNothingChosen, // 19
    JoinNetworkChosen, // 20
    RogueAccessPointChosen, // 21
    EvilTwinChosen, // 22
    BlockTrafficFlowChosen, // 23
    PhishingChosen, // 24
    DNSSpoofingWeight, // 25
    ARPSpoofingWeight, // 26
    DecryptionWeight, // 27
    NetworkscanningWeight, // 28
    SSLStrippingWeight, // 29
    DoNothingWeight, // 30
    JoinNetworkWeight, // 31
    RogueAccessPointWeight, // 32
    EvilTwinWeight, // 33
    BlockTrafficFlowWeight, // 34
    PhishingWeight, // 35
    MakeDecision // 36
};

  int outCounts[11] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

  commonInit("attack_flow", 37, InitialSVs, 22, InitialActions, 12, InitialGroups, 11, outCounts, InitialSteps, 3, InitialGoals);

  advCostPref = 0.1;
  advDetectPref = 0.1;
  advPayPref = 0.8;

  planningHorizon = 1;
  costDiscount = 1.0;
  detectionDiscount = 1.0;
  payoffDiscount = 1.0;

  assignSVsToAttackSteps();

  int AffectArcs[201][2] = {
    {36,0}, {14,0}, {25,0}, {36,1}, {15,1}, {26,1}, {36,2}, {16,2}, 
    {27,2}, {36,3}, {17,3}, {28,3}, {36,4}, {18,4}, {29,4}, {36,5}, 
    {19,5}, {30,5}, {36,6}, {20,6}, {31,6}, {36,7}, {21,7}, {32,7}, 
    {36,8}, {22,8}, {33,8}, {36,9}, {23,9}, {34,9}, {36,10}, {24,10}, 
    {35,10}, {36,11}, {14,11}, {25,11}, {26,11}, {27,11}, {28,11}, {29,11}, 
    {30,11}, {31,11}, {32,11}, {33,11}, {34,11}, {35,11}, {13,11}, {11,11}, 
    {3,11}, {36,12}, {15,12}, {25,12}, {26,12}, {27,12}, {28,12}, {29,12}, 
    {30,12}, {31,12}, {32,12}, {33,12}, {34,12}, {35,12}, {2,12}, {3,12}, 
    {4,12}, {36,13}, {16,13}, {25,13}, {26,13}, {27,13}, {28,13}, {29,13}, 
    {30,13}, {31,13}, {32,13}, {33,13}, {34,13}, {35,13}, {12,13}, {3,13}, 
    {36,14}, {17,14}, {25,14}, {26,14}, {27,14}, {28,14}, {29,14}, {30,14}, 
    {31,14}, {32,14}, {33,14}, {34,14}, {35,14}, {6,14}, {1,14}, {36,15}, 
    {18,15}, {25,15}, {26,15}, {27,15}, {28,15}, {29,15}, {30,15}, {31,15}, 
    {32,15}, {33,15}, {34,15}, {35,15}, {12,15}, {3,15}, {36,16}, {19,16}, 
    {25,16}, {26,16}, {27,16}, {28,16}, {29,16}, {30,16}, {31,16}, {32,16}, 
    {33,16}, {34,16}, {35,16}, {36,17}, {20,17}, {25,17}, {26,17}, {27,17}, 
    {28,17}, {29,17}, {30,17}, {31,17}, {32,17}, {33,17}, {34,17}, {35,17}, 
    {4,17}, {5,17}, {36,18}, {21,18}, {25,18}, {26,18}, {27,18}, {28,18}, 
    {29,18}, {30,18}, {31,18}, {32,18}, {33,18}, {34,18}, {35,18}, {5,18}, 
    {1,18}, {0,18}, {6,18}, {36,19}, {22,19}, {25,19}, {26,19}, {27,19}, 
    {28,19}, {29,19}, {30,19}, {31,19}, {32,19}, {33,19}, {34,19}, {35,19}, 
    {3,19}, {5,19}, {36,20}, {23,20}, {25,20}, {26,20}, {27,20}, {28,20}, 
    {29,20}, {30,20}, {31,20}, {32,20}, {33,20}, {34,20}, {35,20}, {13,20}, 
    {2,20}, {3,20}, {36,21}, {24,21}, {25,21}, {26,21}, {27,21}, {28,21}, 
    {29,21}, {30,21}, {31,21}, {32,21}, {33,21}, {34,21}, {35,21}, {12,21}, 
    {11,21}
};
  for(int n = 0; n < 201;n++)
    AddAffectArc(InitialSVs[AffectArcs[n][0]], InitialActions[AffectArcs[n][1]]);
  int EnableArcs[33][2] = {
    {36,0}, {36,1}, {36,2}, {36,3}, {36,4}, {36,5}, {36,6}, {36,7}, 
    {36,8}, {36,9}, {36,10}, {14,11}, {13,11}, {11,11}, {15,12}, {2,12}, 
    {16,13}, {12,13}, {17,14}, {6,14}, {18,15}, {12,15}, {19,16}, {20,17}, 
    {4,17}, {21,18}, {5,18}, {22,19}, {3,19}, {23,20}, {13,20}, {24,21}, 
    {12,21}
};
  for(int n = 0; n < 33;n++)
    AddEnableArc(InitialSVs[EnableArcs[n][0]], InitialActions[EnableArcs[n][1]]);
  for(int x = 0; x < 22; x++) {
    InitialActions[x]->LinkVariables();
  }

  customInitialization();

  recalculateAdversaryDecisionWeights();

}

attack_flowADVISE::~attack_flowADVISE() {
}

void attack_flowADVISE::assignSVsToAttackSteps() {
  DNSSpoofingOutcome1.DoS = DoS;
  DNSSpoofingOutcome1.Deception = Deception;
  DNSSpoofingOutcome1.DNSpacketforging = DNSpacketforging;
  DNSSpoofingOutcome1.MITM = MITM;
  DNSSpoofingOutcome1.DNSSpoofingChosen = DNSSpoofingChosen;
  DNSSpoofingOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  DNSSpoofingOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  DNSSpoofingOutcome1.DecryptionWeight = DecryptionWeight;
  DNSSpoofingOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  DNSSpoofingOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  DNSSpoofingOutcome1.DoNothingWeight = DoNothingWeight;
  DNSSpoofingOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  DNSSpoofingOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  DNSSpoofingOutcome1.EvilTwinWeight = EvilTwinWeight;
  DNSSpoofingOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  DNSSpoofingOutcome1.PhishingWeight = PhishingWeight;
  DNSSpoofingOutcome1.MakeDecision = MakeDecision;
  DNSSpoofingOutcome1.setSVs(DNSSpoofingChosen, DNSSpoofingWeight);
  ARPSpoofingOutcome1.KeyedClientSessionHijacking = KeyedClientSessionHijacking;
  ARPSpoofingOutcome1.MITM = MITM;
  ARPSpoofingOutcome1.ARPpacketforging = ARPpacketforging;
  ARPSpoofingOutcome1.NetworkJoined = NetworkJoined;
  ARPSpoofingOutcome1.ARPSpoofingChosen = ARPSpoofingChosen;
  ARPSpoofingOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  ARPSpoofingOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  ARPSpoofingOutcome1.DecryptionWeight = DecryptionWeight;
  ARPSpoofingOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  ARPSpoofingOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  ARPSpoofingOutcome1.DoNothingWeight = DoNothingWeight;
  ARPSpoofingOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  ARPSpoofingOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  ARPSpoofingOutcome1.EvilTwinWeight = EvilTwinWeight;
  ARPSpoofingOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  ARPSpoofingOutcome1.PhishingWeight = PhishingWeight;
  ARPSpoofingOutcome1.MakeDecision = MakeDecision;
  ARPSpoofingOutcome1.setSVs(ARPSpoofingChosen, ARPSpoofingWeight);
  DecryptionOutcome1.StolenInformation = StolenInformation;
  DecryptionOutcome1.MITM = MITM;
  DecryptionOutcome1.DecryptionChosen = DecryptionChosen;
  DecryptionOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  DecryptionOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  DecryptionOutcome1.DecryptionWeight = DecryptionWeight;
  DecryptionOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  DecryptionOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  DecryptionOutcome1.DoNothingWeight = DoNothingWeight;
  DecryptionOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  DecryptionOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  DecryptionOutcome1.EvilTwinWeight = EvilTwinWeight;
  DecryptionOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  DecryptionOutcome1.PhishingWeight = PhishingWeight;
  DecryptionOutcome1.MakeDecision = MakeDecision;
  DecryptionOutcome1.setSVs(DecryptionChosen, DecryptionWeight);
  NetworkscanningOutcome1.SSIDMACtargetnetwork = SSIDMACtargetnetwork;
  NetworkscanningOutcome1.NoKey/NoAccess = NoKey/NoAccess;
  NetworkscanningOutcome1.NetworkscanningChosen = NetworkscanningChosen;
  NetworkscanningOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  NetworkscanningOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  NetworkscanningOutcome1.DecryptionWeight = DecryptionWeight;
  NetworkscanningOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  NetworkscanningOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  NetworkscanningOutcome1.DoNothingWeight = DoNothingWeight;
  NetworkscanningOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  NetworkscanningOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  NetworkscanningOutcome1.EvilTwinWeight = EvilTwinWeight;
  NetworkscanningOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  NetworkscanningOutcome1.PhishingWeight = PhishingWeight;
  NetworkscanningOutcome1.MakeDecision = MakeDecision;
  NetworkscanningOutcome1.setSVs(NetworkscanningChosen, NetworkscanningWeight);
  SSLStrippingOutcome1.StolenInformation = StolenInformation;
  SSLStrippingOutcome1.MITM = MITM;
  SSLStrippingOutcome1.Phishing = Phishing;
  SSLStrippingOutcome1.SSLStrippingChosen = SSLStrippingChosen;
  SSLStrippingOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  SSLStrippingOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  SSLStrippingOutcome1.DecryptionWeight = DecryptionWeight;
  SSLStrippingOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  SSLStrippingOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  SSLStrippingOutcome1.DoNothingWeight = DoNothingWeight;
  SSLStrippingOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  SSLStrippingOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  SSLStrippingOutcome1.EvilTwinWeight = EvilTwinWeight;
  SSLStrippingOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  SSLStrippingOutcome1.PhishingWeight = PhishingWeight;
  SSLStrippingOutcome1.MakeDecision = MakeDecision;
  SSLStrippingOutcome1.setSVs(SSLStrippingChosen, SSLStrippingWeight);
  DoNothingOutcome1.DoNothingChosen = DoNothingChosen;
  DoNothingOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  DoNothingOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  DoNothingOutcome1.DecryptionWeight = DecryptionWeight;
  DoNothingOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  DoNothingOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  DoNothingOutcome1.DoNothingWeight = DoNothingWeight;
  DoNothingOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  DoNothingOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  DoNothingOutcome1.EvilTwinWeight = EvilTwinWeight;
  DoNothingOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  DoNothingOutcome1.PhishingWeight = PhishingWeight;
  DoNothingOutcome1.MakeDecision = MakeDecision;
  DoNothingOutcome1.setSVs(DoNothingChosen, DoNothingWeight);
  JoinNetworkOutcome1.NetworkJoined = NetworkJoined;
  JoinNetworkOutcome1.KeyAcquisition = KeyAcquisition;
  JoinNetworkOutcome1.JoinNetworkChosen = JoinNetworkChosen;
  JoinNetworkOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  JoinNetworkOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  JoinNetworkOutcome1.DecryptionWeight = DecryptionWeight;
  JoinNetworkOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  JoinNetworkOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  JoinNetworkOutcome1.DoNothingWeight = DoNothingWeight;
  JoinNetworkOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  JoinNetworkOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  JoinNetworkOutcome1.EvilTwinWeight = EvilTwinWeight;
  JoinNetworkOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  JoinNetworkOutcome1.PhishingWeight = PhishingWeight;
  JoinNetworkOutcome1.MakeDecision = MakeDecision;
  JoinNetworkOutcome1.setSVs(JoinNetworkChosen, JoinNetworkWeight);
  RogueAccessPointOutcome1.KeyAcquisition = KeyAcquisition;
  RogueAccessPointOutcome1.NoKey/NoAccess = NoKey/NoAccess;
  RogueAccessPointOutcome1.NetworkScanning = NetworkScanning;
  RogueAccessPointOutcome1.APHardware = APHardware;
  RogueAccessPointOutcome1.SSIDMACtargetnetwork = SSIDMACtargetnetwork;
  RogueAccessPointOutcome1.RogueAccessPointChosen = RogueAccessPointChosen;
  RogueAccessPointOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  RogueAccessPointOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  RogueAccessPointOutcome1.DecryptionWeight = DecryptionWeight;
  RogueAccessPointOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  RogueAccessPointOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  RogueAccessPointOutcome1.DoNothingWeight = DoNothingWeight;
  RogueAccessPointOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  RogueAccessPointOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  RogueAccessPointOutcome1.EvilTwinWeight = EvilTwinWeight;
  RogueAccessPointOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  RogueAccessPointOutcome1.PhishingWeight = PhishingWeight;
  RogueAccessPointOutcome1.MakeDecision = MakeDecision;
  RogueAccessPointOutcome1.setSVs(RogueAccessPointChosen, RogueAccessPointWeight);
  EvilTwinOutcome1.MITM = MITM;
  EvilTwinOutcome1.KeyAcquisition = KeyAcquisition;
  EvilTwinOutcome1.EvilTwinChosen = EvilTwinChosen;
  EvilTwinOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  EvilTwinOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  EvilTwinOutcome1.DecryptionWeight = DecryptionWeight;
  EvilTwinOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  EvilTwinOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  EvilTwinOutcome1.DoNothingWeight = DoNothingWeight;
  EvilTwinOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  EvilTwinOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  EvilTwinOutcome1.EvilTwinWeight = EvilTwinWeight;
  EvilTwinOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  EvilTwinOutcome1.PhishingWeight = PhishingWeight;
  EvilTwinOutcome1.MakeDecision = MakeDecision;
  EvilTwinOutcome1.setSVs(EvilTwinChosen, EvilTwinWeight);
  BlockTrafficFlowOutcome1.DoS = DoS;
  BlockTrafficFlowOutcome1.KeyedClientSessionHijacking = KeyedClientSessionHijacking;
  BlockTrafficFlowOutcome1.MITM = MITM;
  BlockTrafficFlowOutcome1.BlockTrafficFlowChosen = BlockTrafficFlowChosen;
  BlockTrafficFlowOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  BlockTrafficFlowOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  BlockTrafficFlowOutcome1.DecryptionWeight = DecryptionWeight;
  BlockTrafficFlowOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  BlockTrafficFlowOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  BlockTrafficFlowOutcome1.DoNothingWeight = DoNothingWeight;
  BlockTrafficFlowOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  BlockTrafficFlowOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  BlockTrafficFlowOutcome1.EvilTwinWeight = EvilTwinWeight;
  BlockTrafficFlowOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  BlockTrafficFlowOutcome1.PhishingWeight = PhishingWeight;
  BlockTrafficFlowOutcome1.MakeDecision = MakeDecision;
  BlockTrafficFlowOutcome1.setSVs(BlockTrafficFlowChosen, BlockTrafficFlowWeight);
  PhishingOutcome1.StolenInformation = StolenInformation;
  PhishingOutcome1.Deception = Deception;
  PhishingOutcome1.PhishingChosen = PhishingChosen;
  PhishingOutcome1.DNSSpoofingWeight = DNSSpoofingWeight;
  PhishingOutcome1.ARPSpoofingWeight = ARPSpoofingWeight;
  PhishingOutcome1.DecryptionWeight = DecryptionWeight;
  PhishingOutcome1.NetworkscanningWeight = NetworkscanningWeight;
  PhishingOutcome1.SSLStrippingWeight = SSLStrippingWeight;
  PhishingOutcome1.DoNothingWeight = DoNothingWeight;
  PhishingOutcome1.JoinNetworkWeight = JoinNetworkWeight;
  PhishingOutcome1.RogueAccessPointWeight = RogueAccessPointWeight;
  PhishingOutcome1.EvilTwinWeight = EvilTwinWeight;
  PhishingOutcome1.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  PhishingOutcome1.PhishingWeight = PhishingWeight;
  PhishingOutcome1.MakeDecision = MakeDecision;
  PhishingOutcome1.setSVs(PhishingChosen, PhishingWeight);

  DNSSpoofingAD.MakeDecision = MakeDecision;
  DNSSpoofingAD.DNSSpoofingChosen = DNSSpoofingChosen;
  DNSSpoofingAD.DNSSpoofingWeight = DNSSpoofingWeight;
  ARPSpoofingAD.MakeDecision = MakeDecision;
  ARPSpoofingAD.ARPSpoofingChosen = ARPSpoofingChosen;
  ARPSpoofingAD.ARPSpoofingWeight = ARPSpoofingWeight;
  DecryptionAD.MakeDecision = MakeDecision;
  DecryptionAD.DecryptionChosen = DecryptionChosen;
  DecryptionAD.DecryptionWeight = DecryptionWeight;
  NetworkscanningAD.MakeDecision = MakeDecision;
  NetworkscanningAD.NetworkscanningChosen = NetworkscanningChosen;
  NetworkscanningAD.NetworkscanningWeight = NetworkscanningWeight;
  SSLStrippingAD.MakeDecision = MakeDecision;
  SSLStrippingAD.SSLStrippingChosen = SSLStrippingChosen;
  SSLStrippingAD.SSLStrippingWeight = SSLStrippingWeight;
  DoNothingAD.MakeDecision = MakeDecision;
  DoNothingAD.DoNothingChosen = DoNothingChosen;
  DoNothingAD.DoNothingWeight = DoNothingWeight;
  JoinNetworkAD.MakeDecision = MakeDecision;
  JoinNetworkAD.JoinNetworkChosen = JoinNetworkChosen;
  JoinNetworkAD.JoinNetworkWeight = JoinNetworkWeight;
  RogueAccessPointAD.MakeDecision = MakeDecision;
  RogueAccessPointAD.RogueAccessPointChosen = RogueAccessPointChosen;
  RogueAccessPointAD.RogueAccessPointWeight = RogueAccessPointWeight;
  EvilTwinAD.MakeDecision = MakeDecision;
  EvilTwinAD.EvilTwinChosen = EvilTwinChosen;
  EvilTwinAD.EvilTwinWeight = EvilTwinWeight;
  BlockTrafficFlowAD.MakeDecision = MakeDecision;
  BlockTrafficFlowAD.BlockTrafficFlowChosen = BlockTrafficFlowChosen;
  BlockTrafficFlowAD.BlockTrafficFlowWeight = BlockTrafficFlowWeight;
  PhishingAD.MakeDecision = MakeDecision;
  PhishingAD.PhishingChosen = PhishingChosen;
  PhishingAD.PhishingWeight = PhishingWeight;
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

/*====================== DNSSpoofingOutcome1Step ========================*/

attack_flowADVISE::DNSSpoofingOutcome1Step::DNSSpoofingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DNSSpoofingOutcome1Step", 0, Exponential, RaceEnabled, 17, 2, false);}

attack_flowADVISE::DNSSpoofingOutcome1Step::~DNSSpoofingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::DNSSpoofingOutcome1Step::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  Deception->Register(&Deception_Mobius_Mark);
  DNSpacketforging->Register(&DNSpacketforging_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  DNSSpoofingChosen->Register(&DNSSpoofingChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::DNSSpoofingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DNSSpoofingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::DNSSpoofingOutcome1Step::timeDistributionParameter0() {

}

double attack_flowADVISE::DNSSpoofingOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::DNSSpoofingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::DNSSpoofingOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::DNSSpoofingOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::DNSSpoofingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::DNSSpoofingOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::DNSSpoofingOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::DNSSpoofingOutcome1Step::executeEffects() {

}

double attack_flowADVISE::DNSSpoofingOutcome1Step::getCost() {

}

double attack_flowADVISE::DNSSpoofingOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::DNSSpoofingOutcome1Step::getDetection() {
return 0;
}

/*====================== ARPSpoofingOutcome1Step ========================*/

attack_flowADVISE::ARPSpoofingOutcome1Step::ARPSpoofingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("ARPSpoofingOutcome1Step", 1, Exponential, RaceEnabled, 17, 1, false);}

attack_flowADVISE::ARPSpoofingOutcome1Step::~ARPSpoofingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::ARPSpoofingOutcome1Step::LinkVariables() {
  KeyedClientSessionHijacking->Register(&KeyedClientSessionHijacking_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  ARPpacketforging->Register(&ARPpacketforging_Mobius_Mark);
  NetworkJoined->Register(&NetworkJoined_Mobius_Mark);
  ARPSpoofingChosen->Register(&ARPSpoofingChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::ARPSpoofingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(ARPSpoofingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::ARPSpoofingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::ARPSpoofingOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::ARPSpoofingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::ARPSpoofingOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::ARPSpoofingOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::ARPSpoofingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::ARPSpoofingOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::ARPSpoofingOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::ARPSpoofingOutcome1Step::executeEffects() {

}

double attack_flowADVISE::ARPSpoofingOutcome1Step::getCost() {

}

double attack_flowADVISE::ARPSpoofingOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::ARPSpoofingOutcome1Step::getDetection() {
return 0;
}

/*====================== DecryptionOutcome1Step ========================*/

attack_flowADVISE::DecryptionOutcome1Step::DecryptionOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DecryptionOutcome1Step", 2, Exponential, RaceEnabled, 15, 1, false);}

attack_flowADVISE::DecryptionOutcome1Step::~DecryptionOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::DecryptionOutcome1Step::LinkVariables() {
  StolenInformation->Register(&StolenInformation_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  DecryptionChosen->Register(&DecryptionChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::DecryptionOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(DecryptionChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::DecryptionOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::DecryptionOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::DecryptionOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::DecryptionOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::DecryptionOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::DecryptionOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::DecryptionOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::DecryptionOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::DecryptionOutcome1Step::executeEffects() {

}

double attack_flowADVISE::DecryptionOutcome1Step::getCost() {

}

double attack_flowADVISE::DecryptionOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::DecryptionOutcome1Step::getDetection() {
return 0;
}

/*====================== NetworkscanningOutcome1Step ========================*/

attack_flowADVISE::NetworkscanningOutcome1Step::NetworkscanningOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("NetworkscanningOutcome1Step", 3, Exponential, RaceEnabled, 15, 1, false);}

attack_flowADVISE::NetworkscanningOutcome1Step::~NetworkscanningOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::NetworkscanningOutcome1Step::LinkVariables() {
  SSIDMACtargetnetwork->Register(&SSIDMACtargetnetwork_Mobius_Mark);
  NoKey/NoAccess->Register(&NoKey/NoAccess_Mobius_Mark);
  NetworkscanningChosen->Register(&NetworkscanningChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::NetworkscanningOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(NetworkscanningChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::NetworkscanningOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::NetworkscanningOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::NetworkscanningOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::NetworkscanningOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::NetworkscanningOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::NetworkscanningOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::NetworkscanningOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::NetworkscanningOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::NetworkscanningOutcome1Step::executeEffects() {

}

double attack_flowADVISE::NetworkscanningOutcome1Step::getCost() {

}

double attack_flowADVISE::NetworkscanningOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::NetworkscanningOutcome1Step::getDetection() {
return 0;
}

/*====================== SSLStrippingOutcome1Step ========================*/

attack_flowADVISE::SSLStrippingOutcome1Step::SSLStrippingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("SSLStrippingOutcome1Step", 4, Exponential, RaceEnabled, 16, 1, false);}

attack_flowADVISE::SSLStrippingOutcome1Step::~SSLStrippingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::SSLStrippingOutcome1Step::LinkVariables() {
  StolenInformation->Register(&StolenInformation_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  Phishing->Register(&Phishing_Mobius_Mark);
  SSLStrippingChosen->Register(&SSLStrippingChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::SSLStrippingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(SSLStrippingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::SSLStrippingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::SSLStrippingOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::SSLStrippingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::SSLStrippingOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::SSLStrippingOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::SSLStrippingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::SSLStrippingOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::SSLStrippingOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::SSLStrippingOutcome1Step::executeEffects() {

}

double attack_flowADVISE::SSLStrippingOutcome1Step::getCost() {

}

double attack_flowADVISE::SSLStrippingOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::SSLStrippingOutcome1Step::getDetection() {
return 0;
}

/*====================== DoNothingOutcome1Step ========================*/

attack_flowADVISE::DoNothingOutcome1Step::DoNothingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("DoNothingOutcome1Step", 5, Deterministic, RaceEnabled, 13, 0, false);}

attack_flowADVISE::DoNothingOutcome1Step::~DoNothingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::DoNothingOutcome1Step::LinkVariables() {
  DoNothingChosen->Register(&DoNothingChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
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

/*====================== JoinNetworkOutcome1Step ========================*/

attack_flowADVISE::JoinNetworkOutcome1Step::JoinNetworkOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("JoinNetworkOutcome1Step", 6, Exponential, RaceEnabled, 15, 1, false);}

attack_flowADVISE::JoinNetworkOutcome1Step::~JoinNetworkOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::JoinNetworkOutcome1Step::LinkVariables() {
  NetworkJoined->Register(&NetworkJoined_Mobius_Mark);
  KeyAcquisition->Register(&KeyAcquisition_Mobius_Mark);
  JoinNetworkChosen->Register(&JoinNetworkChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::JoinNetworkOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(JoinNetworkChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::JoinNetworkOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::JoinNetworkOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::JoinNetworkOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::JoinNetworkOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::JoinNetworkOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::JoinNetworkOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::JoinNetworkOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::JoinNetworkOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::JoinNetworkOutcome1Step::executeEffects() {

}

double attack_flowADVISE::JoinNetworkOutcome1Step::getCost() {

}

double attack_flowADVISE::JoinNetworkOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::JoinNetworkOutcome1Step::getDetection() {
return 0;
}

/*====================== RogueAccessPointOutcome1Step ========================*/

attack_flowADVISE::RogueAccessPointOutcome1Step::RogueAccessPointOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("RogueAccessPointOutcome1Step", 7, Exponential, RaceEnabled, 18, 1, false);}

attack_flowADVISE::RogueAccessPointOutcome1Step::~RogueAccessPointOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::RogueAccessPointOutcome1Step::LinkVariables() {
  KeyAcquisition->Register(&KeyAcquisition_Mobius_Mark);
  NoKey/NoAccess->Register(&NoKey/NoAccess_Mobius_Mark);
  NetworkScanning->Register(&NetworkScanning_Mobius_Mark);
  APHardware->Register(&APHardware_Mobius_Mark);
  SSIDMACtargetnetwork->Register(&SSIDMACtargetnetwork_Mobius_Mark);
  RogueAccessPointChosen->Register(&RogueAccessPointChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::RogueAccessPointOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(RogueAccessPointChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::RogueAccessPointOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::RogueAccessPointOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::RogueAccessPointOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::RogueAccessPointOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::RogueAccessPointOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::RogueAccessPointOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::RogueAccessPointOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::RogueAccessPointOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::RogueAccessPointOutcome1Step::executeEffects() {

}

double attack_flowADVISE::RogueAccessPointOutcome1Step::getCost() {

}

double attack_flowADVISE::RogueAccessPointOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::RogueAccessPointOutcome1Step::getDetection() {
return 0;
}

/*====================== EvilTwinOutcome1Step ========================*/

attack_flowADVISE::EvilTwinOutcome1Step::EvilTwinOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("EvilTwinOutcome1Step", 8, Exponential, RaceEnabled, 15, 1, false);}

attack_flowADVISE::EvilTwinOutcome1Step::~EvilTwinOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::EvilTwinOutcome1Step::LinkVariables() {
  MITM->Register(&MITM_Mobius_Mark);
  KeyAcquisition->Register(&KeyAcquisition_Mobius_Mark);
  EvilTwinChosen->Register(&EvilTwinChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::EvilTwinOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(EvilTwinChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::EvilTwinOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::EvilTwinOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::EvilTwinOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::EvilTwinOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::EvilTwinOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::EvilTwinOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::EvilTwinOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::EvilTwinOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::EvilTwinOutcome1Step::executeEffects() {

}

double attack_flowADVISE::EvilTwinOutcome1Step::getCost() {

}

double attack_flowADVISE::EvilTwinOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::EvilTwinOutcome1Step::getDetection() {
return 0;
}

/*====================== BlockTrafficFlowOutcome1Step ========================*/

attack_flowADVISE::BlockTrafficFlowOutcome1Step::BlockTrafficFlowOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("BlockTrafficFlowOutcome1Step", 9, Exponential, RaceEnabled, 16, 1, false);}

attack_flowADVISE::BlockTrafficFlowOutcome1Step::~BlockTrafficFlowOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::BlockTrafficFlowOutcome1Step::LinkVariables() {
  DoS->Register(&DoS_Mobius_Mark);
  KeyedClientSessionHijacking->Register(&KeyedClientSessionHijacking_Mobius_Mark);
  MITM->Register(&MITM_Mobius_Mark);
  BlockTrafficFlowChosen->Register(&BlockTrafficFlowChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::BlockTrafficFlowOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(BlockTrafficFlowChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::BlockTrafficFlowOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::BlockTrafficFlowOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::BlockTrafficFlowOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::BlockTrafficFlowOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::BlockTrafficFlowOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::BlockTrafficFlowOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::BlockTrafficFlowOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::BlockTrafficFlowOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::BlockTrafficFlowOutcome1Step::executeEffects() {

}

double attack_flowADVISE::BlockTrafficFlowOutcome1Step::getCost() {

}

double attack_flowADVISE::BlockTrafficFlowOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::BlockTrafficFlowOutcome1Step::getDetection() {
return 0;
}

/*====================== PhishingOutcome1Step ========================*/

attack_flowADVISE::PhishingOutcome1Step::PhishingOutcome1Step() {
  TheDistributionParameters = new double[1];
  commonInit("PhishingOutcome1Step", 10, Exponential, RaceEnabled, 15, 1, false);}

attack_flowADVISE::PhishingOutcome1Step::~PhishingOutcome1Step() {
  delete[] TheDistributionParameters;
}

void attack_flowADVISE::PhishingOutcome1Step::LinkVariables() {
  StolenInformation->Register(&StolenInformation_Mobius_Mark);
  Deception->Register(&Deception_Mobius_Mark);
  PhishingChosen->Register(&PhishingChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
  NetworkscanningWeight->Register(&NetworkscanningWeight_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
  DoNothingWeight->Register(&DoNothingWeight_Mobius_Mark);
  JoinNetworkWeight->Register(&JoinNetworkWeight_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
  EvilTwinWeight->Register(&EvilTwinWeight_Mobius_Mark);
  BlockTrafficFlowWeight->Register(&BlockTrafficFlowWeight_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
  MakeDecision->Register(&MakeDecision_Mobius_Mark);

}

bool attack_flowADVISE::PhishingOutcome1Step::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(PhishingChosen_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::PhishingOutcome1Step::timeDistributionParameter0() {
return 1;
}

double attack_flowADVISE::PhishingOutcome1Step::Weight() {
  return 1;
}

bool attack_flowADVISE::PhishingOutcome1Step::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::PhishingOutcome1Step::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::PhishingOutcome1Step::SampleDistribution() {
  return TheDistribution->Exponential(timeDistributionParameter0());
}

double *attack_flowADVISE::PhishingOutcome1Step::ReturnDistributionParameters() {
  TheDistributionParameters[0] = timeDistributionParameter0();
  return TheDistributionParameters;
}

int attack_flowADVISE::PhishingOutcome1Step::Rank() {
  return 1;
}

bool attack_flowADVISE::PhishingOutcome1Step::preconditionsMet() {

  return true;
}

void attack_flowADVISE::PhishingOutcome1Step::executeEffects() {

}

double attack_flowADVISE::PhishingOutcome1Step::getCost() {

}

double attack_flowADVISE::PhishingOutcome1Step::getOutcomeProbability() {
return 1;
}

double attack_flowADVISE::PhishingOutcome1Step::getDetection() {
return 0;
}

/*****************************************************************/
/*                   Adversary Decisions                         */
/*****************************************************************/

/*====================== DNSSpoofingAdversaryDecision ========================*/

attack_flowADVISE::DNSSpoofingAdversaryDecision::DNSSpoofingAdversaryDecision() {
  commonInit("DNSSpoofingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::DNSSpoofingAdversaryDecision::~DNSSpoofingAdversaryDecision() {
}

void attack_flowADVISE::DNSSpoofingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DNSSpoofingChosen->Register(&DNSSpoofingChosen_Mobius_Mark);
  DNSSpoofingWeight->Register(&DNSSpoofingWeight_Mobius_Mark);
}

bool attack_flowADVISE::DNSSpoofingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::DNSSpoofingAdversaryDecision::Weight() {
  return DNSSpoofingWeight->Mark();
}

bool attack_flowADVISE::DNSSpoofingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::DNSSpoofingAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::DNSSpoofingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::DNSSpoofingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::DNSSpoofingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::DNSSpoofingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DNSSpoofingWeight_Mobius_Mark))--;
  (*(DNSSpoofingChosen_Mobius_Mark))++;
  return this;
}

/*====================== ARPSpoofingAdversaryDecision ========================*/

attack_flowADVISE::ARPSpoofingAdversaryDecision::ARPSpoofingAdversaryDecision() {
  commonInit("ARPSpoofingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::ARPSpoofingAdversaryDecision::~ARPSpoofingAdversaryDecision() {
}

void attack_flowADVISE::ARPSpoofingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  ARPSpoofingChosen->Register(&ARPSpoofingChosen_Mobius_Mark);
  ARPSpoofingWeight->Register(&ARPSpoofingWeight_Mobius_Mark);
}

bool attack_flowADVISE::ARPSpoofingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::ARPSpoofingAdversaryDecision::Weight() {
  return ARPSpoofingWeight->Mark();
}

bool attack_flowADVISE::ARPSpoofingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::ARPSpoofingAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::ARPSpoofingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::ARPSpoofingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::ARPSpoofingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::ARPSpoofingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(ARPSpoofingWeight_Mobius_Mark))--;
  (*(ARPSpoofingChosen_Mobius_Mark))++;
  return this;
}

/*====================== DecryptionAdversaryDecision ========================*/

attack_flowADVISE::DecryptionAdversaryDecision::DecryptionAdversaryDecision() {
  commonInit("DecryptionAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::DecryptionAdversaryDecision::~DecryptionAdversaryDecision() {
}

void attack_flowADVISE::DecryptionAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  DecryptionChosen->Register(&DecryptionChosen_Mobius_Mark);
  DecryptionWeight->Register(&DecryptionWeight_Mobius_Mark);
}

bool attack_flowADVISE::DecryptionAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::DecryptionAdversaryDecision::Weight() {
  return DecryptionWeight->Mark();
}

bool attack_flowADVISE::DecryptionAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::DecryptionAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::DecryptionAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::DecryptionAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::DecryptionAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::DecryptionAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(DecryptionWeight_Mobius_Mark))--;
  (*(DecryptionChosen_Mobius_Mark))++;
  return this;
}

/*====================== NetworkscanningAdversaryDecision ========================*/

attack_flowADVISE::NetworkscanningAdversaryDecision::NetworkscanningAdversaryDecision() {
  commonInit("NetworkscanningAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== SSLStrippingAdversaryDecision ========================*/

attack_flowADVISE::SSLStrippingAdversaryDecision::SSLStrippingAdversaryDecision() {
  commonInit("SSLStrippingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::SSLStrippingAdversaryDecision::~SSLStrippingAdversaryDecision() {
}

void attack_flowADVISE::SSLStrippingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  SSLStrippingChosen->Register(&SSLStrippingChosen_Mobius_Mark);
  SSLStrippingWeight->Register(&SSLStrippingWeight_Mobius_Mark);
}

bool attack_flowADVISE::SSLStrippingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::SSLStrippingAdversaryDecision::Weight() {
  return SSLStrippingWeight->Mark();
}

bool attack_flowADVISE::SSLStrippingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::SSLStrippingAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::SSLStrippingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::SSLStrippingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::SSLStrippingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::SSLStrippingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(SSLStrippingWeight_Mobius_Mark))--;
  (*(SSLStrippingChosen_Mobius_Mark))++;
  return this;
}

/*====================== DoNothingAdversaryDecision ========================*/

attack_flowADVISE::DoNothingAdversaryDecision::DoNothingAdversaryDecision() {
  commonInit("DoNothingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== JoinNetworkAdversaryDecision ========================*/

attack_flowADVISE::JoinNetworkAdversaryDecision::JoinNetworkAdversaryDecision() {
  commonInit("JoinNetworkAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== RogueAccessPointAdversaryDecision ========================*/

attack_flowADVISE::RogueAccessPointAdversaryDecision::RogueAccessPointAdversaryDecision() {
  commonInit("RogueAccessPointAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::RogueAccessPointAdversaryDecision::~RogueAccessPointAdversaryDecision() {
}

void attack_flowADVISE::RogueAccessPointAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  RogueAccessPointChosen->Register(&RogueAccessPointChosen_Mobius_Mark);
  RogueAccessPointWeight->Register(&RogueAccessPointWeight_Mobius_Mark);
}

bool attack_flowADVISE::RogueAccessPointAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::RogueAccessPointAdversaryDecision::Weight() {
  return RogueAccessPointWeight->Mark();
}

bool attack_flowADVISE::RogueAccessPointAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::RogueAccessPointAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::RogueAccessPointAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::RogueAccessPointAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::RogueAccessPointAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::RogueAccessPointAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(RogueAccessPointWeight_Mobius_Mark))--;
  (*(RogueAccessPointChosen_Mobius_Mark))++;
  return this;
}

/*====================== EvilTwinAdversaryDecision ========================*/

attack_flowADVISE::EvilTwinAdversaryDecision::EvilTwinAdversaryDecision() {
  commonInit("EvilTwinAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== BlockTrafficFlowAdversaryDecision ========================*/

attack_flowADVISE::BlockTrafficFlowAdversaryDecision::BlockTrafficFlowAdversaryDecision() {
  commonInit("BlockTrafficFlowAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
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

/*====================== PhishingAdversaryDecision ========================*/

attack_flowADVISE::PhishingAdversaryDecision::PhishingAdversaryDecision() {
  commonInit("PhishingAdversaryDecision", 11, Instantaneous, RaceEnabled, 2, 1, false);
}

attack_flowADVISE::PhishingAdversaryDecision::~PhishingAdversaryDecision() {
}

void attack_flowADVISE::PhishingAdversaryDecision::LinkVariables() {
  MakeDecision->Register(&MakeDecision_Mobius_Mark);
  PhishingChosen->Register(&PhishingChosen_Mobius_Mark);
  PhishingWeight->Register(&PhishingWeight_Mobius_Mark);
}

bool attack_flowADVISE::PhishingAdversaryDecision::Enabled() {
  OldEnabled = NewEnabled;
  NewEnabled = (((*(MakeDecision_Mobius_Mark)) >= 1));
  return NewEnabled;
}

double attack_flowADVISE::PhishingAdversaryDecision::Weight() {
  return PhishingWeight->Mark();
}

bool attack_flowADVISE::PhishingAdversaryDecision::ReactivationPredicate() {
  return false;
}

bool attack_flowADVISE::PhishingAdversaryDecision::ReactivationFunction() {
  return false;
}

double attack_flowADVISE::PhishingAdversaryDecision::SampleDistribution() {
  return 0;
}

double* attack_flowADVISE::PhishingAdversaryDecision::ReturnDistributionParameters() {
  return NULL;
}

int attack_flowADVISE::PhishingAdversaryDecision::Rank() {
  return 1;
}

BaseActionClass* attack_flowADVISE::PhishingAdversaryDecision::Fire() {
  (*(MakeDecision_Mobius_Mark))--;
  (*(PhishingWeight_Mobius_Mark))--;
  (*(PhishingChosen_Mobius_Mark))++;
  return this;
}

