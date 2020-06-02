#include<iostream>
#include<string>
#include<vector>

using namespace std;
// N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
// pi[]�� ����Ѵ�
// pi[i]=N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	// KMP�� �ڱ� �ڽ��� ã�´�.
	// N�� N���� ã�´�. begin=0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵȴ�!
	int begin = 1, matched = 0;
	// ���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�.
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

vector<int> getPrefixSuffix(const string& s)
{
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k > 0)
	{
		// s[..k-1]�� ���̴�.
		ret.push_back(k);
		// s[..k-1]�� ���̻絵 �ǰ� �����ٵ� �Ǵ� ���ڿ��� ���̴�.
		k = pi[k - 1];
	}
	return ret;
}

int main(void)
{
	string f, m;
	cin >> f >> m;
	vector<int> res = getPrefixSuffix(f + m);
	// �������� ���
	for (auto i = res.rbegin(); i != res.rend(); i++)
		cout << *i << ' ';
	cout << endl;
}