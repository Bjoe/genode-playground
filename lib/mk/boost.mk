
BOOST_DIR = $(call select_from_ports,boost)/src/lib/boost

#SRC_C = libs/system/src/error_code.cpp

#INC_DIR += $(BOOST_PORT_DIR)/include

LIBS += stdcxx pthread

#SHARED_LIB = yes
