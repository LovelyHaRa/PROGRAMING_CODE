#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

vector<vector<double>> dist;
int n;

// ���� ����: �Ÿ� d������ �������� ���� ���� �� ��� ������ �� �ִ��� ���� ��ȯ
bool decision(double d)
{
	// BFS Ž��
	vector<bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0; // ���� ����
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		seen++;
		for (int there = 0; there < n; there++)
		{
			// �Ÿ��� d �����̸� ť�� �߰�
			if (!visited[there] && dist[here][there] <= d)
			{
				visited[there] = true;
				q.push(there);
			}
		}
	}
	// ��� ������ ���� �Ǿ����� true
	return seen == n;
}

// ����ȭ ����: �Ÿ��� ������� �̺й� Ž��
double optimize()
{
	double lo = 0, hi = 1416; // �ִ� �Ÿ�+1
	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2;
		// �ش� �Ÿ����� ��� ������ ���� �����ϸ�
		if (decision(mid))
			hi = mid; // �� ���� ���� ã�´�
		// ���� �Ұ��� �ϸ�
		else
			lo = mid; // �� ū ���� ã�´�
	}
	return hi;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		vector<pair<double, double>> g(n); // ��ǥ�� ����
		for (int i = 0; i < n; i++)
		{
			double x, y;
			cin >> x >> y;
			g[i] = make_pair(x, y);
		}
		dist.resize(n, vector<double>(n));
		// �Ÿ� ����
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				// �Ÿ� ���ϱ�
				double d = sqrt(pow(g[i].first - g[j].first, 2) + pow(g[i].second - g[j].second, 2));
				// ������ �׷��� ����
				dist[i][j] = d;
				dist[j][i] = d;
			}
		}
		// �Ҽ��� 3��° �ڸ����� �ݿø� �Ͽ� ���
		cout.precision(2);
		cout << fixed << optimize() << '\n';
		dist.clear();
	}
}