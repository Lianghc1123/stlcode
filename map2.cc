#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

/*make_pair内联函数  返回一个pair对象*/
 //template<class K, class V>
 //inline pair<K, V> make_pair(const K& k, const V& v)
 //{ 
 //  return pair<K, V>( k,v);    
 //} 

/*
void test_map_insert( ) 
{
	//实现一个字典
	typedef map<string, string>::iterator MyIterator;
	map<string, string> direct;
	direct.insert( pair<string, string>("insert", "插入" ));
	direct.insert( pair<string, string>("sort", "排序" ));
	direct.insert( make_pair("apple", "苹果" ));
	direct.insert( make_pair("insert", "插入" ));
	direct.insert( make_pair("sort", "排序" ));

	//(1)pair<iterator, bool> insert( const value_type& V); 
	pair<MyIterator, bool> ret = direct.insert(make_pair("apple", "苹果"));
	if(ret.second == false)  //插入元素已经存在，将second置为false
	{
		 cout<<"'apple' is inserted！";
		 //first被设置为一个迭代器，指向新插入的元素或映射中具有等效键的元素
		 cout<< "with value of "<<ret.first->second<<endl;
	}
	//(2)指定iterator插入
	direct.insert(direct.begin( ), make_pair("os1", "操作系统1"));
	direct.insert(direct.begin( ), make_pair("os2", "操作系统2")); //os2仍在os1后面

	//(3)范围插入
	map<string, string> another;
	another.insert(direct.begin( ), direct.end( ));

	//遍历(和set方式类似)
	MyIterator it = direct.begin( );
	while( it != direct.end( ))
	{
		 cout<<it->first<<": "<<it->second<<endl;
		 ++it;
	}
}

int main() 
{
	test_map_insert();
	cout << "------------" << endl;
	
	std::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];  //插入key为‘c’的元素，随后将其对应value值修改。

  //key为'a'的元素已经插入，此时返回‘a’所对应value的值
  std::cout << "mymap['a'] is " << mymap['a'] << '\n'; 
  //key为'b'的元素已经插入，此时返回‘b’所对应value的值
  std::cout << "mymap['b'] is " << mymap['b'] << '\n'; 
  //key为'c'的元素已经插入，此时返回‘c’所对应value的值
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';  
  //直接插入key为‘a’的元素，元素对应value值为默认的“”
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';  
  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

	
	return 0;
}
*/

typedef map<string, int>::iterator CountIte;
struct Compare {
	bool operator()(CountIte lhs, CountIte rhs) {
		return lhs->second > rhs->second;
	}
};

void get_topK_gramar(const vector<string>& v, int k) {
	// 统计vector中各种相同key出现的次数
	map<string, int> countMap;
	for (int i = 0; i < v.size(); ++i) {
		countMap[v[i]]++;
	}
	
	multiset<CountIte, Compare> sortSet;
	CountIte cit = countMap.begin();
	while (cit != countMap.end()) {
		sortSet.insert(cit);
		++cit;
	}
	
	multiset<CountIte, Compare>::iterator it1 = sortSet.begin();
	for (; it1 != sortSet.end(); ++it1) {
		if (k--) 
			cout << (*it1)->first << ": " << (*it1)->second << endl;
	}
}

void test_map_ques() {
	vector<string> v;
	v.push_back("PHP");
	v.push_back("python");
	v.push_back("C/C++");
	v.push_back("PHP");
	v.push_back("Java");
	v.push_back("PHP");
	v.push_back("PHP");
	v.push_back("C/C++");
	v.push_back("PHP");
	v.push_back("Java");
	v.push_back("C/C++");
	v.push_back("PHP");
	v.push_back("PHP");
	
	get_topK_gramar(v, 3);
}

int main(void) {
	test_map_ques();
	
	return 0;
}





















