#include <iostream>
using namespace std;

int main(){
    int n, m, a, b;
    cin>>n>>m>>a>>b; // �����ĸ�������n Ϊ��Ҫ�����Ĵ�����a Ϊ����Ʊ�ۣ�b Ϊ m �γ˳�Ʊ��
    if(double(b)/m>=a){ // ��� b/m>=a����ô�򵥳�Ʊ������
        cout<<n*a; // �������Ʊ�Ļ���
        return 0;
    }
    int x = n/m, y = n%m; // ������Ҫ���� m �γ˳�Ʊ�͵���Ʊ��������x Ϊ���� m �γ˳�Ʊ��������y Ϊ���򵥳�Ʊ������
    cout<<(b*x + a*y); // �����С����
    return 0;
}
