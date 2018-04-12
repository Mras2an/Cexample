#include <stdio.h>
#include <stdlib.h>
#include "plugs.h"

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
    (*bb).print();
    (*bb).send("test 2");
  }

  /* Call all the plugins declared with "PLUGIN_EXIT" */
  plugs_exit();
}


