#include <iostream>
#include <deque>
//deque容器和vector容器的区别就是它可以在两端增删
//多了一个push_front和pop_front

//特性总结：
//1 双端插入和删除元素效率较高
//2 指定位置插入也会导致数据元素移动，降低效率
//3 可随机存取，效率高

using namespace std;

void PrintDeque(deque<int> &d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//deque初始化
void test01()
{
    deque<int> d1;
    deque<int> d2(10, 5);
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4(d3);

    //打印d4
    PrintDeque(d4);
}

//赋值 大小操作
void test02()
{
    deque<int> d1;
    d1.assign(10, 5);
    deque<int> d2;
    d2.assign(d1.begin(), d1.end()); //迭代器指定区间赋值
    deque<int> d3;
    d3 = d2; //=操作符

    d1.swap(d2); //交换两个空间元素

    if (d1.empty())
    {
        cout << "空！" << endl;
    }
    else
    {
        cout << "size: " << d1.size() << endl;
    }

    d1.resize(5); //原来有十个元素，后五个元素扔掉
}

//deque容器的插入和删除
void test03()
{
    deque<int> d1;
    d1.push_back(100);
    d1.push_front(200);
    d1.push_back(300);
    d1.push_back(400);
    d1.push_front(500);

    //500 200 100 300 400
    PrintDeque(d1);

    int val = d1.front(); //拿到被删除的数据
    d1.pop_front(); //删除第一个元素

    val = d1.back();
    d1.pop_back(); //删除最后一个元素

}

int main()
{
    test01();
    cout << "----------------" << endl;
    test02();
    cout << "----------------" << endl;
    test03();

    return 0;
}
