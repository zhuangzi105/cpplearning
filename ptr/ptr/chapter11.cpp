
#include "stdafx.h"

#include <fstream>

#include <iostream>
#include <streambuf>
#include <string>
#include <iomanip>
#include <map>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;
class Dog {
public:
	Dog() :age(0), weight(7)
	{
	};
	Dog(int a,double w) :age(a), weight(w)
	{
	};
	~Dog() {};
	void load()
	{
		fstream in("dog.txt", ios::out);
		boost::archive::text_iarchive ia(in);
		ia >> *this;
		in.close();
		//in.read((char*)&age, sizeof(age));
		//in.read((char*)&weight, sizeof(weight));
	}
	void save()
	{
		fstream out("dog.txt", ios::out);
		boost::archive::text_oarchive oa(out);
		oa << *this;
		out.close();
		//out.write((char*)&age,sizeof(age));
	//	out << '\t';
		//out.write((char*)&weight, sizeof(weight));
	}
	int GetAge() const
	{
		return age;
	}
	double GetWeight() const
	{
		return weight;
	}
private:

	friend class boost::serialization::access;

	// 如果类Archive 是一个输出存档，则操作符& 被定义为<<.  同样，如果类Archive

	// 是一个输入存档，则操作符& 被定义为>>.

	template<class Archive>

	void serialize(Archive & ar, const unsigned int version)

	{

		ar & age;

		ar & weight;

	}
	int age;
	double weight;
};
ostream& operator<< (ostream&out, const Dog& dog)
{
	out <<setw(5)<< dog.GetAge() << '\t' << dog.GetWeight() << endl;
	return out;
};
int main()
{
	//11-3 建立文本文件
	ofstream file("test1.txt");
	file << "已成功写入文件！";//  已成功写入文件" << endl;
	file.close();

	//11-4显示文本文件
	ifstream ofile("test1.txt");

	ofile.seekg(0, ios::end);
	size_t length = ofile.tellg();


	ofile.seekg(0, ios::beg);
	char * buffer = new char[length]();
	string str;
	ofile.read(buffer, length);
	str.assign(buffer, length);
	cout.write(buffer, length) << endl;
	ofile.close();
	delete[] buffer;

	//11-5追加并显示文本文件
	fstream file2("test1.txt", ios::app);
	file2 << "已成功添加字符！";
	file2.close();

	ofile.open("test1.txt");
	ofile.seekg(0, ios::end);
	length = ofile.tellg();
	ofile.seekg(0, ios::beg);
	buffer = new char[length]();

	ofile.read(buffer, length);
	str.assign(buffer, length);
	cout.write(buffer, length) << endl;
	ofile.close();
	delete[] buffer;

	//11-6 手动序列化
	Dog dog1(10, 2.3);
	
	dog1.save();
	

	Dog dog2;
	dog2.load();
	cout<<dog1<<dog2;

	//11-8 用户输入十进制，输出十进制，八进制，16进制
	//cout << "请输入一个整数：";
	//int in;
	//cin >> in;
	////cout << setiosflags(ios_base::dec) << in << endl;
	//cout.setf(ios::showbase);
	//cout.setf(ios_base::oct, ios_base::basefield);
	//cout << in << endl;
	//cout << resetiosflags(ios_base::oct);
	//cout << setiosflags(ios_base::hex) << in << endl;

	//11.2.4test
	//非二进制write,windows下会在ascii码10(\n)前追加13(\r)，凑成\r\n
	ofstream file24("test24.txt");//,ios::binary);
	int array[3] = { 99,10,13 };
	file24.write(reinterpret_cast<char *>(array), sizeof(array));
	file24.close();

	//11-9
	ifstream file9("11-9.txt");//,ios::binary);
	ofstream ofile9("11-9out.txt");
	buffer = new char[100]();
	int indexrow = 1;
	while (file9.getline(buffer, 100))
	{
		ofile9 << indexrow << '\t'<<buffer<<endl;	
		indexrow++;
	}
	file9.close();
	ofile9.close();

	delete [] buffer;
	
	
	//11-10
	wifstream file10("11-9.txt");
	locale loc(".936");
	file10.imbue(loc);

	wofstream ofile10("11-10out.txt");
	ofile10.imbue(loc);
	map<wchar_t, int> count;
	wchar_t bu;
	while (file10.get(bu))
	{
		++count[bu];
	}
	
	for each (auto it in count)
	{


		ofile10 << L"字符:"<< it.first <<L"个数:"<< it.second << endl;
	}

 }