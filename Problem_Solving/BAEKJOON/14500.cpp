#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> p(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	}
	int max = 0;
	int sum = 0;
	// �����ϰ� Ǯ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// -
			if (j + 3 < m)
			{
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i][j + 3];
				max = max < sum ? sum : max;
				sum = 0;
			}
			// l
			if (i + 3 < n)
			{
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 3][j];
				max = max < sum ? sum : max;
				sum = 0;
			}
			// ��
			if (i + 1 < n&&j + 1 < m)
			{
				sum += p[i][j] + p[i][j + 1] + p[i + 1][j] + p[i + 1][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
			}
			if (i + 2 < n&&j + 1 < m)
			{
				// L
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 2][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ����
				sum += p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 1][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j] + p[i + 2][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ����
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 1][j] + p[i + 2][j];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j + 1] + p[i][j];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j + 1] + p[i + 1][j + 1] + p[i + 2][j + 1] + p[i + 1][j];
				max = max < sum ? sum : max;
				sum = 0;
			}
			if (i+1<n && j+2<m)
			{
				// ��
				sum += p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ��_
				sum += p[i][j] + p[i][j + 1] + p[i + 1][j + 1] + p[i + 1][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
				// ����
				sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ����
				sum += p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2] + p[i][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// _��
				sum += p[i + 1][j] + p[i + 1][j + 1] + p[i][j + 1] + p[i][j + 2];
				max = max < sum ? sum : max;
				sum = 0;
				// ��
				sum += p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2] + p[i][j + 1];
				max = max < sum ? sum : max;
				sum = 0;
			}
			sum = 0;
		}
	}
	cout << max;
}