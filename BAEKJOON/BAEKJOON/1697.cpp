#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<bool> check(100001);
	int sec = 0;
	// �ʱ� ť ����
	q.push(n);
	check[n] = true;
	// BFS Ž��
	while (!q.empty())
	{
		int curSize = q.size(); // �ش� �ð��� �̵��� �� �ִ� ��ġ�� ��
		// ��ġ ����ŭ �ݺ�
		while (curSize-- > 0)
		{
			int x = q.front();
			q.pop();
			// ������ ��ġ�� ��� ����
			if (x == k)
			{
				cout << sec << '\n';
				return 0;
			}
			// x-1 �̵�
			if (x - 1 >= 0 && !check[x - 1])
			{
				check[x - 1] = true;
				q.push(x - 1);
			}
			// x+1 �̵�
			if (x + 1 <= 100000 && !check[x + 1])
			{
				check[x + 1] = true;
				q.push(x + 1);
			}
			// x*2�̵�
			if (x * 2 <= 100000 && !check[x * 2])
			{
				check[x * 2] = true;
				q.push(x * 2);
			}
		}
		sec++; // �ð� ����
	}
}