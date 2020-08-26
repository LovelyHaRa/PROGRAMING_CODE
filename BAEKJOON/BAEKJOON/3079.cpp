#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<long long> pass(n);
	long long low = 0, high = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> pass[i];
		// 1. �ִ���� ����(���� ���� �ɸ��� �ð� * ��� ��)
		high = max(pass[i], high);
	}
	high *= m;
	long long res = high;
	// 2. �̺� Ž��
	while (low <= high)
	{
		// mid = �ð�
		long long mid = (low + high) / 2;
		long long sum = 0;
		// 3. �ѻ���� �ɻ��� ����� = (��ü�ð�/�Ա�����ڽð�) �� ����
		for (int i = 0; i < n; i++)
			sum += mid / pass[i];
		// 4. �������� ���ų� ũ�� �ּڰ� ���� �� �������� ���̱�
		if (sum >= m)
		{
			res = min(res, mid);
			high = mid - 1;
		}
		// 5. �׷��� ������ �������� ���̱�
		else
			low = mid + 1;		
	}
	cout << res << '\n';
}