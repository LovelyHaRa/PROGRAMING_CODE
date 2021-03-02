#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector <vector<int>> bino(201, vector<int>(201)); // ���װ�� ����
const int M = 1000000000 + 100; // �����÷� ���� 
int min(int a, int b) { return a < b ? a : b; }

// ���װ�� ���ϱ�
void calcBino()
{
	for (int i = 0; i <= 200; i++)
	{
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}

// O(nm)
int skip;
void generate(int n, int m, string s)
{
	if (skip < 0) return; // ���ڿ��� ����� ���̹Ƿ� �ٷ� ����
	// �������: m==n==0
	if (n == 0 && m == 0)
	{
		if (skip == 0)	cout << s << '\n'; // k��°�̸� ���
		skip--;
		return;
	}
	// k�� (n+m,n)���� ũ�� �ش� ���װ����ŭ ����
	if (bino[n + m][n] <= skip)
	{
		skip -= bino[n + m][n];
		return;
	}
	// �𽺺�ȣ ���̱�
	if (n > 0) generate(n - 1, m, s + "-");
	if (m > 0) generate(n, m - 1, s + "o");
}

// O(n+m)
string kth(int n, int m, int skip)
{
	if (n == 0) return string(m, 'o'); // n�� 0�̸� �������� o�ϼ� �ۿ� ����
	// ������ ���� �����ϱ�
	if (n > 0 && skip < bino[n + m - 1][n - 1])
		return "-" + kth(n - 1, m, skip);
	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main(void)
{
	calcBino();
	int c;
	cin >> c;
	while (c--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		//skip = k - 1;
		//generate(n, m, "");
		cout << kth(n, m, k - 1)<<'\n';
	}
}