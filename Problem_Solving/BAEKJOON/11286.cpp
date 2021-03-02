#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	// ����, �������� ������ ������ pq ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	while (n--)
	{
		int x;
		cin >> x;
		// 0�� ��
		if (!x)
		{
			// ť���� ����
			cout << (!pq.empty() ? pq.top().second : x) << '\n';
			if (!pq.empty()) pq.pop();
		}
		// 0�� �ƴ� ��
		else
			pq.push({ abs(x),x }); // ť�� ����
	}
}