#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int k, n;
	cin >> k >> n;
	vector<long long> cable(k);
	long long left = 1, right = 0;
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> cable[i];
		right = right < cable[i] ? cable[i] : right; // �ʱ� ������ �� ���ϱ�
	}
	// �ڸ� ���� �������� �̺� Ž��
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		// ���� �ڸ���
		for (int i = 0; i < k; i++)
			cnt += cable[i] / mid;
		// n�� �̻��̸�
		if (cnt >= n)
		{
			res = res < mid ? mid : res; // �ڸ� �� �ִ� �ִ� ���� ����
			left = mid + 1; // ���� ����
		}
		else right = mid - 1; // ������ ����
	}
	cout << res << '\n';
}