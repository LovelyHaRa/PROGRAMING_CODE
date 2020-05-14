#include<iostream>
#include<vector>
#include<string>

using namespace std;

// ���ڿ� �����
//void curve(const string& seed, int generations)
//{
//	if (generations == 0)
//	{
//		cout << seed;
//		return;
//	}
//	for (int i = 0; i < seed.size(); i++)
//	{
//		if (seed[i] == 'X')
//			curve("X+YF", generations - 1);
//		else if (seed[i] == 'Y')
//			curve("FX-Y", generations - 1);
//		else
//			cout << seed[i];
//	}
//}

const int MAX = 1000000000 + 1;
vector<int> length(51); // N������ �巡��Ŀ�� ����
int min(int a, int b) { return a < b ? a : b; }

// N������ �巡��Ŀ���� ���̸� �̸� ���ϱ�
void precalc()
{
	length[0] = 1;
	for (int i = 1; i <= 50; i++)
		length[i] = min(MAX, 2 + 2 * length[i - 1]);
}
// X, Y�� �� ġȯ�� ���ڿ�
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

// k��° �巡��Ŀ�� ���ڿ� ���
char expand(const string& dragonCurve, int generations, int skip)
{
	// �������: 0�����ϰ��
	if (generations == 0)
		return dragonCurve[skip];
	for (int i = 0; i < dragonCurve.size(); i++)
	{
		// ���ڿ��� Ȯ��Ǵ� ���
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
		{
			if (skip >= length[generations])
				skip -= length[generations];
			else if (dragonCurve[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else if (dragonCurve[i] == 'Y')
				return expand(EXPAND_Y, generations - 1, skip);
		}
		// Ȯ����� ������ �ǳʶپ�� �� ���
		else if (skip > 0) --skip;
		// ���� ã�� ���
		else return dragonCurve[i];
	}	
}

int main(void)
{
	// ���̸� �̸� ����
	precalc();
	int c;
	cin >> c;
	while (c--)
	{
		int n, p, l;
		cin >> n >> p >> l;
		// k��° �巡��Ŀ�� ���ڿ� ���(�ε��� ������ -1) (p-1<=k<p+l-1) 
		for (int i = p - 1; i < p + l - 1; i++)
			cout << expand("FX", n, i);
		cout << '\n';
	}
}