#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;
 
template<class T>
class myVector {
private:
	#define WALK_LENGTH 64;
	
public:
  // 构造函数
	myVector():array(0), theSize(0), theCapacity(0) { }
	myVector(const T& t, unsigned int n):array(0), theSize(0), theCapacity(0) {
		while (n--) {
			push_back(t);
		}
	}
	// 拷贝构造
	myVector(const myVector<T>& other):array(0), theSize(0), theCapacity(0) {
		*this = other;
	} 
	// =操作符重载
	myVector<T>& operator=(myVector<T>& other) {
		if (this == &other)
			return *this;
		clear();
		theSize = other.size();
		theCapacity = other.capacity();
		array = new T[theCapacity];
		for (unsigned int i = 0; i < theSize; ++i) {
			array[i] = other[i];
		}
		return *this;
	}
	// 析构函数
	~myVector() {
		clear();
	}
	// []操作符重载
	T& operator[](unsigned int pos) {
		assert(pos < theSize);
		return array[pos];
	}
	// 长度
	unsigned int size() {
		return theSize;
	}
	// 容量
	unsigned int capacity() {
		return theCapacity;
	}
	// 是否为空
	bool empty() {
		return theSize == 0;
	}
	// 清空
	void clear() {
		deallocator(array);
		array = 0;
		theSize = 0;
		theCapacity = 0;
	}
	// 在尾部添加元素
	void push_back(const T& t) {
		insert_after(theSize - 1, t);
	}
	// 在添加元素
	void push_front(const T& t) {
		insert_before(0, t);
	}
	// 实现insert_after和insert_before
	void insert_after(int pos, const T& t) {
		insert_before(pos + 1, t);
	}
	void insert_before(int pos, const T& t) {
		if (theSize == theCapacity) {
			T* oldArray = array;
			theCapacity += WALK_LENGTH;
			array = allocator(theCapacity);
			for (unsigned int i = 0; i < theSize; ++i) {
				array[i] = oldArray[i];
			}
			deallocator(oldArray);
		}
		for (int i = (int)theSize; i > pos; --i) {
			array[i] = array[i - 1];
		}
		array[pos] = t;
		theSize++;
	}
	// 删除
	void erase(unsigned int pos) {
		if (pos < theSize) {
			--theSize;
			for (unsigned int i = pos; i < theSize; ++i) {
				array[i] = array[i + 1];
			}
		}
	}
	
private:
	T* allocator(unsigned int size) {
		return new T[size];
	}
	void deallocator(T* arr) {
		if (arr)
			delete [] arr;
	}
	
private:
	T*           array;
	unsigned int theSize;
	unsigned int theCapacity;
};

void printmyVector(myVector<int>& vec) {
	for (unsigned int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "alloc capacity = " << vec.capacity() << ", size = " << vec.size() << endl;
}

int main(void) {
	myVector<int> myVector1(0, 10);
	myVector1.push_front(1);
	myVector1.push_back(11);
	printmyVector(myVector1);
	
	myVector<int> myVector2;
	myVector2.push_back(3);
	myVector2.push_front(6);
	printmyVector(myVector2);
	
	myVector2 = myVector1;
	myVector2.erase(0);
	printmyVector(myVector2);
	
	return 0;
}




