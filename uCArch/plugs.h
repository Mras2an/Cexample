#ifndef __PLUG_H__
#define __PLUG_H__

#include "string.h"
#include "stdlib.h"

/* Macro for log */
#define log_info(msg, ...) printf("[INFO: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_plug(msg, ...) printf("[PLUG: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_err(msg, ...)  printf("[ERR : %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)


/* Macro to rename functions */
#define PLUGIN_ADD(initName, exitName, structName) void callback_ ## initName(void) { initName(); } \
  void callback_ ## exitName(void) { exitName(); } \
  static void api_## initName(void) \
  { \
    plugsHandling_setInterface(structName, &api_funcs); \
  } \
  void callbackApi_ ## initName (void) { api_## initName(); } /* TODO: Find another solution! */

#define PLUGIN_ADD_2(initName, exitName, structName) void callback_ ## initName(void) { initName(); } \
  void callback_ ## exitName(void) { exitName(); } \
  static void api_## initName(void) \
  { \
    exPlug1_struct.interface = &api_funcs; \
  } \
  void callbackApi_ ## initName (void) { api_## initName(); }

#define PLUGIN_RENAME(initName, exitName, priority)  extern void callback_##initName(void); \
  extern void callbackApi_##initName(void); \
  extern void callback_##exitName(void); \
  enum { def_##initName  = priority } /* TODO: Find another solution! */

#define PLUGIN_RENAME_2(initName, exitName, stru, priority)  extern void callback_##initName(void); \
  extern void callbackApi_##initName(void); \
  extern void callback_##exitName(void); \
  struct plugs_##stru { \
    void * interface; \
  } stru; \
  enum { def_##initName  = priority }

/* Macro to define cpu information */
#define BIT_PROCESSOR  64 /* Can be 64, 32, 16, 8 */
#define ADDR_SIZE      (BIT_PROCESSOR / 8)

typedef enum ePluginPriority
{
  PLUG_INIT_HARDWARE_AT_BOOT,
  PLUG_INIT_APP_AT_BOOT,
  PLUG_INIT_BEFORE_IAP_MODE,
  PLUG_INIT_AFTER_IAP_MODE,
  PLUG_INIT_BEFORE_AP_MODE,
  PLUG_INIT_AFTER_AP_MODE,
} ePluginPriority_t;

void plugsHandling_setInterface(const char * name, void * tt);
void * plugsHandling_getInterface(const char * interfaceName);
void plugsHandling_removeAllInterface(void);
void plugs_init(ePluginPriority_t prio);
void plugs_exit(ePluginPriority_t prio);

#endif
