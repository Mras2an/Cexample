/* 
 *
 * if you use PLUGIN_INIT and/or PLUGIN_EXIT:
 *  All functions declared with "PLUGIN_INIT" and "PLUGIN_EXIT" need to have prefixed by "callback_".
 * 
 * Ex: PLUGIN_INIT(exPlug1_init) => void callback_exPlug1_init(void);
 *
*/

void callback_exPlug1_init(void);
void callback_exPlug1_exit(void);

