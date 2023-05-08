OBJS=


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

BINDIR=
MAINLIB=-lsimMain
MAINLIB_debug=-lsimMain_debug
SIMLIB=sim
SIMLIB_debug=sim_debug
SIMLIB_trace=sim_trace
PROJECTLIBS=-lstudyRangeStudy -lrewardPV -lattack_flowADVISE 
PROJECTLIBS_debug=-lstudyRangeStudy_debug -lrewardPV_debug -lattack_flowADVISE_debug 
MOBIUSLIBS=-lTRex -lStudy -lPV -lADVISE -lbase -lstate -lmobutil -ldist 
MOBIUSLIBS_debug=-lTRex_debug -lStudy_debug -lPV_debug -lADVISE_debug -lbase_debug -lstate_debug -lmobutil_debug -ldist_debug 
USERDEFLIBNAME=
USERDEFLIBDIR=

all: normal

opt \
simulationSim_$(ARCH): SUBMODELS/opt
	$(MAKE) exec3 "TARGET=simulationSim_$(ARCH)" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB) -l$(SIMLIB) $(USERDEFLIBNAME) $(PROJECTLIBS) $(USERDEFLIBNAME) $(MOBIUSLIBS)" 

normal debug \
simulationSim_$(ARCH)_debug: SUBMODELS/debug
	$(MAKE) exec3 "TARGET=simulationSim_$(ARCH)_debug" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_debug) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

trace \
simulationSim_$(ARCH)_trace:
	$(MAKE) exec3 "TARGET=simulationSim_$(ARCH)_trace" "USERLIBDIR=-L$(MOBIUSROOT)/Cpp/lib/$(PLATFORM)$(FORCE_ARCH) $(USERDEFLIBDIR)" "USERLIB=$(MAINLIB_debug) -l$(SIMLIB_trace) $(USERDEFLIBNAME) $(PROJECTLIBS_debug) $(USERDEFLIBNAME) $(MOBIUSLIBS_debug) " "BUILDTARGET=_debug"

clean_sub_dirs:
	cd ../../Atomic/attack_flow/ && $(MAKE) clean
	cd ../../Reward/reward/ && $(MAKE) clean
	cd ../../Study/study/ && $(MAKE) clean

SUBMODELS/opt SUBMODELS/debug:
	@echo "NEW_SUBMODEL_LIB:[attack_flow]"
	cd ../../Atomic/attack_flow/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[reward]"
	cd ../../Reward/reward/ && $(MAKE) $(@F)
	@echo "NEW_SUBMODEL_LIB:[study]"
	cd ../../Study/study/ && $(MAKE) $(@F)


