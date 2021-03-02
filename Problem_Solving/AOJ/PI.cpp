#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int INF = 1987654321;
string N; // �Է� ���ڿ�
vector<int> cache; // �޸������̼� ĳ��

int min(int a, int b) { return a < b ? a : b; }
int abs(int a, int b) { return a > b ? a - b : b - a; }

int classify(int a, int b)
{
	// �κ� ���� ����
	string M = N.substr(a, b - a + 1);
	// ��� ���ڰ� ���� ��: 1
	if (M == string(M.size(), M[0])) return 1;
	// �������� Ȯ��
	bool progressive = true;
	for (int i = 1; i < M.size() - 1; i++)
	{
		// �������� ����
		if (M[i + 1] - M[i] != M[1] - M[0])
		{
			progressive = false;
			break;
		}
	}
	// ������ 1�� ��������: 2
	if (progressive && abs(M[1] - M[0]) == 1) return 2;
	// �ݺ� ���� Ȯ��
	int alternating = true;
	for (int i = 2; i < M.size(); i++)
	{
		// �ΰ��� ���ڰ� ������ ���鼭 ��Ÿ������ Ȯ��
		if (M[i] != M[i % 2])
		{
			alternating = false;
			break;
		}
	}
	// ������ ���鼭 ��Ÿ����: 4
	if (alternating) return 4;
	// ���������̸�: 5
	if (progressive) return 5;
	// �� ���� ���: 10
	return 10;
}

int memorize(int begin)
{
	// ���� ���: begin�� ���� �������� ��
	if (begin == N.size()) return 0;
	// �޸������̼�
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF; // �ּڰ� ������ ���� �ʱ�ȭ
	// 3~5���� ���� ����
	for (int i = 3; i <= 5; i++)
	{
		// (i���� ���� ������ ������ ���� ������ + ���� i�� ������ ���̵�)�� �� �ּҰ� ����
		if (begin + i <= N.size())
			ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> N;
		cache.resize(N.size() + 1, -1);
		cout << memorize(0) << '\n';
		cache.clear();
	}
}