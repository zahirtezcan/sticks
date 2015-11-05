#include <stx/algorithm/Generate.h>
#include <vector>
#include <gtest/gtest.h>

template<typename Container>
testing::AssertionResult ElementsEqual(const Container& c1, const Container& c2) {
	if (c1.size() != c2.size()) {
		return testing::AssertionFailure() << " container size mismatch ";
	}

	for (typename Container::size_type i = 0; i < c1.size(); ++i) {
		if (c1[i] != c2[i]) {
			return testing::AssertionFailure() << " mismatch at index " << i;
		}
	}

	return testing::AssertionSuccess();
}

TEST(Generate, Basic)
{
	std::vector<int> expected(100, 13);
	auto expectedIter = expected.begin();

	std::vector<int> generated;
	generated.resize(expected.size());
	stx::Generate(generated.begin(), generated.end(), [&]() { return *expectedIter++; });

	EXPECT_TRUE(ElementsEqual(expected, generated));
}

TEST(Generate, Increment)
{
	std::vector<int> expected = { 1, 2, 3 };
	std::vector<int> generated(expected.size());

	stx::GenerateIncrement(generated.begin(), generated.end(), 1);

	EXPECT_TRUE(ElementsEqual(expected, generated));
}

TEST(Generate, Indexed)
{
	std::vector<int> expected(100);
	stx::GenerateIncrement(expected.begin(), expected.end(), 1);

	std::vector<int> generated(expected.size());
	stx::GenerateIndexed(generated.begin(), generated.end(), [&](int i) { return expected[i]; });

	EXPECT_TRUE(ElementsEqual(expected, generated));
}

