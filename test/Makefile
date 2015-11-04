CC=gcc
CXX=$(CC)

CPPFLAGS=-I"../" -I"../gtest/include/"
CXXFLAGS=-std=gnu++11 -Wall -Wextra -Werror
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
LDFLAGS=-L"../gtest/lib/"
LINK.o=$(CC) $(LINKER_OUTPUT) $(LINKER_INPUT) $(LDLIBS) $(LDFLAGS)

MKDIR=mkdir -p
RM=rm -rf

BinDir=_bin_test
ObjDir=_obj_test


vpath %.o $(ObjDir)
vpath %$(EXE) $(BinDir)

all: tests

tests: outputDirectories TestFindPartitionPoint$(EXE) TestCount$(EXE) TestGenerate$(EXE) TestReverse$(EXE) TestRotate$(EXE)

outputDirectories:
	@$(MKDIR) $(ObjDir)
	@$(MKDIR) $(BinDir)

TestRotate$(EXE): TestRotate.o
	$(LINK.o) -lgtest_main -lgtest -lstdc++

TestRotate.o: algorithm/TestRotate.cpp ../stx/algorithm/Rotate.h ../stx/algorithm/IterSwap.h
	$(COMPILE.cpp) $<

TestReverse$(EXE): TestReverse.o
	$(LINK.o)

TestReverse.o: algorithm/TestReverse.cpp ../stx/algorithm/Reverse.h ../stx/algorithm/IterSwap.h
	$(COMPILE.cpp) $<

TestGenerate$(EXE): TestGenerate.o
	$(LINK.o)

TestGenerate.o: algorithm/TestGenerate.cpp ../stx/algorithm/Generate.h
	$(COMPILE.cpp) $<

TestCount$(EXE): TestCount.o
	$(LINK.o)

TestCount.o: algorithm/TestCount.cpp ../stx/algorithm/Count.h ../stx/Iterator.h ../stx/algorithm/Generate.h
	$(COMPILE.cpp) $<

TestFindPartitionPoint$(EXE): TestFindPartitionPoint.o 
	$(LINK.o)

TestFindPartitionPoint.o: algorithm/TestFindPartitionPoint.cpp ../stx/algorithm/FindPartitionPoint.h ../stx/algorithm/Generate.h
	$(COMPILE.cpp) $<

clean:
	@$(RM) $(ObjDir)
	@$(RM) $(BinDir)
