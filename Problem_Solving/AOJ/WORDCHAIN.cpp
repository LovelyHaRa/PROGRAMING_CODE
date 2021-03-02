#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// �׷����� ���� ��� ǥ��, adj[i][j]=i�� j������ ������ ��
vector<vector<int>> adj;
// graph[i][j]=i�� �����ؼ� j�� ������ �ܾ��� ���
vector<string> graph[26][26];
// indegree[i]=i�� �����ϴ� �ܾ��� ��
// outdegree[i]=i�� ������ �ܾ��� ��
vector<int> indegree, outdegree;
// �׷��� ����
void makeGraph(const vector<string>& words)
{
	// ���� ���� �ʱ�ȭ
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			graph[i][j].clear();
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = outdegree = vector<int>(26, 0);
	// �� �ܾ �׷����� ������Ŀ� ǥ���Ѵ�
	for (int i = 0; i < words.size(); i++)
	{
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]); // �׷����� �ܾ� �߰�
		// ���� ��Ŀ� ǥ��
		adj[a][b]++;
		// ���� ����
		outdegree[a]++;
		indegree[b]++;
	}
}

// DFS�� �̿��Ͽ� ���Ϸ� ��Ŷ Ȥ�� Ʈ������ ����Ѵ�
void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < adj.size(); there++)
		while (adj[here][there] > 0)
		{
			adj[here][there]--; // ������ �ϳ� �����
			getEulerCircuit(there, circuit);
		}
	circuit.push_back(here); // ��Ŷ�� ������ �߰��Ѵ�
}

// ���� �׷����� ���Ϸ� Ʈ�����̳� ��Ŷ�� ��ȯ�Ѵ�
vector<int> getEulerTrailOrCircuit()
{
	vector<int> circuit;
	// 1. Ʈ���� Ȯ��
	for (int i = 0; i < 26; i++)
	{
		// Ʈ���� ����: ������ ������ ���� ������ ������ ������ �ϳ� �� ���ƾ��Ѵ�
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	// 2. Ʈ������ �ƴϸ� ��Ŷ�̹Ƿ� ������ ������ �ƹ� �������� ����
	for (int i = 0; i < 26; i++)
	{
		if (outdegree[i])
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	return circuit;
}

// ���� �׷����� ���Ϸ� ��Ŷ/Ʈ���� ���� ���θ� Ȯ���Ѵ�
bool checkEuler()
{
	// ���� �������� ������ ��
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++)
	{
		int delta = outdegree[i] - indegree[i];
		// ��� ������ ������ -1, 1 �Ǵ� 0�̾�� �Ѵ�
		if (delta < -1 || delta > 1) return false;
		if (delta == 1) plus1++;
		if (delta == -1) minus1++;
	}
	// �������� ������ �� �ϳ��� �ְų� �ϳ��� ����� �Ѵ�
	return (plus1 == 1 && minus1 == 1) || (!plus1 && !minus1);
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++)
			cin >> words[i];
		makeGraph(words);
		// ���Ϸ� ��Ŷ/Ʈ������ �������� ������ �Ұ���
		if (!checkEuler())
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<int> circuit = getEulerTrailOrCircuit();
		// ������Ʈ�� �������̸� �Ұ���
		// ��� ������ �湮�ߴ��� Ȯ�� �ʿ�
		if (circuit.size() != words.size() + 1)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		// ���� �׷����̹Ƿ� Ž�� ����� ������
		reverse(circuit.begin(), circuit.end());
		for (int i = 1; i < circuit.size(); i++)
		{
			int a = circuit[i - 1], b = circuit[i];
			cout << graph[a][b].back() << ' ';
			graph[a][b].pop_back();
		}
		cout << '\n';
	}
}