/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sun Apr 15 19:53:33 IST 2018
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTbGCDSimple_h__
#define __mkTbGCDSimple_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTbGCDSimple module */
class MOD_mkTbGCDSimple : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_gcd_bz;
  MOD_Reg<tUInt32> INST_gcd_x;
  MOD_Reg<tUInt32> INST_gcd_y;
  MOD_Reg<tUInt32> INST_state;
 
 /* Constructor */
 public:
  MOD_mkTbGCDSimple(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_RL_exit;
  tUInt8 DEF_CAN_FIRE_RL_exit;
  tUInt8 DEF_WILL_FIRE_RL_finish;
  tUInt8 DEF_CAN_FIRE_RL_finish;
  tUInt8 DEF_WILL_FIRE_RL_go;
  tUInt8 DEF_CAN_FIRE_RL_go;
  tUInt8 DEF_WILL_FIRE_RL_gcd_stop;
  tUInt8 DEF_CAN_FIRE_RL_gcd_stop;
  tUInt8 DEF_WILL_FIRE_RL_gcd_swapANDsub;
  tUInt8 DEF_WILL_FIRE_RL_gcd_subtract;
  tUInt8 DEF_CAN_FIRE_RL_gcd_subtract;
  tUInt8 DEF_CAN_FIRE_RL_gcd_swapANDsub;
  tUInt32 DEF_gcd_y___d2;
  tUInt32 DEF_b__h194;
 
 /* Local definitions */
 private:
 
 /* Rules */
 public:
  void RL_gcd_swapANDsub();
  void RL_gcd_subtract();
  void RL_gcd_stop();
  void RL_go();
  void RL_finish();
  void RL_exit();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbGCDSimple &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbGCDSimple &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbGCDSimple &backing);
};

#endif /* ifndef __mkTbGCDSimple_h__ */
