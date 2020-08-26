#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);
	int matched = 0;
	for (int i = 0; i < n; i++)
	{
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		if (H[i] == N[matched])
		{
			matched++;
			if (matched == m)
			{
				ret.push_back(i - m + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int shift(const string& original, const string& target)
{
	return kmpSearch(original + original, target)[0]; // kmp �˰����� ù��° ���� ��ȯ�Ѵ�.
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<string> k(n + 1);
		for (int i = 0; i < n + 1; i++)
			cin >> k[i];
		int cnt = 0;
		// Ȧ����°�� �ð� ����, ¦�� ��°�� �ݽð� ����
		// b�� �ݽð� �������� ���� a�� ����� �� �ʿ��� ĭ �� = a�� �ð�������� ���� b�� ����� �� �ʿ��� ĭ ��
		for (int i = 1; i < n + 1; i++)
			cnt += (i % 2) ? shift(k[i], k[i - 1]) : shift(k[i - 1], k[i]);
		cout << cnt << '\n';
	}
}