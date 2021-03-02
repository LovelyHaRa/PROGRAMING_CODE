#include<iostream>
#include<vector>
#include"trip.h"

using namespace std;

int n;
vector<int> shifted, a;

void solve()
{
	// Ʈ�� ����
	TripNode<int>* candidates = NULL;
	for (int i = 0; i < n; i++)
		candidates = insert(candidates, new TripNode<int>(i + 1));
	// �������� A[i]�� ����
	for (int i = n - 1; i >= 0; i--)
	{
		int larger = shifted[i]; // A[i]���� ū ���� larger�� �ִ�
		// i+1-larger��° ��带 ã�´�
		TripNode<int>* k = kth(candidates, i + 1 - larger);
		a[i] = k->key; // ��带 �����Ѵ�
		// ����� ��带 �����Ѵ�
		candidates = erase(candidates, k->key);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n;
		a.resize(n);
		shifted.resize(n);
		for (int i = 0; i < n; i++)
			cin >> shifted[i];
		solve();
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
		a.clear();
		shifted.clear();
	}
}