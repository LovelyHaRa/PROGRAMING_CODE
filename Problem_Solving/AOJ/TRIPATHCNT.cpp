#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> triangle, pathCache, countCache;

int max(int a, int b) { return a > b ? a : b; }

// �ִ� �� ��θ� ���Ѵ�.
int path(int y, int x)
{
	if (y == n - 1) return triangle[y][x]; 
	int& ret = pathCache[y][x];
	if (ret != -1) return ret;
	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int count(int y, int x)
{
	// ���� ���: y�� ������ �������� ��
	if (y == n - 1) return 1;
	// �޸������̼�
	int& ret = countCache[y][x];
	if (ret != -1) return ret;
	ret = 0; // ī���� �ʱ�ȭ
	// ��ȭ�� ����
	if (path(y + 1, x) >= path(y + 1, x + 1)) ret += count(y + 1, x);
	if (path(y + 1, x) <= path(y + 1, x + 1)) ret += count(y + 1, x + 1);
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		triangle.resize(n, vector<int>(n));
		pathCache.resize(n, vector<int>(n, -1));
		countCache.resize(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];
		cout << count(0, 0) << '\n';
		triangle.clear();
		pathCache.clear();
		countCache.clear();
	}
}