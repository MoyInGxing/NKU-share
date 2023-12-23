#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAXN 10000
using namespace std;

pii lecture[MAXN];

int main(){
    priority_queue<int, vector<int>, greater<int>> room;  // ��С���Ѵ洢ÿ�����ҵĽ���ʱ��
    int n;
    cin >> n;  // ���뽲������
    for(int i = 0; i < n; i++) cin >> lecture[i].first >> lecture[i].second;  // ����ÿ�������Ŀ�ʼʱ��ͽ���ʱ��
    sort(lecture, lecture + n); //���������տ�ʼʱ������
    room.push(lecture[0].second);  // ����һ������������һ��������
    for(int i = 1; i < n; i++){
        int min_end_time = room.top();  // ��ȡ��ǰ���ý���������Ľ���ʱ��
        int start = lecture[i].first, end = lecture[i].second;  // ��ȡ��ǰ�����Ŀ�ʼʱ��ͽ���ʱ��
        if(start >= min_end_time) room.pop();  // �����ǰ�������԰����ڵ�ǰ���ý����У��򽫿��ý��ҵ���
        room.push(end);  // ����ǰ����������ĳ��������
    }
    cout << room.size();  // ������������
    return 0;
}
