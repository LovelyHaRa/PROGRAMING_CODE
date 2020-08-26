#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache;
vector<int> A;

int max(int a, int b) { return a > b ? a : b; }
int lis(int start)
{
	// �޸������̼�
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1; // A[start]�� �����ϹǷ� �ּڰ��� ������ 1��
	// ���� ��� ó���� �ʿ����.(���� ��ʸ� �����ϸ� �ݺ����� ������� ����)
	for (int i = start + 1; i < n; i++)
		if (A[start] < A[i]) ret = max(ret, lis(i) + 1); // ������ �Ѵٸ� ���� Ž������ �������� ���ȣ��
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		A.resize(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		cache.resize(n, -1);
		int res = 0;
		// ������ġ�� ��� �������־�� �Ѵ�.
		for (int i = 0; i < n; i++)
			res = max(res, lis(i)); // �ִ밪 ����
		cout << res << '\n';
		A.clear();
		cache.clear();
	}
}