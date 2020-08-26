#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>cache; // �޸������̼� ĳ��(y,x���� �� �Ʒ������� �κ� ����� ��)
int n;

int max(int a, int b) { return a > b ? a : b; }

int path(const vector<vector<int>>& triangle, int y, int x)
{
	// ���� ����: �ﰢ�� �عٴڿ� �������� ��
	if (y == n - 1) return triangle[y][x];
	// �޸������̼�
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	// �κ� ����� �ִ밪�� ���� ��ǥ�� ���� ���Ѵ�.
	return ret = max(path(triangle, y + 1, x), path(triangle, y + 1, x + 1)) + triangle[y][x];
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		vector<vector<int>> triangle(n, vector<int>(n));
		cache.resize(n, vector<int>(n, -1)); // ĳ�� �ʱ�ȭ
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];
		}
		cout << path(triangle, 0, 0) << '\n';
		cache.clear();
	}
}