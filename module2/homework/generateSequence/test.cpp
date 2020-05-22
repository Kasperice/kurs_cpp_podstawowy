#include <vector>

#include "generateSequence.hpp"
#include "gtest/gtest.h"

struct Params {
    int count;
    int step;
    std::vector<int> expected_result;
};

class GenerateSequenceTestFixture : public ::testing::TestWithParam<Params> {
};

TEST_P(GenerateSequenceTestFixture, ShouldCreateVector) {
    const Params& test_data = GetParam();
    EXPECT_EQ(generateSequence(test_data.count, test_data.step), test_data.expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    GenerateSequenceTests,
    GenerateSequenceTestFixture,
    ::testing::Values(
        Params{0, 0, std::vector<int>{}},
        Params{-3, 0, std::vector<int>{}},
        Params{-3, 3, std::vector<int>{}},
        Params{1, 0, std::vector<int>{0}},
        Params{3, 0, std::vector<int>{0, 0, 0}},
        Params{3, 1, std::vector<int>{1, 2, 3}},
        Params{3, -1, std::vector<int>{-1, -2, -3}},
        Params{3, -4, std::vector<int>{-4, -8, -12}},
        Params{5, 2, std::vector<int>{2, 4, 6, 8, 10}},
        Params{8, 5, std::vector<int>{5, 10, 15, 20, 25, 30, 35, 40}},
        Params{10, 5, std::vector<int>{5, 10, 15, 20, 25, 30, 35, 40, 45, 50}},
        Params{6, -2, std::vector<int>{-2, -4, -6, -8, -10, -12}}, //added 22.05.2020
        Params{4, 10, std::vector<int>{10, 20, 30, 40}}, //added 22.05.2020
        Params{1, 20, std::vector<int>{20}} //added 22.05.2020
    )
);