#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
const int M = 1000 * 1000 + 1;
int main(void)
{
	int n;
	cin >> n;
	// rgb��, ĳ�ù迭
	vector<vector<int>> rgb(n, vector<int>(3)), cache(n, vector<int>(3));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];
	int res = M; // �ּڰ� ���ϴ� ����
	// �������� ��� ��츦 Ž��
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// ù��° ���� �ش� ������ ���� ��쿡�� ĳ�ÿ� ����
			if (i == j)
				cache[0][j] = rgb[0][j];
			// �׷��� ���� ���� ���� ū �� ����
			else
				cache[0][j] = M;
		}
		// DP Ž��
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < 3; k++)
				cache[j][k] = min(cache[j - 1][(k + 1) % 3], cache[j - 1][(k + 2) % 3]) + rgb[j][k];
		}
		// ù��° ���� �Ȱ��� ������ ���� �ּڰ� ������ �Ұ�
		for (int j = 0; j < 3; j++)
		{
			// �ּڰ� ������ �Ұ����� ���
			if (i == j) continue;
			// �׷��� ���� ���
			res = min(res, cache[n - 1][j]);
		}
	}
	cout << res << '\n';
}