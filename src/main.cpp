#include "../include/org_alu.h"
#include "../include/cpm_alu.h"
#include "../include/binary.h"
#include <gtest/gtest.h>

//LFLAGS = -lgtest_main -lgtest -pthread

string a = "10000";
string b = "00001";
string c = "11010";
string d = "01101";

TEST(origin, opposite)
{
    EXPECT_TRUE(origin_to_opposite(a) == "11111");
    EXPECT_TRUE(origin_to_opposite(b) == "00001");
    EXPECT_TRUE(origin_to_opposite(c) == "10101");
    EXPECT_TRUE(origin_to_opposite(d) == "01101");
}

TEST(origin, complement)
{
    EXPECT_TRUE(origin_to_complement(a) == "00000");
    EXPECT_TRUE(origin_to_complement(b) == "00001");
    EXPECT_TRUE(origin_to_complement(c) == "10110");
    EXPECT_TRUE(origin_to_complement(d) == "01101");
}

TEST(opposite, origin)
{
    EXPECT_TRUE(opposite_to_origin(a) == "11111");
    EXPECT_TRUE(opposite_to_origin(b) == "00001");
    EXPECT_TRUE(opposite_to_origin(c) == "10101");
    EXPECT_TRUE(opposite_to_origin(d) == "01101");
}

TEST(opposite, complement)
{
    EXPECT_TRUE(opposite_to_complement(a) == "10001");
    EXPECT_TRUE(opposite_to_complement(b) == "00001");
    EXPECT_TRUE(opposite_to_complement(c) == "11011");
    EXPECT_TRUE(opposite_to_complement(d) == "01101");
}

TEST(complement,origin)
{
    EXPECT_TRUE(complement_to_origin(a) == "10000");
    EXPECT_TRUE(complement_to_origin(b) == "00001");
    EXPECT_TRUE(complement_to_origin(c) == "10110");
    EXPECT_TRUE(complement_to_origin(d) == "01101");
}

TEST(complement,opposite)
{
    EXPECT_TRUE(complement_to_opposite(a) == "11111");
    EXPECT_TRUE(complement_to_opposite(b) == "00001");
    EXPECT_TRUE(complement_to_opposite(c) == "11001");
    EXPECT_TRUE(complement_to_opposite(d) == "01101");
}

TEST(complement,negtive)
{
    EXPECT_TRUE(negative_complement(a) == "10000");
    EXPECT_TRUE(negative_complement(b) == "11111");
    EXPECT_TRUE(negative_complement(c) == "00110");
    EXPECT_TRUE(negative_complement(d) == "10011");

    cout << negative_complement(b) << endl;
    cout << negative_complement(c) << endl;
    cout << negative_complement(d) << endl;
}
//EXPECT        : when fail continue
//ASSERT        : when fail stop
