TARGET = boost

CONFIGURE_ARGS = --curdir $(PWD)
 
INSTALL_TARGET = install

LIBS += libc libm posix libc_noux stdcxx

include $(call select_from_repositories,mk/noux.mk)
