all: bindir TestFindPartitionPoint

bindir:
	mkdir bin -p

TestFindPartitionPoint: algorithm/TestFindPartitionPoint.cpp ../stx/algorithm/FindPartitionPoint.h
	gcc -o bin/TestFindPartitionPoint algorithm/TestFindPartitionPoint.cpp -std=c++11 -lstdc++ \
-I"../"

