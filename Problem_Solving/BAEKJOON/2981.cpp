#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/* �ִ����� (��Ŭ���� ȣ����) */
int GCD(int a, int b)
{
	if (a < b) return GCD(a, b%a);
	if (b == 0) return a;
	GCD(b, a%b);
}

int main(void)
{
	int n, i;
	int a[100];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	/*
	  1. �Է� ������ ����
	  2. i : 1 ~ n-1 ����
	     a[i]-a[i-1], a[i+1]-a[i] �� �ִ� ������� ���Ѵ�.
	  3. ���������� �ִ� ������� �ִ��� ���´�.
	  4. 3���� ���� ���� ����� ��� ����Ѵ�.
	*/
	sort(a, a + n);
	int gcd = a[1] - a[0];
	for (i = 2; i < n; i++)
		gcd = GCD(gcd, a[i] - a[i - 1]);
	vector<int> res;
	res.push_back(gcd);
	for (i = 2; i*i <= gcd; i++)
	{
		if (!(gcd%i))
		{
			if (i == gcd / i)
				res.push_back(i);
			else
			{
				res.push_back(i);
				res.push_back(gcd / i);
			}
		}
	}
	sort(res.begin(), res.end());
	for (i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}