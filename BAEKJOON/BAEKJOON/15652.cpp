// ������ DFS ����
// ���� ���ϱ�4

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> s; // ��� ���� ����
// �湮���� üũ�� ���ϸ鼭 �񳻸����� ����

void func(int x, int idx)
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
		s.push_back(i); // ������ ����ֱ�
		func(x + 1, i); // ���� ����, �ε����� ������Ű�鼭 �������� ������ ���
		s.pop_back(); // �������� ����
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