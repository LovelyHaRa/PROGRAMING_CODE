#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int n;
vector<int> m, e;

int heat()
{
	vector<pair<int, int>> order; // (-�Դ½ð�, �ε���)�� ������ �����¹迭
	// -e[i] ���� �־������ν� �ڿ������� ���� ����
	for (int i = 0; i < n; i++)
		order.push_back(make_pair(-e[i], i));
	sort(order.begin(), order.end()); // �������� ����(-���̹Ƿ� �ڿ������� �������� ����)
	int ret = 0, beginEat = 0; // �ִ밪, �Դ½ð�
	// �ùķ��̼�
	for (int i = 0; i < n; i++)
	{
		int box = order[i].second; // ���� �Դ½ð��� �� ���ö� ����
		beginEat += m[box]; // �����
		 // �� �ð� = ��絵�ö��� ���ڷ������� ������ �ð� + �Դ½ð��� ���� �� ���ö� �Ѱ�
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		m.resize(n);
		e.resize(n);
		for (int i = 0; i < n; i++)
			cin >> m[i];
		for (int i = 0; i < n; i++)
			cin >> e[i];
		cout << heat() << '\n';
	}
}