#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

// ���� ���� ���׽� p�� ��� ���־��� �� �̺��� ����� ����� ��ȯ�Ѵ�
vector<double> differentiate(const vector<double>& poly)
{
	vector<double> ret;
	int n = poly.size() - 1;
	for (int i = 0; i < n; i++)
		ret.push_back((n - i)*poly[i]);
	return ret;
}
// 1�� or 2�� �������� �ظ� ���Ѵ�
vector<double> solveNative(const vector<double>& poly)
{
	int n = poly.size() - 1;
	vector<double> ret;
	switch (n)
	{
	case 1:
		ret.push_back(-poly[1] / poly[0]);
		break;
	case 2:
		double a = poly[0], b = poly[1], c = poly[2];
		ret.push_back((-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		ret.push_back((-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		break;
	}
	sort(ret.begin(), ret.end());
	return ret;
}
//  ���׽� f(x)�� ��� poly�� �־��� ��, f(x0)�� ��ȯ�Ѵ�.
double evaluate(const vector<double>& poly, double x0)
{
	int n = poly.size() - 1;
	double ret = 0;
	for (int i = 0; i <= n; i++)
		ret += poly[i] * pow(x0, (n - i));
	return ret;
}
// �� ����
const double L = 25;
// ���׽��� ���� ��ȯ�Ѵ�.
vector<double> solve(const vector<double>& poly)
{
	int n = poly.size() - 1;
	// ���� ���: 2�� ���� ���׽��� �ذ� ����
	if (n <= 2) return solveNative(poly);
	// �������� �̺��ؼ� n-1�� �������� ��´�
	vector<double> derivative = differentiate(poly);
	vector<double> sols = solve(derivative);
	// �� ������ ���̸� �ϳ��ϳ� �˻��ϸ�����ֳ� Ȯ���Ѵ�.
	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);
	vector<double> ret;
	for (int i = 0; i + 1 < sols.size(); i++)
	{
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
		// ��ȣ�� ���� ��� ���� ����
		if (y1*y2 > 0) continue;
		// �Һ� ���� ����
		if (y1>y2) { swap(y1, y2); swap(x1, x2); }
		// �̺й� ���
		for (int iter = 0; iter < 100; iter++)
		{
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			if (y1*my > 0)
			{
				y1 = my;
				x1 = mx;
			}
			else
			{
				y2 = my;
				x2 = mx;
			}
		}
		ret.push_back((x1 + x2) / 2);
	}
	cout.precision(12);
	sort(ret.begin(), ret.end());
	return ret;
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<double> poly(n + 1);
		for (int i = 0; i < n + 1; i++)
			cin >> poly[i];
		vector<double> res = solve(poly);
		for (int i = 0; i < res.size(); i++)
			cout << fixed << res[i] << ' ';
		cout << '\n';
	}
}