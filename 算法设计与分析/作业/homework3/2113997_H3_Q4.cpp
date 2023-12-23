#include <bits/stdc++.h>  
#define MAXN 10000         // �������ڵ���
using namespace std;

vector<int> G[MAXN];       // �洢����ͼ���ڽӱ�
int ind[MAXN];             // �洢ÿ���ڵ�����

void Topo(int n){
    priority_queue<int, vector<int>, greater<int>> que;  // ���ڴ洢��ǰ���Ϊ 0 �Ľڵ�����ȶ���
    for(int i=0;i<n;i++){
        if(!ind[i]) que.push(i);  // �����Ϊ 0 �Ľڵ���������
    }
    while(!que.empty()){
        int cur = que.top(); 
        que.pop();
        cout<<cur<<" ";      // ����ýڵ�
        for(int& to:G[cur]){  // �����Ըýڵ�Ϊ�������б�
            if(!--ind[to]) que.push(to);  // ����ȱ�Ϊ 0 �Ľڵ���������
        }
    }
}

int main(){
    int n, m, u, v;
    cin>>n>>m;               // ����ڵ����ͱ���
    for(int i=0;i<m;i++){
        cin>>u>>v;           // ����һ���ߵ������յ�
        G[u].push_back(v);   // �ѱ߼�������ͼ��
        ind[v]++;            // ά��ÿ���ڵ�����
    }
    Topo(n);                 // ������������
    return 0;
}
