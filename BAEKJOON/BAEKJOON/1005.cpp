#include<iostream> // ����� ���
#include<vector> // �迭 ���� ���
#include<queue> // �ڷᱸ�� ť ���
#include<algorithm> //max ���

using namespace std;

int main(void)
{
	int T; //�׽�Ʈ���̽�
	cin >> T;
	while (T > 0)
	{
		int n, k; // ����, ��������
		cin >> n >> k;
		vector<vector<int>> graph; // ����׷���
		queue<int> que; // ���� ť
		vector<int> count; // ���� ���� ����
		vector<int> d; // �Ǽ����
		vector<int> res; // �ش� ���� �ִ���
		graph.resize(n + 1);
		count.resize(n + 1);
		d.resize(n + 1);
		res.resize(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			count[y]++;
		}
		int w; // Ư�� �ǹ�
		cin >> w;
		// �������� �̿�
		// ���� ���� ������ 0�� ������ ť�� �־� �ʱ� ������
		for (int i = 1; i <= n; i++)
		{
			if (!count[i])
				que.push(i);
		}
		while (count[w] != 0)
		{
			// ť���� ������ ������.
			int v = que.front();
			que.pop();
			// ������ �ִ� �Ǽ������ �����Ѵ�.
			for (int next : graph[v])
			{
				res[next] = max(res[next], res[v] + d[v]);
				if (--count[next] == 0) que.push(next);
			}
		}
		cout << res[w] + d[w] << endl; // Ư���ǹ��� �Ǽ������ �߰��Ͽ� ����Ѵ�.
		T--;
	}
}