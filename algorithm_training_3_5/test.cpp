
//C++ STL�ٳ�---2024/3/5
// 
// 
//��һ�����ű�����ǰ�񲹡�������

#include<iostream>   //C++
#include<string>  
#include<vector>
#include<algorithm>
//#include<queue>
//#include<stack>
//#include<set>
//#include<map>
//#include<bitset>

#include<cstring> //C����
#include<ctime>


using namespace std;
int a = clock();
int main()
{
	char str[1000];
	memset(str, 0x3f3f3f, sizeof(str));

	vector<int> arr(100);
	vector<int> list1;
	vector<int> ::iterator p = arr.begin();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int j;
		cin >> j;
		list1.push_back(j);
	}
	
	for (char* p = str; *p; p++)
	{

	}

	for (vector<int> ::iterator p = arr.begin(); p != arr.end(); p++)  //����������ʾ��Ԫ���Լ�βԪ�صĵ�ַ--�൱��ָ��
	{

	}

	int len = list1.size(); //������

	string str1 = "dsajfd";
	string str2;
	cin >> str2;
	str1.length(); str1.size();
	str1.insert(0, "�����㿪����");
	printf("%s",str2.c_str());    // ����C���Ե��׵�ַ
	str1.append(str2); // ƴ�� str1str2
	cout << str1;
	str1.compare(str2);


	//algorithm

	vector<int> str4{ 12,21,21,21,21,21,21,212,1,21,2123,21,14,34,324,32,423,45432,543,55,654,67,67,567,67 };

	int arr3[] = { 3,2,5,8,5,3,2,56,8 };
	int n = 9;
	sort(arr3, arr3 + n);
	sort(str4.begin(), str4.end());



	return 0;
}


//int b = clock() - a;
//cout << b << endl;


//int main()
//{
//	string a , b;
//	cin >> a;
//	cout <<a << endl << endl;
//	return 0;
//}

