#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> A;
	A.push_back(-1987654321);
	int cnt = 0;
	while (n--)
	{
		int k;
		cin >> k;
		// ������ �Ѵٸ� �ڿ� ����
		if (k > A.back())
		{
			A.push_back(k);
			cnt++;
		}
		else
		{
			vector<int>::iterator find = lower_bound(A.begin(), A.end(), k); // �̺� Ž������ k���� ū ������ ��ġ ��ȯ
			*find = k; // �ٲ�ġ��
		}
	}
	cout << cnt;
}