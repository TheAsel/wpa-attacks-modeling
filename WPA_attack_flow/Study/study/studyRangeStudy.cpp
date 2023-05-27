
#include "Study/study/studyRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Short apConfigProf;
Bool hasHardware;
Short networkHackingProf;
Short packetForgingProf;
Short socialEngineeringProf;
Short wantsDOS;
Short wantsSensitiveInfo;

//********************************************************
//studyRangeStudy Constructor
//********************************************************
studyRangeStudy::studyRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 7;
  NumExps = 128;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("apConfigProf");
  GVTypes[0]=strdup("short");
  GVNames[1]=strdup("hasHardware");
  GVTypes[1]=strdup("bool");
  GVNames[2]=strdup("networkHackingProf");
  GVTypes[2]=strdup("short");
  GVNames[3]=strdup("packetForgingProf");
  GVTypes[3]=strdup("short");
  GVNames[4]=strdup("socialEngineeringProf");
  GVTypes[4]=strdup("short");
  GVNames[5]=strdup("wantsDOS");
  GVTypes[5]=strdup("short");
  GVNames[6]=strdup("wantsSensitiveInfo");
  GVTypes[6]=strdup("short");

  // create the arrays to store the values of each gv
  apConfigProfValues = new short[NumExps];
  hasHardwareValues = new bool[NumExps];
  networkHackingProfValues = new short[NumExps];
  packetForgingProfValues = new short[NumExps];
  socialEngineeringProfValues = new short[NumExps];
  wantsDOSValues = new short[NumExps];
  wantsSensitiveInfoValues = new short[NumExps];

  // call methods to assign values to each gv
  SetValues_apConfigProf();
  SetValues_hasHardware();
  SetValues_networkHackingProf();
  SetValues_packetForgingProf();
  SetValues_socialEngineeringProf();
  SetValues_wantsDOS();
  SetValues_wantsSensitiveInfo();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//studyRangeStudy Destructor
//******************************************************
studyRangeStudy::~studyRangeStudy() {
  delete [] apConfigProfValues;
  delete [] hasHardwareValues;
  delete [] networkHackingProfValues;
  delete [] packetForgingProfValues;
  delete [] socialEngineeringProfValues;
  delete [] wantsDOSValues;
  delete [] wantsSensitiveInfoValues;
  delete ThePVModel;
}


//******************************************************
// set values for apConfigProf
//******************************************************
void studyRangeStudy::SetValues_apConfigProf() {
  apConfigProfValues[0] = 0;
  apConfigProfValues[1] = 10;
  apConfigProfValues[2] = 0;
  apConfigProfValues[3] = 10;
  apConfigProfValues[4] = 0;
  apConfigProfValues[5] = 10;
  apConfigProfValues[6] = 0;
  apConfigProfValues[7] = 10;
  apConfigProfValues[8] = 0;
  apConfigProfValues[9] = 10;
  apConfigProfValues[10] = 0;
  apConfigProfValues[11] = 10;
  apConfigProfValues[12] = 0;
  apConfigProfValues[13] = 10;
  apConfigProfValues[14] = 0;
  apConfigProfValues[15] = 10;
  apConfigProfValues[16] = 0;
  apConfigProfValues[17] = 10;
  apConfigProfValues[18] = 0;
  apConfigProfValues[19] = 10;
  apConfigProfValues[20] = 0;
  apConfigProfValues[21] = 10;
  apConfigProfValues[22] = 0;
  apConfigProfValues[23] = 10;
  apConfigProfValues[24] = 0;
  apConfigProfValues[25] = 10;
  apConfigProfValues[26] = 0;
  apConfigProfValues[27] = 10;
  apConfigProfValues[28] = 0;
  apConfigProfValues[29] = 10;
  apConfigProfValues[30] = 0;
  apConfigProfValues[31] = 10;
  apConfigProfValues[32] = 0;
  apConfigProfValues[33] = 10;
  apConfigProfValues[34] = 0;
  apConfigProfValues[35] = 10;
  apConfigProfValues[36] = 0;
  apConfigProfValues[37] = 10;
  apConfigProfValues[38] = 0;
  apConfigProfValues[39] = 10;
  apConfigProfValues[40] = 0;
  apConfigProfValues[41] = 10;
  apConfigProfValues[42] = 0;
  apConfigProfValues[43] = 10;
  apConfigProfValues[44] = 0;
  apConfigProfValues[45] = 10;
  apConfigProfValues[46] = 0;
  apConfigProfValues[47] = 10;
  apConfigProfValues[48] = 0;
  apConfigProfValues[49] = 10;
  apConfigProfValues[50] = 0;
  apConfigProfValues[51] = 10;
  apConfigProfValues[52] = 0;
  apConfigProfValues[53] = 10;
  apConfigProfValues[54] = 0;
  apConfigProfValues[55] = 10;
  apConfigProfValues[56] = 0;
  apConfigProfValues[57] = 10;
  apConfigProfValues[58] = 0;
  apConfigProfValues[59] = 10;
  apConfigProfValues[60] = 0;
  apConfigProfValues[61] = 10;
  apConfigProfValues[62] = 0;
  apConfigProfValues[63] = 10;
  apConfigProfValues[64] = 0;
  apConfigProfValues[65] = 10;
  apConfigProfValues[66] = 0;
  apConfigProfValues[67] = 10;
  apConfigProfValues[68] = 0;
  apConfigProfValues[69] = 10;
  apConfigProfValues[70] = 0;
  apConfigProfValues[71] = 10;
  apConfigProfValues[72] = 0;
  apConfigProfValues[73] = 10;
  apConfigProfValues[74] = 0;
  apConfigProfValues[75] = 10;
  apConfigProfValues[76] = 0;
  apConfigProfValues[77] = 10;
  apConfigProfValues[78] = 0;
  apConfigProfValues[79] = 10;
  apConfigProfValues[80] = 0;
  apConfigProfValues[81] = 10;
  apConfigProfValues[82] = 0;
  apConfigProfValues[83] = 10;
  apConfigProfValues[84] = 0;
  apConfigProfValues[85] = 10;
  apConfigProfValues[86] = 0;
  apConfigProfValues[87] = 10;
  apConfigProfValues[88] = 0;
  apConfigProfValues[89] = 10;
  apConfigProfValues[90] = 0;
  apConfigProfValues[91] = 10;
  apConfigProfValues[92] = 0;
  apConfigProfValues[93] = 10;
  apConfigProfValues[94] = 0;
  apConfigProfValues[95] = 10;
  apConfigProfValues[96] = 0;
  apConfigProfValues[97] = 10;
  apConfigProfValues[98] = 0;
  apConfigProfValues[99] = 10;
  apConfigProfValues[100] = 0;
  apConfigProfValues[101] = 10;
  apConfigProfValues[102] = 0;
  apConfigProfValues[103] = 10;
  apConfigProfValues[104] = 0;
  apConfigProfValues[105] = 10;
  apConfigProfValues[106] = 0;
  apConfigProfValues[107] = 10;
  apConfigProfValues[108] = 0;
  apConfigProfValues[109] = 10;
  apConfigProfValues[110] = 0;
  apConfigProfValues[111] = 10;
  apConfigProfValues[112] = 0;
  apConfigProfValues[113] = 10;
  apConfigProfValues[114] = 0;
  apConfigProfValues[115] = 10;
  apConfigProfValues[116] = 0;
  apConfigProfValues[117] = 10;
  apConfigProfValues[118] = 0;
  apConfigProfValues[119] = 10;
  apConfigProfValues[120] = 0;
  apConfigProfValues[121] = 10;
  apConfigProfValues[122] = 0;
  apConfigProfValues[123] = 10;
  apConfigProfValues[124] = 0;
  apConfigProfValues[125] = 10;
  apConfigProfValues[126] = 0;
  apConfigProfValues[127] = 10;
}


//******************************************************
// set values for hasHardware
//******************************************************
void studyRangeStudy::SetValues_hasHardware() {
  hasHardwareValues[0] = 0;
  hasHardwareValues[1] = 0;
  hasHardwareValues[2] = 1;
  hasHardwareValues[3] = 1;
  hasHardwareValues[4] = 0;
  hasHardwareValues[5] = 0;
  hasHardwareValues[6] = 1;
  hasHardwareValues[7] = 1;
  hasHardwareValues[8] = 0;
  hasHardwareValues[9] = 0;
  hasHardwareValues[10] = 1;
  hasHardwareValues[11] = 1;
  hasHardwareValues[12] = 0;
  hasHardwareValues[13] = 0;
  hasHardwareValues[14] = 1;
  hasHardwareValues[15] = 1;
  hasHardwareValues[16] = 0;
  hasHardwareValues[17] = 0;
  hasHardwareValues[18] = 1;
  hasHardwareValues[19] = 1;
  hasHardwareValues[20] = 0;
  hasHardwareValues[21] = 0;
  hasHardwareValues[22] = 1;
  hasHardwareValues[23] = 1;
  hasHardwareValues[24] = 0;
  hasHardwareValues[25] = 0;
  hasHardwareValues[26] = 1;
  hasHardwareValues[27] = 1;
  hasHardwareValues[28] = 0;
  hasHardwareValues[29] = 0;
  hasHardwareValues[30] = 1;
  hasHardwareValues[31] = 1;
  hasHardwareValues[32] = 0;
  hasHardwareValues[33] = 0;
  hasHardwareValues[34] = 1;
  hasHardwareValues[35] = 1;
  hasHardwareValues[36] = 0;
  hasHardwareValues[37] = 0;
  hasHardwareValues[38] = 1;
  hasHardwareValues[39] = 1;
  hasHardwareValues[40] = 0;
  hasHardwareValues[41] = 0;
  hasHardwareValues[42] = 1;
  hasHardwareValues[43] = 1;
  hasHardwareValues[44] = 0;
  hasHardwareValues[45] = 0;
  hasHardwareValues[46] = 1;
  hasHardwareValues[47] = 1;
  hasHardwareValues[48] = 0;
  hasHardwareValues[49] = 0;
  hasHardwareValues[50] = 1;
  hasHardwareValues[51] = 1;
  hasHardwareValues[52] = 0;
  hasHardwareValues[53] = 0;
  hasHardwareValues[54] = 1;
  hasHardwareValues[55] = 1;
  hasHardwareValues[56] = 0;
  hasHardwareValues[57] = 0;
  hasHardwareValues[58] = 1;
  hasHardwareValues[59] = 1;
  hasHardwareValues[60] = 0;
  hasHardwareValues[61] = 0;
  hasHardwareValues[62] = 1;
  hasHardwareValues[63] = 1;
  hasHardwareValues[64] = 0;
  hasHardwareValues[65] = 0;
  hasHardwareValues[66] = 1;
  hasHardwareValues[67] = 1;
  hasHardwareValues[68] = 0;
  hasHardwareValues[69] = 0;
  hasHardwareValues[70] = 1;
  hasHardwareValues[71] = 1;
  hasHardwareValues[72] = 0;
  hasHardwareValues[73] = 0;
  hasHardwareValues[74] = 1;
  hasHardwareValues[75] = 1;
  hasHardwareValues[76] = 0;
  hasHardwareValues[77] = 0;
  hasHardwareValues[78] = 1;
  hasHardwareValues[79] = 1;
  hasHardwareValues[80] = 0;
  hasHardwareValues[81] = 0;
  hasHardwareValues[82] = 1;
  hasHardwareValues[83] = 1;
  hasHardwareValues[84] = 0;
  hasHardwareValues[85] = 0;
  hasHardwareValues[86] = 1;
  hasHardwareValues[87] = 1;
  hasHardwareValues[88] = 0;
  hasHardwareValues[89] = 0;
  hasHardwareValues[90] = 1;
  hasHardwareValues[91] = 1;
  hasHardwareValues[92] = 0;
  hasHardwareValues[93] = 0;
  hasHardwareValues[94] = 1;
  hasHardwareValues[95] = 1;
  hasHardwareValues[96] = 0;
  hasHardwareValues[97] = 0;
  hasHardwareValues[98] = 1;
  hasHardwareValues[99] = 1;
  hasHardwareValues[100] = 0;
  hasHardwareValues[101] = 0;
  hasHardwareValues[102] = 1;
  hasHardwareValues[103] = 1;
  hasHardwareValues[104] = 0;
  hasHardwareValues[105] = 0;
  hasHardwareValues[106] = 1;
  hasHardwareValues[107] = 1;
  hasHardwareValues[108] = 0;
  hasHardwareValues[109] = 0;
  hasHardwareValues[110] = 1;
  hasHardwareValues[111] = 1;
  hasHardwareValues[112] = 0;
  hasHardwareValues[113] = 0;
  hasHardwareValues[114] = 1;
  hasHardwareValues[115] = 1;
  hasHardwareValues[116] = 0;
  hasHardwareValues[117] = 0;
  hasHardwareValues[118] = 1;
  hasHardwareValues[119] = 1;
  hasHardwareValues[120] = 0;
  hasHardwareValues[121] = 0;
  hasHardwareValues[122] = 1;
  hasHardwareValues[123] = 1;
  hasHardwareValues[124] = 0;
  hasHardwareValues[125] = 0;
  hasHardwareValues[126] = 1;
  hasHardwareValues[127] = 1;
}


//******************************************************
// set values for networkHackingProf
//******************************************************
void studyRangeStudy::SetValues_networkHackingProf() {
  networkHackingProfValues[0] = 0;
  networkHackingProfValues[1] = 0;
  networkHackingProfValues[2] = 0;
  networkHackingProfValues[3] = 0;
  networkHackingProfValues[4] = 10;
  networkHackingProfValues[5] = 10;
  networkHackingProfValues[6] = 10;
  networkHackingProfValues[7] = 10;
  networkHackingProfValues[8] = 0;
  networkHackingProfValues[9] = 0;
  networkHackingProfValues[10] = 0;
  networkHackingProfValues[11] = 0;
  networkHackingProfValues[12] = 10;
  networkHackingProfValues[13] = 10;
  networkHackingProfValues[14] = 10;
  networkHackingProfValues[15] = 10;
  networkHackingProfValues[16] = 0;
  networkHackingProfValues[17] = 0;
  networkHackingProfValues[18] = 0;
  networkHackingProfValues[19] = 0;
  networkHackingProfValues[20] = 10;
  networkHackingProfValues[21] = 10;
  networkHackingProfValues[22] = 10;
  networkHackingProfValues[23] = 10;
  networkHackingProfValues[24] = 0;
  networkHackingProfValues[25] = 0;
  networkHackingProfValues[26] = 0;
  networkHackingProfValues[27] = 0;
  networkHackingProfValues[28] = 10;
  networkHackingProfValues[29] = 10;
  networkHackingProfValues[30] = 10;
  networkHackingProfValues[31] = 10;
  networkHackingProfValues[32] = 0;
  networkHackingProfValues[33] = 0;
  networkHackingProfValues[34] = 0;
  networkHackingProfValues[35] = 0;
  networkHackingProfValues[36] = 10;
  networkHackingProfValues[37] = 10;
  networkHackingProfValues[38] = 10;
  networkHackingProfValues[39] = 10;
  networkHackingProfValues[40] = 0;
  networkHackingProfValues[41] = 0;
  networkHackingProfValues[42] = 0;
  networkHackingProfValues[43] = 0;
  networkHackingProfValues[44] = 10;
  networkHackingProfValues[45] = 10;
  networkHackingProfValues[46] = 10;
  networkHackingProfValues[47] = 10;
  networkHackingProfValues[48] = 0;
  networkHackingProfValues[49] = 0;
  networkHackingProfValues[50] = 0;
  networkHackingProfValues[51] = 0;
  networkHackingProfValues[52] = 10;
  networkHackingProfValues[53] = 10;
  networkHackingProfValues[54] = 10;
  networkHackingProfValues[55] = 10;
  networkHackingProfValues[56] = 0;
  networkHackingProfValues[57] = 0;
  networkHackingProfValues[58] = 0;
  networkHackingProfValues[59] = 0;
  networkHackingProfValues[60] = 10;
  networkHackingProfValues[61] = 10;
  networkHackingProfValues[62] = 10;
  networkHackingProfValues[63] = 10;
  networkHackingProfValues[64] = 0;
  networkHackingProfValues[65] = 0;
  networkHackingProfValues[66] = 0;
  networkHackingProfValues[67] = 0;
  networkHackingProfValues[68] = 10;
  networkHackingProfValues[69] = 10;
  networkHackingProfValues[70] = 10;
  networkHackingProfValues[71] = 10;
  networkHackingProfValues[72] = 0;
  networkHackingProfValues[73] = 0;
  networkHackingProfValues[74] = 0;
  networkHackingProfValues[75] = 0;
  networkHackingProfValues[76] = 10;
  networkHackingProfValues[77] = 10;
  networkHackingProfValues[78] = 10;
  networkHackingProfValues[79] = 10;
  networkHackingProfValues[80] = 0;
  networkHackingProfValues[81] = 0;
  networkHackingProfValues[82] = 0;
  networkHackingProfValues[83] = 0;
  networkHackingProfValues[84] = 10;
  networkHackingProfValues[85] = 10;
  networkHackingProfValues[86] = 10;
  networkHackingProfValues[87] = 10;
  networkHackingProfValues[88] = 0;
  networkHackingProfValues[89] = 0;
  networkHackingProfValues[90] = 0;
  networkHackingProfValues[91] = 0;
  networkHackingProfValues[92] = 10;
  networkHackingProfValues[93] = 10;
  networkHackingProfValues[94] = 10;
  networkHackingProfValues[95] = 10;
  networkHackingProfValues[96] = 0;
  networkHackingProfValues[97] = 0;
  networkHackingProfValues[98] = 0;
  networkHackingProfValues[99] = 0;
  networkHackingProfValues[100] = 10;
  networkHackingProfValues[101] = 10;
  networkHackingProfValues[102] = 10;
  networkHackingProfValues[103] = 10;
  networkHackingProfValues[104] = 0;
  networkHackingProfValues[105] = 0;
  networkHackingProfValues[106] = 0;
  networkHackingProfValues[107] = 0;
  networkHackingProfValues[108] = 10;
  networkHackingProfValues[109] = 10;
  networkHackingProfValues[110] = 10;
  networkHackingProfValues[111] = 10;
  networkHackingProfValues[112] = 0;
  networkHackingProfValues[113] = 0;
  networkHackingProfValues[114] = 0;
  networkHackingProfValues[115] = 0;
  networkHackingProfValues[116] = 10;
  networkHackingProfValues[117] = 10;
  networkHackingProfValues[118] = 10;
  networkHackingProfValues[119] = 10;
  networkHackingProfValues[120] = 0;
  networkHackingProfValues[121] = 0;
  networkHackingProfValues[122] = 0;
  networkHackingProfValues[123] = 0;
  networkHackingProfValues[124] = 10;
  networkHackingProfValues[125] = 10;
  networkHackingProfValues[126] = 10;
  networkHackingProfValues[127] = 10;
}


//******************************************************
// set values for packetForgingProf
//******************************************************
void studyRangeStudy::SetValues_packetForgingProf() {
  packetForgingProfValues[0] = 0;
  packetForgingProfValues[1] = 0;
  packetForgingProfValues[2] = 0;
  packetForgingProfValues[3] = 0;
  packetForgingProfValues[4] = 0;
  packetForgingProfValues[5] = 0;
  packetForgingProfValues[6] = 0;
  packetForgingProfValues[7] = 0;
  packetForgingProfValues[8] = 10;
  packetForgingProfValues[9] = 10;
  packetForgingProfValues[10] = 10;
  packetForgingProfValues[11] = 10;
  packetForgingProfValues[12] = 10;
  packetForgingProfValues[13] = 10;
  packetForgingProfValues[14] = 10;
  packetForgingProfValues[15] = 10;
  packetForgingProfValues[16] = 0;
  packetForgingProfValues[17] = 0;
  packetForgingProfValues[18] = 0;
  packetForgingProfValues[19] = 0;
  packetForgingProfValues[20] = 0;
  packetForgingProfValues[21] = 0;
  packetForgingProfValues[22] = 0;
  packetForgingProfValues[23] = 0;
  packetForgingProfValues[24] = 10;
  packetForgingProfValues[25] = 10;
  packetForgingProfValues[26] = 10;
  packetForgingProfValues[27] = 10;
  packetForgingProfValues[28] = 10;
  packetForgingProfValues[29] = 10;
  packetForgingProfValues[30] = 10;
  packetForgingProfValues[31] = 10;
  packetForgingProfValues[32] = 0;
  packetForgingProfValues[33] = 0;
  packetForgingProfValues[34] = 0;
  packetForgingProfValues[35] = 0;
  packetForgingProfValues[36] = 0;
  packetForgingProfValues[37] = 0;
  packetForgingProfValues[38] = 0;
  packetForgingProfValues[39] = 0;
  packetForgingProfValues[40] = 10;
  packetForgingProfValues[41] = 10;
  packetForgingProfValues[42] = 10;
  packetForgingProfValues[43] = 10;
  packetForgingProfValues[44] = 10;
  packetForgingProfValues[45] = 10;
  packetForgingProfValues[46] = 10;
  packetForgingProfValues[47] = 10;
  packetForgingProfValues[48] = 0;
  packetForgingProfValues[49] = 0;
  packetForgingProfValues[50] = 0;
  packetForgingProfValues[51] = 0;
  packetForgingProfValues[52] = 0;
  packetForgingProfValues[53] = 0;
  packetForgingProfValues[54] = 0;
  packetForgingProfValues[55] = 0;
  packetForgingProfValues[56] = 10;
  packetForgingProfValues[57] = 10;
  packetForgingProfValues[58] = 10;
  packetForgingProfValues[59] = 10;
  packetForgingProfValues[60] = 10;
  packetForgingProfValues[61] = 10;
  packetForgingProfValues[62] = 10;
  packetForgingProfValues[63] = 10;
  packetForgingProfValues[64] = 0;
  packetForgingProfValues[65] = 0;
  packetForgingProfValues[66] = 0;
  packetForgingProfValues[67] = 0;
  packetForgingProfValues[68] = 0;
  packetForgingProfValues[69] = 0;
  packetForgingProfValues[70] = 0;
  packetForgingProfValues[71] = 0;
  packetForgingProfValues[72] = 10;
  packetForgingProfValues[73] = 10;
  packetForgingProfValues[74] = 10;
  packetForgingProfValues[75] = 10;
  packetForgingProfValues[76] = 10;
  packetForgingProfValues[77] = 10;
  packetForgingProfValues[78] = 10;
  packetForgingProfValues[79] = 10;
  packetForgingProfValues[80] = 0;
  packetForgingProfValues[81] = 0;
  packetForgingProfValues[82] = 0;
  packetForgingProfValues[83] = 0;
  packetForgingProfValues[84] = 0;
  packetForgingProfValues[85] = 0;
  packetForgingProfValues[86] = 0;
  packetForgingProfValues[87] = 0;
  packetForgingProfValues[88] = 10;
  packetForgingProfValues[89] = 10;
  packetForgingProfValues[90] = 10;
  packetForgingProfValues[91] = 10;
  packetForgingProfValues[92] = 10;
  packetForgingProfValues[93] = 10;
  packetForgingProfValues[94] = 10;
  packetForgingProfValues[95] = 10;
  packetForgingProfValues[96] = 0;
  packetForgingProfValues[97] = 0;
  packetForgingProfValues[98] = 0;
  packetForgingProfValues[99] = 0;
  packetForgingProfValues[100] = 0;
  packetForgingProfValues[101] = 0;
  packetForgingProfValues[102] = 0;
  packetForgingProfValues[103] = 0;
  packetForgingProfValues[104] = 10;
  packetForgingProfValues[105] = 10;
  packetForgingProfValues[106] = 10;
  packetForgingProfValues[107] = 10;
  packetForgingProfValues[108] = 10;
  packetForgingProfValues[109] = 10;
  packetForgingProfValues[110] = 10;
  packetForgingProfValues[111] = 10;
  packetForgingProfValues[112] = 0;
  packetForgingProfValues[113] = 0;
  packetForgingProfValues[114] = 0;
  packetForgingProfValues[115] = 0;
  packetForgingProfValues[116] = 0;
  packetForgingProfValues[117] = 0;
  packetForgingProfValues[118] = 0;
  packetForgingProfValues[119] = 0;
  packetForgingProfValues[120] = 10;
  packetForgingProfValues[121] = 10;
  packetForgingProfValues[122] = 10;
  packetForgingProfValues[123] = 10;
  packetForgingProfValues[124] = 10;
  packetForgingProfValues[125] = 10;
  packetForgingProfValues[126] = 10;
  packetForgingProfValues[127] = 10;
}


//******************************************************
// set values for socialEngineeringProf
//******************************************************
void studyRangeStudy::SetValues_socialEngineeringProf() {
  socialEngineeringProfValues[0] = 0;
  socialEngineeringProfValues[1] = 0;
  socialEngineeringProfValues[2] = 0;
  socialEngineeringProfValues[3] = 0;
  socialEngineeringProfValues[4] = 0;
  socialEngineeringProfValues[5] = 0;
  socialEngineeringProfValues[6] = 0;
  socialEngineeringProfValues[7] = 0;
  socialEngineeringProfValues[8] = 0;
  socialEngineeringProfValues[9] = 0;
  socialEngineeringProfValues[10] = 0;
  socialEngineeringProfValues[11] = 0;
  socialEngineeringProfValues[12] = 0;
  socialEngineeringProfValues[13] = 0;
  socialEngineeringProfValues[14] = 0;
  socialEngineeringProfValues[15] = 0;
  socialEngineeringProfValues[16] = 10;
  socialEngineeringProfValues[17] = 10;
  socialEngineeringProfValues[18] = 10;
  socialEngineeringProfValues[19] = 10;
  socialEngineeringProfValues[20] = 10;
  socialEngineeringProfValues[21] = 10;
  socialEngineeringProfValues[22] = 10;
  socialEngineeringProfValues[23] = 10;
  socialEngineeringProfValues[24] = 10;
  socialEngineeringProfValues[25] = 10;
  socialEngineeringProfValues[26] = 10;
  socialEngineeringProfValues[27] = 10;
  socialEngineeringProfValues[28] = 10;
  socialEngineeringProfValues[29] = 10;
  socialEngineeringProfValues[30] = 10;
  socialEngineeringProfValues[31] = 10;
  socialEngineeringProfValues[32] = 0;
  socialEngineeringProfValues[33] = 0;
  socialEngineeringProfValues[34] = 0;
  socialEngineeringProfValues[35] = 0;
  socialEngineeringProfValues[36] = 0;
  socialEngineeringProfValues[37] = 0;
  socialEngineeringProfValues[38] = 0;
  socialEngineeringProfValues[39] = 0;
  socialEngineeringProfValues[40] = 0;
  socialEngineeringProfValues[41] = 0;
  socialEngineeringProfValues[42] = 0;
  socialEngineeringProfValues[43] = 0;
  socialEngineeringProfValues[44] = 0;
  socialEngineeringProfValues[45] = 0;
  socialEngineeringProfValues[46] = 0;
  socialEngineeringProfValues[47] = 0;
  socialEngineeringProfValues[48] = 10;
  socialEngineeringProfValues[49] = 10;
  socialEngineeringProfValues[50] = 10;
  socialEngineeringProfValues[51] = 10;
  socialEngineeringProfValues[52] = 10;
  socialEngineeringProfValues[53] = 10;
  socialEngineeringProfValues[54] = 10;
  socialEngineeringProfValues[55] = 10;
  socialEngineeringProfValues[56] = 10;
  socialEngineeringProfValues[57] = 10;
  socialEngineeringProfValues[58] = 10;
  socialEngineeringProfValues[59] = 10;
  socialEngineeringProfValues[60] = 10;
  socialEngineeringProfValues[61] = 10;
  socialEngineeringProfValues[62] = 10;
  socialEngineeringProfValues[63] = 10;
  socialEngineeringProfValues[64] = 0;
  socialEngineeringProfValues[65] = 0;
  socialEngineeringProfValues[66] = 0;
  socialEngineeringProfValues[67] = 0;
  socialEngineeringProfValues[68] = 0;
  socialEngineeringProfValues[69] = 0;
  socialEngineeringProfValues[70] = 0;
  socialEngineeringProfValues[71] = 0;
  socialEngineeringProfValues[72] = 0;
  socialEngineeringProfValues[73] = 0;
  socialEngineeringProfValues[74] = 0;
  socialEngineeringProfValues[75] = 0;
  socialEngineeringProfValues[76] = 0;
  socialEngineeringProfValues[77] = 0;
  socialEngineeringProfValues[78] = 0;
  socialEngineeringProfValues[79] = 0;
  socialEngineeringProfValues[80] = 10;
  socialEngineeringProfValues[81] = 10;
  socialEngineeringProfValues[82] = 10;
  socialEngineeringProfValues[83] = 10;
  socialEngineeringProfValues[84] = 10;
  socialEngineeringProfValues[85] = 10;
  socialEngineeringProfValues[86] = 10;
  socialEngineeringProfValues[87] = 10;
  socialEngineeringProfValues[88] = 10;
  socialEngineeringProfValues[89] = 10;
  socialEngineeringProfValues[90] = 10;
  socialEngineeringProfValues[91] = 10;
  socialEngineeringProfValues[92] = 10;
  socialEngineeringProfValues[93] = 10;
  socialEngineeringProfValues[94] = 10;
  socialEngineeringProfValues[95] = 10;
  socialEngineeringProfValues[96] = 0;
  socialEngineeringProfValues[97] = 0;
  socialEngineeringProfValues[98] = 0;
  socialEngineeringProfValues[99] = 0;
  socialEngineeringProfValues[100] = 0;
  socialEngineeringProfValues[101] = 0;
  socialEngineeringProfValues[102] = 0;
  socialEngineeringProfValues[103] = 0;
  socialEngineeringProfValues[104] = 0;
  socialEngineeringProfValues[105] = 0;
  socialEngineeringProfValues[106] = 0;
  socialEngineeringProfValues[107] = 0;
  socialEngineeringProfValues[108] = 0;
  socialEngineeringProfValues[109] = 0;
  socialEngineeringProfValues[110] = 0;
  socialEngineeringProfValues[111] = 0;
  socialEngineeringProfValues[112] = 10;
  socialEngineeringProfValues[113] = 10;
  socialEngineeringProfValues[114] = 10;
  socialEngineeringProfValues[115] = 10;
  socialEngineeringProfValues[116] = 10;
  socialEngineeringProfValues[117] = 10;
  socialEngineeringProfValues[118] = 10;
  socialEngineeringProfValues[119] = 10;
  socialEngineeringProfValues[120] = 10;
  socialEngineeringProfValues[121] = 10;
  socialEngineeringProfValues[122] = 10;
  socialEngineeringProfValues[123] = 10;
  socialEngineeringProfValues[124] = 10;
  socialEngineeringProfValues[125] = 10;
  socialEngineeringProfValues[126] = 10;
  socialEngineeringProfValues[127] = 10;
}


//******************************************************
// set values for wantsDOS
//******************************************************
void studyRangeStudy::SetValues_wantsDOS() {
  wantsDOSValues[0] = 200;
  wantsDOSValues[1] = 200;
  wantsDOSValues[2] = 200;
  wantsDOSValues[3] = 200;
  wantsDOSValues[4] = 200;
  wantsDOSValues[5] = 200;
  wantsDOSValues[6] = 200;
  wantsDOSValues[7] = 200;
  wantsDOSValues[8] = 200;
  wantsDOSValues[9] = 200;
  wantsDOSValues[10] = 200;
  wantsDOSValues[11] = 200;
  wantsDOSValues[12] = 200;
  wantsDOSValues[13] = 200;
  wantsDOSValues[14] = 200;
  wantsDOSValues[15] = 200;
  wantsDOSValues[16] = 200;
  wantsDOSValues[17] = 200;
  wantsDOSValues[18] = 200;
  wantsDOSValues[19] = 200;
  wantsDOSValues[20] = 200;
  wantsDOSValues[21] = 200;
  wantsDOSValues[22] = 200;
  wantsDOSValues[23] = 200;
  wantsDOSValues[24] = 200;
  wantsDOSValues[25] = 200;
  wantsDOSValues[26] = 200;
  wantsDOSValues[27] = 200;
  wantsDOSValues[28] = 200;
  wantsDOSValues[29] = 200;
  wantsDOSValues[30] = 200;
  wantsDOSValues[31] = 200;
  wantsDOSValues[32] = 1000;
  wantsDOSValues[33] = 1000;
  wantsDOSValues[34] = 1000;
  wantsDOSValues[35] = 1000;
  wantsDOSValues[36] = 1000;
  wantsDOSValues[37] = 1000;
  wantsDOSValues[38] = 1000;
  wantsDOSValues[39] = 1000;
  wantsDOSValues[40] = 1000;
  wantsDOSValues[41] = 1000;
  wantsDOSValues[42] = 1000;
  wantsDOSValues[43] = 1000;
  wantsDOSValues[44] = 1000;
  wantsDOSValues[45] = 1000;
  wantsDOSValues[46] = 1000;
  wantsDOSValues[47] = 1000;
  wantsDOSValues[48] = 1000;
  wantsDOSValues[49] = 1000;
  wantsDOSValues[50] = 1000;
  wantsDOSValues[51] = 1000;
  wantsDOSValues[52] = 1000;
  wantsDOSValues[53] = 1000;
  wantsDOSValues[54] = 1000;
  wantsDOSValues[55] = 1000;
  wantsDOSValues[56] = 1000;
  wantsDOSValues[57] = 1000;
  wantsDOSValues[58] = 1000;
  wantsDOSValues[59] = 1000;
  wantsDOSValues[60] = 1000;
  wantsDOSValues[61] = 1000;
  wantsDOSValues[62] = 1000;
  wantsDOSValues[63] = 1000;
  wantsDOSValues[64] = 200;
  wantsDOSValues[65] = 200;
  wantsDOSValues[66] = 200;
  wantsDOSValues[67] = 200;
  wantsDOSValues[68] = 200;
  wantsDOSValues[69] = 200;
  wantsDOSValues[70] = 200;
  wantsDOSValues[71] = 200;
  wantsDOSValues[72] = 200;
  wantsDOSValues[73] = 200;
  wantsDOSValues[74] = 200;
  wantsDOSValues[75] = 200;
  wantsDOSValues[76] = 200;
  wantsDOSValues[77] = 200;
  wantsDOSValues[78] = 200;
  wantsDOSValues[79] = 200;
  wantsDOSValues[80] = 200;
  wantsDOSValues[81] = 200;
  wantsDOSValues[82] = 200;
  wantsDOSValues[83] = 200;
  wantsDOSValues[84] = 200;
  wantsDOSValues[85] = 200;
  wantsDOSValues[86] = 200;
  wantsDOSValues[87] = 200;
  wantsDOSValues[88] = 200;
  wantsDOSValues[89] = 200;
  wantsDOSValues[90] = 200;
  wantsDOSValues[91] = 200;
  wantsDOSValues[92] = 200;
  wantsDOSValues[93] = 200;
  wantsDOSValues[94] = 200;
  wantsDOSValues[95] = 200;
  wantsDOSValues[96] = 1000;
  wantsDOSValues[97] = 1000;
  wantsDOSValues[98] = 1000;
  wantsDOSValues[99] = 1000;
  wantsDOSValues[100] = 1000;
  wantsDOSValues[101] = 1000;
  wantsDOSValues[102] = 1000;
  wantsDOSValues[103] = 1000;
  wantsDOSValues[104] = 1000;
  wantsDOSValues[105] = 1000;
  wantsDOSValues[106] = 1000;
  wantsDOSValues[107] = 1000;
  wantsDOSValues[108] = 1000;
  wantsDOSValues[109] = 1000;
  wantsDOSValues[110] = 1000;
  wantsDOSValues[111] = 1000;
  wantsDOSValues[112] = 1000;
  wantsDOSValues[113] = 1000;
  wantsDOSValues[114] = 1000;
  wantsDOSValues[115] = 1000;
  wantsDOSValues[116] = 1000;
  wantsDOSValues[117] = 1000;
  wantsDOSValues[118] = 1000;
  wantsDOSValues[119] = 1000;
  wantsDOSValues[120] = 1000;
  wantsDOSValues[121] = 1000;
  wantsDOSValues[122] = 1000;
  wantsDOSValues[123] = 1000;
  wantsDOSValues[124] = 1000;
  wantsDOSValues[125] = 1000;
  wantsDOSValues[126] = 1000;
  wantsDOSValues[127] = 1000;
}


//******************************************************
// set values for wantsSensitiveInfo
//******************************************************
void studyRangeStudy::SetValues_wantsSensitiveInfo() {
  wantsSensitiveInfoValues[0] = 200;
  wantsSensitiveInfoValues[1] = 200;
  wantsSensitiveInfoValues[2] = 200;
  wantsSensitiveInfoValues[3] = 200;
  wantsSensitiveInfoValues[4] = 200;
  wantsSensitiveInfoValues[5] = 200;
  wantsSensitiveInfoValues[6] = 200;
  wantsSensitiveInfoValues[7] = 200;
  wantsSensitiveInfoValues[8] = 200;
  wantsSensitiveInfoValues[9] = 200;
  wantsSensitiveInfoValues[10] = 200;
  wantsSensitiveInfoValues[11] = 200;
  wantsSensitiveInfoValues[12] = 200;
  wantsSensitiveInfoValues[13] = 200;
  wantsSensitiveInfoValues[14] = 200;
  wantsSensitiveInfoValues[15] = 200;
  wantsSensitiveInfoValues[16] = 200;
  wantsSensitiveInfoValues[17] = 200;
  wantsSensitiveInfoValues[18] = 200;
  wantsSensitiveInfoValues[19] = 200;
  wantsSensitiveInfoValues[20] = 200;
  wantsSensitiveInfoValues[21] = 200;
  wantsSensitiveInfoValues[22] = 200;
  wantsSensitiveInfoValues[23] = 200;
  wantsSensitiveInfoValues[24] = 200;
  wantsSensitiveInfoValues[25] = 200;
  wantsSensitiveInfoValues[26] = 200;
  wantsSensitiveInfoValues[27] = 200;
  wantsSensitiveInfoValues[28] = 200;
  wantsSensitiveInfoValues[29] = 200;
  wantsSensitiveInfoValues[30] = 200;
  wantsSensitiveInfoValues[31] = 200;
  wantsSensitiveInfoValues[32] = 200;
  wantsSensitiveInfoValues[33] = 200;
  wantsSensitiveInfoValues[34] = 200;
  wantsSensitiveInfoValues[35] = 200;
  wantsSensitiveInfoValues[36] = 200;
  wantsSensitiveInfoValues[37] = 200;
  wantsSensitiveInfoValues[38] = 200;
  wantsSensitiveInfoValues[39] = 200;
  wantsSensitiveInfoValues[40] = 200;
  wantsSensitiveInfoValues[41] = 200;
  wantsSensitiveInfoValues[42] = 200;
  wantsSensitiveInfoValues[43] = 200;
  wantsSensitiveInfoValues[44] = 200;
  wantsSensitiveInfoValues[45] = 200;
  wantsSensitiveInfoValues[46] = 200;
  wantsSensitiveInfoValues[47] = 200;
  wantsSensitiveInfoValues[48] = 200;
  wantsSensitiveInfoValues[49] = 200;
  wantsSensitiveInfoValues[50] = 200;
  wantsSensitiveInfoValues[51] = 200;
  wantsSensitiveInfoValues[52] = 200;
  wantsSensitiveInfoValues[53] = 200;
  wantsSensitiveInfoValues[54] = 200;
  wantsSensitiveInfoValues[55] = 200;
  wantsSensitiveInfoValues[56] = 200;
  wantsSensitiveInfoValues[57] = 200;
  wantsSensitiveInfoValues[58] = 200;
  wantsSensitiveInfoValues[59] = 200;
  wantsSensitiveInfoValues[60] = 200;
  wantsSensitiveInfoValues[61] = 200;
  wantsSensitiveInfoValues[62] = 200;
  wantsSensitiveInfoValues[63] = 200;
  wantsSensitiveInfoValues[64] = 1000;
  wantsSensitiveInfoValues[65] = 1000;
  wantsSensitiveInfoValues[66] = 1000;
  wantsSensitiveInfoValues[67] = 1000;
  wantsSensitiveInfoValues[68] = 1000;
  wantsSensitiveInfoValues[69] = 1000;
  wantsSensitiveInfoValues[70] = 1000;
  wantsSensitiveInfoValues[71] = 1000;
  wantsSensitiveInfoValues[72] = 1000;
  wantsSensitiveInfoValues[73] = 1000;
  wantsSensitiveInfoValues[74] = 1000;
  wantsSensitiveInfoValues[75] = 1000;
  wantsSensitiveInfoValues[76] = 1000;
  wantsSensitiveInfoValues[77] = 1000;
  wantsSensitiveInfoValues[78] = 1000;
  wantsSensitiveInfoValues[79] = 1000;
  wantsSensitiveInfoValues[80] = 1000;
  wantsSensitiveInfoValues[81] = 1000;
  wantsSensitiveInfoValues[82] = 1000;
  wantsSensitiveInfoValues[83] = 1000;
  wantsSensitiveInfoValues[84] = 1000;
  wantsSensitiveInfoValues[85] = 1000;
  wantsSensitiveInfoValues[86] = 1000;
  wantsSensitiveInfoValues[87] = 1000;
  wantsSensitiveInfoValues[88] = 1000;
  wantsSensitiveInfoValues[89] = 1000;
  wantsSensitiveInfoValues[90] = 1000;
  wantsSensitiveInfoValues[91] = 1000;
  wantsSensitiveInfoValues[92] = 1000;
  wantsSensitiveInfoValues[93] = 1000;
  wantsSensitiveInfoValues[94] = 1000;
  wantsSensitiveInfoValues[95] = 1000;
  wantsSensitiveInfoValues[96] = 1000;
  wantsSensitiveInfoValues[97] = 1000;
  wantsSensitiveInfoValues[98] = 1000;
  wantsSensitiveInfoValues[99] = 1000;
  wantsSensitiveInfoValues[100] = 1000;
  wantsSensitiveInfoValues[101] = 1000;
  wantsSensitiveInfoValues[102] = 1000;
  wantsSensitiveInfoValues[103] = 1000;
  wantsSensitiveInfoValues[104] = 1000;
  wantsSensitiveInfoValues[105] = 1000;
  wantsSensitiveInfoValues[106] = 1000;
  wantsSensitiveInfoValues[107] = 1000;
  wantsSensitiveInfoValues[108] = 1000;
  wantsSensitiveInfoValues[109] = 1000;
  wantsSensitiveInfoValues[110] = 1000;
  wantsSensitiveInfoValues[111] = 1000;
  wantsSensitiveInfoValues[112] = 1000;
  wantsSensitiveInfoValues[113] = 1000;
  wantsSensitiveInfoValues[114] = 1000;
  wantsSensitiveInfoValues[115] = 1000;
  wantsSensitiveInfoValues[116] = 1000;
  wantsSensitiveInfoValues[117] = 1000;
  wantsSensitiveInfoValues[118] = 1000;
  wantsSensitiveInfoValues[119] = 1000;
  wantsSensitiveInfoValues[120] = 1000;
  wantsSensitiveInfoValues[121] = 1000;
  wantsSensitiveInfoValues[122] = 1000;
  wantsSensitiveInfoValues[123] = 1000;
  wantsSensitiveInfoValues[124] = 1000;
  wantsSensitiveInfoValues[125] = 1000;
  wantsSensitiveInfoValues[126] = 1000;
  wantsSensitiveInfoValues[127] = 1000;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void studyRangeStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "apConfigProf\tshort\t" << apConfigProf << endl;
  cout << "hasHardware\tbool\t" << hasHardware << endl;
  cout << "networkHackingProf\tshort\t" << networkHackingProf << endl;
  cout << "packetForgingProf\tshort\t" << packetForgingProf << endl;
  cout << "socialEngineeringProf\tshort\t" << socialEngineeringProf << endl;
  cout << "wantsDOS\tshort\t" << wantsDOS << endl;
  cout << "wantsSensitiveInfo\tshort\t" << wantsSensitiveInfo << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *studyRangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("apConfigProf", TheGVName) == 0)
    return &apConfigProf;
  else if (strcmp("hasHardware", TheGVName) == 0)
    return &hasHardware;
  else if (strcmp("networkHackingProf", TheGVName) == 0)
    return &networkHackingProf;
  else if (strcmp("packetForgingProf", TheGVName) == 0)
    return &packetForgingProf;
  else if (strcmp("socialEngineeringProf", TheGVName) == 0)
    return &socialEngineeringProf;
  else if (strcmp("wantsDOS", TheGVName) == 0)
    return &wantsDOS;
  else if (strcmp("wantsSensitiveInfo", TheGVName) == 0)
    return &wantsSensitiveInfo;
  else 
    cerr<<"!! studyRangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void studyRangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("apConfigProf", TheGVName) == 0)
    SetGvValue(apConfigProf, *(short *)TheGVValue);
  else if (strcmp("hasHardware", TheGVName) == 0)
    SetGvValue(hasHardware, *(bool *)TheGVValue);
  else if (strcmp("networkHackingProf", TheGVName) == 0)
    SetGvValue(networkHackingProf, *(short *)TheGVValue);
  else if (strcmp("packetForgingProf", TheGVName) == 0)
    SetGvValue(packetForgingProf, *(short *)TheGVValue);
  else if (strcmp("socialEngineeringProf", TheGVName) == 0)
    SetGvValue(socialEngineeringProf, *(short *)TheGVValue);
  else if (strcmp("wantsDOS", TheGVName) == 0)
    SetGvValue(wantsDOS, *(short *)TheGVValue);
  else if (strcmp("wantsSensitiveInfo", TheGVName) == 0)
    SetGvValue(wantsSensitiveInfo, *(short *)TheGVValue);
  else 
    cerr<<"!! studyRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void studyRangeStudy::SetGVs(int expNum) {
  SetGvValue(apConfigProf, apConfigProfValues[expNum]);
  SetGvValue(hasHardware, hasHardwareValues[expNum]);
  SetGvValue(networkHackingProf, networkHackingProfValues[expNum]);
  SetGvValue(packetForgingProf, packetForgingProfValues[expNum]);
  SetGvValue(socialEngineeringProf, socialEngineeringProfValues[expNum]);
  SetGvValue(wantsDOS, wantsDOSValues[expNum]);
  SetGvValue(wantsSensitiveInfo, wantsSensitiveInfoValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new studyRangeStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* studyRangeStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new rewardPVModel(expandTimeArrays);
  return ThePVModel;
}


