#include <gtest/gtest.h>

#include "linked_list.h"
#include "braces_validation.h"

//Task 2 
//Implement detection of loop in linked-list
TEST(HasLoopTest, EmptyList)
{
    //arrange
    linked_list_t* list = NULL;
    create(&list);

    //act
    bool value = has_loop(list);

    //assert
    EXPECT_EQ(false, value);

    destroy(list);
}

TEST(HasLoopTest, LooplessList)
{
    //arrange
    linked_list_t* list = NULL;
    create(&list);

    for (int i = 0; i < 4; ++i)
    {
        void* data = malloc(sizeof(int));
        *(int*)data = i;

        push_back(list, data);
    }

    //act
    bool value = has_loop(list);

    //assert
    EXPECT_EQ(false, value);

    destroy_deep(list, &free);
}

TEST(HasLoopTest, CyclicList)
{
    //arrange
    linked_list_t* list = NULL;
    create(&list);

    void* data = malloc(sizeof(int));
    *(int*)data = 0;
    node_t* head = push_back(list, data);

    node_t* curr = NULL;
    for (int i = 1; i < 4; ++i)
    {
        void* data = malloc(sizeof(int));
        *(int*)data = i;

        curr = push_back(list, data);
    }

    curr->next = head;

    //act
    bool value = has_loop(list);

    //assert
    EXPECT_EQ(true, value);

    curr->next = NULL;
    destroy_deep(list, &free);
}

//Task 3
//Write a function with single-linked list as input. 
//Output is pointer to node in the middle of this list. 
//If count of nodes is even, return the left one node on the middle
TEST(GetListMiddleTest, EmptyList)
{
    //arrange
    linked_list_t* list = NULL;
    create(&list);

    //act
    node_t* middle = get_middle(list);

    //assert
    EXPECT_EQ(NULL, middle);

    destroy(list);
}

TEST(GetListMiddleTest, EvenElemsCount)
{
    //arrange
    linked_list_t* list = NULL;
    create(&list);

    for (int i = 0; i < 4; ++i)
    {
        void* data = malloc(sizeof(int));
        *(int*)data = i;
        
        push_back(list, data);
    }

    //act
    int value = *(int*)get_middle(list)->data;

    //assert
    EXPECT_EQ(1, value);

    destroy_deep(list, &free);
}

TEST(GetListMiddleTest, OddElemsCount)
{
    //arrange
    linked_list_t* list = NULL;
    create(&list);

    for (int i = 0; i < 5; ++i)
    {
        void* data = malloc(sizeof(int));
        *(int*)data = i;

        push_back(list, data);
    }

    //act
    int value = *(int*)get_middle(list)->data;

    //assert
    EXPECT_EQ(2, value);

    destroy_deep(list, &free);
}

//Task 4
//Write function with string as input 
//the string could contain 3 types of braces(), {}, []
//Function must validate if braces are correct or not
TEST(BracesValidationTest, EmptyString)
{
    //arrange
    char str[] = "";

    //act
    bool value = is_valid(str);

    //assert
    EXPECT_EQ(true, value);
}

TEST(BracesValidationTest, BalancedSeq)
{
    //arrange
    char str[] = "{()}";

    //act
    bool value = is_valid(str);

    //assertq
    EXPECT_EQ(true, value);
}

TEST(BracesValidationTest, UnbalancedSeq)
{
    //arrange
    char str[] = "({)}";

    //act
    bool value = is_valid(str);

    //assert
    EXPECT_EQ(false, value);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
