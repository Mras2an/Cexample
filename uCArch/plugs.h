#ifndef __PLUG_H__
#define __PLUG_H__

/* Macro for log */
#define log_info(msg, ...) printf("[INFO: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_plug(msg, ...) printf("[PLUG: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_err(msg, ...)  printf("[ERR : %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)

/* Macro to rename functions */
#define PLUGIN_ADD(initName, halName, exitName) void callback_ ## initName(void) { initName(); } \
  void callback_ ## halName(void) { halName(); } \
  void callback_ ## exitName(void) { exitName(); }

#define PLUGIN_RENAME(initName, halName, exitName)  extern void callback_##initName(void); \
  extern void callback_##halName(void); \
  extern void callback_##exitName(void);

/* Macro to define cpu information */
#define BIT_PROCESSOR  64 /* Can be 64, 32, 16, 8 */
#define ADDR_SIZE      (BIT_PROCESSOR / 8)

void plugsHandling_setInterface(const char * name, void * tt);
void * plugsHandling_getInterface(const char * interfaceName);
void plugs_init(void);
void plugs_setHal(void);
void plugs_exit(void);

#endif
