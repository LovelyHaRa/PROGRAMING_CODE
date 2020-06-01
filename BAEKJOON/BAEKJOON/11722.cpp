#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;
vector<int> A;

int max(int a, int b) { return a > b ? a : b; }

// ���������� start�� �� ���� �κ� ���� ���� ���̸� ��ȯ
int lds(int start)
{
	// �޸������̼�
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1; // ���̴� ������ 1���� ����
	for (int i = start + 1; i < n; i++)
		// ���������� -1�̰ų� ������ �������� ���
		if (start == -1 || A[start] > A[i])
			ret = max(ret, lds(i) + 1); // ������ �ִ밪 ����
	return ret; // ���� ��ȯ
}

int main(void)
{
	cin >> n;
	A.resize(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cache.resize(n + 1, -1);
	cout << lds(-1) - 1 << '\n'; // -1 ���� ���������Ƿ� -1 ���ҵ� ���� ���
}