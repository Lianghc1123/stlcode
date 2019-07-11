#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class String {
public:
	String(const char* str = NULL);
	String(const String& another);
	~String();
	String& operator=(const String& another);
	String& operator+(const String& another);
	bool operator==(const String& another);
	int getLength();
	friend ostream& operator<<(ostream& out, const String& str);

private:
	char* m_data;
};

String::String(const char* str) {
	if (str == NULL) {
		m_data = new char[1];
		*m_data = '\0';
	} else {
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
	}
}

String::String(const String& another) {
	if (!another.m_data) {
		m_data = 0;
	}
	m_data = new char[strlen(another.m_data) + 1];
	strcpy(m_data, another.m_data);
}

String::~String() {
	if (m_data) {
		delete [] m_data;
		m_data = 0;
	}
}

String& String::operator=(const String& another) {
	if (this != &another) {
		delete [] m_data;
		if (!another.m_data) {
			m_data = 0;
		} else {
			m_data = new char[strlen(another.m_data) + 1];
			strcpy(m_data, another.m_data);
		}
	}
	
	return *this;
}

String& String::operator+(const String& another) {
	String newString;
	if (!another.m_data) {
		newString = *this;
	} else if (!m_data) {
		newString = another;
	} else {
		newString.m_data = new char[strlen(m_data) + strlen(another.m_data) + 1];
		strcpy(newString.m_data, m_data);
		strcat(newString.m_data, another.m_data);
	}
	*this = newString;
	
	return *this;
}

bool String::operator==(const String& another) {
	if (strlen(m_data) != strlen(another.m_data)) {
		return false;
	} else {
		return strcmp(m_data, another.m_data) ? false : true;
	}
}

int String::getLength() {
	return strlen(m_data);
}

ostream& operator<<(ostream& out, const String& str) {
	cout << str.m_data;
	return out;
}

int main(void) {
	String str1("lianghongchen");
	String str2(", lakers");
	
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	
	String str3 = str1 + str2;
	cout << "str3: " << str3 << endl;
	
	cout << "str1 length: " << str1.getLength() << endl;
	cout << "str2 length: " << str2.getLength() << endl;
	cout << "str3 length: " << str3.getLength() << endl;
	
	return 0;
}