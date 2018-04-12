#include <stdio.h>
#include <stdlib.h>
#include "plugs.h"

plugin_functs plugs[] =
{
  PLUGS_DECLARATIONS
};

plugin_functs_hal plugsHal[] =
{
  PLUGS_SETHAL
};

static void plugs_init(void)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);
  log_plug("Nb plugins init detected: %i\n", (nb_plugins / 2));
  int i;

  for(i = 0; i < (nb_plugins / 2); i++)
    (plugs[i].ptfx_init)();
}

static void plugs_setHal(void)
{
  int nb_plugins_hal = ((int)sizeof(plugsHal) / (int)ADDR_SIZE);
  log_plug("Nb HAL detected: %i\n", nb_plugins_hal);

  for(int i = 0; i < nb_plugins_hal; i++)
    (plugsHal[i].ptfx_setHal)();
}

static void plugs_exit(void)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);
  log_plug("Nb plugins exit detected: %i\n", (nb_plugins / 2));
  int i;

  for(i = 0; i < (nb_plugins / 2); i++)
    (plugs[i].ptfx_exit)();
}

void main()
{
  /* Call all the plugins declared with "PLUGIN_INIT" */
  plugs_init();
  plugs_setHal();

  struct exPlug1_api * aa = plugsHandling_getInterface("exPlug1_setHal");
  if(aa != NULL)
  {
    aa->print();
    aa->send("test");
  }

  struct exPlug2_api * bb = plugsHandling_getInterface("exPlug2_setHal");
  if(bb != NULL)
  {
    bb->print();
    bb->send("test 2");
  }

  /* Call all the plugins declared with "PLUGIN_EXIT" */
  plugs_exit();
}


