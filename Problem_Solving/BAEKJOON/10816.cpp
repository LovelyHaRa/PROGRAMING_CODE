#include<iostream>
#include<set>
#include <unordered_map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	unordered_map<int, int> cardCnt; // �ؽ� ���̺��� �̿�
	// �ؽ� ����
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		cardCnt[c]++;
	}
	int m;
	cin >> m;
	// �ؽ� Ž��
	for (int i = 0; i < m; i++)
	{
		int c;
		cin >> c;
		cout << cardCnt[c] << ' ';
	}
	cout << '\n';
}