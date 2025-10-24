#include <gtest/gtest.h>
#include "../include/threeArray.h"

TEST(ThreeTest, DefaultConstructor) {
    Three num;
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\n");  // Ожидаем только перевод строки
}

TEST(ThreeTest, SizeConstructor) {
    Three num(4, 2);
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2222\n");
}

TEST(ThreeTest, InitializerListConstructor) {
    Three num{1, 0, 2};
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "102\n");
}

TEST(ThreeTest, StringConstructor) {
    Three num("2101");
    testing::internal::CaptureStdout();
    num.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2101\n");
}

TEST(ThreeTest, CopyConstructor) {
    Three num1{1, 2, 0};
    Three num2 = num1;
    testing::internal::CaptureStdout();
    num2.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "120\n");
}

TEST(ThreeTest, MoveConstructor) {
    Three num1{2, 1, 0};
    Three num2 = std::move(num1);
    testing::internal::CaptureStdout();
    num2.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "210\n");
}

TEST(ThreeTest, AddOperation) {
    Three num1("12");
    Three num2("21");
    Three result = num1.add(num2);
    testing::internal::CaptureStdout();
    result.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "110\n");
}

TEST(ThreeTest, SubtractOperation) {
    Three num1("21");
    Three num2("12");
    Three result = num1.subtract(num2);
    testing::internal::CaptureStdout();
    result.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2\n");
}

TEST(ThreeTest, SubtractThrowsException) {
    Three num1("1");
    Three num2("2");
    EXPECT_THROW(num1.subtract(num2), std::invalid_argument);
}

TEST(ThreeTest, ComparisonOperations) {
    Three num1("21");
    Three num2("12");
    
    EXPECT_TRUE(num2.less(num1));
    EXPECT_TRUE(num1.greater(num2));
    EXPECT_FALSE(num1.equals(num2));
    
    Three num3("21");
    EXPECT_TRUE(num1.equals(num3));
}

TEST(ThreeTest, InvalidDigitThrowsException) {
    EXPECT_THROW(Three(3, 5), std::invalid_argument);
    EXPECT_THROW(Three("312"), std::invalid_argument);
}

TEST(ThreeTest, EmptyStringThrowsException) {
    EXPECT_THROW(Three(""), std::invalid_argument);
}

TEST(ThreeTest, AddWithCarry) {
    Three num1("222");
    Three num2("1");
    Three result = num1.add(num2);
    testing::internal::CaptureStdout();
    result.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1000\n");
}

TEST(ThreeTest, LeadingZerosRemoval) {
    Three num1("100");
    Three num2("001");
    Three result = num1.subtract(num2);
    testing::internal::CaptureStdout();
    result.print(std::cout);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "22\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}