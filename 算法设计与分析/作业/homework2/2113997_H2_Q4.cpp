#include <bits/stdc++.h>
using namespace std;

//����һ����ṹ��
struct Point{
    int x;
    int y;
    Point(int a=0, int b=0):x(a),y(b){} 
};

//��������֮��ľ���ƽ��
int dis(const Point& a, const Point& b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main(){
    int lens, mdis = 0x7FFFFFFF; //lens��ʾ������mdis��ʾĿǰ�ҵ�����С�����ƽ��
    cin>>lens;
    Point p[lens],a,b; //����һ��������
    cin>>p[0].x>>p[0].y; //�����һ����
    //�ӵڶ����㿪ʼ���룬����Ѱ����С�����ƽ������Ӧ��������
    for(int i=1;i<lens;i++){
        cin>>p[i].x>>p[i].y;
        for(int j=0;j<i;j++){
            int disij = dis(p[i],p[j]); //����i��j����֮��ľ���ƽ��
            if(disij < mdis){ //���С�ڵ�ǰ�ҵ�����С����ƽ��
                mdis = disij; //������С����ƽ��
                b = p[i]; //����b��
                a = p[j]; //����a��
            }
        }
    }
    printf("(%d,%d),(%d,%d)",a.x,a.y,b.x,b.y); //�����С��������Ӧ��������
    return 0;
}
