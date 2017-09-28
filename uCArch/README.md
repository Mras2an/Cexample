## Uc Arch : dynamic plugin handling

This project is dynamic plugin handling.

## Create a new plugin (see template exPlug.c and exPlug.h)

1) Create *.c and *.h files
2) In your *.c
   - Add plugs.h,
   - Create tow static functions "init" and "exit",
   - Add the static functions in PLUGIN_INIT ans PLUGIN_INIT macro.
3) In your *.h
   - Create the "init" and "exit" functions, prefixed by "callback_".
4) Add in your Makefile the builtin_plugs and builtin_source variables

