// ť ����
#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> q;
	int n;
	cin >> n;
	// 1. 1���� n ���� ť�� ����
	// 2. ť���� ����
	// 3. ť�� ��������� ������ �� ���
	// 4. �ƴϸ� ť���� ����
	// 5. 4���� ���� �� �ٽ� ť�� ����.
	// 6. 2~5 �ݺ�, 3�� ���ǿ��� Ż��
	// 1
	int k = 1;
	while (k <= n)
		q.push(k++);
	int res;
	// 6
	while (1)
	{
		// 2
		res = q.front();
		q.pop();
		// 3
		if (q.empty())
			break;
		// 4
		int t = q.front();
		q.pop();
		// 5
		q.push(t);
	}
	cout << res << '\n';
}