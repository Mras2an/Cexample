#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_INTERFACE 10
typedef struct splugsHandling
{
  char * name;
  void * tmp;
} plugsHandling_t[MAX_INTERFACE];

static plugsHandling_t plugsHandling;
#define this (&plugsHandling)

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
    if(strncmp(interfaceName, this[i]->name, strlen(interfaceName)) == 0)
      return this[i]->tmp;
  }
}
