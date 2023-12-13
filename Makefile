cc = gcc
src = $(shell ls src/*.c)
obj = $(src:.c=.o)
ldflags = -lgc

tests=$(shell ls tests/*.c)
tests_bin=$(tests:.c=.bin)

all: libdymc.a
	-rm -rf build/
	-@mkdir -p build/include/dymc/
	-@mkdir -p build/lib
	mv libdymc.a build/lib/
	cp src/*.h build/include/dymc

libdymc.a: $(obj)
	ar cr $@ $^

test: $(tests_bin)
	@echo
	@echo "Run tests:"
	@scripts/runall.sh $^

$(obj):%.o:%.c
	$(cc) -c -g $< -MD -MF $@.d -o $@

$(tests_bin):%.bin:%.c libdymc.a
	$(cc) -g -Isrc/ $(ldflags) $< libdymc.a -MD -MF $@.d -o $@

clean:
	-rm $(shell find tests/ -name '*.bin')
	-rm $(shell find . -name '*.o' -or -name '*.a' -or -name '*.d')
	-rm -rf build

DEPS := $(shell find . -name *.d)
ifneq ($(DEPS),)
include $(DEPS)
endif
