#include <bits/stdc++.h>
using namespace std;

// ���ֲ��Һ���
int binary_search(int* a, int val, int start, int end) {
    // �����ʼ�±���ڽ����±꣬�����û���ҵ�������-1
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (val == a[mid]) return mid;
    // ����м�ֵ����Ҫ���ҵ�ֵ��������벿�ּ�������
    else if (val < a[mid]) return binary_search(a, val, start, mid - 1);
    // ����м�ֵС��Ҫ���ҵ�ֵ�������Ұ벿�ּ�������
    else return binary_search(a, val, mid + 1, end);
}

int main() {
    // ����һ������Ϊ10����������a��Ҫ���ҵ�ֵx
    int a[10], x;
    for (int i = 0; i < 10; i++) cin >> a[i];
    cin >> x;
    int place = binary_search(a, x, 0, 9);
    cout << place;

    return 0;
}
