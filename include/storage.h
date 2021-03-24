#pragma once
#include <vector>
#include <iostream>
#include <assert.h>

namespace VisualConstruct
{
    //TODO: move to storage.cpp
    template <class T>
    struct item_t
    {
        T object;
        uint32_t next_free = -1;
        bool active;
    };

    template <class T>
    class IStorage
    {
        virtual void freeItem(uint32_t i) = 0;
        virtual uint32_t allocateItem() = 0;
        virtual T *getItem(uint32_t i) = 0;
        virtual uint64_t size() = 0;
    };

    template <class T>
    class StorageDynamic : public IStorage<T>
    {
    public:
        StorageDynamic(uint32_t segmentSize_t);
        void freeItem(uint32_t i);
        uint32_t allocateItem();
        T *getItem(uint32_t i);
        uint64_t size();

    private:
        uint32_t segmentSize;
        std::vector<std::vector<item_t<T>>> storageBuffers;
        uint32_t lastIndex = 0;
        uint32_t next_free = 0;
        uint32_t allocatedItems = 0;
    };

    template <class T>
    class StorageStatic : public IStorage<T>
    {
    public:
        StorageStatic(uint32_t maxSize_t);
        void freeItem(uint32_t i);
        uint32_t allocateItem();
        T *getItem(uint32_t i);
        uint64_t size();

    private:
        uint32_t maxSize;
        std::vector<item_t<T>> storageBuffers;
        uint32_t lastIndex = 0;
        uint32_t next_free = 0;
        uint32_t allocatedItems = 0;
    };

}
