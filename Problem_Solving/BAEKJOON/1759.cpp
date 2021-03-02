#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int l, c;
vector<char> pw, selected;
vector<int> visited;

// ���� ����
void permutation(int cnt)
{
	// ���� ���: ��ǥ ���̿� �������� ��
	if (cnt == l)
	{
		// ��/���� üũ
		int con = 0, vow = 0;
		for (int i = 0; i < l; i++)
		{
			if (selected[i] == 'a' || selected[i] == 'e' || selected[i] == 'i' || selected[i] == 'o' || selected[i] == 'u')
				vow++;
			else
				con++;
			if (con > 1 && vow > 0) break;
		}
		// ���� 2���̸� �Ǵ� ������ ������ ��� ����
		if (con <= 1 || vow == 0) return;
		// ���� ���
		for (int i = 0; i < l; i++)
			cout << selected[i];
		cout << '\n';
		return;
	}
	for (int i = 0; i < c; i++)
	{
		// ������ ���������̾�� �Ѵ�
		if (visited[i] || (cnt > 0 && selected[cnt - 1] > pw[i])) continue;
		visited[i] = 1; // �湮 üũ
		selected[cnt] = pw[i]; // ���� ���� �߰�
		permutation(cnt + 1); // ���� ���� Ž��
		visited[i] = 0; // ���� ����
	}
}

int main(void)
{
	cin >> l >> c;
	pw.resize(c);
	visited.resize(c);
	selected.resize(l);
	for (int i = 0; i < c; i++)
		cin >> pw[i];
	// ����
	sort(pw.begin(), pw.end());
	permutation(0);
}