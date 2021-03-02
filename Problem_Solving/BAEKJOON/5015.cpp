#include<iostream>
#include<string>
#include<vector>

using namespace std;

string w;

bool matchMemorize(vector<vector<int>>& cache, const string& s, int wpos, int spos)
{
	// �޸����̼�
	int& ret = cache[wpos][spos];
	if (ret != -1) return ret;
	// ���ϰ� ���ڿ� ��Ī
	while (wpos < w.size() && spos < s.size() && (w[wpos] == '?' || w[wpos] == s[spos]))
		return ret = matchMemorize(cache, s, wpos + 1, spos + 1);
	// ������ ������ ��� ���ڿ��� ���� ������ true
	if (wpos == w.size()) return ret = (spos == s.size());
	// ������ *�� ��� ���� ���ڸ� �����ϴ� �Ͱ� �ǳʶٴ� �� �ΰ����� ���Ž�� �Ͽ� 
	// �� �� �ϳ��� true�� ��ȯ�ϸ� true
	if (w[wpos] == '*')
		return ret = (matchMemorize(cache, s, wpos + 1, spos) || (spos < s.size() && matchMemorize(cache, s, wpos, spos + 1)));
	// �� ���� ��� false
	return ret = false;
}

int main(void)
{	
	cin >> w;
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		vector<vector<int>> cache(101, vector<int>(101, -1)); // ĳ��
		if (matchMemorize(cache, s, 0, 0)) cout << s << '\n';
	}
}