#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int n;
vector<int> p, cache;

// pick���� ī�带 �������� �� �ִ� ������ ����
int card(int pick)
{
	// ���� ���: ������ ī�尡 ���� ���
	if (!pick) return 0;
	// �޸������̼�
	int& ret = cache[pick];
	if (ret != -1) return ret;
	ret = 0; // �ּҰ��� 0��
	// 1���� pick������ �ݺ�
	for (int j = 1; j <= pick; j++)
		// j���� ī�带 �����ϰ� �������� ������ ��츦 ���Ѱ��� ���Ͽ� �ִ밪 ����
		ret = max(ret, p[j] + card(pick - j));
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