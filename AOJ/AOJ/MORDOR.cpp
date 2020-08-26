#include<iostream>
#include<vector>
#include "rmq.h"

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> h(n), maxh(n); // �ּҳ���, �ִ����
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
			maxh[i] = -h[i]; // ������ �����ؼ� �ִ밪�� ���� �� �ֵ��� �Ѵ�
		}
		// ���� �ּ� Ʈ�� ����
		range_min_query<int> rngLow(h);
		range_min_query<int> rngHigh(maxh);
		// ������ ������� ���
		for (int i = 0; i < q; i++)
		{
			int a, b;
			cin >> a >> b;
			cout << -rngHigh.query(a, b) - rngLow.query(a, b) << '\n';
		}
	}
}