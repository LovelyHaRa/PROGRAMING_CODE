#include <string>
#include <vector>
#include <queue>

using namespace std;
// �켱 ���� ť�� ���� ���
struct qnode {
    int x, y, num; // ��ǥ, ����ȣ
};

// �켱 ���� �� ����ü
struct compare {
    bool operator()(qnode& a, qnode& b) {
        // y��ǥ�� �Ȱ��ٸ�
        if (a.y == b.y) {
            return a.x > b.x; // x��ǥ ��������
        }
        // y��ǥ ��������
        return a.y < b.y;
    }
};

// Ʈ�� ��� ����ü
struct TreeNode {
    int num, x;
    TreeNode* left, * right;
};

// ���� Ʈ�� tree�� ���� ��� curNode�� ����
void insert(TreeNode* tree, TreeNode* curNode) {
    // ���� ��尡 ����ְ� x��ǥ ���� ���� ��
    if (tree->left == NULL && tree->x > curNode->x) {
        tree->left = curNode; // ���� ��忡 ���� ��� ����
    }
    // ���� ��尡 ������� �ʰ� x��ǥ ���� ���� ��
    else if (tree->left != NULL && tree->x > curNode->x) {
        insert(tree->left, curNode); // ���� ���� �̵�
    }
    // ������ ��尡 ����ְ� x��ǥ ���� Ŭ ��
    else if (tree->right == NULL && tree->x < curNode->x) {
        tree->right = curNode; // ������ ��忡 ���� ��� ����
    }
    // ������ ��尡 ������� �ʰ� y��ǥ ���� Ŭ ��
    else if (tree->right != NULL && tree->x < curNode->x) {
        insert(tree->right, curNode);
    }
}

vector<vector<int>> answer;

// ���� ��ȸ
void preorder(TreeNode* tree) {
    if (tree == NULL) return;
    answer[0].push_back(tree->num);
    preorder(tree->left);
    preorder(tree->right);
}

// ���� ��ȸ
void postorder(TreeNode* tree) {
    if (tree == NULL) return;
    postorder(tree->left);
    postorder(tree->right);
    answer[1].push_back(tree->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    answer.resize(2); // ������ȸ, ������ȸ ��� ���� ���� �����
    // 1. �켱 ���� ť�� ��� �ֱ�
    priority_queue<qnode, vector<qnode>, compare> pq;
    for (int i = 0; i < nodeinfo.size(); i++) {
        qnode qn;
        qn.x = nodeinfo[i][0];
        qn.y = nodeinfo[i][1];
        qn.num = i + 1;
        pq.push(qn);
    }
    // 2. Ʈ�� ����
    // Ʈ�� ��Ʈ ����
    TreeNode* tree = new TreeNode();
    qnode topNode = pq.top();
    tree->num = topNode.num;
    tree->x = topNode.x;
    pq.pop();
    // Ʈ���� ��� ������� ����
    while (!pq.empty()) {
        topNode = pq.top();
        pq.pop();
        TreeNode* curNode = new TreeNode();
        curNode->num = topNode.num;
        curNode->x = topNode.x;
        insert(tree, curNode);
    }
    // 3. ���� ��ȸ, ���� ��ȸ
    preorder(tree);
    postorder(tree);
    return answer;
}