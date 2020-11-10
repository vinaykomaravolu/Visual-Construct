#include <storage.h>
#include <entityManager.h>

namespace VisualConstruct
{
	// Dynamic Storage Implementation
	// Linked list with holes and multiple segmented arrays
	// TODO: need to remove segmented array if nothing is stored.
	template <class T>
	StorageDynamic<T>::StorageDynamic(uint32_t segmentSize_t)
	{
		segmentSize = segmentSize_t;
		storageBuffers = std::vector<std::vector<item_t<T>>>(1, std::vector<item_t<T>>(segmentSize));
	}

	template <class T>
	uint32_t StorageDynamic<T>::allocateItem()
	{
		uint32_t freeSlot = next_free;
		// Allocate new segment if not enough space
		if(freeSlot >= segmentSize * storageBuffers.size())
		{
			storageBuffers.push_back(std::vector<item_t<T>>(segmentSize));
		}

		if (storageBuffers[freeSlot / segmentSize][freeSlot % segmentSize].next_free == 0)
		{
			next_free = freeSlot + 1;
		}
		else
		{
			next_free = storageBuffers[freeSlot / segmentSize][freeSlot % segmentSize].next_free;
		}
		storageBuffers[freeSlot / segmentSize][freeSlot % segmentSize].active = true;
		allocatedItems++;
		return freeSlot;
	}

	template <class T>
	void StorageDynamic<T>::freeItem(uint32_t i)
	{
		assert(i < segmentSize * storageBuffers.size());
		storageBuffers[i / segmentSize][i % segmentSize] = item_t<T>();
		storageBuffers[i / segmentSize][i % segmentSize].active = false;
		storageBuffers[i / segmentSize][i % segmentSize].next_free = next_free;
		next_free = i;
		allocatedItems--;
	}

	template <class T>
	T* StorageDynamic<T>::getItem(uint32_t i)
	{
		return &storageBuffers[i / segmentSize][i % segmentSize].object;
	}

	template <class T>
	uint64_t StorageDynamic<T>::allocatedItemsSize()
	{
		return allocatedItems;
	}

	// Static Storage Implementation
	// Linked list with holes and single fixed size array
	template <class T>
	StorageStatic<T>::StorageStatic(uint32_t maxSize_t)
	{
		maxSize = maxSize_t;
		storageBuffers = std::vector<item_t<T>>(maxSize);
	}

	template <class T>
	uint32_t StorageStatic<T>::allocateItem()
	{
		assert(allocatedItems <= maxSize);
		uint32_t freeSlot = next_free;
		if (storageBuffers[freeSlot].next_free == 0)
		{
			next_free = freeSlot + 1;
		}
		else
		{
			next_free = storageBuffers[freeSlot].next_free;
		}
		storageBuffers[freeSlot].active = true;
		allocatedItems++;
		return freeSlot;
	}

	template <class T>
	void StorageStatic<T>::freeItem(uint32_t i)
	{
		assert(i < maxSize);
		storageBuffers[i] = item_t<T>();
		storageBuffers[i].active = false;
		storageBuffers[i].next_free = next_free;
		next_free = i;
		allocatedItems--;
	}

	template <class T>
	T* StorageStatic<T>::getItem(uint32_t i)
	{
		return &storageBuffers[i].object;
	}

	template <class T>
	uint64_t StorageStatic<T>::allocatedItemsSize()
	{
		return allocatedItems;
	}

    template class StorageStatic<int>;
    template class StorageDynamic<int>;
}