// ������ DFS ����
// ���� ���ϱ�

#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> s; // ��� ���� ����
int f[10]; // �湮 ���� üũ

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
		if (f[i]) continue; // �̹� üũ �Ǿ��ٸ� ���� �Ұ���
		f[i] = 1; // ���� üũ
		s.push_back(i); // ������ ����ֱ�
		func(x + 1); // ���� ����
		s.pop_back(); // �������� ����
		f[i] = 0; // üũ �ʱ�ȭ
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