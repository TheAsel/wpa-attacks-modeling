OBJS=rewardPVNodes.o rewardPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/librewardPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/librewardPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/librewardPV.a: FORCE
	$(MAKE) lib TARGET=librewardPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/librewardPV_debug.a: FORCE
	$(MAKE) lib TARGET=librewardPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

