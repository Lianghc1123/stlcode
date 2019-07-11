#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> stringmap;

// 将a和b融合为一个unordered_map
stringmap merge(const stringmap& a, const stringmap& b) {
	stringmap temp(a);
	temp.insert(b.begin(), b.end());
	
	return temp;
}

int main() {
	// 1 unordered_map 元素计算与基础便利
	std::unordered_map<std::string, int> mymap = {{"Mars", 3000}, {"Saturn", 60000}, {"Jupiter", 70000}};
	mymap.at("Mars") = 3396;
	mymap.at("Saturn") += 272;
	mymap.at("Jupiter") = mymap.at("Saturn") + 9638;
	
	for (auto& x : mymap) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
	std::cout << "mymap.size() is "  << mymap.size() << std::endl;
	std::cout << std::endl;
	
	// 2 iterator 迭代器便利
	std::unordered_map<std::string, std::string> mymap2 = {{"Australia", "Canberra"}, {"U.S.", "Washington"}, {"France", "Paris"}};
	std::cout << "mymap2 contains: " << std::endl;
	for (auto it = mymap2.begin(); it != mymap2.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << std::endl;
	
	// mymap2 分配的各桶中的元素
	std::cout << "mymap2's buckets contains: " << std::endl;
	for (unsigned int i = 0; i < mymap2.bucket_count(); ++i) {
		std::cout << "bucket #" << i << " contains: ";
		for (auto local_it = mymap2.begin(i); local_it != mymap2.end(i); ++local_it) {
			std::cout << " " << local_it->first << ": " << local_it->second;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	// 3 bucket 桶操作
	std::unordered_map<std::string, std::string> mymap3 = {
		{"us", "United States"},
    {"uk", "United Kingdom"},
    {"fr", "France"},
    {"de", "Germany"}
	};
	
	for (auto& x : mymap3) {
		std::cout << "Element [" << x.first << ": " << x.second << "]";
		std::cout << " is in bucket #" << mymap3.bucket(x.first) << std::endl;
	}
	std::cout << std::endl;
	
	// 4 count 判断元素是否在容器中
	std::unordered_map<std::string, double> mymap4 = {
		{"Burger", 2.99},
		{"Fris", 1.99},
		{"Soda", 1.50},
	};
	
	for (auto& x : {"Burger", "Pizza", "Salad", "Soda"}) {
		if (mymap4.count(x) > 0)
			std::cout << "mymap4 has " << x << std::endl;
		else 
			std::cout << "mymap4 has no " << x << std::endl;
	}
	std::cout << std::endl;
	
	// 5 erase 删除操作
	std::unordered_map<std::string, std::string> mymap5;
	mymap5["U.S."] = "Washington";
	mymap5["U.K."] = "London";
	mymap5["France"] = "Paris";
	mymap5["Russia"] = "Moscow";
	mymap5["China"] = "Beijing";
	mymap5["Germany"] = "Berlin";
	mymap5["Japan"] = "Tokyo";
	
	//mymap5.erase(mymap5.begin());
	//mymap5.erase("France");
	//mymap5.erase(mymap5.find("China"), mymap5.end());
	
	for (auto& x : mymap5) {
		std::cout << x.first << ": " << x.second << std::endl;
	}
	std::cout << std::endl;
	
	// 6 find 搜索操作
	std::unordered_map<std::string, double> mymap6 = {
		{"mom", 5.4},
		{"dad", 6.1},
		{"bro", 5.9},
	};
	std::string input;
	std::cout << "who? ";
	getline(std::cin, input);
	
	std::unordered_map<std::string, double>::const_iterator got = mymap6.find(input);
	if (got == mymap6.end())
		std::cout << "not found" << std::endl;
	else
		std::cout << got->first << " is " << got->second << std::endl;
	std::cout << std::endl;
	
	// 7 insert 插入操作
	std::unordered_map<std::string, double> myrecipe, mypantry = {{"milk", 2.0}, {"flour", 1.5}};
	std::pair<std::string, double> myshopping("baking powder", 0.3);
	
	myrecipe.insert(myshopping);
	myrecipe.insert(std::make_pair<std::string, double>("egg", 6.0));
	myrecipe.insert(mypantry.begin(), mypantry.end());
	myrecipe.insert({{"sugar", 0.8}, {"salt", 0.1}});
	
	std::cout << "myrecipe contains: " << std::endl;
	for (auto& x : myrecipe)
		std::cout << x.first << ": " << x.second << std::endl;
	std::cout << std::endl;
	
	// 8 等号=操作
	stringmap first = {{"AAPL", "Apple"}, {"MSFT", "Microsoft"}};
	stringmap second = {{"GOOG", "Google"}, {"ORCL", "Oracle"}};

	stringmap third = merge(first, second);
	first = third;

	std::cout << "first contains: " << std::endl;
	for (auto& elem : first) 
		std::cout << elem.first << ":" << elem.second << std::endl;
	std::cout << std::endl;
	
	return 0;
}




