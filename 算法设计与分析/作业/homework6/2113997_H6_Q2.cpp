#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAXN 100050
using namespace std;

int pa[MAXN], fre[MAXN]; // pa[i]��ʾ�ڵ�i�ĸ��ڵ㣬fre[i]��ʾ�ڵ�i��Ƶ��
priority_queue<pii, vector<pii>, greater<pii>> que; // �洢Ƶ�ʵ�С����

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> fre[i];
        pa[i] = i; // ��ʼ��ÿ���ڵ�ĸ��ڵ�Ϊ������
        que.push({fre[i], i}); // ���ڵ����С����
    }
    int r = n; // ��¼�����ɵĽڵ���
    while(que.size() > 1){
        pii n1 = que.top(); // ȡ��Ƶ����С�Ľڵ�
        que.pop();
        pii n2 = que.top(); // ȡ��Ƶ�ʴ�С�Ľڵ�
        que.pop();
        pa[n1.second] = pa[n2.second] = pa[r] = r; // �������ڵ���½ڵ�ϲ�
        que.push({n1.first + n2.first, r}); // ���½ڵ����С������
        r++; // �����½ڵ�ı��
    }
    int wl = 0, sumw = 0; // wl��ʾ����Huffman���볤��֮�ͣ�sumw��ʾ�����ַ�Ƶ��֮��
    for(int i = 0;i < n;i++){
        int cur = i, len = 0;
        while(pa[cur] != cur){ // �������ϲ��Ҹ��ڵ㣬ֱ�����ڵ�Ϊֹ
            cur = pa[cur];
            len++;
        }
        wl += fre[i] * len; // ���㵱ǰ�ַ��ı��볤��
        sumw += fre[i]; // ͳ�������ַ�Ƶ��֮��
    }
    printf("%.2f", double(wl)/sumw); // ���ƽ�����볤��
    return 0;
}
