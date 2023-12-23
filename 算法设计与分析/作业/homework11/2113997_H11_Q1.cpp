#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

bool vis[MAXN];
vector<int> primeList;

// ����ɸѡ����������
void Prime(int n){
    for (int i = 2; i <= n; i++){
        if(!vis[i]) primeList.push_back(i);  // ���iδ����ǣ�˵��i��������������ӵ������б���
        for(int &p : primeList){
            if (i * p > n) break;  // ���i*p����n����������ǰѭ��
            vis[i * p] = true;  // ������е�i*p������pΪ������Ϊ������
            if (i % p == 0) break;  // ���i�ܱ�p������˵��i*p֮������Ѿ�����ǹ��ˣ���������ѭ��
        }
    }
}

// �����ַ���ָ�ƣ�ʹ��ģpȡ��ȷ����������޷�Χ��
int getIP(const string& x, int p){
    int ans = 0, base = 1;
    for(int i = (int)x.length() - 1; i >= 0; i--){
        ans = (ans + (x[i] - 'a' + 1) * base) % p;  // �����ַ�����ָ��ֵ
        base = (base * 2) % p;  // ���»���
    }
    return ans;
}


// xΪ��ƥ�䴮��yΪƥ�䴮
int solve(const string& x, const string& y){
    int m = y.size(), n = x.size(), j = 0;
    Prime(n * n * m);  // Ԥ������������
    int p = primeList[rand() % primeList.size()];  // ���ѡ��һ��������Ϊģ��
    int w = 1;
    for (int i = 0; i < m; i++) w = (w * 2) % p;  // ����2^m mod p��ֵ���洢Ϊw
    int IPy = getIP(y, p);  // ����ƥ�䴮��ָ��
    int IPx = getIP(x.substr(0, m), p);  // ���㱻ƥ�䴮��ǰm���ַ���ָ��
    while(j <= n - m){
        if(IPx == IPy) return j;  // �������ָ����ͬ���򷵻ص�ǰ����ʼλ��
        // ���±�ƥ�䴮��ָ�ƣ�ͬʱ�����������
        IPx = (IPx * 2 - (x[j] - 'a' + 1) * w + (x[j + m] - 'a' + 1)) % p;
        while(IPx < 0) IPx += p;
        j++;
    }
    return -1;  // ���û���ҵ�ƥ�䣬����-1
}

int main(){
    srand(time(NULL));
    string x, y;
    cin >> x >> y;
    cout << solve(x, y);
    return 0;
}
