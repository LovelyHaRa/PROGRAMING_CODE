#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// �� ���̻���� ù t���ڸ� �������� �� �׷� ��ȣ�� �־��� ��,
// �־��� �� ���̻縦 ù 2*t���ڸ� �������� ���Ѵ�.
// group[]�� ���̰� 0�� ���̻絵 �����Ѵ�.
struct Comparator
{
	const vector<int>& group; // �׷�����
	int t; // ù ������ 2���
	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {} // ������
	// ������ �����ε�(���Լ� ����)
	bool operator () (int a, int b)
	{
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

// s�� ���̻� �迭�� ����Ѵ�.
vector<int> getSuffixArray(const string& s)
{
	int n = s.size(); // ���ڿ� ����
	// group[i]=���̻���� ù t���ڸ� �������� �������� ��, s[i..]�� ���� �׷� ��ȣ
	// t=1�� ���� ������ �� ���� s[i..]�� ù ���ڷ� �׷� ��ȣ�� ���� �൵ ���� ȿ���� �ִ�.
	int t = 1;
	vector<int> group(n + 1);
	// t=1�� �� �׷� �迭 ó��
	for (int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1; // �������� �׻� ���� ������ �ϸ� �迭�� �����÷ο쿡 ���� ����ó���� ���ص� �ȴ�.
	// ��������� ���̻� �迭�� �� ��ȯ ��. �� �迭�� lg(n)�� �����Ѵ�.
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i; // ���̻� ������ ����
	while (t < n)
	{
		// group[]�� ù t���ڸ� �������� ����� �״�.
		// ù 2t���ڸ� �������� perm�� �ٽ� �����Ѵ�.
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		// 2t���ڰ� n�� �Ѵ´ٸ� ���� ���̻� �迭 �ϼ�
		t *= 2;
		if (t >= n) break;
		// 2t���ڸ� �������� �� �׷� ������ �����.
		// ���ο� �׷� �迭 �ʱ�ȭ
		vector<int> newGroup(n + 1); 
		newGroup[n] = -1;
		newGroup[perm[0]] = 0; // ù��° ���̻�� �׻� �׷� 0������ ����
		for (int i = 1; i < n; i++)
		{
			// ���� ���̻�� ���ڰ� �ٸ��� �ٸ� �׷�
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1; // �׷� ��ȣ �߰�
			// �ݴ��� ��� ���� �׷��̹Ƿ� �׷� ��ȣ ����
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		}
		group = newGroup; // �׷� �迭 ����
	}
	return perm; // ����
}

// s[i..]�� s[j..]�� ���� ���λ��� �ִ� ���̸� ����Ѵ�
int commonPrefix(const string& s, int i, int j)
{
	int k = 0; // ī����
	while (i < s.size() && j < s.size() && s[i] == s[j])
	{
		i++;
		j++;
		k++;
	}
	return k;
}

// k�� �̻� �����ϴ� s�� �κ� ���ڿ� �� �ִ� ���̸� ã�´�.
int longestFrequent(int k, const string& s)
{
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); i++)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int k;
		cin >> k;
		string s;
		cin >> s;
		cout << longestFrequent(k, s) << '\n';
	}
}