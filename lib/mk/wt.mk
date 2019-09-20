WT_DIR := $(call select_from_ports,wt)/src/lib/wt
SRC_C = $(notdir $(wildcard $(SDL_NET_DIR)/*.c))

vpath %.c $(WT_DIR)
INC_DIR += $(WT_DIR)
#LIBS += libc
