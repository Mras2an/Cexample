#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "plugs.h"

#define MAX_INTERFACE 10

/* Struct */
typedef struct
{
  void (*ptfx_init)(void);
  void (*ptfx_exit)(void);
} plugin_functs;

typedef struct
{
  void (*ptfx_setApi)(void);
} plugin_functs_hal;

typedef struct
{
  int priority;
} plugin_priority;

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

plugin_priority plugsPriority[] =
{
  PLUGS_PRIORITY
};

void plugs_init(ePluginPriority_t prio)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);

  for(int i = 0; i < (nb_plugins / 2); i++)
  {
    if(prio == plugsPriority[i].priority)
    {
      (plugs[i].ptfx_init)();
      (plugsHal[i].ptfx_setApi)();
    }
    else if(prio == plugsPriority[i].priority)
    {
      (plugs[i].ptfx_init)();
      (plugsHal[i].ptfx_setApi)();
    }
    else if(prio  == plugsPriority[i].priority)
    {
      (plugs[i].ptfx_init)();
      (plugsHal[i].ptfx_setApi)();
    }
    else if(prio  == plugsPriority[i].priority)
    {
      (plugs[i].ptfx_init)();
      (plugsHal[i].ptfx_setApi)();
    }
    else if(prio  == plugsPriority[i].priority)
    {
      (plugs[i].ptfx_init)();
      (plugsHal[i].ptfx_setApi)();
    }
  }
}

void plugs_exit(ePluginPriority_t prio)
{
  int nb_plugins = ((int)sizeof(plugs) / (int)ADDR_SIZE);

  for(int i = 0; i < (nb_plugins / 2); i++)
  {
    if(prio == plugsPriority[i].priority)
      (plugs[i].ptfx_exit)();
    else if(prio == plugsPriority[i].priority)
      (plugs[i].ptfx_exit)();
    else if(prio  == plugsPriority[i].priority)
      (plugs[i].ptfx_exit)();
    else if(prio  == plugsPriority[i].priority)
      (plugs[i].ptfx_exit)();
    else if(prio  == plugsPriority[i].priority)
      (plugs[i].ptfx_exit)();
  }
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
