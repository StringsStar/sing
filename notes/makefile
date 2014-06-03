$(warning bash script start)
$(warning start to test cmake_version)

SHELL := /bin/bash

$(warning make_version: $(MAKE_VERSION) )

ifeq (1 , $(shell expr $$(echo $(MAKE_VERSION)) \>= 3.81))
$(warning \$MAKE_VERSION $$(echo $(MAKE_VERSION)) )
endif

ifeq (1,$(shell expr $$(echo $(MAKE_VERSION) | sed "s/[^0-9\.].*//") \>= 3.81))
$(warning Found the cmake version > 3.81)
endif

ifeq (1,$(shell expr $$(echo $(MAKE_VERSION)) \>= 3.81))
$(warning Again Found the cmake version > 3.81)
endif
