#include <bits/stdc++.h>
using namespace std;

// ����a������b�ĳ���
int lena, lenb;

// �ϲ�������������
void merge(int* a, int* b, int* c) {
    // ��������ָ�룬�ֱ�ָ������a������b������c
    int pa = 0, pb = 0, pc = 0;
    while (pc < lena + lenb) {
        // �������a�Ѿ���ɨ���꣬��������b�ĵ�ǰԪ�ر�����a�ĵ�ǰԪ��С��
        // ������b�ĵ�ǰԪ�ؼ�������c������ָ������b��ָ��pb��1
        if (pa >= lena || (pb < lenb && a[pa] >= b[pb])) {
            c[pc++] = b[pb];
            pb++;
        }
        // ���򣬽�����a�ĵ�ǰԪ�ؼ�������c������ָ������a��ָ��pa��1
        else if (pb >= lenb || (pa < lena && a[pa] <= b[pb])) {
            c[pc++] = a[pa];
            pa++;
        }
    }
}

int main() {
    // ��������a������b�ĳ���
    cin >> lena >> lenb;

    // ��������a������b�����������ǵ�Ԫ��
    int a[lena], b[lenb];
    for (int i = 0; i < lena; i++) cin >> a[i];
    for (int i = 0; i < lenb; i++) cin >> b[i];

    // ����c���ڴ�źϲ������������
    int c[lena + lenb];

    // ����merge������������a������b�ϲ�Ϊ����c
    merge(a, b, c);
    for (int i = 0; i < lena + lenb; i++) cout << c[i] << " ";

    return 0;
}
