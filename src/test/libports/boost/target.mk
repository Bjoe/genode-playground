TARGET = test-boost
LIBS   = base stdcxx pthread boost
SRC_CC = main.cc

vpath main.cc $(PRG_DIR)/..

# Why are this defines not set by default?
#CC_OPT = -D__GENODE__ -D_REENTRANT -D_GNU_SOURCE
