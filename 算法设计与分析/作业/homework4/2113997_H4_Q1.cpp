#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;  // ������������
    priority_queue<pii, vector<pii>, greater<pii>> que;  // С���ѣ���ÿ�����񰴽���ʱ������
    for(int i = 0; i < n; i++){
        cin >> x >> y;     // ���뿪ʼʱ��x�ͽ���ʱ��y
        que.push({y, x});  // ���������С���ѣ�����{y,x}������{x,y}�����ڶѶ�pair������Ĭ�ϰ����һ��Ԫ��
    }
    int last_finish_time = -1, ans = 0;  // ��ʼ��������ʱ��Ϊ-1���Լ��𰸼�����
    while(!que.empty()){
        int start = que.top().second;  // ȡ���Ѷ��Ŀ�ʼʱ��
        int end = que.top().first;  // ȡ��������С����ʱ��
        que.pop();  
        if(start >= last_finish_time){  // �����ǰ����Ŀ�ʼʱ����ڵ���������ʱ�䣬�Ϳ��԰����������
            ans++;  
            last_finish_time = end;  // ����������ʱ��
        }
    }
    cout << ans;  
    return 0;
}