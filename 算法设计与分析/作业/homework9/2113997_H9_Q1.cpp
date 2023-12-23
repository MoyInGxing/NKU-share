#include <bits/stdc++.h>
#define N 10000
using namespace std;

int a[N], n;

// �����ǰ��
void output(){
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// �жϵ�ǰ���Ƿ�Ϸ�
bool is_valid(int cnt){
    for(int i = 1; i < cnt; i++){
        if(a[i] == a[cnt]) return false;
    }
    return true;
}

// ���û��ݷ�����1,2,...,n��ȫ����
void backtrack(int cnt){
    for(int i = 1; i <= n; i++){
        a[cnt] = i;
        if(is_valid(cnt)){
            if(cnt == n) output();
            else backtrack(cnt + 1);
        }
    }
}

int main(){
    scanf("%d", &n);
    backtrack(1);
    return 0;
}