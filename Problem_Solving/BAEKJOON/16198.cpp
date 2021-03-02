#include<iostream>
#include<vector>

using namespace std;

int maxEnergy; // ������ �ִ밪

//  ���� ���� �迭 w�� ���ݱ��� ���� ������ e�� �������� �������� ������
void makeEnergy(vector<int> w, int e)
{
	// ���� ���: ������ 2�� ������ ��
	if (w.size() == 2)
	{
		// �ִ밪 ����
		maxEnergy = maxEnergy < e ? e : maxEnergy;
		return;
	}
	// ù �κа� ������ �κ��� �����ϰ� Ž��
	for (int i = 1; i < w.size() - 1; i++)
	{
		// �κ� ������ ���
		int pe = w[i - 1] * w[i + 1] + e;
		// �迭 ����
		vector<int> nw = w;
		// ���� ����
		nw.erase(nw.begin() + i);
		// ���� ������ ������ ������
		makeEnergy(nw, pe);
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	makeEnergy(w, 0);
	cout << maxEnergy << '\n';
}