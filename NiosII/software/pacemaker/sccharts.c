/*
 * Automatically generated C code by
 * KIELER SCCharts - The Key to Efficient Modeling
 *
 * http://rtsys.informatik.uni-kiel.de/kieler
 */

#include "timing.h"

#include "sccharts.h"

void logic(TickData* d) {
  d->AP = 0;
  d->VP = 0;
  d->AVI_event = 0;
  d->PVARP_event = 0;
  d->VRP_event = 0;
  d->AEI_event = 0;
  d->LRI_event = 0;
  d->URI_event = 0;
  d->_pre_AVI_event = d->_reg_AVI_event;
  d->_g104 = d->_pg86;
  d->_cg104 = d->_pre_AVI_event;
  d->_g105 = d->_g104 && d->_cg104;
  if (d->_g105) {
    d->URI = 1;
  }
  d->_g147 = d->_pg102;
  if (d->_g147) {
    d->_region5_rURI_URI_clock += d->deltaT;
  }
  d->_g117 = d->_pg108;
  d->_cg117 = d->_region5_rURI_URI_clock >= d->URI_CON;
  d->_g118 = d->_g117 && d->_cg117;
  if (d->_g118) {
    d->_PaceMaker_local__Atrig7 = 1;
  }
  if (d->_g105) {
    d->_region5_rURI_URI_clock = 0;
    d->_PaceMaker_local__Atrig7 = 0;
  }
  d->_g111 = d->_pg110;
  d->_g114 = d->_pg113;
  d->_g114 = d->_g105 || d->_g111 || d->_g114;
  d->_cg107 = d->_region5_rURI_URI_clock < d->URI_CON;
  d->_g111 = d->_g114 && !d->_cg107;
  d->_cg112 = d->_PaceMaker_local__Atrig7;
  d->_g113 = d->_g111 && !d->_cg112;
  d->sleepT = 1000.0;
  d->_g107 = d->_g114 && d->_cg107;
  if (d->_g107) {
    d->sleepT = (d->sleepT < (d->URI_CON - d->_region5_rURI_URI_clock)) ? d->sleepT : (d->URI_CON - d->_region5_rURI_URI_clock);
  }
  d->_cg108 = d->_PaceMaker_local__Atrig7;
  d->_g110 = d->_g107 && !d->_cg108;
  d->_g109_e1 = !(d->_g113 || d->_g110);
  d->_g112 = (d->_g107 && d->_cg108) || (d->_g111 && d->_cg112);
  d->_g108 = d->_g105 || (d->_g117 && !d->_cg117);
  d->_g105 = !d->_g108;
  d->_g117 = (d->_g109_e1 || d->_g112) && (d->_g105 || d->_g118) && (d->_g112 || d->_g118);
  d->_g118_e2 = d->_GO || d->_g117;
  if (d->_g118_e2) {
    d->URI = 0;
  }
  d->_g109 = d->_pg86_e1;
  if (d->_g109) {
    d->_region0_rAVI_AVI_clock += d->deltaT;
  }
  d->_g118 = d->_pg109_e1;
  d->_g109_e1 = d->_GO || d->_g118;
  if (d->_g109_e1) {
    d->_pre_LRI = d->_reg_LRI;
  }
  d->_g119 = d->_pg13;
  d->_cg18 = (d->_region0_rAVI_AVI_clock >= d->AVI_CON && !d->URI) || !d->_pre_LRI;
  d->_g160 = d->_g119 && d->_cg18;
  if (d->_g160) {
    d->_PaceMaker_local__Atrig = 1;
  }
  d->_g37 = d->_pg24;
  d->_cg37 = d->_pre_AVI_event;
  d->_g38 = d->_g37 && d->_cg37;
  if (d->_g38) {
    d->VRP = 1;
  }
  d->_g135 = d->_pg99;
  if (d->_g135) {
    d->_region2_rVRP_VRP_clock += d->deltaT;
  }
  d->_g50 = d->_pg41;
  d->_cg50 = d->_region2_rVRP_VRP_clock >= d->VRP_CON;
  d->_g51 = d->_g50 && d->_cg50;
  if (d->_g51) {
    d->_PaceMaker_local__Atrig2 = 1;
  }
  if (d->_g38) {
    d->_region2_rVRP_VRP_clock = 0;
    d->_PaceMaker_local__Atrig2 = 0;
  }
  d->_g44 = d->_pg43;
  d->_g47 = d->_pg46;
  d->_g44 = d->_g38 || d->_g44 || d->_g47;
  d->_cg40 = d->_region2_rVRP_VRP_clock < d->VRP_CON;
  d->_g47 = d->_g44 && !d->_cg40;
  d->_cg45 = d->_PaceMaker_local__Atrig2;
  d->_g46 = d->_g47 && !d->_cg45;
  d->_g40 = d->_g44 && d->_cg40;
  if (d->_g40) {
    d->sleepT = (d->sleepT < (d->VRP_CON - d->_region2_rVRP_VRP_clock)) ? d->sleepT : (d->VRP_CON - d->_region2_rVRP_VRP_clock);
  }
  d->_cg41 = d->_PaceMaker_local__Atrig2;
  d->_g43 = d->_g40 && !d->_cg41;
  d->_g42_e1 = !(d->_g46 || d->_g43);
  d->_g45 = (d->_g40 && d->_cg41) || (d->_g47 && d->_cg45);
  d->_g41 = d->_g38 || (d->_g50 && !d->_cg50);
  d->_g38 = !d->_g41;
  d->_g50 = (d->_g42_e1 || d->_g45) && (d->_g38 || d->_g51) && (d->_g45 || d->_g51);
  d->_g51 = d->_GO || d->_g50;
  if (d->_g51) {
    d->VRP = 0;
  }
  d->_g42 = d->_g119 && !d->_cg18;
  d->_cg21 = d->VS && !d->VRP;
  d->_g51_e2 = d->_g42 && d->_cg21;
  if (d->_g51_e2) {
    d->_PaceMaker_local__Atrig1 = 1;
  }
  d->_g42_e1 = d->_pg10;
  d->_cg29 = d->_pre_AVI_event;
  d->_g52 = d->_g42_e1 && d->_cg29;
  if (d->_g52) {
    d->PVARP = 1;
  }
  d->_g18 = d->_pg23;
  d->_cg32 = d->PVARP >= d->PVARP_CON;
  d->_g27 = d->_GO || (d->_g18 && d->_cg32);
  if (d->_g27) {
    d->PVARP = 0;
  }
  d->_g139 = d->_pg81;
  if (d->_g139) {
    d->_region3_rAEI_AEI_clock += d->deltaT;
  }
  d->_g70 = d->_pg61;
  d->_cg70 = d->_region3_rAEI_AEI_clock >= d->AEI_CON;
  d->_g71 = d->_g70 && d->_cg70;
  if (d->_g71) {
    d->_PaceMaker_local__Atrig3 = 1;
  }
  d->_g70 = d->_g70 && !d->_cg70;
  d->_g74 = d->_g70 && d->AS;
  if (d->_g74) {
    d->_PaceMaker_local__Atrig4 = 1;
  }
  d->_g57 = d->_pg27;
  d->_cg57 = d->_pre_AVI_event;
  d->_g58 = d->_g57 && d->_cg57;
  if (d->_g58) {
    d->AEI = 1;
    d->_region3_rAEI_AEI_clock = 0;
    d->_PaceMaker_local__Atrig3 = 0;
    d->_PaceMaker_local__Atrig4 = 0;
  }
  d->_g64 = d->_pg63;
  d->_g67 = d->_pg66;
  d->_g67 = d->_g58 || d->_g64 || d->_g67;
  d->_cg60 = d->_region3_rAEI_AEI_clock < d->AEI_CON;
  d->_g64 = d->_g67 && !d->_cg60;
  d->_cg65 = d->_PaceMaker_local__Atrig3 || d->_PaceMaker_local__Atrig4;
  d->_g66 = d->_g64 && !d->_cg65;
  d->_g60 = d->_g67 && d->_cg60;
  if (d->_g60) {
    d->sleepT = (d->sleepT < (d->AEI_CON - d->_region3_rAEI_AEI_clock)) ? d->sleepT : (d->AEI_CON - d->_region3_rAEI_AEI_clock);
  }
  d->_cg61 = d->_PaceMaker_local__Atrig3 || d->_PaceMaker_local__Atrig4;
  d->_g63 = d->_g60 && !d->_cg61;
  d->_g62_e1 = !(d->_g66 || d->_g63);
  d->_g65 = (d->_g60 && d->_cg61) || (d->_g64 && d->_cg65);
  d->_g61 = d->_g58 || (d->_g70 && !d->AS);
  d->_g73 = !d->_g61;
  d->_g58 = d->_g71 || d->_g74;
  d->_g74 = (d->_g62_e1 || d->_g65) && (d->_g73 || d->_g58) && (d->_g65 || d->_g58);
  if (d->_g74) {
    d->AEI_event |= 1;
  }
  d->_g71 = d->_pg20;
  d->_cg5 = (d->AS && !d->PVARP) || d->AEI_event;
  d->_g62 = d->_g71 && d->_cg5;
  if (d->_g62) {
    d->AVI = 1;
    d->_region0_rAVI_AVI_clock = 0;
    d->_PaceMaker_local__Atrig = 0;
    d->_PaceMaker_local__Atrig1 = 0;
  }
  d->_g72_e2 = d->_pg11;
  d->_g62_e1 = d->_pg12;
  d->_g72 = d->_g62 || d->_g72_e2 || d->_g62_e1;
  d->_cg8 = d->_region0_rAVI_AVI_clock < d->AVI_CON;
  d->_g15 = d->_g72 && !d->_cg8;
  d->_cg13 = d->_PaceMaker_local__Atrig || d->_PaceMaker_local__Atrig1;
  d->_g12 = d->_g15 && !d->_cg13;
  d->_g8 = d->_g72 && d->_cg8;
  if (d->_g8) {
    d->sleepT = (d->sleepT < (d->AVI_CON - d->_region0_rAVI_AVI_clock)) ? d->sleepT : (d->AVI_CON - d->_region0_rAVI_AVI_clock);
  }
  d->_cg9 = d->_PaceMaker_local__Atrig || d->_PaceMaker_local__Atrig1;
  d->_g11 = d->_g8 && !d->_cg9;
  d->_g10_e1 = !(d->_g12 || d->_g11);
  d->_g9 = (d->_g8 && d->_cg9) || (d->_g15 && d->_cg13);
  d->_g13 = d->_g62 || (d->_g42 && !d->_cg21);
  d->_g21 = !d->_g13;
  d->_g6 = d->_g160 || d->_g51_e2;
  d->_g22 = (d->_g10_e1 || d->_g9) && (d->_g21 || d->_g6) && (d->_g9 || d->_g6);
  if (d->_g22) {
    d->AVI_event |= 1;
  }
  d->_cg23 = d->_PaceMaker_local__Atrig;
  d->_g19 = d->_g22 && d->_cg23;
  if (d->_g19) {
    d->VP |= 1;
  }
  d->_g10_e1 = d->_GO || d->_g19 || (d->_g22 && !d->_cg23);
  if (d->_g10_e1) {
    d->AVI = 0;
  }
  d->_g20 = d->_g10_e1 || (d->_g71 && !d->_cg5);
  d->_g10 = d->_g27 || (d->_g42_e1 && !d->_cg29);
  d->_g20_e2 = d->_pg96_e2;
  if (d->_g20_e2) {
    d->_region1_rPVARP_PVARP_clock += d->deltaT;
  }
  if (d->_g52) {
    d->_region1_rPVARP_PVARP_clock = 0;
  }
  d->_g23 = d->_g52 || (d->_g18 && !d->_cg32);
  d->_g24 = d->_g51 || (d->_g37 && !d->_cg37);
  d->_cg75 = d->_PaceMaker_local__Atrig3;
  d->_g5 = d->_g74 && d->_cg75;
  if (d->_g5) {
    d->AP |= 1;
  }
  d->_g3 = d->_GO || d->_g5 || (d->_g74 && !d->_cg75);
  if (d->_g3) {
    d->AEI = 0;
  }
  d->_g27 = d->_g3 || (d->_g57 && !d->_cg57);
  d->_g29 = d->_pg85;
  d->_cg94 = d->AVI_event;
  d->_g30 = d->_g29 && d->_cg94;
  if (d->_g30) {
    d->_PaceMaker_local__Atrig5 = 1;
  }
  d->_g32 = d->_pg79;
  if (d->_g32) {
    d->_region4_rLRI_LRI_clock += d->deltaT;
  }
  d->_g37 = d->_g29 && !d->_cg94;
  d->_cg97 = d->_region4_rLRI_LRI_clock >= d->LRI_CON;
  d->_g35 = d->_g37 && d->_cg97;
  if (d->_g35) {
    d->_PaceMaker_local__Atrig6 = 1;
  }
  d->_g75 = d->_pg96;
  d->_cg81 = d->_pre_AVI_event;
  d->_g76 = d->_g75 && d->_cg81;
  if (d->_g76) {
    d->LRI = 1;
    d->_region4_rLRI_LRI_clock = 0;
    d->_PaceMaker_local__Atrig5 = 0;
    d->_PaceMaker_local__Atrig6 = 0;
  }
  d->_g55 = d->_pg87;
  d->_g57 = d->_pg88;
  d->_g94 = d->_g76 || d->_g55 || d->_g57;
  d->_cg84 = d->_region4_rLRI_LRI_clock < d->LRI_CON;
  d->_g91 = d->_g94 && !d->_cg84;
  d->_cg89 = d->_PaceMaker_local__Atrig5 || d->_PaceMaker_local__Atrig6;
  d->_g88 = d->_g91 && !d->_cg89;
  d->_g84 = d->_g94 && d->_cg84;
  if (d->_g84) {
    d->sleepT = (d->sleepT < (d->LRI_CON - d->_region4_rLRI_LRI_clock)) ? d->sleepT : (d->LRI_CON - d->_region4_rLRI_LRI_clock);
  }
  d->_cg85 = d->_PaceMaker_local__Atrig5 || d->_PaceMaker_local__Atrig6;
  d->_g87 = d->_g84 && !d->_cg85;
  d->_g86_e1 = !(d->_g88 || d->_g87);
  d->_g89 = (d->_g84 && d->_cg85) || (d->_g91 && d->_cg89);
  d->_g85 = d->_g76 || (d->_g37 && !d->_cg97);
  d->_g97 = !d->_g85;
  d->_g82 = d->_g30 || d->_g35;
  d->_g95 = (d->_g86_e1 || d->_g89) && (d->_g97 || d->_g82) && (d->_g89 || d->_g82);
  d->_cg99 = d->_PaceMaker_local__Atrig5;
  d->_g98 = d->_GO || (d->_g95 && d->_cg99) || (d->_g95 && d->_cg99);
  if (d->_g98) {
    d->LRI = 0;
  }
  d->_g96 = d->_g98 || (d->_g75 && !d->_cg81);
  d->_g86 = d->_g118_e2 || (d->_g104 && !d->_cg104);
  d->_g86_e1 = d->_GO || d->_g109;
  d->_g96_e2 = d->_GO || d->_g20_e2;
  d->_g99 = d->_GO || d->_g135;
  d->_g81 = d->_GO || d->_g139;
  d->_g79 = d->_GO || d->_g32;
  d->_g102 = d->_GO || d->_g147;
  d->_reg_AVI_event = d->AVI_event;
  if (d->_g109_e1) {
    d->_reg_LRI = d->LRI;
  }
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
  d->_region0_rAVI_AVI_clock = 0;
  d->_region1_rPVARP_PVARP_clock = 0;
  d->_region2_rVRP_VRP_clock = 0;
  d->_region3_rAEI_AEI_clock = 0;
  d->_region4_rLRI_LRI_clock = 0;
  d->_region5_rURI_URI_clock = 0;
  d->deltaT = 0.0;
  d->sleepT = 0.0;
  d->AP = 0;
  d->VP = 0;
  d->AVI_event = 0;
  d->PVARP_event = 0;
  d->VRP_event = 0;
  d->AEI_event = 0;
  d->LRI_event = 0;
  d->URI_event = 0;
  d->_reg_AVI_event = 0;
  d->_reg_LRI = 0;
  d->_pg86 = 0;
  d->_pg102 = 0;
  d->_pg108 = 0;
  d->_pg110 = 0;
  d->_pg113 = 0;
  d->_pg86_e1 = 0;
  d->_pg109_e1 = 0;
  d->_pg13 = 0;
  d->_pg24 = 0;
  d->_pg99 = 0;
  d->_pg41 = 0;
  d->_pg43 = 0;
  d->_pg46 = 0;
  d->_pg10 = 0;
  d->_pg23 = 0;
  d->_pg81 = 0;
  d->_pg61 = 0;
  d->_pg27 = 0;
  d->_pg63 = 0;
  d->_pg66 = 0;
  d->_pg20 = 0;
  d->_pg11 = 0;
  d->_pg12 = 0;
  d->_pg96_e2 = 0;
  d->_pg85 = 0;
  d->_pg79 = 0;
  d->_pg96 = 0;
  d->_pg87 = 0;
  d->_pg88 = 0;
}

void tick(TickData* d) {
  logic(d);

  d->_pg86 = d->_g86;
  d->_pg102 = d->_g102;
  d->_pg108 = d->_g108;
  d->_pg110 = d->_g110;
  d->_pg113 = d->_g113;
  d->_pg86_e1 = d->_g86_e1;
  d->_pg109_e1 = d->_g109_e1;
  d->_pg13 = d->_g13;
  d->_pg24 = d->_g24;
  d->_pg99 = d->_g99;
  d->_pg41 = d->_g41;
  d->_pg43 = d->_g43;
  d->_pg46 = d->_g46;
  d->_pg10 = d->_g10;
  d->_pg23 = d->_g23;
  d->_pg81 = d->_g81;
  d->_pg61 = d->_g61;
  d->_pg27 = d->_g27;
  d->_pg63 = d->_g63;
  d->_pg66 = d->_g66;
  d->_pg20 = d->_g20;
  d->_pg11 = d->_g11;
  d->_pg12 = d->_g12;
  d->_pg96_e2 = d->_g96_e2;
  d->_pg85 = d->_g85;
  d->_pg79 = d->_g79;
  d->_pg96 = d->_g96;
  d->_pg87 = d->_g87;
  d->_pg88 = d->_g88;
  d->_GO = 0;
}
