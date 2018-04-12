/* Macro for log */
#define log_info(msg, ...) printf("[INFO: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_plug(msg, ...) printf("[PLUG: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_err(msg, ...)  printf("[ERR : %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)

/* Macro to rename functions */
#define PLUGIN_INIT(name)    void callback_ ## name(void) { name(); }
#define PLUGIN_SET_HAL(name) void callback_ ## name(void) { name(); }
#define PLUGIN_EXIT(name)    void callback_ ## name(void) { name(); }

/* Macro to define cpu information */
#define BIT_PROCESSOR  64 /* Can be 64, 32, 16, 8 */
#define ADDR_SIZE      (BIT_PROCESSOR / 8)

/* Struct */
typedef struct
{
  void (*ptfx_init)(void);
  void (*ptfx_exit)(void);
} plugin_functs;

typedef struct
{
  void (*ptfx_setHal)(void);
} plugin_functs_hal;

void plugsHandling_setInterface(const char * name, void * tt);
void * plugsHandling_getInterface(const char * interfaceName);
void plugs_init(void);
void plugs_setHal(void);
void plugs_exit(void);
