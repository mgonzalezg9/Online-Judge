MOOSHAK_FLAGS = -std=c99 -O2 -Wno-deprecated
FLAGS = -g -O0 -DSF_VISIBILITY -fvisibility=hidden -fno-strict-aliasing -Wall -std=c++11 -Wno-deprecated

all: G

G: G.cpp
	g++ G.cpp $(MOOSHAK_FLAGS) -o G

clean: 
	rm G G.sal