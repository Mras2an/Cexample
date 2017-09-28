/* 
 *
 * if you use PLUGIN_INIT and/or PLUGIN_EXIT:
 *  All functions declared with "PLUGIN_INIT" and "PLUGIN_EXIT" need to have prefixed by "callback_".
 * 
 * Ex: PLUGIN_INIT(exPlug2_init) => void callback_exPlug2_init(void);
 *
*/

void callback_exPlug2_init(void);
void callback_exPlug2_exit(void);

