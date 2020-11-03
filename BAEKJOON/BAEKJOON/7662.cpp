#include<iostream>
#include<set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		multiset<int> pq; // �ߺ� ������ set
		while (k--)
		{
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') pq.insert(n); // ����(�ڵ� ����)
			else
			{
				if (pq.empty()) continue;
				pq.erase((n < 0 ? pq.begin() : --pq.end())); // ����
			}
		}
		if (pq.empty()) cout << "EMPTY\n";
		else cout << *--pq.end() << ' ' << *pq.begin() << '\n'; // �ִ�, �ּڰ� ���
	}
}