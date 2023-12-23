#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int a[MAXN], t[MAXN], cnt;

// �鲢�����������鲢�������������
void Mergearr(int* a, int begin, int mid, int end, int* t){
    int i = begin, j = mid + 1, k = begin;
    while(i <= mid && j <= end){
        if(a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++], cnt += mid - i + 1; // ���a[i] > a[j]����a[i...mid]����a[j]���������������mid-i+1
    }
    // ����whileѭ��ֻ��ִ��һ��
    while(i <= mid) t[k++] = a[i++]; // ��ʣ��Ԫ�ط�������
    while(j <= end) t[k++] = a[j++]; // ��ʣ��Ԫ�ط�������
    for(int i = begin; i <= end; i++) a[i] = t[i]; // ���ź����Ԫ�طŻ�ԭ����
}

// �鲢���򲢼������������
void Mergesort(int* a, int begin, int end, int* t){
    if(begin >= end) return; // ���鳤��Ϊ1ʱ��ֱ�ӷ���
    int mid = (begin + end) / 2; // �����м�λ��
    Mergesort(a, begin, mid, t); // �ݹ鴦����벿��
    Mergesort(a, mid + 1, end, t); // �ݹ鴦���Ұ벿��
    Mergearr(a, begin, mid, end, t); // �ϲ����������ֲ��������������
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    Mergesort(a, 0, n - 1, t); // �鲢���򲢼������������
    cout << cnt; // ������������
    return 0;
}
