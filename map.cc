#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#if 0
int main() {
	map<int, string> mapStu;
	mapStu.insert(pair<int, string>(1, "stu_one"));
	mapStu.insert(pair<int, string>(2, "stu_two"));
	mapStu.insert(pair<int, string>(3, "stu_three"));
	
	mapStu.insert(map<int, string>::value_type (4, "stu_four"));
	mapStu.insert(map<int, string>::value_type (5, "stu_five"));
	
	mapStu[6] = "stu_six";
	
	map<int, string>::iterator it;
	for (it = mapStu.begin(); it != mapStu.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	
/* 	map<int, string>::reverse_iterator iter;
	for (iter = mapStu.rbegin(); iter != mapStu.rend(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}
	
	int iSize = mapStu.size();
	for (int i = 1; i <= iSize; ++i) {
		cout << i << " " << mapStu[i] << endl;
	} */
	
	map<int, string>::iterator itfind = mapStu.find(3);
	if (itfind != mapStu.end()) {
		cout << "Found, the value is " << itfind->second << endl;
	} else {
		cout << "Do not found" << endl;
	}
	
	for (it = mapStu.begin(); it != mapStu.end();) {
		if ((*it).second == "stu_three") {
			mapStu.erase(it++); // 关联式容器的插入删除不会导致迭代器失效，所以可以使用被删除元素位置的下一个位置
		} else {
			++it;
		}
	}
	for (it = mapStu.begin(); it != mapStu.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	
	
	return 0;
}
#endif

#if 0
int main() {
	map<int, string, greater<int> > mapStu; // 注意空格
	mapStu.insert(pair<int, string>(1, "stu_one"));
	mapStu.insert(pair<int, string>(2, "stu_two"));
	mapStu.insert(pair<int, string>(3, "stu_three"));
	
	mapStu.insert(map<int, string>::value_type (4, "stu_four"));
	mapStu.insert(map<int, string>::value_type (5, "stu_five"));
	
	mapStu[6] = "stu_six";
	
	map<int, string>::iterator it;
	for (it = mapStu.begin(); it != mapStu.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	
	return 0;
}
#endif

#if 0
struct CmpByKeyLength {
	bool operator()(const string& k1, const string& k2) {
		return k1.length()  < k2.length();
	}
};

int main() {
	map<string, int, CmpByKeyLength > mapStu;
	mapStu["Liming"] = 90;
	mapStu["Bob"] = 70;
	mapStu["Kate"] = 80;
	
	for (map<string, int>::iterator it = mapStu.begin(); it != mapStu.end(); ++it) {
		cout << it->first << " " << (*it).second << endl;
	}
	
	return 0;
}
#endif

typedef struct tagStuInfo {
	int iID;
	string strName;
	bool operator<(const tagStuInfo& r) const {
		if (iID < r.iID)
			return true;
		if (iID == r.iID)
			return strName.compare(r.strName) < 0;
		
		return false;
	}
} StuInfo;

#if 0
int main() {
	map<StuInfo, int> mapStu;
	
	StuInfo stuinfo;
	stuinfo.iID = 1;
	stuinfo.strName = "stu_one";
	mapStu[stuinfo] = 90;
	
	stuinfo.iID = 2;
	stuinfo.strName = "stu_two";
	mapStu[stuinfo] = 80;
	
	for (map<StuInfo, int>::iterator iter = mapStu.begin(); iter != mapStu.end(); ++iter) {
		cout << iter->first.iID << " " << iter->first.strName << " " << iter->second << endl;
	}
	
	return 0;
}
#endif

// 将map按value排序
typedef pair<string, int> PAIR;
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
}

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
};

int main() {
	map<string, int> name_score_map;
	name_score_map["LiMing"] = 90;
	name_score_map["Lily"] = 70;
	name_score_map["MingHua"] = 80;
	name_score_map.insert(make_pair("Bing", 63));
	name_score_map.insert(make_pair("Alex", 86));
	
	vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
	sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
	// 或者如下
	//sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
	for (int i = 0; i != name_score_vec.size(); ++i) {
		cout << name_score_vec[i].first << " " << name_score_vec[i].second << endl; 
	}
	
	return 0;
}






















