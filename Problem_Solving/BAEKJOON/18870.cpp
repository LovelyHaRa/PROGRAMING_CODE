#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n; // �Է� �ޱ�
	// ��ǥ ������, ���� �� ������
	vector<int> x(n), sorted(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sorted[i] = x[i];
	}
	// ��ǥ ������ ����
	sort(sorted.begin(), sorted.end());
	// unique�� ����Ͽ� �ߺ� ������ �ڷ� ������
	// ��ȯ ���� �� �ڷ� �̵��� �ߺ����� ù ��° ��ġ
	// �̸� erase�� �̿��Ͽ� �����Ѵ�
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	// ��ǥ ����
	for (auto i : x)
	{
		// �̺� Ž������ ���ĵ� �����Ϳ��� ��ġ ã��
		auto pos = lower_bound(sorted.begin(), sorted.end(), i);
		// begin ���ͷ����͸� �� �����ν� ��ġ ���
		cout << pos - sorted.begin() << ' ';
	}
	cout << '\n';
}