/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"

#include "PaceMaker.h"

void logic(TickData* d) {
  d->APace = 0;
  d->VPace = 0;
  d->AVI_event = 0;
  d->PVARP_event = 0;
  d->VRP_event = 0;
  d->AEI_event = 0;
  d->LRI_event = 0;
  d->URI_event = 0;
  d->_g15 = d->_pg14;
  if (d->_g15) {
    d->_region0_AVI_AVI_clock += d->deltaT;
  }
  d->_g15 = d->_pg130;
  if (d->_g15) {
    d->_region4_LRI_LRI_clock += d->deltaT;
  }
  d->_g131 = d->_pg145;
  d->_cg146 = d->_region4_LRI_LRI_clock >= d->VRP_CON;
  d->_g146 = d->_g131 && d->_cg146;
  if (d->_g146) {
    d->_PaceMaker_local__Atrig9 = 1;
  }
  d->_g147 = d->_pg141;
  d->_g136 = d->_pg135;
  d->sleepT = 1000.0;
  d->_g142 = d->_g136 || d->_g147;
  d->_cg137 = d->_region4_LRI_LRI_clock < d->VRP_CON;
  d->_g136 = d->_g142 && d->_cg137;
  if (d->_g136) {
    d->sleepT = (d->sleepT < (d->VRP_CON - d->_region4_LRI_LRI_clock)) ? d->sleepT : (d->VRP_CON - d->_region4_LRI_LRI_clock);
  }
  d->_g137 = d->_pg120;
  if (d->_g137) {
    d->_region4_LRI_LRI_clock += d->deltaT;
  }
  d->_g138 = d->_pg167;
  if (d->_g138) {
    d->_region5_URI_URI_clock += d->deltaT;
  }
  d->_g121 = !d->_g138;
  d->_g183 = d->_pg182;
  d->_cg183 = d->_region5_URI_URI_clock >= d->VRP_CON;
  d->_g184 = d->_g183 && d->_cg183;
  if (d->_g184) {
    d->_PaceMaker_local__Atrig12 = 1;
  }
  d->_cg168 = d->_PaceMaker_local__Atrig12;
  d->_g168 = d->_g138 && d->_cg168;
  d->_g179 = d->_pg178;
  d->_g173 = d->_pg172;
  d->_g176_e2 = !(d->_g179 || d->_g173);
  d->_g179 = d->_g173 || d->_g179;
  d->_cg174 = d->_region5_URI_URI_clock < d->VRP_CON;
  d->_g173 = d->_g179 && d->_cg174;
  if (d->_g173) {
    d->sleepT = (d->sleepT < (d->VRP_CON - d->_region5_URI_URI_clock)) ? d->sleepT : (d->VRP_CON - d->_region5_URI_URI_clock);
  }
  d->_cg175 = d->_PaceMaker_local__Atrig12;
  d->_g174 = d->_g179 && !d->_cg174;
  d->_cg177 = d->_PaceMaker_local__Atrig12;
  d->_g175 = (d->_g173 && d->_cg175) || (d->_g174 && d->_cg177);
  d->_g177 = !d->_g183;
  d->_g183 = (d->_g121 || d->_g168) && (d->_g176_e2 || d->_g175) && (d->_g177 || d->_g184) && (d->_g168 || d->_g175 || d->_g184);
  if (d->_g183) {
    d->_taken_transitions[14] += 1;
  }
  d->_g176 = d->_GO || d->_g183;
  if (d->_g176) {
    d->URI = 0;
    d->_PaceMaker_local__Atrig11 = 0;
  }
  d->_g176_e2 = d->_pg158;
  if (d->_g176_e2) {
    d->_region5_URI_URI_clock += d->deltaT;
  }
  d->_g169_e1 = d->_pg25;
  d->_g184_e3 = d->_pg19;
  d->_g169 = d->_g184_e3 || d->_g169_e1;
  d->_cg21 = d->_region0_AVI_AVI_clock < d->AVI_CON;
  d->_g184 = d->_g169 && d->_cg21;
  if (d->_g184) {
    d->sleepT = (d->sleepT < (d->AVI_CON - d->_region0_AVI_AVI_clock)) ? d->sleepT : (d->AVI_CON - d->_region0_AVI_AVI_clock);
  }
  d->_g185 = d->_pg44;
  d->_cg45 = d->PVARP >= d->PVARP_CON;
  d->_g156 = d->_g185 && d->_cg45;
  if (d->_g156) {
    d->_taken_transitions[4] += 1;
  }
  d->_g159 = d->_GO || d->_g156;
  if (d->_g159) {
    d->PVARP = 0;
  }
  d->_g26 = d->_pg92;
  if (d->_g26) {
    d->_region3_AEI_AEI_clock += d->deltaT;
  }
  d->_g20 = !d->_g26;
  d->_g21 = d->_pg107;
  d->_cg108 = d->_region3_AEI_AEI_clock >= d->AEI_CON;
  d->_g22 = d->_g21 && d->_cg108;
  if (d->_g22) {
    d->_PaceMaker_local__Atrig6 = 1;
  }
  d->_g45 = d->_g21 && !d->_cg108;
  d->_g46 = d->_g45 && d->ASense;
  if (d->_g46) {
    d->_PaceMaker_local__Atrig7 = 1;
  }
  d->_cg93 = d->_PaceMaker_local__Atrig6 || d->_PaceMaker_local__Atrig7;
  d->_g40 = d->_g26 && d->_cg93;
  d->_g111 = d->_pg103;
  d->_g93 = d->_pg97;
  d->_g101_e2 = !(d->_g111 || d->_g93);
  d->_g98 = d->_g93 || d->_g111;
  d->_cg99 = d->_region3_AEI_AEI_clock < d->AEI_CON;
  d->_g104 = d->_g98 && d->_cg99;
  if (d->_g104) {
    d->sleepT = (d->sleepT < (d->AEI_CON - d->_region3_AEI_AEI_clock)) ? d->sleepT : (d->AEI_CON - d->_region3_AEI_AEI_clock);
  }
  d->_cg100 = d->_PaceMaker_local__Atrig6 || d->_PaceMaker_local__Atrig7;
  d->_g99 = d->_g98 && !d->_cg99;
  d->_cg102 = d->_PaceMaker_local__Atrig6 || d->_PaceMaker_local__Atrig7;
  d->_g102 = (d->_g104 && d->_cg100) || (d->_g99 && d->_cg102);
  d->_g100 = !d->_g21;
  d->_g108 = d->_g22 || d->_g46;
  d->_g112 = (d->_g20 || d->_g40) && (d->_g101_e2 || d->_g102) && (d->_g100 || d->_g108) && (d->_g40 || d->_g102 || d->_g108);
  if (d->_g112) {
    d->AEI_event |= 1;
  }
  d->_g109 = d->_pg5;
  if (d->_g109) {
    d->_region0_AVI_AVI_clock += d->deltaT;
  }
  d->_g101 = d->_pg60;
  if (d->_g101) {
    d->_region2_VRP_VRP_clock += d->deltaT;
  }
  d->_g101_e2 = !d->_g101;
  d->_g110 = d->_pg75;
  d->_cg76 = d->_region2_VRP_VRP_clock >= d->VRP_CON;
  d->_g110_e3 = d->_g110 && d->_cg76;
  if (d->_g110_e3) {
    d->_PaceMaker_local__Atrig4 = 1;
  }
  d->_cg61 = d->_PaceMaker_local__Atrig4;
  d->_g94 = d->_g101 && d->_cg61;
  d->_g94_e1 = d->_pg71;
  d->_g6 = d->_pg65;
  d->_g61 = !(d->_g94_e1 || d->_g6);
  d->_g66 = d->_g6 || d->_g94_e1;
  d->_cg67 = d->_region2_VRP_VRP_clock < d->VRP_CON;
  d->_g72 = d->_g66 && d->_cg67;
  if (d->_g72) {
    d->sleepT = (d->sleepT < (d->VRP_CON - d->_region2_VRP_VRP_clock)) ? d->sleepT : (d->VRP_CON - d->_region2_VRP_VRP_clock);
  }
  d->_cg68 = d->_PaceMaker_local__Atrig4;
  d->_g67 = d->_g66 && !d->_cg67;
  d->_cg70 = d->_PaceMaker_local__Atrig4;
  d->_g70 = (d->_g72 && d->_cg68) || (d->_g67 && d->_cg70);
  d->_g68 = !d->_g110;
  d->_g76 = (d->_g101_e2 || d->_g94) && (d->_g61 || d->_g70) && (d->_g68 || d->_g110_e3) && (d->_g94 || d->_g70 || d->_g110_e3);
  if (d->_g76) {
    d->_taken_transitions[6] += 1;
  }
  d->_g62 = d->_GO || d->_g76;
  if (d->_g62) {
    d->VRP = 0;
    d->_PaceMaker_local__Atrig3 = 0;
  }
  d->_cg50 = d->_PaceMaker_local__Atrig3;
  d->_g77_e3 = d->_pg51;
  if (d->_g77_e3) {
    d->_region2_VRP_VRP_clock += d->deltaT;
  }
  d->_cg113 = d->_PaceMaker_local__Atrig6;
  d->_g62_e1 = d->_g112 && d->_cg113;
  if (d->_g62_e1) {
    d->APace |= 1;
    d->_taken_transitions[8] += 1;
  }
  d->_g77 = d->_g112 && !d->_cg113;
  if (d->_g77) {
    d->_taken_transitions[9] += 1;
  }
  d->_g69_e2 = d->_GO || d->_g62_e1 || d->_g77;
  if (d->_g69_e2) {
    d->AEI = 0;
    d->_PaceMaker_local__Atrig5 = 0;
  }
  d->_cg82 = d->_PaceMaker_local__Atrig5;
  d->_g69 = d->_pg83;
  if (d->_g69) {
    d->_region3_AEI_AEI_clock += d->deltaT;
  }
  d->_cg157 = d->_PaceMaker_local__Atrig11;
}

void reset(TickData* d) {
  d->_GO = 1;
  d->_TERM = 0;
  d->AVI_CON = AVI_VALUE;
  d->AEI_CON = AEI_VALUE;
  d->PVARP_CON = PVARP_VALUE;
  d->VRP_CON = VRP_VALUE;
  d->LRI_CON = LRI_VALUE;
  d->URI_CON = URI_VALUE;
  d->AVI = 0;
  d->PVARP = 0;
  d->VRP = 0;
  d->AEI = 0;
  d->LRI = 0;
  d->URI = 0;
  d->_region0_AVI_AVI_clock = 0;
  d->_region1_PVARP_PVARP_clock = 0;
  d->_region2_VRP_VRP_clock = 0;
  d->_region3_AEI_AEI_clock = 0;
  d->_region4_LRI_LRI_clock = 0;
  d->_region5_URI_URI_clock = 0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->APace = 0;
  d->VPace = 0;
  d->AVI_event = 0;
  d->PVARP_event = 0;
  d->VRP_event = 0;
  d->AEI_event = 0;
  d->LRI_event = 0;
  d->URI_event = 0;
  d->_taken_transitions[0] = 0;
  d->_taken_transitions[1] = 0;
  d->_taken_transitions[2] = 0;
  d->_taken_transitions[3] = 0;
  d->_taken_transitions[4] = 0;
  d->_taken_transitions[5] = 0;
  d->_taken_transitions[6] = 0;
  d->_taken_transitions[7] = 0;
  d->_taken_transitions[8] = 0;
  d->_taken_transitions[9] = 0;
  d->_taken_transitions[10] = 0;
  d->_taken_transitions[11] = 0;
  d->_taken_transitions[12] = 0;
  d->_taken_transitions[13] = 0;
  d->_taken_transitions[14] = 0;
  d->_pg14 = 0;
  d->_pg130 = 0;
  d->_pg145 = 0;
  d->_pg141 = 0;
  d->_pg135 = 0;
  d->_pg120 = 0;
  d->_pg167 = 0;
  d->_pg182 = 0;
  d->_pg178 = 0;
  d->_pg172 = 0;
  d->_pg158 = 0;
  d->_pg25 = 0;
  d->_pg19 = 0;
  d->_pg44 = 0;
  d->_pg92 = 0;
  d->_pg107 = 0;
  d->_pg103 = 0;
  d->_pg97 = 0;
  d->_pg5 = 0;
  d->_pg60 = 0;
  d->_pg75 = 0;
  d->_pg71 = 0;
  d->_pg65 = 0;
  d->_pg51 = 0;
  d->_pg83 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg14 = d->_g14;
  d->_pg130 = d->_g130;
  d->_pg145 = d->_g145;
  d->_pg141 = d->_g141;
  d->_pg135 = d->_g135;
  d->_pg120 = d->_g120;
  d->_pg167 = d->_g167;
  d->_pg182 = d->_g182;
  d->_pg178 = d->_g178;
  d->_pg172 = d->_g172;
  d->_pg158 = d->_g158;
  d->_pg25 = d->_g25;
  d->_pg19 = d->_g19;
  d->_pg44 = d->_g44;
  d->_pg92 = d->_g92;
  d->_pg107 = d->_g107;
  d->_pg103 = d->_g103;
  d->_pg97 = d->_g97;
  d->_pg5 = d->_g5;
  d->_pg60 = d->_g60;
  d->_pg75 = d->_g75;
  d->_pg71 = d->_g71;
  d->_pg65 = d->_g65;
  d->_pg51 = d->_g51;
  d->_pg83 = d->_g83;
  d->_GO = 0;
}
