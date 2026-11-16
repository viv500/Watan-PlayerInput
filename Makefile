CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -g -Iinclude
EXEC = build/watan
SOURCES = $(wildcard src/*.cc)
OBJECTS = $(patsubst src/%.cc,build/%.o,$(SOURCES))
DEPENDS = $(OBJECTS:.o=.d)

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

build:
	mkdir -p build

build/%.o: src/%.cc | build
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDS)

clean:
	rm -rf build
