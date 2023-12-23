#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int df[MAXN], ra[MAXN];

// ���鼯����
int find(int x) { 
    // ���x���丸�ڵ㣬��ֱ�ӷ���x������ͨ��·��ѹ����x�ĸ��ڵ�ֱ��ָ����ڵ�
    return x == df[x] ? x : df[x] = find(df[x]); 
}

// ���鼯�ϲ�
inline void merge(int a, int b) {
    // �ҵ�a��b�ĸ��ڵ�
    int x = find(a), y = find(b);
    if (x == y) return;
    // ���x���ȱ�y����y�ϲ���x������
    if (ra[x] > ra[y]) df[y] = x;
    // ���y���ȱ�x����x�ϲ���y������
    else if (ra[x] < ra[y]) df[x] = y;
    // ���x��y������ͬ����x�ϲ���y�����У�ͬʱy���ȼ�1
    else { df[x] = y; ra[y]++; }
}

// �洢�ߵĽṹ�壬������㡢�յ�ͱ�Ȩ��
struct Edge {
    int u; // ���
    int v; // �յ�
    int w; // ��Ȩ��
    Edge(int u = 0, int v = 0, int w = 1) :u(u), v(v), w(w) {} // ���캯��
    bool operator<(const Edge& a)const { return w > a.w; } // �������������������
};

priority_queue<Edge> que; // �洢�ߵ����ȶ���

// ��С������Kruskal�㷨
int kruskal(int n) {
    // ��ʼ�����鼯
    for (int i = 1; i <= n; i++) { df[i] = i; ra[i] = 1; }
    int ans = 0;
    // ����ȡ����С�߽��кϲ�
    while (!que.empty()) {
        Edge ed = que.top();
        que.pop();
        // ��������˵��Ѿ���ͬһ����ͨ������������ٺϲ�
        if (find(ed.u) == find(ed.v)) continue;
        merge(ed.u, ed.v);
        ans += ed.w; // ͳ����С�������ı�Ȩ�غ�
    }
    return ans; // ������С�������ı�Ȩ�غ�
}

int main() {
    int n, m, u, v, w, ans;
    cin >> n >> m;
    // ����ߵ���Ϣ���������ȶ�����
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        que.push(Edge(u, v, w));
    }
    ans = kruskal(n); 
	cout << ans; // �����С�������ı�Ȩ�غ�
	return 0;
}

