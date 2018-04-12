#include <stdio.h>
#include "plugs.h"

/*********************************************************
 *                                                       *
 ********************************************************/
static void exPlug2_print(void)
{
  log_info("print2\n");
}

static void exPlug2_send(char * data)
{
  log_info("send2: %s\n", data);
}




/*********************************************************
 *                                                       *
 ********************************************************/
static struct exPlug2_api api_funcs2 =
{
  .print        = exPlug2_print,
  .send         = exPlug2_send,
};

static void exPlug2_init(void)
{
  log_info("init\n");
}

static void exPlug2_setHal(void)
{
  //log_info("HAL\n");
  //plugsHandling_setInterface(__FUNCTION__, &api_funcs2);
}

static void exPlug2_exit(void)
{
  log_info("exit\n");
}

PLUGIN_INIT(exPlug2_init)
PLUGIN_INIT(exPlug2_setHal)
PLUGIN_EXIT(exPlug2_exit)
