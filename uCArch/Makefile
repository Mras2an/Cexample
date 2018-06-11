# Add plugin 1
builtin_plugs += exPlug1
builtin_source += exPlug1.c
# Add plugin 2
builtin_plugs += exPlug2
builtin_source += exPlug2.c



#
# List
#
plugs_declaration=$(foreach i,$(builtin_plugs),{callback_$(subst : ,,$(i))_init, callback_$(subst : ,,$(i))_exit},)
plugs_setApi=$(foreach i,$(builtin_plugs),{callbackApi_$(subst : ,,$(i))_init},)
plugs_priority=$(foreach i,$(builtin_plugs),{def_$(subst : ,,$(i))_init},)
source_file_head = $(foreach i,$(builtin_source), -include $(patsubst  %.c,%.h,$(i)))
source_file_obj = $(patsubst  %.c,%.o,$(builtin_source))



#
# Env
#
CC=gcc
CFLAGS=-DPLUGS_DECLARATIONS="$(plugs_declaration)" -DPLUGS_SETHAL="$(plugs_setApi)" -DPLUGS_PRIORITY="$(plugs_priority)"
LDFLAGS=
EXEC=myPluginProject



all: $(EXEC)

myPluginProject: main.o $(source_file_obj) plugsHandling.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ $(source_file_head) -c $< $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf $(EXEC)

