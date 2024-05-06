#include<bits/stdc++.h>
using namespace std;
bool Is(long long num)
{
	if (num <= 1)
		return false;
	for (long long i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
long long lcm(long a, long b)
{	
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
long long mcm(long a, long b)
{
	return a * b / lcm(a, b);
}
int main()
{
	long long num = 0,n; 
	int flag = 1,final = 1;
	vector <long long> arr,arrab,son,none;
	cin >> num;
	n = num;
	if (Is(num))
	{
		printf("<1,%lld>\n���в���\n", num);
		return 0;
	}
	for (long long i = 1; i <= num; i++)
		if (!(num % i)) son.push_back(i);
	for (;!Is(num);)
	{
		for (long long i = 2;; i++)
		{
			if (!Is(i)) continue;
			else if(!(num%i))
			{
				num /= i;
				arr.push_back(i);
				if (flag)
				{
					arrab.push_back(i);
					flag = 0;
				}
				else if (arrab[arrab.size()-1] != i) arrab.push_back(i);
				break;
			}
		}
	}
	arr.push_back(num);
	if (arrab[arrab.size() - 1] != num) arrab.push_back(num);

	printf("\nƫ���ϵ���£�\n\n");
	for (vector<long long>::iterator p = son.begin(); p != son.end(); p++)
	{
		int flag2 = 0;
		for (vector<long long>::iterator j = p; j != son.end(); j++)
		{
			if ((find(arrab.begin(),arrab.end(),(*j)/(*p)) != arrab.end()) && (!((*j) % (*p))) && (j != p))
				printf("<%lld,%lld>\t", *p,*j);
			else if ((lcm(*p, *j) == 1) && (mcm(*p, *j) == n))
			{
				flag2 = 1;
			}
		}
		if (!flag2)
		{
			none.push_back(*p);
			final = 0;
			if(*p!=n)
				printf("-#-");
		}
		printf("\n");
	}
	printf("\n\n");

	if (!final)
	{
		printf("�����в���");
		for (vector<long long>::iterator p = none.begin(); p + 1 != none.end(); p++)
		{
			printf("%lld", *p);
			if (!(p + 2 == none.end()))
				printf("��");
		}
		printf("û�в�Ԫ\n");
		printf("\"-#-\"����û�в�Ԫ��Ԫ��������\n");
	}
	else
	{
		printf("���в���\n");
	}
	return 0;
}