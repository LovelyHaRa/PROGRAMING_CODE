#include<iostream>
#include<vector>

using namespace std;

// ���� ����: �׸��� �˰��� �̿�
// ī�޶� �������� gap��ŭ ����� ��ġ�� �� �ִ� ��찡 ī�޶� ������ ũ�� true
bool decision(const vector<double>& location, int cameras, double gap)
{
	double limit = -1; // ���� ī�޶� ��ġ �ּ� ����
	int installed = 0; // ��ġ�� ī�޶� ���
	// ��ġ ������ ������ Ž��
	for (int i = 0; i < location.size(); i++)
	{
		if (limit <= location[i])
		{
			installed++;
			// gap �̻� ��ŭ �Ǿ�� ��ġ ����
			limit = location[i] + gap;
		}
	}
	// ��������� ī�޶� ������� ���� ��ġ�� �� ������ true
	return cameras <= installed;
}

// ����ȭ ����: �̺й� �̿�
double optimize(const vector<double>& location, int cameras)
{
	double lo = 0, hi = 241;
	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2.0;
		// mid ���� ������ ����� ���� ������ ������ ����
		if (decision(location, cameras, mid))
			lo = mid;
		// �׷��� �ʴٸ� ���� ������ ����
		else
			hi = mid;
	}
	return lo;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, m;
		cin >> n >> m;
		vector<double> location(m);
		for (int i = 0; i < m; i++)
			cin >> location[i];
		// ����° �ڸ����� �ݿø�
		cout.precision(2);
		cout << fixed << optimize(location, n) << '\n';
	}
}
