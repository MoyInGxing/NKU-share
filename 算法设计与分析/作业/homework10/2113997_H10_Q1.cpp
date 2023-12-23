#include <bits/stdc++.h>
using namespace std;

// �����������ڵ�ṹ��
struct Node {
    int lv; // ��ǰ�㼶
    vector<int> assign; // ����Ŀγ�
    int tt; // �ܱ���ʱ��
    int lb; // ���ű߽�
    bool operator<(const Node &other) const {
        return lb > other.lb;
    }
};

// ���γ��Ƿ��Ѿ������
bool check(const Node &node, int course){
    for (size_t i = 0; i < node.assign.size(); i++) {
        if (node.assign[i] == course) {
            return false;
        }
    }
    return true;
}

// �������ű߽�ĺ���
// ���ű߽�Lb = �ѷ�������Ĵ��� + ʣ��δ������������С�Ĵ���
int calc_lb(const Node &node, const vector<vector<int>> &prep_time) {
    int min_time = 0;
    for (size_t t = node.lv; t < prep_time.size(); t++) {
        int min_t = INT_MAX;
        for (size_t c = 0; c < prep_time.size(); c++) {
            if (check(node, c)) { //�Ѿ�������Ŀγ̲��ټ���
                min_t = min(min_t, prep_time[t][c]);
            }
        }
        min_time += min_t;
    }
    return node.tt + min_time;
}

int main() {
    // ����ʱ������
    vector<vector<int>> prep_time = {
        {2, 10, 9, 7},
        {15, 4, 14, 8},
        {13, 14, 16, 11},
        {4, 15, 13, 9},
    };

    int n = prep_time.size();

    // ���ȶ��У������ű߽�����
    priority_queue<Node> pq;
    Node root{0, vector<int>(n, -1), 0, 0};
    root.lb = calc_lb(root, prep_time);
    pq.push(root);
    int min_time = INT_MAX;
    vector<int> best_assign;

    // ��֧�޽�����
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        // ����Ҷ�ӽڵ㣬�������Ž�
        if (cur.lv == n) {
            if (cur.tt < min_time) {
                min_time = cur.tt;
                best_assign = cur.assign;
            }
            continue;
        }

        // ��չ�ӽڵ�
        for (int c = 0; c < n; c++) {
            if (check(cur, c)) {
                Node nxt = cur;
                nxt.lv++;
                nxt.assign[cur.lv] = c;
                nxt.tt += prep_time[cur.lv][c];
                nxt.lb = calc_lb(nxt, prep_time);
                if (nxt.lb < min_time) {
                    pq.push(nxt);
                }
            }
        }
    }

    // ������
    cout << "��С����ʱ��: " << min_time << endl;
    cout << "�γ̷���: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "��ʦ" << char('A' + i) << " -> �γ�" << best_assign[i] + 1 << endl;
    }
    cout << endl;
    return 0;
}
