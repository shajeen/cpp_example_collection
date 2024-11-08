#include <gtest/gtest.h>
#include <vector>

// Function to be tested
std::vector<double> matrix_dot_vector(const std::vector<std::vector<double>> &a, const std::vector<double> &b) {
    if (a.empty() || a[0].size() != b.size()) {
        return std::vector<double>{-1};
    }

    std::vector<double> output(a.size(), 0.0);

    for (size_t k = 0; k < a.size(); ++k) {
        const auto &row = a[k];
        for (size_t j = 0; j < row.size(); ++j) {
            output[k] += row[j] * b[j];
        }
    }

    return output;
}

// Test cases
TEST(MatrixDotVectorTest, ValidDimensions) {
    EXPECT_EQ(matrix_dot_vector({{1, 2}, {2, 4}}, {1, 2}), (std::vector<double>{5, 10}));
}

TEST(MatrixDotVectorTest, MismatchedDimensions) {
    EXPECT_EQ(matrix_dot_vector({{1, 2}, {2, 4}, {6, 8}, {12, 4}}, {1, 2, 3}), (std::vector<double>{-1}));
}

TEST(MatrixDotVectorTest, EmptyMatrix) {
    EXPECT_EQ(matrix_dot_vector({}, {1, 2}), (std::vector<double>{-1}));
}

TEST(MatrixDotVectorTest, EmptyVector) {
    EXPECT_EQ(matrix_dot_vector({{1, 2}, {2, 4}}, {}), (std::vector<double>{-1}));
}

TEST(MatrixDotVectorTest, ZeroVector) {
    EXPECT_EQ(matrix_dot_vector({{1, 2}, {2, 4}}, {0, 0}), (std::vector<double>{0, 0}));
}

TEST(MatrixDotVectorTest, IdentityMatrix) {
    EXPECT_EQ(matrix_dot_vector({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {3, 4, 5}), (std::vector<double>{3, 4, 5}));
}

TEST(MatrixDotVectorTest, LargeMatrix) {
    EXPECT_EQ(matrix_dot_vector({{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}}, {1, 2, 3, 4}), (std::vector<double>{30, 40, 50}));
}

TEST(MatrixDotVectorTest, Valid2x3Matrix) {
    EXPECT_EQ(matrix_dot_vector({{1, 2, 3}, {4, 5, 6}}, {1, 1, 1}), (std::vector<double>{6, 15}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
