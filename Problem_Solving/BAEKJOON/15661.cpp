#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> table;

// ���� �ɷ�ġ ���
int calcSkill(const vector<int>& t)
{
	int ret = 0;
	for (int i = 0; i < t.size(); i++)
		for (int j = i + 1; j < t.size(); j++)
			ret += table[t[i]][t[j]] + table[t[j]][t[i]];
	return ret;
}

int abs(int a) { return a >= 0 ? a : -a; }

// A��, B���� ���� ���� �Ǿ��� �� �ɷ�ġ�� ġ���� �ּڰ��� ��ȯ
int process(int a, int b)
{
	vector<vector<int>> team1, team2;
	vector<int> t1(a), t2(b);

	// ������ ����ϱ� ���� ����
	vector<bool> c(n);
	fill(c.end() - b, c.end(), true);

	int idx1, idx2;
	// ������ �̿��Ͽ� ��� ����� �� ���
	do
	{
		idx1 = idx2 = 0;
		for (int i = 0; i < n; i++)
		{
			// ��� ���� �շ����� ����
			if (!c[i])
				t1[idx1++] = i;
			else
				t2[idx2++] = i;
		}
		team1.push_back(t1);
		team2.push_back(t2);
	} while (next_permutation(c.begin(), c.end()));

	// �ɷ�ġ ������ �ּڰ��� ���
	int ret = 1987654321;
	for (int i = 0; i < team1.size(); i++)
		ret = min(ret, abs(calcSkill(team1[i]) - calcSkill(team2[i])));
	return ret;
}

int main(void)
{
	cin >> n;
	table.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> table[i][j];
	int res = 1987654321;
	int mod = n % 2;
	// ��� ����� �� ���
	// � ������ ������ �ּڰ��� 0�̱� ������ res�� 0�� �Ǹ� �ٷ� ����
	for (int i = 0; i < n / 2; i++)
	{
		res = min(res, process(n / 2 + i + mod, n / 2 - i));
		if (!res) break;
		res = min(res, process(n / 2 + i, n / 2 - i + mod));
		if (!res) break;
		res = min(res, process(n / 2 - i + mod, n / 2 + i));
		if (!res) break;
		res = min(res, process(n / 2 - i, n / 2 + i + mod));
		if (!res) break;
	}
	cout << res << '\n';
}