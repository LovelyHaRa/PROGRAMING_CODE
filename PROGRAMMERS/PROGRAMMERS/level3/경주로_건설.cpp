#include <string>
#include <vector>
#include <queue>

using namespace std;

// ť�� ������ ���� ����
struct Road {
    int x, y, cost, dir; // ��ǥ, �������� ��ġ�� ���, ����(0, 1, 2, 3)
    // ������
    Road(int _x, int _y, int _cost, int _dir) : x(_x), y(_y), cost(_cost), dir(_dir) {}
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> build(n, vector<int>(n)); // build[x][y]: (x, y)���� �Ǽ��� �ּ� ���
    int dx[] = { -1,0,0,1 }, dy[] = { 0,-1,1,0 }; // �����¿� �̵� ������
    // �ʱ� ť ����
    queue<Road> q;
    Road road(0, 0, 0, -1); // ���������� ���� ���� ���� �����̱� ������ ���ܷ� �Ѵ�
    q.push(road);
    // BFS Ž��
    while (!q.empty()) {
        // ť���� ����
        Road curRoad = q.front();
        q.pop();
        // �����¿� �̵�
        for (int i = 0; i < 4; i++) {
            // ���� ��ǥ
            int nx = curRoad.x + dx[i], ny = curRoad.y + dy[i];
            // ���� ��ǥ������ ��ġ ���
            int nextCost = curRoad.cost;
            // ������ ����ų� ���� ��� �ǳʶٱ�
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny]) continue;
            // �������̰ų�, ������ ���� ���
            if (curRoad.dir == -1 || curRoad.dir == i) {
                nextCost += 100;
            }
            // ������ �ٸ� ���(������, ��, ��)
            else if (curRoad.dir != i) {
                nextCost += 600;
            }
            // ó�� �湮 �ϰų� ���� �Ǽ��� ����� ���� ���� ��뺸�� ��� ���
            if (!build[nx][ny] || build[nx][ny] >= nextCost) {
                build[nx][ny] = nextCost; // ��� ����
                // ť�� �߰�
                Road nextRoad(nx, ny, nextCost, i);
                q.push(nextRoad);
            }
        }
    }
    return build[n - 1][n - 1];
}