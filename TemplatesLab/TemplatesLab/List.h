#pragma once
template <class T, size_t N>
class List {
public:
	List() : maxItemCount(N), currentItemCount(0) {
		objectArray = new T[maxItemCount];
	}

	~List() {
		delete[] objectArray;
	}

	size_t size() const {
		return currentItemCount;
	}

	const T& operator[] (int index) const {
		return objectArray[index];
	}

	void operator+= (const T& new_item) {
		if (currentItemCount != maxItemCount) {
			objectArray[currentItemCount++] = new_item;
		}
	}

private:
	T* objectArray;
	size_t maxItemCount;
	size_t currentItemCount;
};