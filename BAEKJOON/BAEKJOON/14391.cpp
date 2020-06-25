#include<iostream>
#include<vector>
#include<string>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> paper(n);
	for (int i = 0; i < n; i++)
		cin >> paper[i];
	int res = 0; // �ִ밪
	// ���� ������ 0, ���� ������ 1�� �ϴ� ��Ʈ����ũ�� �ذ�
	// ��ü ����� ���� 2^(m*n)��
	// ��� ����� �� Ž��
	for (int i = 0; i < (1 << (n*m)); i++)
	{
		// ��, ���� ��Ʈ��, �ֻ��� ��Ʈ ��ġ
		int sum = 0, cur = i, msb = (1 << (n*m - 1));
		// ���� ���� ���
		for (int j = 0; j < n; j++)
		{
			int num = 0;
			for (int k = 0; k < m; k++)
			{
				// ���� ������ 0���� ǥ����
				if ((cur&msb) == 0)
				{
					num *= 10;
					num += paper[j][k] - '0';
				} 
				// ������ ����� sum ���� �� ���� ����
				else
				{
					sum += num;
					num = 0;
				}
				// msb ��ĭ �� ����
				msb /= 2;
			}
			// ������ ���� sum ����
			sum += num;
		}
		// ���� ���� ���
		for (int j = 0; j < m; j++)
		{
			// ù ���� j��° ��ġ���� ����
			msb = (1 << ((m*n) - 1 - j));
			int num = 0;
			for (int k = 0; k < n; k++)
			{
				// ���� ������ 1�� ǥ����
				if (cur&msb)
				{
					num *= 10;
					num += paper[k][j] - '0'; // ���� Ž��
				}
				// ������ ����� sum ���� �� ���� ����
				else
				{
					sum += num;
					num = 0;
				}
				// m����ŭ �ǳʶٱ�(���η� Ž��)
				msb /= (1 << m);
			}
			// ������ ���� sum ����
			sum += num;
		}
		// �ִ� ����
		res = max(res, sum);
	}
	cout << res << '\n';
}