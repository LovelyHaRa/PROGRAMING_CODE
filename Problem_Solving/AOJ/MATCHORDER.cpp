#include<iostream>
#include<vector>
#include<set>

using namespace std;

int order(const vector<int>& russian, const vector<int>& korean)
{
	int n = korean.size(), wins = 0;
	multiset<int> ratings(korean.begin(), korean.end()); // ���� Ž�� Ʈ���� ����
	for (int rus = 0; rus < n; rus++)
	{
		// � ������ �̱� �� ���� ���
		if (*ratings.rbegin() < russian[rus])
			ratings.erase(ratings.begin()); // ���� ���� ������ ���� ����
		else
		{
			// �̱� �� �ִ� ���� �� �ּҰ��� �������� ���� ������ ����
			ratings.erase(ratings.lower_bound(russian[rus]));
			wins++; // �¼� �߰�
		}
	}
	return wins;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> russian(n), korean(n);
		for (int i = 0; i < n; i++)
			cin >> russian[i];
		for (int i = 0; i < n; i++)
			cin >> korean[i];
		cout << order(russian, korean) << '\n';
	}
}