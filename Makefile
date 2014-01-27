CC = gcc
PY = python
CFLAGS = 

MODULES = primesieve.c
MODULE_OBJECTS = $(MODULES:.c=.so)
TEMPLATES = template.c
SOURCES = $(filter-out $(TEMPLATES) $(MODULES),$(wildcard *.c))
TARGETS = $(SOURCES:.c=)
ifndef LANGUAGE
LANGUAGE = c
endif

# Compile all problems implemented in C.
all: $(TARGETS)

# Build an individual problem implemented in C.
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Compile all C extension modules for Python.
modules: $(MODULE_OBJECTS)

# Build an individual C extension module for Python.
%.so: %.c
	@echo "from distutils.core import setup, Extension; setup(name='$(<:.c=)', ext_modules=[Extension('$(<:.c=)', ['$<'])])" | $(PY) - build_ext --inplace

# Create a new problem from a template.
new: template.$(LANGUAGE)
ifndef PROBLEM
	$(error use "make new PROBLEM=<problem-number>")
endif
	@cat $< | sed 's/PROBLEM/$(PROBLEM)/g' > $(PROBLEM).$(LANGUAGE)
	@echo "Initialized new program '$(PROBLEM)' from template in $(PROBLEM).$(LANGUAGE)"

# Remove old builds, compiled python code, temp build directory from making modules.
clean:
	rm -rf $(TARGETS) __pycache__/ build/

# Remove modules to allow them to be rebuilt.
moduleclean:
	rm -rf $(MODULE_OBJECTS)
