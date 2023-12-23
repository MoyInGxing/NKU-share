#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

// ���峣��
const int MAXN = 1e5; // ���ڵ���
const int INF = 0x3FFFFFFF; // ����һ���������Ϊ��ʼ����
int dis[MAXN]; // ����ÿ���ڵ㵽Դ�ڵ����̾���
bool vis[MAXN]; // ���һ���ڵ��Ƿ��Ѿ�������

vector<pii> G[MAXN]; // �ڽӱ��ʾ����ͼ������ÿ���ڵ�����ڽڵ㼰�ߵ�Ȩ��

// Dijkstra�㷨ʵ��
void dijkstra(int n, int s) {
    priority_queue<pii, vector<pii>, greater<pii>> que; // ʹ�����ȶ��У�ÿ��ѡȡ������С�Ľڵ�
    for (int i = 1; i <= n; i++) dis[i] = INF; // ��ʼ�����нڵ㵽Դ�ڵ�ľ���Ϊ�����
    dis[s] = 0; // Դ�ڵ㵽����ľ���Ϊ0
    que.push({0, s}); // ��Դ�ڵ�������ȶ���
    while (!que.empty()) {
        int cur = que.top().second; // ��ȡ��ǰ������С�Ľڵ�
        que.pop(); // ���ڵ�Ӷ������Ƴ�
        if (vis[cur]) continue; // ����ڵ��ѷ��ʣ������ýڵ�
        vis[cur] = true; // ��ǽڵ�Ϊ�ѷ���
        for (pii& nd : G[cur]) { // ������ǰ�ڵ�����ڽڵ�
            int to = nd.second, w = nd.first; // ��ȡ���ڽڵ㼰�ߵ�Ȩ��
            if (dis[to] > dis[cur] + w) { // �ж��Ƿ��ҵ��˸��̵�·��
                dis[to] = dis[cur] + w; // ������̾���
                if (!vis[to]) que.push({dis[to], to}); // ������ڽڵ�δ���ʣ�����������ȶ���
            }
        }
    }
}

int main() {
    int n, m, s, u, v, w;
    cin >> n >> m >> s; // ��ȡ���룺�ڵ���n������m��Դ�ڵ�s
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w; // ��ȡ�ߵ���Ϣ����ʼ�ڵ�u����ֹ�ڵ�v���ߵ�Ȩ��w
        G[u].push_back({w, v}); // ������ӵ��ڽӱ�
    }
    dijkstra(n, s); // ִ��Dijkstra�㷨
    for (int i = 1; i <= n; i++) cout << dis[i] << " "; // ���ÿ���ڵ㵽Դ�ڵ����̾���
    return 0;
}
