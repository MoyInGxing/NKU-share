#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // ��������˻�Ϊ����������Ҫɾ�����֣�ֱ���������
    if(n>=0){
        cout<<n;
        return 0;
    }
    // ��������˻�Ϊ��������ȡ�����ֵ���������
    n = -n;
    // aΪɾ����λ��Ľ����bΪɾ��ʮλ��Ľ��
    int a = n/10;
    int b = (n/100)*10 + n%10;
    // ȡɾ����λ��ɾ��ʮλ�Ľ���е���Сֵ
    int ans = min(a,b);
    // ��������Ϊ0����˵����Ҫ�������
    if(ans!=0) cout<<'-';
    cout<<ans;
    return 0;
}
