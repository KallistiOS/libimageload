TARGET = libimageload.a
OBJS = readpcx.o readbmp.o readjpeg.o imageload.o jitter.o
KOS_CFLAGS += -Iinclude

defaultall: create_kos_link $(OBJS) subdirs linklib

include $(KOS_BASE)/addons/Makefile.prefab

# creates the kos link to the headers
create_kos_link:
	rm -f $(KOS_BASE)/addons/include/imageload
	ln -s $(CURDIR)/include $(KOS_BASE)/addons/include/imageload
