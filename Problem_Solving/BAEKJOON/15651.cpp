// ������ DFS ����
// ���� ���ϱ�3

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> s; // ��� ���� ����
// �湮���� üũ ���ʿ�

void func(int x)
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

	for (int i = 1; i <= N; i++)
	{
		s.push_back(i); // ������ ����ֱ�
		func(x + 1); // ���� ����
		s.pop_back(); // �������� ����
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	func(0); // ���� 0���� ����
}