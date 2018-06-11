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

struct exPlug2_api reurnStruct()
{
  return api_funcs;
}

static void exPlug2_exit(void)
{
  log_plug("exit\n");
}

PLUGIN_ADD(exPlug2_init, exPlug2_exit, "exPlug2_api")

