#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, capacity; // ��ǰ ����, ���� �Ѱ�
vector<vector<int>> cache; // ĳ��
vector<int> volume, need; // ���� ����Ʈ, ���ڵ� ����Ʈ
vector<string> name; // ��ǰ �̸� ����Ʈ

int max(int a, int b) { return a > b ? a : b; }

int pack(int capacity, int item)
{
	// ���� ���: �������� ��� Ž������ ��
	if (item == n) return 0;
	// �޸������̼�
	int& ret = cache[capacity][item];
	if (ret != -1)return ret;
	// 1. ���� �������� �������� �ʾ��� ��
	ret = pack(capacity, item + 1);
	// 2. ���� �������� �������� ��
	if (capacity >= volume[item])
		// 1�� ���Ͽ� �ִ밪 ����
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked)
{
	// ���� ���: �������� ��� Ž������ ��
	if (item == n) return;
	// ���� �������� �������� ���� ���: �����ϰ� ���� ������ Ž��
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	// ���� �������� ������ ���
	else
	{
		picked.push_back(name[item]); // ������ ����
		// ���� ������ Ž��
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		// �Է�
		cin >> n >> capacity;
		cache.resize(1001, vector<int>(n, -1));
		volume.resize(n);
		need.resize(n);
		name.resize(n);
		for (int i = 0; i < n; i++)
			cin >> name[i] >> volume[i] >> need[i];
		// ���ڵ� �ִ밪 ���ϱ�
		pack(capacity, 0);
		// ������ ������ ����Ʈ �����
		vector<string> picked;
		reconstruct(capacity, 0, picked);
		// ���
		int cnt = picked.size();
		cout << pack(capacity, 0) << ' ' << cnt << '\n';
		for (int i = 0; i < cnt; i++)
			cout << picked[i] << '\n';
		// �ʱ�ȭ
		cache.clear();
		volume.clear();
		need.clear();
		name.clear();
	}
}