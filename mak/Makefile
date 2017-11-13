###############################################################################
#
# Copyright 2014, 2015, Mariano Cerdeiro
# Copyright 2014, ACSE, CADIEEL
#    ACSE   : http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
#    CADIEEL: http://www.cadieel.org.ar
# All rights reserved.
#
# This file is part of CIAA Firmware.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from this
#    software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
###############################################################################

BUILD_LIBS += freeosek

###############################################################################
# Check module dependencies with other modules
freeosek_path := $(ROOT_DIR)/modules/freeosek
freeosek_dependencies := $(ROOT_DIR)/modules/generator
$(eval $(call module_dependencies, $(freeosek_path),$(freeosek_dependencies)))

freeosek_templates_path := gen/inc gen/src gen/inc/$(ARCH) gen/src/$(ARCH)

project_oil ?= $(wildcard $(PROJECT)/etc/*.oil)

project_poil ?= $(wildcard $(PROJECT)/etc/*.poil)
project_oil += $(patsubst $(PROJECT)/etc/%.poil,$(ETC_DIR)/%.oil,$(project_poil))

###############################################################################
# Rule to generate OILs files
$(ETC_DIR)/%.oil: $(PROJECT)/etc/%.poil
	@echo ' '
	@echo ===============================================================================
	@echo Generate OIL File $@ from $<
	@echo ' '
	$(PP) $(PFLAGS) -E -x c++ -I modules/base/inc $< | grep -v "^#.*" > $@

define freeosek_templates
	$(foreach path,$(freeosek_templates_path), $(wildcard $(freeosek_path)/$(path)/*.?.php))
endef
gen_info: $(project_oil)
	@echo OIL: $(project_oil)
	@echo POIL: $(project_poil)

###############################################################################
# Rule to generate OS from OILs files
generate: $(project_oil)
	@echo ' '
	@echo ===============================================================================
	@echo Run FREEOSEK RTOS Generator
	@echo ' '
	$(GE) $(GFLAGS) -c $(project_oil) -t $(strip $(call freeosek_templates)) -o $(GEN_DIR)

###############################################################################
# Rule to build library from objects files
#$(LIB_DIR)/freeosek.a: generate
freeosek_inc = $(freeosek_path)/inc $(freeosek_path)/inc/$(ARCH) $(freeosek_path)/inc/$(ARCH)/$(CPUTYPE) 
freeosek_inc += $(GEN_DIR)/inc $(GEN_DIR)/inc/$(ARCH)

freeosek_src = $(freeosek_path)/src $(freeosek_path)/src/$(ARCH) 
freeosek_src += $(GEN_DIR)/src $(GEN_DIR)/src/$(ARCH)

freeosek_asm += $(freeosek_path)/src/$(ARCH)
