#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int n, m;
// catEat[i]: i��° ģ���� ���� �� �ִ� ������ ����
// eaters[i]: i��° ������ ���� �� �ִ� ģ���� ����
vector<vector<int>> canEat, eaters;
int best;

void search(vector<int>& edible, int chosen)
{
	// ������ ����ġ��
	if (chosen >= best) return;
	int first = 0;
	// ���� ���õ� ���ĵ��� ���Դ� ��� �˻�
	while (first < n && edible[first]>0) first++;
	// ���� ���: ��� ģ���� ������ ���� �� ���� ��
	if (first == n) {
		best = chosen; // ���� �� ����
		return;
	}
	// ���Դ� ����� ���� �� �ִ� ���� Ž��
	for (int i = 0; i < canEat[first].size(); i++)
	{
		// ������ ���� �� �ִ��� üũ
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); j++)
			edible[eaters[food][j]]++;
		search(edible, chosen + 1); // ��� Ž��
		// ���� ����
		for (int j = 0; j < eaters[food].size(); j++)
			edible[eaters[food][j]]--;
	}
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		map<string,int> friends; //ģ������ �ε����� ����
		vector<int> edible(n, 0); // edible[i]: i��° ģ���� ���� �� �ִ� ������ ����
		for (int i = 0; i < n; i++)
		{
			string f;
			cin >> f;
			friends[f] = i; // ����
		}
		eaters.resize(m);
		canEat.resize(n);
		for (int i = 0; i < m; i++)
		{
			int c;
			cin >> c;
			for (int j = 0; j < c; j++)
			{
				string f;
				cin >> f;
				eaters[i].push_back(friends[f]);
				canEat[friends[f]].push_back(i);
			}
		}
		best = m;
		search(edible, 0);
		cout << best << '\n';
		canEat.clear();
		eaters.clear();
	}
}