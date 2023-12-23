#include <bits/stdc++.h>
using namespace std;

// ��Ʒ�ṹ��
struct Item {
    int value, weight; // ��ֵ������
    double value_weight_ratio; // ��ֵ-������
};

// �������ڵ�ṹ��
struct Node {
    int level; // ��ǰ�ڵ����ڲ㼶
    int value; // ��ѡ����Ʒ�ܼ�ֵ
    int weight; // ��ѡ����Ʒ������
    double ub; // �Ͻ�
    bool operator<(const Node &other) const { // ����<��������������ȶ�������
        return ub < other.ub;
    }
};

// ����ֵ-�����Ƚ���������
bool cmp(const Item &a, const Item &b) {
    return a.value_weight_ratio > b.value_weight_ratio;
}

// �����Ͻ纯��
double get_ub(int level, int weight, int value, int capacity, vector<Item> &items) {
    if (weight >= capacity) {
        return value;
    }
    double max_ratio = 0;
    for (size_t i = level + 1; i < items.size(); i++) {
        max_ratio = max(max_ratio, items[i].value_weight_ratio);
    }
    double ub = value + (capacity - weight) * max_ratio;
    return ub;
}


// 0-1����������⺯��
int knapsack(int capacity, vector<Item> &items) {
    // ���ݼ�ֵ-������������Ʒ
    sort(items.begin(), items.end(), cmp);
    int n = items.size();
    int max_value = 0; // ��¼����ֵ
    priority_queue<Node> pq; // ���ȶ��У����Ͻ罵������

    // ��ʼ�����ڵ�
    Node root;
    root.level = -1;
    root.value = 0;
    root.weight = 0;
    root.ub = get_ub(root.level, root.weight, root.value, capacity, items);
    pq.push(root);

    // ��֧�޽�����
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // �����ǰ�ڵ���Ҷ�ӽڵ㣬����
        if (current.level == n - 1) continue;

        // �������ӽڵ㣨ѡ��ǰ��Ʒ��
        Node left = current;
        left.level++;
        left.weight += items[left.level].weight;
        left.value += items[left.level].value;
        left.ub = get_ub(left.level, left.weight, left.value, capacity, items);

        // ������ӽڵ����㱳����������
        if (left.weight <= capacity) {
            // ��������ֵ
            if (left.value > max_value) {
                max_value = left.value;
            }
            // ������ӽڵ��Ͻ���ڵ�ǰ����ֵ���������ȶ���
            if (left.ub > max_value) {
                pq.push(left);
            }
        }

        // �������ӽڵ㣨��ѡ��ǰ��Ʒ��
        Node right = current;
        right.level++;
        right.ub = get_ub(right.level, right.weight, right.value, capacity, items);

        // ������ӽڵ��Ͻ���ڵ�ǰ����ֵ���������ȶ���
        if (right.ub > max_value) {
            pq.push(right);
        }
    }
    return max_value;
}

int main() {
    int capacity, n;
    vector<Item> items;
    printf("�����뱳������: ");
    scanf("%d", &capacity);
    printf("��������Ʒ����: ");
    scanf("%d", &n);
    printf("������������Ʒ��Ϣ: \n");
    for(int i = 0; i < n; i++){
        int w, v; 
        double r;
        printf("-----��Ʒ%d-----\n", i+1);
        printf("��ֵ: "); scanf("%d", &v);
        printf("����: "); scanf("%d", &w);
        r = v / w;
        items.push_back({v, w, r});
    }
    int max_value = knapsack(capacity, items);
    cout << "����ֵΪ: " << max_value << endl;
    return 0;
}
