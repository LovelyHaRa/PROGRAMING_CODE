#include<iostream>
#include<cstring>

using namespace std;

int n; // �л� ��
bool areFriends[10][10]; // ģ�� �� ǥ��

// ���� �ذ��� ���� ��� ȣ�� �ڵ�
int countPairings(bool[10]);

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int C; // �׽�Ʈ���̽�
	int m; // ģ�� ���� ��
	cin.sync_with_stdio(false);
	cin >> C;
	while (C > 0)
	{
		// taken[i] = i��° �л��� ¦�� �̹� ã������ true, �ƴϸ� false
		bool taken[10] = { false };
		memset(areFriends, false, sizeof(areFriends));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			areFriends[x][y] = areFriends[y][x] = true;
		}
		cout << countPairings(taken) << endl;
		C--;
	}
}

int countPairings(bool taken[10])
{
	//���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	// ���� ��� : ��� �л��� ¦�� ã���� �Ѱ��� ����� ã������ �����Ѵ�.
	if (firstFree == -1) return 1;
	int ret = 0;
	// �� �л��� ¦���� �л��� �����Ѵ�.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriends[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}