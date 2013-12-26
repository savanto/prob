CC = gcc
CFLAGS = 

# Exclude template
SOURCES = $(filter-out template.c,$(wildcard *.c))
TARGETS = $(SOURCES:.c=)
ifndef LANGUAGE
LANGUAGE = c
endif

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

new: template.$(LANGUAGE)
ifndef PROBLEM
	$(error use "make new PROBLEM=<problem-number>")
endif
	@cat $< | sed 's/PROBLEM/$(PROBLEM)/g' > $(PROBLEM).$(LANGUAGE)
	@echo "Initialized new program '$(PROBLEM)' from template in $(PROBLEM).$(LANGUAGE)"

clean:
	rm -rf $(TARGETS) __pycache__
