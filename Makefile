cc = gcc
src = $(shell ls src/*.c)
obj = $(src:.c=.o)
ldflags = -lgc

tests=$(shell ls tests/*.c)
tests_bin=$(tests:.c=.bin)

all: libgcutils.a
	-rm -rf build/
	-@mkdir -p build/include/gcutils/
	-@mkdir -p build/lib
	mv libgcutils.a build/lib/
	cp src/*.h build/include/gcutils

libgcutils.a: $(obj)
	ar cr $@ $^

test: $(tests_bin)
	@echo
	@echo "Run tests:"
	@scripts/runall.sh $^

$(obj):%.o:%.c
	$(cc) -c -g $< -MD -MF $@.d -o $@

$(tests_bin):%.bin:%.c libgcutils.a
	$(cc) -g -Isrc/ $(ldflags) $< libgcutils.a -MD -MF $@.d -o $@

clean:
	-rm $(shell find tests/ -name '*.bin')
	-rm $(shell find . -name '*.o' -or -name '*.a' -or -name '*.d')
	-rm -rf build

DEPS := $(shell find . -name *.d)
ifneq ($(DEPS),)
include $(DEPS)
endif
