#include<iostream>
#include<vector>

using namespace std;

vector<bool> num(2000001); // �κ� �� üũ
vector<int> s(20); // ����
int n;

// ������ ���� ��ġ, ���ݱ��� ���� �κ� ���� ������ dfs Ž��
void makeSum(int here, int psum)
{
	num[psum] = 1; // �κ� �� üũ
	// ������ ������ ����� ����
	if (here >= n) return;
	makeSum(here + 1, psum + s[here]); // ���� ���Ҹ� �κ� �տ� ����
	makeSum(here + 1, psum); // ���� ���Ҹ� �κ� �տ� �������� ����
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	makeSum(0, 0);
	int i = 0;
	while (1)
		// ���ʷ� �߰ߵǴ� false ���� �κ� ������ ���� �� ���� ����
		if (!num[++i])
		{
			cout << i << '\n';
			return 0;
		}
}
