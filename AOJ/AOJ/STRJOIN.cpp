#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int concat(const vector<int>& lengths)
{
	priority_queue<int, vector<int>, greater<int>> pq; // �������� �켱����ť ���
	// ť�� ������ ����
	for (int i = 0; i < lengths.size(); i++)
		pq.push(lengths[i]);
	int ret = 0;
	while (pq.size() > 1)
	{
		// �ּҰ� �ΰ� ������
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();
		// ���ؼ� �ٽ� �ֱ�
		pq.push(min1 + min2);
		// ���� �� ����
		ret += min1 + min2;
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> lengths(n);
		for (int i = 0; i < n; i++)
			cin >> lengths[i];
		cout << concat(lengths) << '\n';
	}
}