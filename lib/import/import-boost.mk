BOOST_PORT_DIR := $(call select_from_ports,boost)
INC_DIR += $(BOOST_PORT_DIR)/include

CC_OPT += -D__GENODE__ -D_REENTRANT -D_GNU_SOURCE
