CC=gcc
CXX=$(CC)
CPPFLAGS=-I"../"
CXXFLAGS=-std=c++11 -Wall -Wextra -Werror
LDLIBS+=-lstdc++
MKDIR=mkdir -p
RM=rm -rf

BinDir=_bin_test
ObjDir=_obj_test


all: outputDirectories $(BinDir)/TestFindPartitionPoint

outputDirectories:
	$(MKDIR) $(ObjDir)
	$(MKDIR) $(BinDir)

$(BinDir)/TestFindPartitionPoint: $(ObjDir)/TestFindPartitionPoint.o 
	$(CC) -o $@ $< $(LDLIBS) 

$(ObjDir)/TestFindPartitionPoint.o: algorithm/TestFindPartitionPoint.cpp ../stx/algorithm/FindPartitionPoint.h
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(ObjDir)
	$(RM) $(BinDir)
