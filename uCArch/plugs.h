/* Macro for log */
#define log_info(msg, ...) printf("[INFO: %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define log_err(msg, ...)  printf("[ERR : %s, L%d] "msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)

/* Macro to rename functions */
#define PLUGIN_INIT(name) void callback_ ## name(void) { name(); }
#define PLUGIN_EXIT(name) void callback_ ## name(void) { name(); }

/* Macro to define cpu information */
#define BIT_PROCESSOR  64 /* Can be 64, 32, 16, 8 */
#define ADDR_SIZE      (BIT_PROCESSOR / 8)

/* Struct */
typedef struct {
  void (*ptfx_init)(void);
  void (*ptfx_exit)(void);
} plugin_functs;


