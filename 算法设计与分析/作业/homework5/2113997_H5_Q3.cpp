#include <bits/stdc++.h>
#define MAXN 10000
#define pii pair<int, int>
using namespace std;

const int INF = 0x3FFFFFFF;
vector<pii> G[MAXN]; // �ڽӱ��ʾ����ͼ������ÿ���ڵ�����ڽڵ㼰�ߵ�Ȩ��
int dis[MAXN], ans; // dis���鱣��ÿ���ڵ㵽��ѡ�ڵ㼯�ľ��룬ans��¼��С�������ı�Ȩ��
bool vis[MAXN]; // ���һ���ڵ��Ƿ��Ѿ�������

// Prim�㷨ʵ��
void Prim(int n, int s) {
	priority_queue<pii, vector<pii>, greater<pii>> que; // ʹ�����ȶ��У�ÿ��ѡȡ������С�Ľڵ�
	for (int i = 1; i <= n; i++) dis[i] = INF; // ��ʼ�����нڵ㵽��ѡ�ڵ㼯�ľ���Ϊ�����
	dis[s] = 0;
	que.push({0, s}); // ����ʼ�ڵ�������ȶ���
	while (!que.empty()) {
		int cur = que.top().second, len = que.top().first; // ��ȡ��ǰ������С�Ľڵ㼰����
		que.pop(); // ���ڵ�Ӷ������Ƴ�
		if (vis[cur]) continue; // ����ڵ��ѷ��ʣ������ýڵ�
		vis[cur] = true; // ��ǽڵ�Ϊ�ѷ���
		ans += len; // �ۼӱ�Ȩ
		for (pii& nd : G[cur]) { // ������ǰ�ڵ�����ڽڵ�
			int to = nd.second, w = nd.first; // ��ȡ���ڽڵ㼰�ߵ�Ȩ��
			if (dis[to] > w) { // �ж��Ƿ��ҵ��˸��̵ľ���
				dis[to] = w; // ���¾���
				if (!vis[to]) que.push({dis[to], to}); // ������ڽڵ�δ���ʣ�����������ȶ���
			}
		}
	}
}

int main() {
	int u, v, w, n, m;
	cin >> n >> m; // ��ȡ���룺�ڵ���n������m
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w; // ��ȡ�ߵ���Ϣ����ʼ�ڵ�u����ֹ�ڵ�v���ߵ�Ȩ��w
		G[u].push_back({w, v}); // ������ӵ��ڽӱ�
		G[v].push_back({w, u}); // ��Ϊ������ͼ����Ҫ������������ӱ�
	}
    Prim(n, 1); // ִ��Prim�㷨���ӽڵ�1��ʼ
	cout << ans; // �����С�������ı�Ȩ��
	return 0;
}
