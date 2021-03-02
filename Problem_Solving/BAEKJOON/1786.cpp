#include<iostream>
#include<string>
#include<vector>

using namespace std;

// N�� ���̺� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� ���̸� ��ȯ
vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	// KMP Ž���� �̿�
	// �ڱ� �ڽ��� ��ġ�ϴ� ���ڿ��� ���Ѵ�
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

// KMP �˰����� �̿��� ��ġ�ϴ� ���� �ε��� �迭�� ��ȯ
vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N); // �̸� ���̻�=���λ� ���̸� ���Ѵ�
	int matched = 0;
	for (int i = 0; i < n; i++)
	{
		// ���ڰ� ��ġ���� ������ pi[matched-1]��ŭ �ǳʶڴ�
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];
		// ���ڰ� ��ġ�ϸ�
		if (H[i] == N[matched])
		{
			matched++;
			// ���ڿ��� ��ġ�ϸ�
			if (matched == m)
			{
				ret.push_back(i - m + 1); // �ε��� �߰�
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main(void)
{
	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int> res = kmpSearch(t, p);
	int s = res.size();
	cout << s << '\n';
	for (int i = 0; i < s; i++)
		cout << res[i] + 1 << ' ';
	cout << '\n';
}