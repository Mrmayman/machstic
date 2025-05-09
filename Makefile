# Note: this makefile exists purely for building the examples
# The core library `machstic.hpp` is header-only

ifeq ($(OS),Windows_NT)
    EXEEXT = .exe
    RM = del
else
    EXEEXT =
    RM = rm -f
endif

example: error types
error: examples/error
types: examples/types

examples/error$(EXEEXT): examples/error.cpp
	$(CXX) examples/error.cpp -o examples/error$(EXEEXT)
examples/types$(EXEEXT): examples/types.cpp
	$(CXX) examples/types.cpp -o examples/types$(EXEEXT)

clean:
	$(RM) examples/error$(EXEEXT) examples/types$(EXEEXT)
