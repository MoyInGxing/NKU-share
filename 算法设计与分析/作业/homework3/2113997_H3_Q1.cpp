#include <bits/stdc++.h>   
#define MAXN 10000          //�������ڵ���Ϊ10000
using namespace std;

vector<int> G[MAXN];        //�����ڽӱ�G
int layer[MAXN];            //����ڵ㵽���Ĳ���

void bfs(int s){            //���������������
    queue<int> que;         //������У��������������
    que.push(s);            
    int depth = 0, width = 1;   //������ȺͿ�ȣ����Ϊ0�����Ϊ1
    while(!que.empty()){    
        for(int i=0;i<width;i++){   //����ÿһ���е�ÿһ���ڵ�
            int cur = que.front();  
            que.pop();              
            if(layer[cur]!=-1) continue;  //����ýڵ��Ѿ������ʹ�����������ѭ��
            layer[cur] = depth;     //��Ǹýڵ����Ϊdepth
            for(int& to:G[cur]){    //�����ýڵ������ڽӽڵ�
                if(layer[to]==-1) que.push(to); //����ڽӽڵ�δ�����ʹ����������
            }
        }
        width = que.size();     //���¿��Ϊ���д�С
        depth++;                //�������
    }
}

int main(){            
    int n, m, s, u, v;      
    cin>>n>>m>>s;       //����ڵ��������������
    for(int i=0;i<m;i++){     
        cin>>u>>v;
        G[u].push_back(v);      //���������
        G[v].push_back(u);
    }
    memset(layer, -1, sizeof(layer));   //���ڵ���������ʼ��Ϊ-1
    bfs(s);             //���й����������
    for(int i=0;i<n;i++){       //���ÿ���ڵ㵽���Ĳ���
        cout<<layer[i]<<" ";
    }
    return 0;
}
