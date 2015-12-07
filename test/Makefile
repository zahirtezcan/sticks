CC=gcc
CXX=$(CC)

CPPFLAGS=-I"../" -I"../gtest/include/"
CXXFLAGS=-std=gnu++14 -Wall -Wextra -Werror
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

tests: outputDirectories TestAllAlgorithms$(EXE) TestPartition$(EXE) TestCount$(EXE) TestGenerate$(EXE)
tests: TestReverse$(EXE) TestRotate$(EXE) TestAll$(EXE) TestAny$(EXE) TestAllEqual$(EXE) TestMismatch$(EXE)
tests: TestFind$(EXE) TestForEach$(EXE) TestTransform$(EXE) TestRemove$(EXE) TestReplace$(EXE) TestCopy$(EXE)
tests: TestMove$(EXE) TestFill$(EXE) TestSwapRanges$(EXE) TestBinarySearch$(EXE) TestMinMax$(EXE)
tests: TestLexicographicalCompare$(EXE) TestPermutation$(EXE) TestAccumulate$(EXE) TestInnerProduct$(EXE)
tests: TestAdjacentDifference$(EXE) TestPartialSum$(EXE) TestSortedIncludes$(EXE) TestMerge$(EXE)
tests: TestSortedDifference$(EXE) TestSortedIntersection$(EXE) TestSortedUnion$(EXE) TestSortedSymmetricDifference$(EXE)
tests: TestHeap$(EXE) TestSort$(EXE) TestNthElement$(EXE)

outputDirectories:
	@$(MKDIR) $(ObjDir)
	@$(MKDIR) $(BinDir)

%$(EXE) : %.o
	$(LINK.o)

%.o : algorithm/%.cpp
	$(COMPILE.cpp) $<

TestAllAlgorithms$(EXE): TestPartition.o TestCount.o TestGenerate.o TestReverse.o TestMinMax.o
TestAllAlgorithms$(EXE): TestRotate.o TestAll.o TestAny.o TestAllEqual.o TestMismatch.o TestFind.o
TestAllAlgorithms$(EXE): TestForEach.o TestTransform.o TestRemove.o TestReplace.o TestCopy.o 
TestAllAlgorithms$(EXE): TestMove.o TestFill.o TestSwapRanges.o TestBinarySearch.o TestLexicographicalCompare.o
TestAllAlgorithms$(EXE): TestPermutation.o TestAccumulate.o TestInnerProduct.o TestAdjacentDifference.o
TestAllAlgorithms$(EXE): TestPartialSum.o TestSortedIncludes.o TestMerge.o TestSortedDifference.o
TestAllAlgorithms$(EXE): TestSortedIntersection.o TestSortedUnion.o TestSortedSymmetricDifference.o
TestAllAlgorithms$(EXE): TestHeap.o TestSort.o TestNthElement.o
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

TestPartition$(EXE): TestPartition.o 
TestPartition.o: algorithm/TestPartition.cpp
TestPartition.o: ../stx/algorithm/Partition.h ../stx/algorithm/Rotate.h

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
TestRemove.o: ../stx/algorithm/Remove.h ../stx/utility/Equals.h

TestCopy$(EXE): TestCopy.o
TestCopy.o: algorithm/TestCopy.cpp
TestCopy.o: ../stx/algorithm/Copy.h ../stx/utility/Equals.h ../stx/algorithm/Find.h

TestMove$(EXE): TestMove.o
TestMove.o: algorithm/TestMove.cpp
TestMove.o: ../stx/algorithm/Move.h ../stx/utility/Equals.h ../stx/algorithm/Find.h

TestFill$(EXE): TestFill.o
TestFill.o: algorithm/TestFill.cpp
TestFill.o: ../stx/algorithm/Fill.h ../stx/utility/Equals.h

TestSwapRanges$(EXE): TestSwapRanges.o
TestSwapRanges.o: algorithm/TestSwapRanges.cpp
TestSwapRanges.o: ../stx/algorithm/SwapRanges.h ../stx/algorithm/SwapPointee.h

TestBinarySearch$(EXE): TestBinarySearch.o
TestBinarySearch.o: algorithm/TestBinarySearch.cpp
TestBinarySearch.o: ../stx/algorithm/BinarySearch.h
../stx/algorithm/BinarySearch.h: ../stx/Iterator.h ../stx/utility/Compare.h

TestMinMax$(EXE): TestMinMax.o
TestMinMax.o: algorithm/TestMinMax.cpp
TestMinMax.o: ../stx/algorithm/MinMax.h ../stx/utility/Compare.h

TestLexicographicalCompare$(EXE): TestLexicographicalCompare.o
TestLexicographicalCompare.o: algorithm/TestLexicographicalCompare.cpp
TestLexicographicalCompare.o: ../stx/algorithm/LexicographicalCompare.h ../stx/utility/Compare.h

TestPermutation$(EXE): TestPermutation.o
TestPermutation.o: algorithm/TestPermutation.cpp
TestPermutation.o: ../stx/algorithm/Permutation.h ../stx/Iterator.h ../stx/algorithm/SwapPointee.h ../stx/algorithm/Reverse.h ../stx/utility/Compare.h ../stx/utility/Equals.h ../stx/algorithm/Count.h ../stx/algorithm/Find.h 

TestAccumulate$(EXE): TestAccumulate.o
TestAccumulate.o: algorithm/TestAccumulate.cpp
TestAccumulate.o: ../stx/algorithm/Accumulate.h

TestInnerProduct$(EXE): TestInnerProduct.o
TestInnerProduct.o: algorithm/TestInnerProduct.cpp
TestInnerProduct.o: ../stx/algorithm/InnerProduct.h ../stx/utility/Arithmetic.h

TestAdjacentDifference$(EXE): TestAdjacentDifference.o
TestAdjacentDifference.o: algorithm/TestAdjacentDifference.cpp
TestAdjacentDifference.o: ../stx/algorithm/AdjacentDifference.h ../stx/utility/Arithmetic.h

TestPartialSum$(EXE): TestPartialSum.o
TestPartialSum.o: algorithm/TestPartialSum.cpp
TestPartialSum.o: ../stx/algorithm/PartialSum.h ../stx/utility/Arithmetic.h

TestSortedIncludes$(EXE): TestSortedIncludes.o
TestSortedIncludes.o: algorithm/TestSortedIncludes.cpp
TestSortedIncludes.o: ../stx/algorithm/SortedIncludes.h ../stx/utility/Compare.h

TestMerge$(EXE): TestMerge.o
TestMerge.o: algorithm/TestMerge.cpp
TestMerge.o: ../stx/algorithm/Merge.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestSortedDifference$(EXE): TestSortedDifference.o
TestSortedDifference.o: algorithm/TestSortedDifference.cpp
TestSortedDifference.o: ../stx/algorithm/SortedDifference.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestSortedIntersection$(EXE): TestSortedIntersection.o
TestSortedIntersection.o: algorithm/TestSortedIntersection.cpp
TestSortedIntersection.o: ../stx/algorithm/SortedIntersection.h ../stx/utility/Compare.h

TestSortedUnion$(EXE): TestSortedUnion.o
TestSortedUnion.o: algorithm/TestSortedUnion.cpp
TestSortedUnion.o: ../stx/algorithm/SortedUnion.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestSortedSymmetricDifference$(EXE): TestSortedSymmetricDifference.o
TestSortedSymmetricDifference.o: algorithm/TestSortedSymmetricDifference.cpp
TestSortedSymmetricDifference.o: ../stx/algorithm/SortedSymmetricDifference.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestHeap$(EXE): TestHeap.o
TestHeap.o: algorithm/TestHeap.cpp
TestHeap.o: ../stx/algorithm/Heap.h ../stx/utility/Compare.h ../stx/Iterator.h ../stx/algorithm/SwapPointee.h

TestSort$(EXE): TestSort.o
TestSort.o: algorithm/TestSort.cpp
TestSort.o: ../stx/algorithm/Sort.h ../stx/utility/Compare.h ../stx/Iterator.h ../stx/algorithm/SwapPointee.h

TestNthElement$(EXE): TestNthElement.o
TestNthElement.o: algorithm/TestNthElement.cpp
TestNthElement.o: ../stx/algorithm/NthElement.h ../stx/utility/Compare.h ../stx/Iterator.h ../stx/algorithm/SwapPointee.h ../stx/algorithm/Partition.h



clean:
	@$(RM) $(ObjDir)
	@$(RM) $(BinDir)

