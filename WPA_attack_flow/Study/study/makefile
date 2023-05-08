OBJS=studyRangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libstudyRangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libstudyRangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libstudyRangeStudy.a: FORCE
	$(MAKE) lib TARGET=libstudyRangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libstudyRangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libstudyRangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

