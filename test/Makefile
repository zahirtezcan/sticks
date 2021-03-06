CC=gcc
CXX=$(CC)

CPPFLAGS=-I"../" -I"../googletest/googletest/include/"
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
LDLIBS+=-lpthread
LDLIBS+=-lm
LDFLAGS=-L"../googletest/googletest/sticks_build/"
LINK.o=$(CC) $(LINKER_OUTPUT) $(LINKER_INPUT) $(LDLIBS) $(LDFLAGS)

MKDIR=mkdir -p
RM=rm -rf

BinDir=_bin_test
ObjDir=_obj_test


vpath %.o $(ObjDir)
vpath %$(EXE) $(BinDir)

all: tests

%$(EXE) : %.o
	$(LINK.o)

%.o : algorithm/%.cpp
	$(COMPILE.cpp) $<

tests: outputDirectories TestAllAlgorithms$(EXE) TestPartition$(EXE) TestCount$(EXE) TestCountValue$(EXE) TestGenerate$(EXE)
tests: TestReverse$(EXE) TestRotate$(EXE) TestAll$(EXE) TestAny$(EXE) TestAllEqual$(EXE) TestMismatch$(EXE)
tests: TestFind$(EXE) TestFindAdjacent$(EXE) TestFindRepitition$(EXE) TestFindLastSequence$(EXE) TestFindSequence$(EXE)
tests: TestFindAny$(EXE)
tests: TestForEach$(EXE) TestTransform$(EXE) TestRemove$(EXE) TestReplace$(EXE)
tests: TestCopy$(EXE) TestCopyDistinct$(EXE) TestCopyReplaced$(EXE) TestCopyReversed$(EXE) TestCopyPartitioned$(EXE)
tests: TestCopyRotated$(EXE) TestCopyIf$(EXE) TestCopyBackward$(EXE) TestCopyN$(EXE)
tests: TestEqualRange$(EXE) TestUpperBound$(EXE) TestLowerBound$(EXE) TestBinarySearch$(EXE)
tests: TestMove$(EXE) TestFill$(EXE) TestFillN$(EXE) TestSwapRanges$(EXE) TestMinMax$(EXE)
tests: TestLexicographicalCompare$(EXE) TestPermutation$(EXE) TestAccumulate$(EXE) TestInnerProduct$(EXE)
tests: TestAdjacentDifference$(EXE) TestPartialSum$(EXE) TestSortedIncludes$(EXE) TestMerge$(EXE)
tests: TestSortedDifference$(EXE) TestSortedIntersection$(EXE) TestSortedUnion$(EXE) TestSortedSymmetricDifference$(EXE)
tests: TestHeap$(EXE) TestSort$(EXE) TestNthElement$(EXE) TestMergeInplace$(EXE) TestInsertionSort$(EXE)
tests: TestStableSortInplace$(EXE)

outputDirectories:
	@$(MKDIR) $(ObjDir)
	@$(MKDIR) $(BinDir)

TestAllAlgorithms$(EXE): TestPartition.o TestCount.o TestCountValue.o TestGenerate.o TestReverse.o TestMinMax.o
TestAllAlgorithms$(EXE): TestRotate.o TestAll.o TestAny.o TestAllEqual.o TestMismatch.o
TestAllAlgorithms$(EXE): TestFind.o TestFindAdjacent.o TestFindRepitition.o TestFindLastSequence.o TestFindSequence.o
TestAllAlgorithms$(EXE): TestFindAny.o
TestAllAlgorithms$(EXE): TestForEach.o TestTransform.o TestRemove.o TestReplace.o
TestAllAlgorithms$(EXE): TestCopy.o TestCopyDistinct.o TestCopyReplaced.o TestCopyReversed.o TestCopyPartitioned.o
TestAllAlgorithms$(EXE): TestCopyRotated.o TestCopyIf.o TestCopyBackward.o TestCopyN.o
TestAllAlgorithms$(EXE): TestEqualRange.o TestUpperBound.o TestLowerBound.o TestBinarySearch.o
TestAllAlgorithms$(EXE): TestMove.o TestFill.o TestFillN.o TestSwapRanges.o TestLexicographicalCompare.o
TestAllAlgorithms$(EXE): TestPermutation.o TestAccumulate.o TestInnerProduct.o TestAdjacentDifference.o
TestAllAlgorithms$(EXE): TestPartialSum.o TestSortedIncludes.o TestMerge.o TestSortedDifference.o
TestAllAlgorithms$(EXE): TestSortedIntersection.o TestSortedUnion.o TestSortedSymmetricDifference.o
TestAllAlgorithms$(EXE): TestHeap.o TestSort.o TestNthElement.o TestMergeInplace.o TestInsertionSort.o
TestAllAlgorithms$(EXE): TestStableSortInplace.o
	$(LINK.o)

TestAllEqual.o: ../stx/algorithm/AllEqual.h ../stx/utility/Equals.h

TestAny.o: ../stx/algorithm/Any.h

TestAll.o: ../stx/algorithm/All.h

TestRotate.o: ../stx/algorithm/Rotate.h ../stx/algorithm/Reverse.h ../stx/algorithm/SwapPointee.h

TestReverse.o: ../stx/algorithm/Reverse.h ../stx/algorithm/SwapPointee.h

TestGenerate.o: ../stx/algorithm/Generate.h

TestCount.o: ../stx/algorithm/Count.h ../stx/utility/Iterator.h
TestCountValue.o: ../stx/algorithm/CountValue.h ../stx/algorithm/Count.h

TestPartition.o: ../stx/algorithm/Partition.h ../stx/algorithm/Rotate.h

TestMismatch.o: ../stx/algorithm/Mismatch.h

TestFind.o: ../stx/algorithm/Find.h
TestFindAdjacent.o: ../stx/algorithm/FindAdjacent.h ../stx/utility/Equals.h
TestFindRepitition.o: ../stx/algorithm/FindRepitition.h ../stx/utility/Equals.h
TestFindLastSequence.o: ../stx/algorithm/FindLastSequence.h  ../stx/algorithm/FindSequence.h ../stx/utility/Equals.h
TestFindSequence.o: ../stx/algorithm/FindSequence.h ../stx/utility/Equals.h
TestFindAny.o: ../stx/algorithm/FindAny.h ../stx/utility/Equals.h

TestReplace.o: ../stx/algorithm/Replace.h

TestForEach.o: ../stx/algorithm/ForEach.h ../stx/utility/Iterator.h

TestTransform.o: ../stx/algorithm/Transform.h ../stx/utility/Iterator.h

TestRemove.o: ../stx/algorithm/Remove.h ../stx/utility/Equals.h

TestCopy.o: ../stx/algorithm/Copy.h ../stx/utility/Equals.h 
TestCopyDistinct.o: ../stx/algorithm/CopyDistinct.h ../stx/utility/Equals.h ../stx/algorithm/Find.h
TestCopyReplaced.o: ../stx/algorithm/CopyReplaced.h ../stx/utility/Equals.h 
TestCopyReversed.o: ../stx/algorithm/CopyReversed.h
TestCopyPartitioned.o: ../stx/algorithm/CopyPartitioned.h
TestCopyRotated.o: ../stx/algorithm/CopyRotated.h ../stx/algorithm/Copy.h ../stx/utility/Equals.h
TestCopyIf.o: ../stx/algorithm/CopyIf.h
TestCopyBackward.o: ../stx/algorithm/CopyBackward.h
TestCopyN.o: ../stx/algorithm/CopyN.h

TestMove.o: ../stx/algorithm/Move.h ../stx/utility/Equals.h ../stx/algorithm/Find.h

TestFill.o: ../stx/algorithm/Fill.h
TestFillN.o: ../stx/algorithm/FillN.h

TestSwapRanges.o: ../stx/algorithm/SwapRanges.h ../stx/algorithm/SwapPointee.h

TestBinarySearch.o: ../stx/algorithm/BinarySearch.h ../stx/algorithm/LowerBound.h ../stx/utility/Compare.h
TestEqualRange.o: ../stx/algorithm/EqualRange.h ../stx/algorithm/UpperBound.h ../stx/algorithm/BinarySearch.h ../stx/utility/Compare.h
TestUpperBound.o: ../stx/algorithm/UpperBound.h ../stx/utility/Iterator.h ../stx/utility/Compare.h
TestLowerBound.o: ../stx/algorithm/LowerBound.h ../stx/utility/Iterator.h ../stx/utility/Compare.h

TestMinMax.o: ../stx/algorithm/MinMax.h ../stx/utility/Compare.h

TestLexicographicalCompare.o: ../stx/algorithm/LexicographicalCompare.h ../stx/utility/Compare.h

TestPermutation.o: ../stx/algorithm/Permutation.h ../stx/utility/Iterator.h ../stx/algorithm/SwapPointee.h ../stx/algorithm/Reverse.h ../stx/utility/Compare.h ../stx/utility/Equals.h ../stx/algorithm/Count.h ../stx/algorithm/Find.h 

TestAccumulate.o: ../stx/algorithm/Accumulate.h

TestInnerProduct.o: ../stx/algorithm/InnerProduct.h ../stx/utility/Arithmetic.h

TestAdjacentDifference.o: ../stx/algorithm/AdjacentDifference.h ../stx/utility/Arithmetic.h

TestPartialSum.o: ../stx/algorithm/PartialSum.h ../stx/utility/Arithmetic.h

TestSortedIncludes.o: ../stx/algorithm/SortedIncludes.h ../stx/utility/Compare.h

TestMerge.o: ../stx/algorithm/Merge.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestSortedDifference.o: ../stx/algorithm/SortedDifference.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestSortedIntersection.o: ../stx/algorithm/SortedIntersection.h ../stx/utility/Compare.h

TestSortedUnion.o: ../stx/algorithm/SortedUnion.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestSortedSymmetricDifference.o: ../stx/algorithm/SortedSymmetricDifference.h ../stx/utility/Compare.h ../stx/algorithm/Copy.h

TestHeap.o: ../stx/algorithm/Heap.h ../stx/utility/Compare.h ../stx/utility/Iterator.h ../stx/algorithm/SwapPointee.h

TestSort.o: ../stx/algorithm/Sort.h ../stx/utility/Compare.h ../stx/utility/Iterator.h ../stx/algorithm/SwapPointee.h ../stx/algorithm/Heap.h

TestNthElement.o: ../stx/algorithm/NthElement.h ../stx/utility/Compare.h ../stx/utility/Iterator.h ../stx/algorithm/SwapPointee.h ../stx/algorithm/Partition.h

TestMergeInplace.o: ../stx/algorithm/MergeInplace.h ../stx/utility/Compare.h ../stx/algorithm/Rotate.h ../stx/algorithm/SwapPointee.h ../stx/algorithm/Sort.h

TestInsertionSort.o: ../stx/algorithm/InsertionSort.h ../stx/algorithm/Sort.h ../stx/utility/Compare.h  ../stx/algorithm/Rotate.h ../stx/algorithm/Reverse.h ../stx/algorithm/SwapPointee.h

TestStableSortInplace.o: ../stx/algorithm/StableSortInplace.h ../stx/algorithm/MergeInplace.h ../stx/algorithm/InsertionSort.h ../stx/algorithm/Sort.h ../stx/utility/Compare.h  ../stx/algorithm/Rotate.h ../stx/algorithm/Reverse.h ../stx/algorithm/SwapPointee.h


clean:
	@$(RM) $(ObjDir)
	@$(RM) $(BinDir)

