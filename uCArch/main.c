#include <stdio.h>
#include <stdlib.h>
#include "plugs.h"

void main()
{
  /* Call all the plugins declared with "PLUGIN_INIT" */
  plugs_init(PLUG_INIT_APP_AT_BOOT);
  plugs_init(PLUG_INIT_BEFORE_IAP_MODE);
  struct exPlug1_api * aa = plugsHandling_getInterface("exPlug1_api");

  if(aa != NULL)
  {
    aa->print();
    aa->send("test");
  }

  struct exPlug2_api * bb = plugsHandling_getInterface("exPlug2_api");

  if(bb != NULL)
  {
    (*bb).print();
    (*bb).send("test 2");
  }

  plugsHandling_removeAllInterface();
  plugs_init(PLUG_INIT_APP_AT_BOOT);
  plugs_init(PLUG_INIT_BEFORE_IAP_MODE);
  struct exPlug1_api * dd = plugsHandling_getInterface("exPlug1_api");

  if(dd != NULL)
  {
    dd->print();
    dd->send("test3");
  }

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


