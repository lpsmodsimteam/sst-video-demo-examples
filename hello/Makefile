CXX=$(shell sst-config --CXX)
CXXFLAGS=$(shell sst-config --ELEMENT_CXXFLAGS)
LDFLAGS=$(shell sst-config --ELEMENT_LDFLAGS)

all: libhelloSST.so install

libhelloSST.so: hello.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

install:
	sst-register helloSST helloSST_LIBDIR=$(CURDIR)

clean:
	rm -rf tests/graphs libhelloSST.so
	sst-register -u helloSST
