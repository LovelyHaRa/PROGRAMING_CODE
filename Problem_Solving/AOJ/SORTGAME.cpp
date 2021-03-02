#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

map<vector<int>, int> toSort; // �迭�� ��ȯȽ���� ����
// ��� ������ ���� toSort[]�� �̸� ���
void bfs(int n)
{
	// ���� ����
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	// bfs�� ���� ť ����
	queue<vector<int>> q;
	// ������ ť�� ����
	toSort[perm] = 0;
	q.push(perm);
	// bfs Ž��
	while (!q.empty())
	{
		// ť���� ������
		vector<int> here = q.front();
		q.pop();
		// ��� �ҷ�����
		int cost = toSort[here];
		// ������ ��� ������ ������ ����
		for(int i=0;i<n;i++)
			for (int j = i + 2; j <= n; j++)
			{
				// ������
				reverse(here.begin() + i, here.begin() + j);
				// Ž������ Ȯ��
				if (toSort.count(here) == 0)
				{
					toSort[here] = cost + 1;
					q.push(here);
				}
				// ���� ����
				reverse(here.begin() + i, here.begin() + j);
			}
	}
}

int solve(const vector<int>& perm)
{
	int n = perm.size();
	// perm�� [0~n-1]�� ������ ��ȯ
	vector<int> fixed(n);
	for (int i = 0; i < n; i++)
	{
		int smaller = 0;
		for (int j = 0; j < n; j++)
			if (perm[j] < perm[i])
				smaller++;
		fixed[i] = smaller;
	}
	// �ش� �迭�� ��� ��ȯ
	return toSort[fixed];
}

int main(void)
{
	// ��� ��쿡 ���� �̸� ���
	for (int i = 1; i <= 8; i++)
		bfs(i);
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> perm(n);
		for (int i = 0; i < n; i++) cin >> perm[i];		
		cout << solve(perm) << '\n';
	}
}