#include <map>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void test_compare() {
	unordered_map<int, int> umap;
	map<int, int> mp;
	srand(time(NULL));
	
	const int N = 100000;
	vector<int> a;
	for (int i = 0; i < N; ++i) {
		a.push_back(rand() % N);
	}
	
	clock_t begin1, end1;
	begin1 = clock();
	umap.rehash(100000);
	for (int i = 0; i < N; ++i) {
		umap[a[i]];
	}
	end1 = clock();
	
	clock_t begin2, end2;
	begin2 = clock();
	for (int i = 0; i < N; ++i) {
		mp[a[i]];
	}
	end2 = clock();
	
	cout << "负载因子：" << umap.load_factor() << " " << "桶数：" << umap.bucket_count() << endl;
  //统计运行的毫秒差
  cout << "unordered_map: " << (end1 - begin1) / 1000 << endl;
  cout << "map: " << (end2 - begin2) / 1000 << endl;
}

int main() {
	test_compare();
	
	return 0;
}