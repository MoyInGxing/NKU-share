#include <bits/stdc++.h>   
#define MAXN 10000          //�������ڵ���Ϊ10000
using namespace std;

vector<int> G[MAXN];        //�����ڽӱ�G
bool vis[MAXN];             //����������vis

void bfs(int s){            //���������������
    queue<int> que;         //������У��������������
    que.push(s);
    while(!que.empty()){    
        int cur = que.front();  
        que.pop();              
        if(vis[cur]) continue;  //����ýڵ��Ѿ������ʹ�����������ѭ��
        vis[cur] = true;        //��Ǹýڵ��ѱ����ʹ�
        cout<<cur<<" ";         
        for(int& to:G[cur]){    //�����ýڵ������ڽӽڵ�
            if(!vis[to]) que.push(to); //����ڽӽڵ�δ�����ʹ����������
        }
    }
}

void dfs(int s){            //���������������
    cout<<s<<" ";           //����ýڵ�
    vis[s] = true;          //��Ǹýڵ��ѱ����ʹ�
    for(int& to:G[s]){      //�����ýڵ������ڽӽڵ�
        if(!vis[to]) dfs(to);   //����ڽӽڵ�δ�����ʹ����ݹ�����
    }
}

int main(){             
    int n, m, s, u, v;      
    cin>>n>>m>>s;       //����ڵ��������������
    for(int i=0;i<m;i++){       //����ߵ������˵�
        cin>>u>>v;
        G[u].push_back(v);      //���������
        G[v].push_back(u);
    }
    for(int i=0;i<n;i++){       //����ÿ���ڵ㣬���ڽӽڵ�����
        sort(G[i].begin(), G[i].end());
    }
    bfs(s); cout<<endl;     //���й����������
    memset(vis, false, sizeof(vis));    //����������ʼ��Ϊfalse
    dfs(s);                 //���������������
    return 0;
}
