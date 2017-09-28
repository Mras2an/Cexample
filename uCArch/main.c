#include <stdio.h>
#include <stdlib.h>
#include "plugs.h"

plugin_functs plugs[] = {
   PLUGS_DECLARATIONS
};

static void plugs_init(void)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);
  log_info("Nb plugins init detected: %i\n", (nb_plugins / 2));

  int i;
  for (i = 0; i < (nb_plugins / 2); i++)
    (plugs[i].ptfx_init)();
}

static void plugs_exit(void)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);
  log_info("Nb plugins exit detected: %i\n", (nb_plugins / 2));

  int i;
  for (i = 0; i < (nb_plugins / 2); i++)
    (plugs[i].ptfx_exit)();
}


void main()
{
  /* Call all the plugins declared with "PLUGIN_INIT" */
  plugs_init();

  /* Call all the plugins declared with "PLUGIN_EXIT" */
  plugs_exit();
}


