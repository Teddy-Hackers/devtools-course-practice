// Copyright 2023 Shipilov Artem

#include <gtest/gtest.h>

#include "include/hashmap.h"

TEST(Hashmap, Can_Create_An_Empty_Hashmap) {
    ASSERT_ANY_THROW(hashmap THash(0));
}

TEST(Hashmap, Can_Create_Hashmap) { ASSERT_NO_THROW(hashmap THash(5)); }

TEST(Hashmap, Can_Copy) {
    hashmap THash(5);
    ASSERT_NO_THROW(hashmap THash2(THash));
}

TEST(Hashmap, GetKey_From_Empty_Hashtable) {
    hashmap THash(2);
    ASSERT_ANY_THROW(THash.GetKey());
}

TEST(Hashmap, GetKey_NoThrow) {
    hashmap THash(2);
    THash.InsRecord("2", 20);
    ASSERT_NO_THROW(THash.GetKey());
}

TEST(Hashmap, GetKey_True) {
    hashmap THash(4);
    THash.InsRecord("5", 10);
    THash.InsRecord("2", 11);
    ASSERT_EQ(THash.GetKey(), "2");
}

TEST(Hashmap, GetData_From_Empty_Hashtable) {
    hashmap THash(2);
    ASSERT_ANY_THROW(THash.GetData());
}

TEST(Hashmap, GetData_NoThrow) {
    hashmap THash(2);
    THash.InsRecord("2", 20);
    ASSERT_NO_THROW(THash.GetData());
}

TEST(Hashmap, GetData_True) {
    hashmap THash(4);
    THash.InsRecord("5", 10);
    THash.InsRecord("2", 11);
    ASSERT_EQ(*THash.GetData(), 11);
}

TEST(Hashmap, GoNext_Throw) {
    hashmap THash(3);
    THash.InsRecord("5", 10);
    THash.InsRecord("2", 11);
    ASSERT_NO_THROW(THash.GoNext());
}

TEST(Hashmap, Move_On_When_The_Hashtable_Ends) {
    hashmap THash(2);
    THash.InsRecord("5", 10);
    THash.InsRecord("2", 11);
    THash.GoNext();
    THash.GoNext();
    ASSERT_ANY_THROW(THash.GoNext());
}

TEST(Hashmap, Reset_Throw) {
    hashmap THash(3);
    THash.InsRecord("5", 10);
    THash.InsRecord("2", 11);
    ASSERT_NO_THROW(THash.Reset());
}

TEST(Hashmap, HashFunc_Throw) {
    hashmap THash(3);
    THash.InsRecord("5", 10);
    THash.InsRecord("2", 11);
    ASSERT_NO_THROW(THash.HashFunc("5"));
}

TEST(Hashmap, InsRecord_NoThrow) {
    hashmap TH(2);
    ASSERT_NO_THROW(TH.InsRecord("4", 12));
}

TEST(Hashmap, Insert_Into_Completed_Hashtable) {
    hashmap THash(2);
    THash.InsRecord("5", 20);
    THash.InsRecord("6", 21);
    ASSERT_ANY_THROW(THash.InsRecord("7", 22));
}

TEST(Hashmap, Insert_Hashtable_Of_Existing_Entry) {
    hashmap THash(2);
    THash.InsRecord("5", 20);
    THash.InsRecord("6", 21);
    ASSERT_ANY_THROW(THash.InsRecord("6", 21));
}

TEST(Hashmap, Insert_Into_Almost_Complete_Hashtable) {
    hashmap THash(3);
    THash.InsRecord("5", 12);
    THash.InsRecord("1", 3);
    ASSERT_NO_THROW(THash.InsRecord("3", 1233));
}

TEST(Hashmap, The_Correctness_Of_The_Inserted_Values) {
    hashmap THash(5);
    THash.InsRecord("1", 6);
    ASSERT_EQ(*THash.GetData(), 6);
    ASSERT_EQ(THash.GetKey(), "1");
    ASSERT_EQ(THash.GetDataCount(), 1);
    THash.InsRecord("3", 93);
    ASSERT_EQ(*THash.GetData(), 93);
    ASSERT_EQ(THash.GetKey(), "3");
    THash.InsRecord("28", 71);
    ASSERT_EQ(*THash.GetData(), 71);
    ASSERT_EQ(THash.GetKey(), "28");
    ASSERT_EQ(THash.GetDataCount(), 3);
}

TEST(Hashmap, Delete_An_Inserted_Record) {
    hashmap THash(2);
    THash.InsRecord("2", 12);
    ASSERT_NO_THROW(THash.DelRecord("2"));
}

TEST(Hashmap, Delete_From_Full_Hashtable) {
    hashmap THash(3);
    THash.InsRecord("1", 1);
    THash.InsRecord("2", 2);
    THash.InsRecord("3", 3);
    ASSERT_NO_THROW(THash.DelRecord("1"));
}

TEST(Hashmap, Delete_From_Empty_Hashtable) {
    hashmap THash(2);
    ASSERT_ANY_THROW(THash.DelRecord("1"));
}

TEST(Hashmap, Deleting_NonExistent_Entry) {
    hashmap THash(2);
    THash.InsRecord("1", 1);
    THash.InsRecord("2", 2);
    ASSERT_ANY_THROW(THash.DelRecord("3"));
}

TEST(Hashmap, DelRecord_Value) {
    hashmap THash(5);
    THash.InsRecord("4", 6);
    THash.InsRecord("1", 5);
    THash.InsRecord("5", 71);
    THash.InsRecord("11", 7);
    THash.InsRecord("41", 71);
    ASSERT_EQ(THash.GetDataCount(), 5);
    THash.DelRecord("1");
    ASSERT_EQ(THash.FindRecord("1"), nullptr);
    ASSERT_NE(THash.FindRecord("5"), nullptr);
    THash.DelRecord("5");
    ASSERT_EQ(THash.FindRecord("5"), nullptr);
    ASSERT_EQ(THash.GetDataCount(), 3);
}

TEST(Hashmap, FindRecord_An_Entry_In_The_Hashtable) {
    hashmap THash(2);
    THash.InsRecord("10", 1);
    ASSERT_NO_THROW(THash.FindRecord("10"));
}

TEST(Hashmap, FindRecord_An_Entry_In_Empty_Hashtable1) {
    hashmap THash(2);
    ASSERT_NO_THROW(THash.FindRecord("1"));
}

TEST(Hashmap, FindRecord_For_An_Entry_In_NonEmpty_Hashtable) {
    hashmap THash(5);
    THash.InsRecord("5", 3);
    THash.InsRecord("4", 4);
    THash.InsRecord("3", 5);
    ASSERT_NO_THROW(THash.FindRecord("4"));
}

TEST(Hashmap, FindRecord_For_Empty_record_In_Hashtable) {
    hashmap THash(2);
    ASSERT_EQ(THash.FindRecord("1"), nullptr);
}

TEST(Hashmap, FindRecord_For_record_In_Hashtable) {
    hashmap THash(5);
    THash.InsRecord("1", 1);
    THash.InsRecord("2", 5);
    ASSERT_EQ(THash.FindRecord("5"), nullptr);
}

TEST(Hashmap, FindRecord_Correct_Search) {
    hashmap THash(5);
    THash.InsRecord("1", 12);
    THash.InsRecord("2", 9);
    THash.InsRecord("3", 7);
    THash.InsRecord("5", 17);
    ASSERT_EQ(*THash.FindRecord("1"), 12);
    ASSERT_EQ(*THash.FindRecord("3"), 7);
}
