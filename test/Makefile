CC=gcc
CXX=$(CC)

CPPFLAGS=-I"../"
CXXFLAGS=-std=c++11 -Wall -Wextra -Werror
COMPILER_OUTPUT=-o $(ObjDir)/$@
COMPILE.cpp=$(CXX) -c $(COMPILER_OUTPUT) $(CPPFLAGS) $(CXXFLAGS)

ifdef COMSPEC
  EXE:=.exe
else
  EXE:=
endif

LINKER_INPUT=$(addprefix $(ObjDir)/,$^)
LINKER_OUTPUT=-o $(BinDir)/$@
LDLIBS+=-lstdc++
LINK.o=$(CC) $(LINKER_OUTPUT) $(LINKER_INPUT) $(LDLIBS) $(LDFLAGS)

MKDIR=mkdir -p
RM=rm -rf

BinDir=_bin_test
ObjDir=_obj_test


vpath %.o $(ObjDir)
vpath %$(EXE) $(BinDir)

all: tests

tests: outputDirectories TestFindPartitionPoint$(EXE) TestCount$(EXE) TestGenerate$(EXE)

outputDirectories:
	@$(MKDIR) $(ObjDir)
	@$(MKDIR) $(BinDir)

TestGenerate$(EXE): TestGenerate.o
	$(LINK.o)

TestGenerate.o: algorithm/TestGenerate.cpp ../stx/algorithm/Generate.h
	$(COMPILE.cpp) $<

TestCount$(EXE): TestCount.o
	$(LINK.o)

TestCount.o: algorithm/TestCount.cpp ../stx/algorithm/Count.h ../stx/Iterator.h
	$(COMPILE.cpp) $<

TestFindPartitionPoint$(EXE): TestFindPartitionPoint.o 
	$(LINK.o)

TestFindPartitionPoint.o: algorithm/TestFindPartitionPoint.cpp ../stx/algorithm/FindPartitionPoint.h
	$(COMPILE.cpp) $<

clean:
	@$(RM) $(ObjDir)
	@$(RM) $(BinDir)
