#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int h, w, r, c;
int blockSize;
vector< vector<pair<int, int>>> rotations;
vector<vector<int>> covered;

// ����� ȸ����Ų��
vector<string> rotate(const vector<string>& arr)
{
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++)
		for (int j = 0; j < arr[0].size(); j++)
			ret[j][arr.size() - i - 1] = arr[i][j];
	return ret;
}

// ����� �����ǥ�� ��� �����Ѵ�
void generateRotations(vector<string> block)
{
	rotations.clear();
	rotations.resize(4);
	// �� 4��
	for (int rot = 0; rot < 4; rot++)
	{
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); i++)
			for (int j = 0; j < block[i].size(); j++)
				if (block[i][j] == '#')
				{
					// �»�� ��ǥ�� ���Ѵ�
					if (originY == -1)
					{
						originY = i;
						originX = j;
					}
					// �»�� ��ǥ ���� �����ǥ�� �����Ѵ�.
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
		block = rotate(block); // ����� 90�� ȸ����Ų��.
	}
	sort(rotations.begin(), rotations.end()); // ����
	// �ߺ��Ǵ� ���� �����Ѵ�.
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size(); // �� ��ü�� ������ ���Ѵ�
}

int best;
// (y,x)�� ���� ���� �� �ִ��� ���θ� ��ȯ, delta�� ���� �ְų� ����.
bool set(int y, int x, const vector<pair<int, int>>& block, int delta)
{
	bool res = true;
	for (int i = 0; i < block.size(); i++)
	{
		// ��ǥ�� ���� �ȿ� ���ԵǸ�
		if (y + block[i].first >= 0 && y + block[i].first < h && x + block[i].second >= 0 && x + block[i].second < w)
		{
			covered[y + block[i].first][x + block[i].second] += delta; // �� �ֱ�/����
			res = res && (covered[y + block[i].first][x + block[i].second] == 1); // ���� ��ġ�� �������̸� 2�� �� �̴�
		}
		else res = false;
	}
	return res;
}

// ����ġ��
int blockPrune(int placed)
{
	int cnt = 0;
	// ���忡 ���� �� �ִ� ĭ�� ������ ���Ѵ�.
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cnt += !(covered[i][j]) ? 1 : 0;
	}
	// ĭ�� ���� / ������ ���� + ���� ���� ������ best���� ������ �� ���� �����ظ� ã�� �� ����
	return ((cnt / blockSize) + placed <= best);
}

void search(int placed)
{
	// ����ġ��
	if (blockPrune(placed))
		return;
	// �»�ܺ��� ������ �� ������ ã�´�.
	int y = -1, x = -1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0;j < w; j++)
		{
			if (covered[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	// ���� ���: ��� ĭ�� ä���� ������ �ִ밪 ���� �� ����
	if (y == -1)
	{
		best = max(best, placed);
		return;
	}
	// ���� �־��
	for (int i = 0; i < rotations.size(); i++)
	{
		// �� ä���
		if (set(y, x, rotations[i], 1))
			search(placed + 1); // ä�� �� ������ ī���� �ϰ� ���Ž��
		set(y, x, rotations[i], -1); // �� ����
	}
	covered[y][x] = 1; // �� ĭ�� ���� �ʰ� ���Ƶд�
	search(placed);
	covered[y][x] = 0;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> h >> w >> r >> c;
		vector<string> block(r);
		covered.resize(h, vector<int>(w));
		// ������ ������ 1, 0���� ġȯ �� ����
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char x;
				cin >> x;
				covered[i][j] = (x == '#') ? 1 : 0;
			}
		}
		for (int i = 0; i < r; i++)
			cin >> block[i];
		// ����� �����ǥ ����
		generateRotations(block);
		best = 0;
		search(0);
		cout << best << '\n';
		rotations.clear();
		covered.clear();
	}
}