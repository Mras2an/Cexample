#include <stdio.h>
#include "plugs.h"

static void exPlug2_init(void)
{
  log_info("init\n");
}

static void exPlug2_exit(void)
{
  log_info("exit\n");
}

PLUGIN_INIT(exPlug2_init)
PLUGIN_EXIT(exPlug2_exit)
