#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> que; // ʹ��С���Ѷ����񰴽�ֹʱ���������
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        que.push({y, x}); // ����Ľ�ֹʱ�� y ����ǰ�棬��֤С���Ѱ���ֹʱ���С��������
    }
    int cur_time = 0, max_lateness = 0;
    while(!que.empty()){
        // ȡ�����׵�������д���
        int end = cur_time + que.top().second; // ������������ʱ��
        int lateness = end - que.top().first; // ����������ӳ�ʱ��
        que.pop();
        cur_time = end; // ���µ�ǰʱ��
        max_lateness = max(max_lateness, lateness); // ��������ӳ�ʱ��
    }
    cout << max_lateness; // �������ӳ�ʱ��
    return 0;
}
