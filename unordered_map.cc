#include <map>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

/* typedef unordered_map<string, double>::iterator MyIte;

void test_unordered_map() {
	unordered_map<string, double> umap;
	umap.insert(make_pair("苹果", 2.5));
	umap.insert(make_pair("香蕉", 3.5));
	umap.insert(make_pair("香蕉", 3.5));
	umap.insert(make_pair("西瓜", 1.6));
	umap.insert(make_pair("哈密瓜", 2.9));
	umap["榴莲"] = 4.0;
	
	MyIte it = umap.begin();
	while (it != umap.end()) {
		cout << it->first << ": " << it->second << endl;
		++it;
	}
	cout << "桶数量：" << umap.bucket_count() << endl;
	cout << "负载因子：" << umap.load_factor() << endl;
	
} */

struct Store {
	string name;
	string addr;
	Store(const string& na = "", const string& ad = "") : name(na), addr(ad) {}
	// 重载==支持等于比较
	bool operator==(const Store& s) const {
		return name == s.name && addr == s.addr;
	}
};

// 定制返回哈希值的仿函数
struct hash_key {
	size_t operator()(const Store& s) const {
		size_t seed = 131;
		size_t hash = 0;
		size_t i = 0;
		for (i = 0; i < s.name.size(); ++i) {
			hash = (hash * seed) + s.name[i];
		}
		return hash;
	}
};

typedef unordered_map<Store, int, hash_key>::iterator MyIte;
void test_unordered_map() {
	unordered_map<Store, int, hash_key> umap;
	Store s1("火锅店", "重庆");
	Store s2("凉皮店", "西安");
	Store s3("烤鸭店", "北京");
	
	umap.insert(make_pair(s1, 1));
	umap.insert(make_pair(s2, 1));
	umap[s3] = 1;
	
	MyIte it = umap.begin();
	while (it != umap.end()) {
		cout << it->first.name << " " << it->first.addr << ": " << it->second << endl;
		++it;
	}
}

int main() {
	test_unordered_map();
	
	return 0;
}
















