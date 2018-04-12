#include <stdio.h>
#include "exPlug1.h"

/*********************************************************
 *                                                       *
 ********************************************************/
static void exPlug1_print(void)
{
  log_plug("print\n");
}

static void exPlug1_send(char * data)
{
  log_plug("send: %s\n", data);
}




/*********************************************************
 *                                                       *
 ********************************************************/
static struct exPlug1_api api_funcs =
{
  .print        = exPlug1_print,
  .send         = exPlug1_send,
};

static void exPlug1_init(void)
{
  log_plug("init\n");
}

static void exPlug1_setHal(void)
{
  log_plug("HAL\n");
  plugsHandling_setInterface(__FUNCTION__, &api_funcs);
}

static void exPlug1_exit(void)
{
  log_plug("exit\n");
}

PLUGIN_INIT(exPlug1_init)
PLUGIN_INIT(exPlug1_setHal)
PLUGIN_EXIT(exPlug1_exit)


