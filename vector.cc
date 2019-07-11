#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct rect {
	int id;
	int length;
	int width;
	bool operator<(const rect& a) const {
		if (id != a.id) {
			return id < a.id;
		} else {
			if (length != a.length)
				return length < a.length;
			else
				return width < a.width;
		}
	}
} Rect;

void printV(int n) {
	cout << n << " ";
}

int main(void) {
	int a[7] = {1,2,3,4,5,6,7};
	vector<int> ivector(a, a + 7);
	
	vector<int>::iterator iter;
	for (iter = ivector.begin(); iter != ivector.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	ivector[5] = 1;
	cout << ivector[5] << endl << ivector.size() << endl << ivector.capacity() << endl;

	for (int i = 0; i < ivector.size(); ++i) {
		cout << ivector[i] << " ";
	}
	cout << endl;

	for_each(ivector.begin(), ivector.end(), printV);
	cout << endl;
	
	cout << "----------------" << endl;
	
	vector<Rect> vec;
	Rect rect1;
	rect1.id = 2;
	rect1.length = 3;
	rect1.width = 4;
	vec.push_back(rect1);
	
	rect1.id = 2;
	rect1.length = 1;
	rect1.width = 9;
	vec.push_back(rect1);
	
	vector<Rect>::iterator it = vec.begin();
	cout << (*it).id << " " << (*it).length << " " << (*it).width << endl;
	sort(vec.begin(), vec.end());
	cout << (*it).id << " " << (*it).length << " " << (*it).width << endl;
	
	cout << "----------------" << endl;
	
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	ivec.push_back(4);
	ivec.push_back(3);
	ivec.push_back(3);
	ivec.push_back(6);
	ivec.push_back(7);
	for_each(ivec.begin(), ivec.end(), printV);
	cout << endl;
	
/* 	vector<int>::iterator itfind = find(ivec.begin(), ivec.end(), 4);
  if (itfind == ivec.end())
		cout << "Not Found" << endl;
	else
		cout << "Found " << *itfind << endl; */
	
	// vector的删除
	for (vector<int>::iterator iit = ivec.begin(); iit != ivec.end(); ) {
		if (*iit == 3) {
			iit = ivec.erase(iit); // 序列式容器的插入删除都会使迭代器失效，需要返回值接收
		} else {
			++iit;
		}
	}
	for_each(ivec.begin(), ivec.end(), printV);
	cout << endl;
	
	return 0;
}














