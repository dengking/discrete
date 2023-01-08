#include <string>
#include "singly_linked_list.h"

#include <gtest/gtest.h>

class SinglyLinkedListTest : public ::testing::Test
{
};

TEST_F(SinglyLinkedListTest, simple)
{
    SinglyLinkedList<int> l{};
    l.push(1);
    l.push(2);
    l.push(3);
    EXPECT_EQ(l.get_size_by_iteration(), 3);
}
