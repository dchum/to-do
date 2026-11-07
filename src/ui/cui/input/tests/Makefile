CXX:= g++

CFLAGS = -Wall -g -Wno-unused-variable
CXXFLAGS = -Wall -g -Wno-unused-variable -std=c++17 -Wall -Wextra
DEFS = -DNCURSES_WIDECHAR
INCS = -I. -I../ -Ijson/ -I../../../../common/
LIBS = -lncurses

SRCS_INPUT = test_input.cpp input.cpp
SRCS_CONFIG = test_config.cc config.cpp

TARGETS = test_input test_config

VPATH := . ..

default: all
all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

OBJS_INPUT = $(patsubst %.cpp,%.o,$(filter %.cpp,$(SRCS_INPUT))) \
             $(patsubst %.cc,%.o,$(filter %.cc,$(SRCS_INPUT)))

OBJS_CONFIG = $(patsubst %.cpp,%.o,$(filter %.cpp,$(SRCS_CONFIG))) \
              $(patsubst %.cc,%.o,$(filter %.cc,$(SRCS_CONFIG)))

test_input: $(OBJS_INPUT)
	$(CXX) $(CXXFLAGS) $(INCS) $^ -o $@ $(DEFS) $(LIBS)

test_config: $(OBJS_CONFIG)
	$(CXX) $(CXXFLAGS) $(INCS) $^ -o $@ $(DEFS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $< -o $@