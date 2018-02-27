PATH := $(eTCpath)$(PATH)

.PHONY: ENIGMA clean Game clean-game codegen .FORCE

ENIGMA: .FORCE liblodepng
	$(MAKE) -C CommandLine/libGMX/ codegen
	$(MAKE) -C CompilerSource 

clean:
	$(MAKE) -C CompilerSource clean

Game: liblodepng
	$(MAKE) -C ENIGMAsystem/SHELL

clean-game:
	$(MAKE) -C ENIGMAsystem/SHELL clean
	
liblodepng:
	$(MAKE) -C lodepng/

libGMX: .FORCE
	$(MAKE) -C CommandLine/libGMX/

emake: libGMX .FORCE
	$(MAKE) -C CommandLine/emake/

test-runner: emake .FORCE
	$(MAKE) -C CommandLine/testing/

required-directories:
	mkdir -p "$(WORKDIR)"
	mkdir -p "$(CODEGEN)Preprocessor_Environment_Editable/"

.FORCE:
