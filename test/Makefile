CC=gcc
CXX=$(CC)

CPPFLAGS=-I"../"
CXXFLAGS=-std=c++11 -Wall -Wextra -Werror
COMPILER_OUTPUT=-o $(ObjDir)/$@
COMPILE.cpp=$(CXX) -c $(COMPILER_OUTPUT) $(CPPFLAGS) $(CXXFLAGS)

LINKER_INPUT=$(addprefix $(ObjDir)/,$^)
LINKER_OUTPUT=-o $(BinDir)/$@
LDLIBS+=-lstdc++
LINK.o=$(CC) $(LINKER_OUTPUT) $(LINKER_INPUT) $(LDLIBS) $(LDFLAGS)

MKDIR=mkdir -p
RM=rm -rf

BinDir=_bin_test
ObjDir=_obj_test


all: tests

tests: outputDirectories TestFindPartitionPoint

outputDirectories:
	$(MKDIR) $(ObjDir)
	$(MKDIR) $(BinDir)

TestFindPartitionPoint: TestFindPartitionPoint.o 
	$(LINK.o)

TestFindPartitionPoint.o: algorithm/TestFindPartitionPoint.cpp ../stx/algorithm/FindPartitionPoint.h
	$(COMPILE.cpp) $<

clean:
	$(RM) $(ObjDir)
	$(RM) $(BinDir)
