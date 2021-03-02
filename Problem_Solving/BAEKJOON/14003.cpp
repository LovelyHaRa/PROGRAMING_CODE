#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> cache, a, choices;

int lis(int start)
{
	// �޸������̼�
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	// ���̴� ������ 1���� ����(�ڱ��ڽ�)
	ret = 1;
	int bestNext = -1;
	for (int next = start+1; next < n; next++)
	{
		if (start == -1 || a[start] < a[next])
		{
			// ���� ������ ���� ���� ���ϱ�
			int c = lis(next) + 1;
			// ���� �ִ밪 ����
			if (ret < c)
			{
				ret = c;
				bestNext = next;
			}
		}
	}
	// �ִ밪 �ε��� ����
	choices[start + 1] = bestNext;
	return ret;
}

// choices�� ������� LIS ������ �����.
void reconstruct(int start, vector<int>& seq)
{
	// choices[i] = ���� �ִ� ���� ���� �� ��ġ
	if (start != -1) seq.push_back(a[start]); // ������ LIS ������ ����
	int next = choices[start + 1]; // ���� ��ġ ���ϱ�
	if (next != -1) reconstruct(next, seq); // ��� Ž��
}

int main(void)
{
	cin >> n;
	a.resize(n);
	cache.resize(n + 1, -1);
	choices.resize(n + 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	lis(-1); // ��� �������� Ž��
	vector<int> seq;
	reconstruct(choices[0], seq);
	int cnt = seq.size();
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << seq[i] << ' ';
}