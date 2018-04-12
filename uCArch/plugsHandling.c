#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "plugs.h"

#define MAX_INTERFACE 10
typedef struct splugsHandling
{
  char * name;
  void * tmp;
} plugsHandling_t[MAX_INTERFACE];

static plugsHandling_t plugsHandling;
#define this (&plugsHandling)

plugin_functs plugs[] =
{
  PLUGS_DECLARATIONS
};

plugin_functs_hal plugsHal[] =
{
  PLUGS_SETHAL
};

void plugs_init(void)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);
  log_plug("Nb plugins init detected: %i\n", (nb_plugins / 2));

  for(int i = 0; i < (nb_plugins / 2); i++)
    (plugs[i].ptfx_init)();
}

void plugs_setHal(void)
{
  int nb_plugins_hal = ((int)sizeof(plugsHal) / (int)ADDR_SIZE);
  log_plug("Nb HAL detected: %i\n", nb_plugins_hal);

  for(int i = 0; i < nb_plugins_hal; i++)
    (plugsHal[i].ptfx_setHal)();
}

void plugs_exit(void)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);
  log_plug("Nb plugins exit detected: %i\n", (nb_plugins / 2));

  for(int i = 0; i < (nb_plugins / 2); i++)
    (plugs[i].ptfx_exit)();
}

void plugsHandling_setInterface(const char * name, void * tt)
{
  for(int i = 0; i < MAX_INTERFACE; i++)
  {
    if(this[i]->tmp == NULL)
    {
      this[i]->name = malloc(strlen(name) + 1);
      memset(this[i]->name, '\0', strlen(name) + 1);
      memcpy(this[i]->name, name, strlen(name));
      this[i]->tmp = tt;
      break;
    }
  }
}

void * plugsHandling_getInterface(const char * interfaceName)
{
  for(int i = 0; i < MAX_INTERFACE; i++)
  {
    if(this[i]->name != NULL)
      if(strncmp(interfaceName, this[i]->name, strlen(this[i]->name)) == 0)
        return this[i]->tmp;
  }

  return NULL;
}
