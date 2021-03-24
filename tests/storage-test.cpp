#include "gtest/gtest.h"
#include <visualconstruct.h>

using namespace std;
using namespace VisualConstruct;

TEST(StorageTest, init)
{
    StorageDynamic<int> *storageDynamic = new StorageDynamic<int>(5);
    StorageStatic<int> *storageStatic = new StorageStatic<int>(5);
    EXPECT_NE(nullptr, storageDynamic);
    EXPECT_NE(nullptr, storageStatic);
}

TEST(StorageTest, staticAllocateFreeItemsSmall)
{
    StorageStatic<int> *storageStatic = new StorageStatic<int>(10);
    for (int i = 0; i < 10; i++)
    {
        storageStatic->allocateItem();
    }
    EXPECT_EQ(10, storageStatic->size());
    for (int i = 0; i < 10; i++)
    {
        storageStatic->freeItem(i);
    }
    EXPECT_EQ(0, storageStatic->size());
}

TEST(StorageTest, staticAllocateFreeItemsLarge)
{
    StorageStatic<int> *storageStatic = new StorageStatic<int>(1000);
    for (int i = 0; i < 1000; i++)
    {
        storageStatic->allocateItem();
    }
    EXPECT_EQ(1000, storageStatic->size());
    for (int i = 0; i < 1000; i++)
    {
        storageStatic->freeItem(i);
    }
    EXPECT_EQ(0, storageStatic->size());
}

TEST(StorageTest, dynamicAllocateFreeItemsSmall)
{
    StorageDynamic<int> *storageDynamic = new StorageDynamic<int>(5);
    for (int i = 0; i < 10; i++)
    {
        storageDynamic->allocateItem();
    }
    EXPECT_EQ(10, storageDynamic->size());
    for (int i = 0; i < 10; i++)
    {
        storageDynamic->freeItem(i);
    }
    EXPECT_EQ(0, storageDynamic->size());
}

TEST(StorageTest, dynamicAllocateFreeItemsLarge)
{
    StorageDynamic<int> *storageDynamic = new StorageDynamic<int>(20);
    for (int i = 0; i < 1000; i++)
    {
        storageDynamic->allocateItem();
    }
    EXPECT_EQ(1000, storageDynamic->size());
    for (int i = 0; i < 1000; i++)
    {
        storageDynamic->freeItem(i);
    }
    EXPECT_EQ(0, storageDynamic->size());
}

TEST(StorageTest, staticSetGetItem)
{
    StorageStatic<int> *storageStatic = new StorageStatic<int>(20);
    for (int i = 0; i < 10; i++)
    {
        auto item_index = storageStatic->allocateItem();
        int *item = storageStatic->getItem(i);
        *item = i;
    }
    int *item = storageStatic->getItem(5);
    EXPECT_EQ(5, *item);
    for (int i = 0; i < 10; i++)
    {
        storageStatic->freeItem(i);
    }
    EXPECT_EQ(0, storageStatic->size());
}

TEST(StorageTest, dynamicSetGetItem)
{
    StorageDynamic<int> *storageDynamic = new StorageDynamic<int>(5);
    for (int i = 0; i < 10; i++)
    {
        auto item_index = storageDynamic->allocateItem();
        int *item = storageDynamic->getItem(i);
        *item = i;
    }
    int *item = storageDynamic->getItem(5);
    EXPECT_EQ(5, *item);
    for (int i = 0; i < 10; i++)
    {
        storageDynamic->freeItem(i);
    }
    EXPECT_EQ(0, storageDynamic->size());
}

TEST(StorageTest, staticStressTest)
{
    StorageStatic<int> *storageStatic = new StorageStatic<int>(10000);
    for (int i = 0; i < 10000; i++)
    {
        auto item_index = storageStatic->allocateItem();
        int *item = storageStatic->getItem(i);
        *item = i;
    }
    EXPECT_EQ(10000, storageStatic->size());
    for (int i = 0; i < 10000; i++)
    {
        storageStatic->freeItem(i);
    }
    EXPECT_EQ(0, storageStatic->size());
}

TEST(StorageTest, dynamicStressTest)
{
    StorageDynamic<int> *storageDynamic = new StorageDynamic<int>(20);
    for (int i = 0; i < 10000; i++)
    {
        auto item_index = storageDynamic->allocateItem();
        int *item = storageDynamic->getItem(i);
        *item = i;
    }
    EXPECT_EQ(10000, storageDynamic->size());
    for (int i = 0; i < 10000; i++)
    {
        storageDynamic->freeItem(i);
    }
    EXPECT_EQ(0, storageDynamic->size());
}
