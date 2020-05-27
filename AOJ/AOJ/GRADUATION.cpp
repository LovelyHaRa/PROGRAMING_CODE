#include<iostream>
#include<vector>
#include<intrin.h>

using namespace std;

const int INF = 987654321;
int n, k, m, l;
vector<int> prerequisite; // �������� ����
vector<int> classes; // �б� �������� ����
vector<vector<int>> cache; // ĳ��

// ���� ��Ʈ�� ��ȯ
int bitCount(int n) { return __popcnt(n); /* __builtin_popcount(n); // g++ */ } 
int min(int a, int b) { return a < b ? a : b; }

// �̹��бⰡ smemster�̰� ���ݱ��� ���� ������ ������ taken�� ��
// k�� �̻� ������ �������� ���б⳪ �� �־�� �ϴ°�
int graduate(int semester, int taken)
{
	// ���� ���: �̹� k�� �̻� ���� ���
	if (bitCount(taken) >= k) return 0;
	// ���� ���: m�бⰡ ���� ���� ���(IMPOSSIBLE)
	if (semester == m) return INF; // INF�� ��ȯ
	// �޸������̼�
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF; // �ʱ� ����
	// �̹��б⿡ ���� �� �ִ� ���� �� ���� ���� ���� ������ ã�´�.
	int canTake = (classes[semester] & ~taken); // semester��  taken�� �������� ���Ѵ�.
	// ���� ������ �� ���� ���� ������ �����Ѵ�
	for (int i = 0; i < n; i++)
		// ���� ������ �ȵ���µ� ���������� ��� ���� �ʾ�����
		if ((canTake&(1 << i)) && (taken&prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i); // ���� ����
	// canTake�� ��� �κ����� ��ȸ
	for (int take = canTake; take; take = ((take - 1) & canTake))
	{
		if (bitCount(take) > l) continue; // �б�� l�� ���ϸ� ���� �� �ִ�
		// �ش� �κ������� ������� ���� ���� �� �ּڰ� ����
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	// �̹��б� ����
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> m >> l;
		prerequisite.resize(n);
		for (int i = 0; i < n; i++)
		{
			int r;
			cin >> r;
			for (int j = 0; j < r; j++)
			{
				int ri;
				cin >> ri;
				prerequisite[i] |= (1 << ri);
			}
		}
		classes.resize(m);
		for (int i = 0; i < m; i++)
		{
			int c;
			cin >> c;
			for (int j = 0; j < c; j++)
			{
				int ci;
				cin >> ci;
				classes[i] |= (1 << ci);
			}
		}
		cache.resize(n, vector<int>(1 << n, -1));
		int res = graduate(0, 0);
		if (res == INF) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
		prerequisite.clear();
		classes.clear();
		cache.clear();
	}
}