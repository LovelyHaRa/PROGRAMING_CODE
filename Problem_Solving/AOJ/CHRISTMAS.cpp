#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
// ��� ������� ��� �ִ��� ��ȯ
int waysToBuy(const vector<int>& psum, int k)
{
	const int mod = 20091101;
	int ret = 0;
	// ������ �����Ϸ��� psum[H-1]=psum[T]�̾�� �Ѵ� [ (psum[T]-psum[H-1]) mod k == 0 ]
	vector<long long> count(k, 0); // �κ��� ī��Ʈ
	// �κ����� ������ ���� ���´�
	for (int i = 0; i < psum.size(); i++)
		count[psum[i]]++;
	// 2���� �����ϸ� �ѹ��� �ֹ��� �ȴ�
	for (int i = 0; i < k; i++)
		if (count[i] >= 2)
			// �� �� �� �ΰ��� �����ϴ� ����� ���� ���Ѵ�.
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % mod;
	return ret;
}

// ��ġ�� �ʰ� �� ���̳� �� ���ִ��� ��ȯ
int maxBuys(const vector<int>& psum, int k)
{
	// ù ��° ���ں��� i��° ���ڱ��� ������� �� �� �� �ִ� �ִ� Ƚ��
	vector<int> ret(psum.size(), 0);
	// psum�� s���� ������ ��ġ
	vector<int> prev(k, -1);
	for (int i = 0; i < psum.size(); i++)
	{
		// i��° ���ڸ� �ƿ� ������� �ʴ� ���
		if (i > 0) ret[i] = ret[i - 1];
		else ret[i] = 0;
		// psum[i]�� ������ �� ���� ������, prev[psum[i]]+1 ���� ������� �� �� ����.
		int loc = prev[psum[i]];
		if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		// ���� ��ġ�� ����Ѵ�.
		prev[psum[i]] = i;
	}
	return ret.back();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> d(n + 1), psum(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> d[i];
			psum[i] = (psum[i - 1] + d[i]) % k; // �κ����� k�� ���� �������� �����Ѵ�
		}
		cout << waysToBuy(psum, k) << ' ';
		cout << maxBuys(psum, k) << '\n';
	}
}