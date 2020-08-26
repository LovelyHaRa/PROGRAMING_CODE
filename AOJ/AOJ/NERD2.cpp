#include<iostream>
#include<map>

using namespace std;

map<int, int> coords;

// (x, y)�� ���� ���鿡 ���� ������ϴ��� Ȯ��
bool isDominated(int x, int y)
{
	// Ž���Ѵ�
	map<int, int>::iterator it = coords.lower_bound(x);
	// ������ false
	if (it == coords.end()) return false;
	// �ִٸ� y ���� Ŀ�� ���踦 �ȴ��Ѵ�(ã�� ���� y���� ���ʿ� �ִ�)
	return y < it->second;
}

// (x, y)�� ���� ������ϴ� ������ �����Ѵ�
void removeDominated(int x, int y)
{
	// ���� �� ��ġ ã��
	map<int, int>::iterator it = coords.lower_bound(x);
	// ���� ������ ���� ���� ������ �ƹ� �ϵ� ����
	if (it == coords.begin()) return;
	it--; // ���ͷ����� ����
	// y������ ū ���� ���ö� ���� �ݺ�
	while (1)
	{
		// �ߴ� ����: ���� ���ͷ����Ͱ� y�� �̻��� ���
		if (it->second > y) break;
		// �ߴ� ����: ���� ���ͷ����Ͱ� ���� ���� ���� ���
		if (it == coords.begin())
		{
			// ���� ���� ����
			coords.erase(it);
			break;
		}
		// ���� ������ ���ͷ����͸� �ϳ� �Ű� ���� it�� �����
		else {
			map<int, int>::iterator jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

// �� �� (x, y)�� �߰��Ǿ��� �� coords�� �����ϰ�
// �ٸ� ���� ��������� �ʴ� ������ ������ ��ȯ�Ѵ�
int registered(int x, int y)
{
	// (x, y)�� �̹� ������� ��� �� ���� �׳� ������
	if (isDominated(x, y)) return coords.size();
	// ������ �߰��� ���� �� ������ϴ� ������ �����
	removeDominated(x, y);
	// ������ �߰��Ѵ�
	coords[x] = y;
	// ������ ������ ��ȯ�Ѵ�
	return coords.size();
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		int res = 0; // ������ ��� �� ���� �ʵ��� ������ ����
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			res += registered(x, y);
		}
		cout << res << '\n';
		coords.clear();
	}
}