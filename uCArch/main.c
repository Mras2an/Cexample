#include <stdio.h>
#include <stdlib.h>
#include "plugs.h"

void main()
{
  /* Call all the plugins declared with "PLUGIN_INIT" */
  plugs_init(PLUG_INIT_APP_AT_BOOT);
  plugs_init(PLUG_INIT_BEFORE_IAP_MODE);
  struct exPlug1_api * gg = exPlug1_struct.interface;
  gg->print();
  gg->send("test");
  struct exPlug2_api * bb = plugsHandling_getInterface("exPlug2_api");

  if(bb != NULL)
  {
    (*bb).print();
    (*bb).send("test 2");
  }

  plugsHandling_removeAllInterface();
  plugs_init(PLUG_INIT_APP_AT_BOOT);
  plugs_init(PLUG_INIT_BEFORE_IAP_MODE);
  bb = plugsHandling_getInterface("exPlug2_api");

  if(bb != NULL)
  {
    (*bb).print();
    (*bb).send("test 4");
  }

  plugsHandling_removeAllInterface();
  /* Call all the plugins declared with "PLUGIN_EXIT" */
  plugs_exit(PLUG_INIT_APP_AT_BOOT);
  plugs_exit(PLUG_INIT_BEFORE_IAP_MODE);
}


