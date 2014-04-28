#!/bin/bash

# check for broken versions of make
ifeq (1,$(shell expr $(shell echo $(MAKE_VERSION) | sed "s/[^0-9\.].*//") \>= 3.81))
$(warning ********************************************************************************)
$(warning *  You are using version $(MAKE_VERSION) of make.)
$(warning *  $(shell echo 123)You must upgrade to version 3.81 or greater.)
$(warning *  see http://source.android.com/download)
$(warning ********************************************************************************)
$(error stopping)
endif


