#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
	int ID;
	char name[20];
	double mathscore;
	double pscore;
	double englishscore;
};
typedef struct Student Student;
int main()
{
	int n;
	scanf_s("%d", &n);
	Student s1 = { 1001,"Zhang",100,90,80 };
	//Student si;
	//һ��ʼ�������ˣ����������ֲ�д��̬����Ҳ���ԡ�
	Student* p = (Student*)malloc(n * sizeof(Student));
	double*sum = (double*)malloc(n*sizeof(double));
	if (p == NULL || sum == NULL) exit(1);
	for (int i = 0; i < n; i++)
	{
		//scanf_s("%d %s %lf %lf %lf", &si.ID, si.name, &si.mathscore, &si.pscore, &si.englishscore);
		scanf_s("%d %s %lf %lf %lf", &p[i].ID, p[i].name,20, &p[i].mathscore, &p[i].pscore, &p[i].englishscore);
		//ע�⣡������VS2022��ʹ�õ�scanf_s��fscanf_s�ڶ����ַ����Ĺ����ж������ַ���������볤����һunsigned int ������
		// ��΢����Ϊԭ�ȵ�scanf��fscanf������ȫ����������д�����������
		//��������鷳����VS2022���뻷���Ŀ�ͷ����#define _CRT_SECURE_NO_WARNINGS 1�����������ʹ��scanf��fscanf��䣡
		sum[i] = (p[i].mathscore + p[i].pscore + p[i].englishscore) / 3;
	}
	for (int j = 0; j < n; j++)
	{
		//int m = 0;
		//m = j + 1;
		//printf("The average score of the %dth student is %d.\n",m, sum[j]);
		printf("The average score of the %dth student is %lf.\n", j + 1, sum[j]);//sum������double���͵�������lf
	}
	free(p);
	free(sum);
	return 0;
}