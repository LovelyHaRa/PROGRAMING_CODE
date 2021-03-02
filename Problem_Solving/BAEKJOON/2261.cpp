#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// ��ǥ��� �� �� ǥ��
class Point
{
public:
	int x, y;
};

// �� ����ü
struct compare
{
	bool comp_in_x; // x��ǥ ���� ���� ����
	compare(bool b) : comp_in_x(b) {};
	// ������ �����ε�
	bool operator()(Point &p, Point &q) {
		return (this->comp_in_x ? p.x < q.x : p.y < q.y);
	}
};

// �� �� ������ �Ÿ�
int dist(Point &p, Point &q)
{
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

// �� �������� �Ÿ��� �ּڰ��� ���ϴ� �Լ�
int closest_pair(vector<Point>::iterator it, int n)
{
	// n = 3 ������ �ܼ� �� ����
	if (n == 2) return dist(it[0], it[1]);
	if (n == 3) return min({ dist(it[0], it[1]), dist(it[1], it[2]), dist(it[0], it[2]) });

	// x��ǥ�� �������� �߾����� �������� ���� �ϳ� ����
	int line = (it[n / 2 - 1].x + it[n / 2].x) / 2;
	// ���� �������� �� ��� ���� ���� �Ͽ� �ּڰ� ����
	int d = min(closest_pair(it, n / 2), closest_pair(it + n / 2, n - n / 2));

	// ���� �����ϴ� �� �� ������ ������ ����
	vector<Point> mid;
	mid.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int t = line - it[i].x;
		// ���ο��� x ��ǥ������ �Ÿ��� d �̻��̸� ����� �ּҰ��� �� �� �����Ƿ� ����
		if (t*t < d) mid.push_back(it[i]);
	}
	
	// ������ ���� y�� �������� ����
	sort(mid.begin(), mid.end(), compare(false));

	// ���� �ؿ� ������ Ž��
	int mid_sz = mid.size();
	for (int i = 0; i < mid_sz - 1; i++)
	{
		// �Ÿ��� d �̻��� ������ ����� �ּҰ��� �� �� �����Ƿ� ������ ������ Ž�� �ߴ�
		for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y)*(mid[j].y - mid[i].y) < d; j++)
			d = min(d, dist(mid[i], mid[j]));
	}

	return d;
}

int main(void)
{
	int n;
	cin >> n;

	vector<Point> points(n);
	for (auto i = points.begin(); i != points.end(); i++)
		cin >> i->x >> i->y;

	// x��ǥ �������� ����
	sort(points.begin(), points.end(), compare(true));

	// �Ÿ��� �ּڰ� ���
	cout << closest_pair(points.begin(), n) << '\n';
}