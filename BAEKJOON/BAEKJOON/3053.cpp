#include<cstdio>
#define _USE_MATH_DEFINES
#include<cmath>
using namespace std;

int main(void)
{
	double r;
	scanf("%lf", &r);
	/*
	  ��Ŭ���� �����п����� ���� ���� : PI*r*r
	  �ý� �����п����� ���� ����
	   2*r=sqrt(2)*a -> 4*r*r=2*a*a
	   2*r*r=a*a
	   ���簢���� ���� = 2*r*r
	 */
	printf("%.6lf\n", r*r*M_PI);
	printf("%.6lf\n", 2*r*r);
}