#include "../inc/set.hpp"
#include <string>
#include <gtest/gtest.h>


TEST(TEST_PUBLIC_INTERFACES, simple_add_elements){
    mycontainer::set data;
    ASSERT_FALSE(data.add("Element1"));
    ASSERT_FALSE(data.add("Element2"));
    ASSERT_FALSE(data.add("Element3"));

    ASSERT_EQ(3, data.size());
}

TEST(TEST_PUBLIC_INTERFACES, simple_contains_elements){
    mycontainer::set data;
    ASSERT_FALSE(data.add("Element1"));
    ASSERT_FALSE(data.add("Element2"));
    ASSERT_FALSE(data.add("Element3"));

    ASSERT_EQ(3, data.size());

    ASSERT_TRUE(data.contains("Element1"));
    ASSERT_FALSE(data.contains("Element"));
}

TEST(TEST_PUBLIC_INTERFACES, simple_remove_elements){
    mycontainer::set data;
    ASSERT_FALSE(data.add("Element1"));
    ASSERT_FALSE(data.add("Element2"));
    ASSERT_FALSE(data.add("Element3"));

    ASSERT_EQ(3, data.size());

    ASSERT_TRUE(data.contains("Element3"));
    ASSERT_TRUE(data.remove("Element3"));
    ASSERT_FALSE(data.contains("Element3"));
    ASSERT_EQ(2, data.size());
}

TEST(TEST_OPERATIONAL_BEHAVIOR, assignment_operator_test){
    mycontainer::set data;
    ASSERT_FALSE(data.remove(""));
    ASSERT_FALSE(data.contains("sjhd"));
    ASSERT_FALSE(data.add("Element1"));
    ASSERT_FALSE(data.add("Element2"));
    ASSERT_FALSE(data.add(""));

    ASSERT_EQ(3, data.size());

    auto data2 = data;
    ASSERT_EQ(3, data2.size());
    ASSERT_TRUE(data.remove("Element1"));
    ASSERT_EQ(2, data.size());
    ASSERT_FALSE(data.contains("Element1"));
    ASSERT_EQ(3, data2.size());
    ASSERT_TRUE(data2.contains("Element1"));
    ASSERT_TRUE(data2.contains("Element2"));
    ASSERT_TRUE(data2.contains(""));
}

TEST(TEST_OPERATIONAL_BEHAVIOR, copy_constructor_test){
    mycontainer::set data;
    ASSERT_FALSE(data.remove(""));
    ASSERT_FALSE(data.contains("sjhd"));
    ASSERT_FALSE(data.add("Element1"));
    ASSERT_FALSE(data.add("Element2"));
    ASSERT_FALSE(data.add(""));

    ASSERT_EQ(3, data.size());

    mycontainer::set data2(data);
    ASSERT_EQ(3, data2.size());
    ASSERT_TRUE(data.remove("Element1"));
    ASSERT_EQ(2, data.size());
    ASSERT_FALSE(data.contains("Element1"));
    ASSERT_EQ(3, data2.size());
    ASSERT_TRUE(data2.contains("Element1"));
    ASSERT_TRUE(data2.contains("Element2"));
    ASSERT_TRUE(data2.contains(""));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}