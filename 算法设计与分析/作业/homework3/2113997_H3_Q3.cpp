#include <bits/stdc++.h> 
#define MAXN 10000 // ������Ϊ 10000
using namespace std;

vector<int> G[MAXN]; // ʹ���ڽӱ�洢ͼ
int color[MAXN]; // color �������ڼ�¼ÿ�������ɫ��-1 ��ʾ��ɫ��1 ��ʾ��ɫ

bool bfs(int s){ // ���� bfs ������s ��ʾ���
    queue<int> que; // ����que���ڴ洢�������Ľڵ�
    que.push(s); // �����������
    color[s] = 1; // ���ȾΪ��ɫ
    while(!que.empty()){ 
        int cur = que.front(); 
        que.pop(); 
        for(int& to:G[cur]){ // ö�� cur �������ھ� to
            if(!color[to]){ // ��� to ��û�б�Ⱦɫ
                color[to] = -color[cur]; // �� to Ⱦ���� cur ��ͬ����ɫ
                que.push(to); // �� to �������
            }
            else if(color[to] == color[cur]){ // ��� to �� cur ����ɫ��ͬ��˵�����Ƕ���ͼ
                return false; // ���� false
            }
        }
    }
    return true; // ����ܹ����������нڵ㣬˵���Ƕ���ͼ������ true
}

int main(){
    int n, m, u, v; // n ��ʾ������m ��ʾ������u, v ��ʾһ���ߵ������˵�
    cin>>n>>m; // ��������ͱ���
    for(int i=0;i<m;i++){ 
        cin>>u>>v;
        G[u].push_back(v); 
        G[v].push_back(u); 
    }
    bool flag = bfs(1); // �� 1 �ŵ㿪ʼ bfs���ж��Ƿ��Ƕ���ͼ
    if(flag) cout<<"Yes"; // ����Ƕ���ͼ����� Yes
    else cout<<"No"; // ������Ƕ���ͼ����� No
    return 0; 
}
