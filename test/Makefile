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
LDLIBS+=-lgtest_main
LDLIBS+=-lgtest
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

tests: outputDirectories TestAll$(EXE) TestFindPartitionPoint$(EXE) TestCount$(EXE) TestGenerate$(EXE) TestReverse$(EXE) TestRotate$(EXE)

outputDirectories:
	@$(MKDIR) $(ObjDir)
	@$(MKDIR) $(BinDir)

%$(EXE) : %.o
	$(LINK.o)

%.o : algorithm/%.cpp
	$(COMPILE.cpp) $<

TestAll$(EXE): TestFindPartitionPoint.o TestCount.o TestGenerate.o TestReverse.o TestRotate.o
	$(LINK.o)

TestRotate$(EXE): TestRotate.o
TestRotate.o: algorithm/TestRotate.cpp 
TestRotate.o: ../stx/algorithm/Rotate.h ../stx/algorithm/Reverse.h ../stx/algorithm/SwapPointee.h

TestReverse$(EXE): TestReverse.o
TestReverse.o: algorithm/TestReverse.cpp
TestReverse.o: ../stx/algorithm/Reverse.h ../stx/algorithm/SwapPointee.h

TestGenerate$(EXE): TestGenerate.o
TestGenerate.o: algorithm/TestGenerate.cpp
TestGenerate.o: ../stx/algorithm/Generate.h

TestCount$(EXE): TestCount.o
TestCount.o: algorithm/TestCount.cpp
TestCount.o: ../stx/algorithm/Count.h ../stx/Iterator.h

TestFindPartitionPoint$(EXE): TestFindPartitionPoint.o 
TestFindPartitionPoint.o: algorithm/TestFindPartitionPoint.cpp
TestFindPartitionPoint.o: ../stx/algorithm/FindPartitionPoint.h ../stx/algorithm/Rotate.h

clean:
	@$(RM) $(ObjDir)
	@$(RM) $(BinDir)
