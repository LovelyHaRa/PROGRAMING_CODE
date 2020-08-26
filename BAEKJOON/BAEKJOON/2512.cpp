#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// �̺�Ž�� ����
int main(void)
{
	int n, m;
	cin >> n;
	vector<int> budget(n);
	int low = 0, high = 0; // �̺�Ž���� �� ����
	// 1. ���� �� �ִ밪�� high�� ����
	for (int i = 0; i < n; i++)
	{
		cin >> budget[i];
		high = max(high, budget[i]);
	}
	cin >> m;
	int res = 0;
	// 2. �̺� Ž��
	while (low <= high)
	{
		// 3. �߰��� ����
		int mid = (low + high) / 2;
		// 4. ���� �հ� ����
		int sum = 0;
		for (int i = 0; i < n; i++)
			// �߰���(���� �й�� ����)�� ���� ���� �� �ּҰ� ����
			sum += min(budget[i], mid);
		// 5. �հ谡 �� ���꺸�� ������ ���ʰ� ���� �� �߰��� ����
		if (sum <= m)
		{
			res = max(mid, res); // �߰����� �ִ밪�� �����ϱ� ����
			low = mid + 1;
		}
		// 6. �� ������ �ʰ��ϸ� ������ �� ����
		else
			high = mid - 1;
	}
	cout << res << '\n';
}