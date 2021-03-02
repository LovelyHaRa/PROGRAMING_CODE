#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> alpha(26); // alpha[x]: x��° ���ĺ��� �ڸ������� ������ ����� ��
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;
		int p = 1; // �ڸ���(1, 10, 100...)
		// ���ڸ����� ���
		for (int j = word.size() - 1; j >= 0; j--)
		{
			alpha[word[j] - 'A'] += p; // �ش� ������ �ڸ����� ������Ŵ 
			p *= 10; // �ڸ��� ����
		}
	}
	sort(alpha.begin(), alpha.end(), greater<int>()); // ���ĺ� �迭 �������� ����
	int num = 9, res = 0;
	// 9���� �����Ͽ� ���ĵ� �迭�� �����ְ� �ϳ��� ���ҽ�Ų��.
	for (int i = 0; i < alpha.size(); i++)
		res += alpha[i] * num--;
	cout << res << '\n';
}