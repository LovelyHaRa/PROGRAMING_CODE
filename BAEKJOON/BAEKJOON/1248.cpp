#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<char>> c; // ���� ���� ���̺�
vector<int> ans; // ���� �迭
vector<int> psum; // ������ �κ��� �迭
bool success = false; // ������ ã���� ��� �Լ��� ������ ���� �÷���

// start ~ end ������ ���� ��ȣ�� c�� ��ġ�ϴ��� Ȯ���Ѵ�
bool check(int start, int end, char c)
{
	int sum = start == 0 ? psum[end] : psum[end] - psum[start - 1];
	// c�� ��ȣ�� ���� ó��
	switch (c)
	{
	case '-':
		return sum < 0 ? true : false;
	case '0':
		return sum == 0 ? true : false;
	case '+':
		return sum > 0 ? true : false;
	}
}

// cnt���� ���ڸ� Ž������ �� �迭�� ���� ������ �����ϴ��� �Ǵ��Ѵ�
void process(int cnt)
{	
	// ���� ���� ���̺�� ������ ��ġ���� ������ ��ȯ��Ų��
	for (int i = 0; i < cnt; i++)
		for (int j = i; j < cnt; j++)
			if (!check(i, j, c[i][j])) return;
	// ���ϵ��� �ʾ����� ���ݱ��� �߰��� ���ڵ��� ������ �������� �ǹ�
	// ���� ���: cnt==n
	if (cnt == n)
	{
		// ����Ѵ�
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		success = true;
		return;
	}
	// ���� ���� �߰�
	// 0�� ��� Ž��
	if (c[cnt][cnt] == '0')
	{
		ans[cnt] = 0; // 0 �߰�
		// �κ��� �߰�
		cnt == 0 ? psum[cnt] = ans[cnt] : psum[cnt] = psum[cnt - 1] + ans[cnt];
		// ���� ���� Ž��
		process(cnt + 1);
		// �������� ��� ���� ����
		if (success) return;
	}
	// 1~10�� ��� Ž��
	for (int i = 1; i <= 10; i++)
	{
		ans[cnt] = c[cnt][cnt] == '-' ? -i : i; // ���� �߰�
		// �κ��� �߰�
		cnt == 0 ? psum[cnt] = ans[cnt] : psum[cnt] = psum[cnt - 1] + ans[cnt];
		// ���� ���� Ž��
		process(cnt + 1);
		// �������� ��� ���� ����
		if (success) return;
	}
}

int main(void)
{
	cin >> n;
	c.resize(n, vector<char>(n));
	ans.resize(n);
	psum.resize(n);
	// i~j ������ ���� ������ �Է¹޴´�
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> c[i][j];
	process(0);
}