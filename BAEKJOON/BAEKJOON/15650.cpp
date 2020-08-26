// ������ DFS ����
// ���� ���ϱ�2

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> s; // ��� ���� ����
int f[10]; // �湮 ���� üũ

void func(int x, int idx) // �޶��� ���� �ø������� ����ϱ� ���� �ε��� �߰�
{
	// ���� ������ŭ�� ���̿� �����ϸ�
	if (x == M)
	{
		// ������ ���� ���
		for (int i = 0; i < s.size(); i++)
			cout << s[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		if (f[i]) continue; // �̹� üũ �Ǿ��ٸ� ���� �Ұ���
		f[i] = 1; // ���� üũ
		s.push_back(i); // ������ ����ֱ�
		func(x + 1, i + 1); // ���� ����, �ε����� ������Ű�鼭 �������� ������ ���
		s.pop_back(); // �������� ����
		f[i] = 0;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	func(0, 1); // ���� 0���� ����
}