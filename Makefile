LIBNAME:=rpiplc

override CXXFLAGS+=-Wall -Werror -std=c++14
override LDFLAGS+=-shared

CC=g++
CXX=g++
PREFIX=/usr/local

LIBRARY:=lib$(LIBNAME).so
HEADERS:=$(wildcard src/*.h)
SRCS:=$(wildcard src/*.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(SRCS))

TEST_SRCS=$(wildcard test/*.cpp)
TEST_BINS=$(patsubst %.cpp,%,$(TEST_SRCS))

define test-targets
.PHONY: $(1)
$(1): $(1).cpp $(LIBRARY)
	$(CXX) $(CXXFLAGS) -Isrc -L. -o $(1) $(1).cpp -l$(LIBNAME)
endef

.PHONY: first all world clean tests install pack pre-pack
first all world: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJS): CXXFLAGS+=-fpic
$(OBJS): $(SRCS) $(HEADERS)

$(foreach TEST_BIN,$(TEST_BINS),$(eval $(call test-targets,$(TEST_BIN))))

tests: $(TEST_BINS)

install:
	if [ -n "$(DESTDIR)" ]; then mkdir -p $(DESTDIR); fi
	mkdir -p $(DESTDIR)$(PREFIX)/lib/
	cp $(LIBRARY) $(DESTDIR)$(PREFIX)/lib/
	if [ -z "$(DESTDIR)" ]; then ldconfig; fi
	mkdir -p $(DESTDIR)$(PREFIX)/include/$(LIBNAME)
	cp $(HEADERS) $(DESTDIR)$(PREFIX)/include/$(LIBNAME)/

pack: DESTDIR=/tmp/$(LIBNAME)
pack: PREFIX=
pack: pre-pack $(LIBRARY) install
	tar -C $(DESTDIR) -cjvf lib$(LIBNAME).tar.bz2 .

pre-pack:
	rm -rf $(DESTDIR)

clean:
	rm -f $(OBJS) $(LIBRARY) $(TEST_BINS)
