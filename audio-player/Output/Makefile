SRC_DIR=.
SUBDIRS=coreaudio

all: make_recursive_targets

clean: clean_recursive_targets
	@for subdir in $(SUBDIRS); do \
		sd_makefile="$(SRC_DIR)/$$subdir/Makefile"; \
		if test -f $$sd_makefile; then \
			echo "Cleaning $$sd_makefile"; \
			(cd $(SRC_DIR)/$$subdir && $(MAKE) clean); \
		fi; \
	done

make_recursive_targets:
	@for subdir in $(SUBDIRS); do \
		sd_makefile="$(SRC_DIR)/$$subdir/Makefile"; \
		if test -f $$sd_makefile; then \
			echo "Making $$sd_makefile"; \
			(cd $(SRC_DIR)/$$subdir && $(MAKE)); \
		fi; \
	done

.PHONY: make_recursive_targets clean_recursive_targets
