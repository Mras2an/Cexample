#include <stdio.h>
#include "plugs.h"

/*********************************************************
 *                                                       *
 ********************************************************/
static void exPlug2_print(void)
{
  log_plug("print2\n");
}

static void exPlug2_send(char * data)
{
  log_plug("send2: %s\n", data);
}




/*********************************************************
 *                                                       *
 ********************************************************/
static struct exPlug2_api api_funcs =
{
  .print        = exPlug2_print,
  .send         = exPlug2_send,
};

static void exPlug2_init(void)
{
  log_plug("init\n");
}

static void exPlug2_setHal(void)
{
  log_plug("HAL\n");
  plugsHandling_setInterface(__FUNCTION__, &api_funcs);
}

static void exPlug2_exit(void)
{
  log_plug("exit\n");
}

PLUGIN_ADD(exPlug2_init, exPlug2_setHal, exPlug2_exit)
