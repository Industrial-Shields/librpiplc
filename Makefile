LIBNAME:=rpiplc
LIBRARY:=lib$(LIBNAME).so

override CFLAGS+=-fpic -Wall -Werror
override LDFLAGS+=-shared

CC=gcc
PREFIX=/usr/local

HEADERS:=$(wildcard src/*.h)
SRCS:=$(wildcard src/*.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))

TEST_SRCS=$(wildcard test/*.c)
TEST_BINS=$(patsubst %.c,%,$(TEST_SRCS))

define test-targets
$(1): $(1).c
	$(CC) -Isrc -L. -o $(1) $(1).c -lrpiplc
endef

.PHONY: first all world clean tests install
first all world: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJS): $(SRCS)

$(foreach TEST_BIN,$(TEST_BINS),$(eval $(call test-targets,$(TEST_BIN))))

tests: $(TEST_BINS)

install:
	cp $(LIBRARY) $(PREFIX)/lib/
	ldconfig
	mkdir -p $(PREFIX)/include/$(LIBNAME)
	cp $(HEADERS) $(PREFIX)/include/$(LIBNAME)/

clean:
	rm -f $(OBJS) $(LIBRARY) $(TEST_BINS)
