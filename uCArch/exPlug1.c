#include <stdio.h>
#include "plugs.h"

static void exPlug1_init(void)
{
  log_info("init\n");
}

static void exPlug1_exit(void)
{
  log_info("exit\n");
}

PLUGIN_INIT(exPlug1_init)
PLUGIN_EXIT(exPlug1_exit)
