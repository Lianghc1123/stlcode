#include <iostream>
#include <list>

using namespace std;

//初始化
void test01() {
	list<int> mlist1;
	list<int> mlist2(10, 10); //有参构造
	list<int> mlist3(mlist2); //拷贝构造
	list<int> mlist4(mlist2.begin(), mlist2.end());

	//遍历
	for (list<int>::iterator it = mlist4.begin(); it != mlist4.end(); it++) {
			cout << *it << " ";
	}
	cout << endl;
}

//list容器插入删除
void test02() {
	list<int> mlist;

	mlist.push_back(100);
	mlist.push_front(200);

	//插入操作
	mlist.insert(mlist.begin(), 300);
	mlist.insert(mlist.end(), 400);
	mlist.insert(mlist.end(), 200);

	list<int>::iterator it = mlist.begin();
	it++; //不支持随机访问，所以不能完成类似 it + 3 的操作，只能it++
	it++;
	mlist.insert(it, 500);
	mlist.insert(mlist.end(), 200);

	//删除
	//mlist.pop_back();
	//mlist.pop_front();
	//mlist.erase(mlist.begin(), mlist.end()); //mlist.clear()
	mlist.remove(200); //删除匹配的所有值

	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
			cout << *lit << " ";
	}
	cout << endl;
}

//赋值操作
void test03() {
	list<int> mlist;
	mlist.assign(10, 10); //赋值操作

	list<int> mlist2;
	mlist2 = mlist; //=赋值

	mlist2.swap(mlist);
}

//翻转
void test04() {
	list<int> mlist;
	for (int i = 0; i < 10; i++) {
			mlist.push_back(i);
	}

	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
			cout << *lit << " ";
	}
	cout << endl;

	mlist.reverse(); //容器元素翻转

	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
			cout << *lit << " ";
	}
	cout << endl;
}

bool mycompare05(int v1, int v2) {
	return v1 > v2; //从大到小
}
//排序
void test05() {
	list<int> mlist;
	mlist.push_back(2);
	mlist.push_back(1);
	mlist.push_back(6);
	mlist.push_back(7);
	mlist.push_back(9);
	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
			cout << *lit << " ";
	}
	cout << endl;

	mlist.sort(); //这个sort是list的成员函数 默认从小到大
	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
			cout << *lit << " ";
	}
	cout << endl;

	mlist.sort(mycompare05); //从大到小
	for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++) {
			cout << *lit << " ";
	}
	cout << endl;

	//算法sort 支持可随机访问的容器
	//此处的list不支持随机访问 它用的sort是它的成员函数
}

int main(void) {
	test01();
	cout << "---------------------" << endl;
	test02();
	cout << "---------------------" << endl;
	test04();
	cout << "---------------------" << endl;
	test05();

	return 0;
}