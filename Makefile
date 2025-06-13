# top-level Makefile

#TODO: 	1. Target Make for test_modules				(for most part should be platform independent)
#	   	2. Target Make for python c_types wrapper	(shared library compilation is platform dependent)
#		3. Target Make for rust wrapper?

#targets: prerequisites
#	command
#	command

#TODO: add directory creation if not exist


# determine OS
UNAME_S := $(shell uname -s)
OS :=

ifeq ($(UNAME_S),Linux)
	OS := LINUX
endif

ifeq ($(UNAME_S),Darwin)
	OS := MAC
endif


# targets
.PHONY: all clean test lib

test:
ifeq ($(OS),LINUX)
	@echo "Compiling tests for $(OS)"
	$(MAKE) -C bst test OS=$(OS)
endif

ifeq ($(OS),MAC)
	@echo "Compiling tests for $(OS)"
	$(MAKE) -C bst test OS=$(OS)
endif

lib:
ifeq ($(OS),LINUX)
	@echo "Compiling shared libraries for $(OS)"
	$(MAKE) -C bst lib OS=$(OS)
endif

ifeq ($(OS),MAC)
	@echo "Compiling shared libraries for $(OS)"
	$(MAKE) -C bst lib OS=$(OS)
endif

# clean
clean:
ifeq ($(OS),LINUX)
	@echo "Cleaning for $(OS)"
endif

ifeq ($(OS),MAC)
	@echo "Cleaning for $(OS)"
	$(MAKE) -C bst clean OS=$(OS)
endif


#TODO:Windows