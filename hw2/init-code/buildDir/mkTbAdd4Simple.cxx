/*
 * Generated by Bluespec Compiler, version 2016.07.beta1 (build 34806, 2016-07-05)
 * 
 * On Sun Apr 15 19:30:17 IST 2018
 * 
 */
#include "bluesim_primitives.h"
#include "mkTbAdd4Simple.h"


/* String declarations */
static std::string const __str_literal_2("%d + %d = %d", 12u);
static std::string const __str_literal_3("FAILED %d + %d gave %d instead of %d", 36u);
static std::string const __str_literal_1("PASSED", 6u);


/* Constructor */
MOD_mkTbAdd4Simple::MOD_mkTbAdd4Simple(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_cycle(simHdl, "cycle", this, 32u, 0u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 2u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkTbAdd4Simple::init_symbols_0()
{
  init_symbol(&symbols[0u], "cycle", SYM_MODULE, &INST_cycle);
  init_symbol(&symbols[1u], "RL_test", SYM_RULE);
}


/* Rule actions */

void MOD_mkTbAdd4Simple::RL_test()
{
  tUInt8 DEF__theResult___fst__h215;
  tUInt32 DEF_x__h1962;
  tUInt8 DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_1_6_XOR_SE_ETC___d19;
  tUInt8 DEF_c_in__h1170;
  tUInt8 DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_2_2_XOR_SE_ETC___d15;
  tUInt8 DEF_c_in__h1270;
  tUInt8 DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_XOR_SEL__ETC___d11;
  tUInt8 DEF_NOT_cycle_EQ_8_AND_SEL_ARR_1_4_6_9_1_8_15_15_c_ETC___d44;
  tUInt8 DEF_NOT_cycle_EQ_8___d3;
  tUInt8 DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_4_6_9_1_8_15__ETC___d46;
  tUInt8 DEF_realAns__h166;
  tUInt8 DEF_test__h165;
  tUInt8 DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_AND_SEL__ETC___d43;
  tUInt8 DEF_cycle_EQ_8___d2;
  tUInt8 DEF_b__h351;
  tUInt8 DEF_b__h1068;
  tUInt8 DEF_b__h1169;
  tUInt8 DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8;
  tUInt8 DEF_b__h1269;
  tUInt8 DEF_a__h350;
  tUInt8 DEF_a__h1067;
  tUInt8 DEF_a__h1168;
  tUInt8 DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5;
  tUInt8 DEF_a__h1268;
  tUInt8 DEF_c_in__h1069;
  tUInt32 DEF_x__h708;
  DEF_x__h708 = INST_cycle.METH_read();
  switch (DEF_x__h708) {
  case 0u:
  case 4u:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)1u;
    break;
  case 1u:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)4u;
    break;
  case 2u:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)6u;
    break;
  case 3u:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)9u;
    break;
  case 5u:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)8u;
    break;
  case 6u:
  case 7u:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)15u;
    break;
  default:
    DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 = (tUInt8)10u;
  }
  DEF_a__h1268 = (tUInt8)(DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 >> 3u);
  DEF_a__h1168 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 >> 2u));
  DEF_a__h1067 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5 >> 1u));
  DEF_a__h350 = (tUInt8)((tUInt8)1u & DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5);
  switch (DEF_x__h708) {
  case 0u:
  case 6u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)1u;
    break;
  case 1u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)4u;
    break;
  case 2u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)11u;
    break;
  case 3u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)2u;
    break;
  case 4u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)7u;
    break;
  case 5u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)8u;
    break;
  case 7u:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)15u;
    break;
  default:
    DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 = (tUInt8)10u;
  }
  DEF_b__h1269 = (tUInt8)(DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 >> 3u);
  DEF_b__h1169 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 >> 2u));
  DEF_b__h1068 = (tUInt8)((tUInt8)1u & (DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8 >> 1u));
  DEF_b__h351 = (tUInt8)((tUInt8)1u & DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8);
  DEF_c_in__h1069 = (tUInt8)((tUInt8)1u & ((DEF_a__h350 & DEF_b__h351 ? (tUInt8)2u : (tUInt8)0u) >> 1u));
  DEF_cycle_EQ_8___d2 = DEF_x__h708 == 8u;
  DEF_realAns__h166 = (tUInt8)31u & (((tUInt8)31u & DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5) + ((tUInt8)31u & DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8));
  DEF_NOT_cycle_EQ_8___d3 = !DEF_cycle_EQ_8___d2;
  DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_XOR_SEL__ETC___d11 = DEF_a__h1268 ^ DEF_b__h1269;
  DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_2_2_XOR_SE_ETC___d15 = DEF_a__h1168 ^ DEF_b__h1169;
  DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_1_6_XOR_SE_ETC___d19 = DEF_a__h1067 ^ DEF_b__h1068;
  DEF_c_in__h1170 = (DEF_a__h1067 & DEF_b__h1068) | (DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_1_6_XOR_SE_ETC___d19 & DEF_c_in__h1069);
  DEF_c_in__h1270 = (DEF_a__h1168 & DEF_b__h1169) | (DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_2_2_XOR_SE_ETC___d15 & DEF_c_in__h1170);
  DEF_x__h1962 = DEF_x__h708 + 1u;
  DEF__theResult___fst__h215 = (tUInt8)15u & (((((DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_XOR_SEL__ETC___d11 ^ DEF_c_in__h1270) << 3u) | ((DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_2_2_XOR_SE_ETC___d15 ^ DEF_c_in__h1170) << 2u)) | ((DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_1_6_XOR_SE_ETC___d19 ^ DEF_c_in__h1069) << 1u)) | (tUInt8)((tUInt8)1u & (DEF_a__h350 ^ DEF_b__h351 ? (tUInt8)1u : (tUInt8)0u)));
  DEF_test__h165 = (tUInt8)31u & ((((DEF_a__h1268 & DEF_b__h1269) | (DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_XOR_SEL__ETC___d11 & DEF_c_in__h1270)) << 4u) | DEF__theResult___fst__h215);
  DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_AND_SEL__ETC___d43 = DEF_test__h165 == DEF_realAns__h166;
  DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_4_6_9_1_8_15__ETC___d46 = DEF_NOT_cycle_EQ_8___d3 && !DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_AND_SEL__ETC___d43;
  DEF_NOT_cycle_EQ_8_AND_SEL_ARR_1_4_6_9_1_8_15_15_c_ETC___d44 = DEF_NOT_cycle_EQ_8___d3 && DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle_BIT_3_AND_SEL__ETC___d43;
  if (!(PORT_RST_N == (tUInt8)0u))
  {
    if (DEF_cycle_EQ_8___d2)
      dollar_display(sim_hdl, this, "s", &__str_literal_1);
    if (DEF_cycle_EQ_8___d2)
      dollar_finish(sim_hdl, "32", 1u);
    if (DEF_NOT_cycle_EQ_8_AND_SEL_ARR_1_4_6_9_1_8_15_15_c_ETC___d44)
      dollar_display(sim_hdl,
		     this,
		     "s,4,4,5",
		     &__str_literal_2,
		     DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5,
		     DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8,
		     DEF_test__h165);
    if (DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_4_6_9_1_8_15__ETC___d46)
      dollar_display(sim_hdl,
		     this,
		     "s,4,4,5,5",
		     &__str_literal_3,
		     DEF_SEL_ARR_1_4_6_9_1_8_15_15_cycle___d5,
		     DEF_SEL_ARR_1_4_11_2_7_8_1_15_cycle___d8,
		     DEF_test__h165,
		     DEF_realAns__h166);
    if (DEF_NOT_cycle_EQ_8_AND_NOT_SEL_ARR_1_4_6_9_1_8_15__ETC___d46)
      dollar_finish(sim_hdl, "32", 1u);
  }
  INST_cycle.METH_write(DEF_x__h1962);
}


/* Methods */


/* Reset routines */

void MOD_mkTbAdd4Simple::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_cycle.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkTbAdd4Simple::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkTbAdd4Simple::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_cycle.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkTbAdd4Simple::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 2u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  num = INST_cycle.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkTbAdd4Simple::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbAdd4Simple &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkTbAdd4Simple::vcd_defs(tVCDDumpType dt, MOD_mkTbAdd4Simple &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
    }
}

void MOD_mkTbAdd4Simple::vcd_prims(tVCDDumpType dt, MOD_mkTbAdd4Simple &backing)
{
  INST_cycle.dump_VCD(dt, backing.INST_cycle);
}
