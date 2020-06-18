#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> t, p;
int res = 0; // �ִ밪

int max(int a, int b) { return a > b ? a : b; }

// ���������� ���ݱ����� ����� �־����� ��
// ���������� �������� ��� ������ ��� ��츦 Ž���Ѵ�
void leave(int start, int sum)
{
	// ���� ��� ������ �������� �����Ѵ�
	int next = start + t[start] - 1;
	// ���� ���: ���� ������ n �̻��� ���
	if (next >= n)
	{
		// ������ ���� ���ϴ� ���
		if (next > n)
			res = max(res, sum - p[start]); // ���� �� ���
		// ������ ���� �� �� �ִ� ���
		else
			res = max(res, sum);
		return;
	}
	// ���� ��� ������ �������� Ž���Ѵ�
	for (int i = next + 1; i <= n; i++)
		leave(i, sum + p[i]);
}

int main(void)
{
	cin >> n;
	t.resize(n + 1);
	p.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	for (int i = 1; i <= n; i++)
		leave(i, p[i]);
	cout << res << '\n';
}