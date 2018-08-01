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

typedef struct splugsHandling plugsHandling_t;
struct splugsHandling
{
  char * name;
  void * tmp;
  plugsHandling_t * next;
};

static plugsHandling_t * this;

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

int plugsHandling_find(plugsHandling_t * l, const char * name)
{
  if(l == NULL)
    return 0;

  if(strncmp(name, (*l).name, strlen((*l).name)) == 0)
    return 1;
  else
    return(plugsHandling_find((*l).next, name));
}


void plugsHandling_setInterface(const char * name, void * tt)
{
  if(plugsHandling_find(this, name))
    return;

  plugsHandling_t * p = malloc(sizeof(plugsHandling_t));
  (*p).name = malloc(strlen(name) + 1);
  memset((*p).name, '\0', strlen(name) + 1);
  memcpy((*p).name, name, strlen(name));
  (*p).tmp = tt;
  (*p).next = this;
  this = p;
}

void * plugsHandling_getInterface(const char * interfaceName)
{
  plugsHandling_t * p = this;

  while(p != NULL)
  {
    if((*p).name != NULL)
      if(strncmp(interfaceName, (*p).name, strlen((*p).name)) == 0)
        return (*p).tmp;

    p = (*p).next;
  }

  return NULL;
}

void plugsHandling_removeAllInterface(void)
{
  plugsHandling_t * p = this;

  while(this != NULL)
  {
    this = (*this).next;
    free((*p).name);
    (*p).name = NULL;
    free(p);
    p = this;
  }
}
