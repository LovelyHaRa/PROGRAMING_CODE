#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
// -1 : ���� ��� �ȵ�
// 1: �ش� �Էµ��� ���� ������
// 0: �ش� �Էµ��� ���� �������� ����
bool matchMemoized(vector<vector<int>>& cache, const string& w, const string& s, int wpos, int spos)
{
	// �޸������̼�
	int& ret = cache[wpos][spos];
	if (ret != -1) return ret;
	// w[wpos]�� s[spos]�� ���糪����
	while (wpos < w.size() && spos < s.size() && (w[wpos] == '?' || w[wpos] == s[spos]))
	{
		wpos++;
		spos++;
	}
	// 1. w[wpos]�� s[spos] �� �������� �ʴ´�: return false
	// 2. ���� ���� �����ؼ� ���� ���(wpos==w.size()): s�� ������� true
	if (wpos == w.size()) return ret = (spos == s.size());
	// 3. s�� ���� �������� ���: ���� ������ *�� ��� true�� ���� �����Ƿ� 4���� ó��
	// 4. w[wpos]=='*' �� ���: 0���� s.size()-1 ���� �ݺ��ϴ� skip�� ����
	//                          wpos+1������ ���ϰ� spos+skip ������ ���ؼ� �ϳ��� true�̸� ture ����
	if (w[wpos] == '*')
		for (int skip = 0; skip+spos <= s.size(); skip++)
			if (matchMemoized(cache, w, s, wpos + 1, spos + skip)) return ret = 1;
	// �� ���� ��� false ����
	return ret = 0;
}

int main(void)   
{
	int c;
	cin >> c;
	while (c--)
	{
		string w;
		cin >> w;
		int n;
		cin >> n;
		vector<string> res;
		while (n--)
		{
			string s;
			cin >> s;
			vector<vector<int>> cache(101, vector<int>(101, -1)); // ĳ��, -1�� �ʱ�ȭ
			if (matchMemoized(cache, w, s, 0, 0)) res.push_back(s);
		}
		sort(res.begin(), res.end()); // ����
		for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';

	}
}