#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int toNumber(char c) { return c - 'A'; }
const int ALPHABETS = 26;
// Ʈ������ �� ��带 ��Ÿ���� ��ü
struct TrieNode {
	TrieNode* children[ALPHABETS];
	// �� ��忡�� �����ϴ� ���ڿ��� ��ȣ. ������ -1
	int terminal;
	// �� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���� ���� �߰��� �ܾ��� ��ȣ. -1�� �ʱ�ȭ
	int first;
	TrieNode() : terminal(-1), first(-1) { memset(children, 0, sizeof(children)); }
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}
	// �� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ��ȣ id�� ���ڿ� key�� �߰��Ѵ�
	void insert(const char* key, int id) {
		// first�� �켱 ����
		if (first == -1) first = id;
		// ���ڿ��� �����ٸ� terminal�� �ٲٰ� ����
		if (*key == 0)
			terminal = id;
		else {
			int next = toNumber(*key);
			// �ش� �ڽ� ��尡 ���ٸ� �����Ѵ�.
			if (children[next] == NULL)
				children[next] = new TrieNode();
			// �ش� �ڽ� ���� ��� ȣ��
			children[next]->insert(key + 1, id);
		}
	}
	// �� ��带 ��Ʈ�� �ϴ� Ʈ���̿� ���ڿ� key�� �����Ǵ� ��带 ã�´�
	// ������ NULL�� ��ȯ
	TrieNode* find(const char* key) {
		// ���ڿ� ���� ��
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
	// �� ������ Ÿ���� �ؿ��� ��, ��ȣ id�� eky�� Ÿ���� �ϱ� ����
	// �ּ� �� ���� Ű�� �� ������ �ϳ�?
	int type(const char* key, int id) {
		// ���ڿ� ���� ��
		if (*key == 0) return 0;
		//�� ��忡�� ��õ�Ǵ� ���ڿ��� �� ���ڿ��̸� �� ������ ����
		if (first == id) return 1;
		// �ƴϸ� ���� ���ڸ� Ÿ���� �Ѵ�
		int next = toNumber(*key);
		return 1 + children[next]->type(key + 1, id);
	}
};
// ������ ��Ÿ���� Ʈ���̰� �־��� ��, �ܾ� word�� Ÿ�����ϴ� ��
// �� ���̳� Ű�� ������ �ϴ��� ����Ѵ�
int countKeys(TrieNode* trie, const char* word) {
	// �� ���ڿ��� ������ �ִ��� Ȯ���ϰ�,�ִٸ� ��ȣ�� ���Ѵ�.
	TrieNode* node = trie->find(word);
	// ������ ������ ���� Ÿ����
	if (node == NULL || node->terminal == -1) return strlen(word);
	// Ž���ϸ鼭 Ÿ������ ����� ã�´�
	return trie->type(word, node->terminal);
}
// �Է¿� �־����� �ܾ���� �����ؼ� Ʈ���̷� ��ȯ�Ѵ�
TrieNode* readInput(int words)
{
	// �ܾ���� ���� ���� ��������, �ܾ��� ������������ ����
	vector<pair<int, string>> input;
	for (int i = 0; i < words; i++) {
		char buf[11];
		int freq;
		scanf("%s %d", buf, &freq);
		input.push_back(make_pair(-freq, buf));
	}
	sort(input.begin(), input.end());
	// �迭�� �ε����� �� �ܾ��� ��ȣ�� ���
	TrieNode* trie = new TrieNode();
	for (int i = 0; i < input.size(); i++)
		trie->insert(input[i].second.c_str(), i);
	trie->first = -1;
	return trie;
}

int main(void)
{
	int c; 
	scanf("%d", &c);
	while (c--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		TrieNode* trie = readInput(n);
		int res = 0; // Ÿ���� Ƚ�� ī����
		for (int i = 0; i < m; i++) {
			char word[11];
			scanf("%s", word);
			res += countKeys(trie, word);
		}
		res += (m - 1); // ���� Ƚ�� �߰�
		printf("%d\n", res);
	}
}