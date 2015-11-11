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

LINKER_INPUT=$(patsubst %,$(ObjDir)/%,$(patsubst $(ObjDir)/%,%,$^))
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

tests: outputDirectories TestAllAlgorithms$(EXE) TestFindPartitionPoint$(EXE) TestCount$(EXE) TestGenerate$(EXE)
tests: TestReverse$(EXE) TestRotate$(EXE) TestAll$(EXE) TestAny$(EXE) TestAllEqual$(EXE) TestMismatch$(EXE)
tests: TestFind$(EXE) TestForEach$(EXE) TestTransform$(EXE) TestRemove$(EXE) TestReplace$(EXE)

outputDirectories:
	@$(MKDIR) $(ObjDir)
	@$(MKDIR) $(BinDir)

%$(EXE) : %.o
	$(LINK.o)

%.o : algorithm/%.cpp
	$(COMPILE.cpp) $<

TestAllAlgorithms$(EXE): TestFindPartitionPoint.o TestCount.o TestGenerate.o TestReverse.o
TestAllAlgorithms$(EXE): TestRotate.o TestAll.o TestAny.o TestAllEqual.o TestMismatch.o TestFind.o
TestAllAlgorithms$(EXE): TestForEach.o TestTransform.o TestRemove.o TestReplace.o 
	$(LINK.o)

TestAllEqual$(EXE): TestAllEqual.o
TestAllEqual.o: algorithm/TestAllEqual.cpp
TestAllEqual.o: ../stx/algorithm/AllEqual.h

TestAny$(EXE): TestAny.o
TestAny.o: algorithm/TestAny.cpp
TestAny.o: ../stx/algorithm/Any.h

TestAll$(EXE): TestAll.o
TestAll.o: algorithm/TestAll.cpp
TestAll.o: ../stx/algorithm/All.h

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

TestMismatch$(EXE): TestMismatch.o
TestMismatch.o: algorithm/TestMismatch.cpp
TestMismatch.o: ../stx/algorithm/Mismatch.h

TestFind$(EXE): TestFind.o
TestFind.o: algorithm/TestFind.cpp
TestFind.o: ../stx/algorithm/Find.h

TestReplace$(EXE): TestReplace.o
TestReplace.o: algorithm/TestReplace.cpp
TestReplace.o: ../stx/algorithm/Replace.h

TestForEach$(EXE): TestForEach.o
TestForEach.o: algorithm/TestForEach.cpp
TestForEach.o: ../stx/algorithm/ForEach.h ../stx/Iterator.h

TestTransform$(EXE): TestTransform.o
TestTransform.o: algorithm/TestTransform.cpp
TestTransform.o: ../stx/algorithm/Transform.h ../stx/Iterator.h

TestRemove$(EXE): TestRemove.o
TestRemove.o: algorithm/TestRemove.cpp
TestRemove.o: ../stx/algorithm/Remove.h

clean:
	@$(RM) $(ObjDir)
	@$(RM) $(BinDir)

