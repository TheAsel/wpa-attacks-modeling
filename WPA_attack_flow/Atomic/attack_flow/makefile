OBJS=attack_flowADVISE.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libattack_flowADVISE.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libattack_flowADVISE_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libattack_flowADVISE.a: FORCE
	$(MAKE) lib TARGET=libattack_flowADVISE.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libattack_flowADVISE_debug.a: FORCE
	$(MAKE) lib TARGET=libattack_flowADVISE_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

