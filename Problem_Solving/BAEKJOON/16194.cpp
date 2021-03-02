#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> p, cache;

int min(int a, int b) { return a < b ? a : b; }

// pick���� ī�带 ������ �� �ִ� �ּ� ����� ��ȯ
int card(int pick)
{
	// ���� ���: ī�带 ������ �� ���� ���
	if (pick == 0) return 0;
	// �޸������̼�
	int& ret = cache[pick];
	if (ret != -1) return ret;
	ret = 987654321; // �ּҰ��� �����ϱ� ���� �ʱ� ����
	// 1~pick���� ī�� ����
	for (int buy = 1; buy <= pick; buy++)
		ret = min(ret, p[buy] + card(pick - buy)); // ������ ī�带 ��� �ݺ�
	return ret;
}

int main(void)
{
	cin >> n;
	p.resize(n + 1);
	cache.resize(n + 1, -1);
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	cout << card(n);
}