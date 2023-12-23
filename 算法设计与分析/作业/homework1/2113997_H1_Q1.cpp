#include <iostream>
#include <map>
using namespace std;

const int MAXN = 1001; // ���峣������ʾ��������
map<char, int> num; // ����ӳ�䣬��¼������Ӧ���

// �˵Ľṹ��
struct person{
    char name; //����
    char fav[MAXN]; // ϲ�����ˣ������ȼ�˳������
    char date_to; // ��Լ�����
    bool vis[MAXN]; // �Ƿ��ѱ����ʹ�
    // �ж��Ƿ������˶��ѱ����ʹ�
    bool all_vis(int n){
        for(int i=1;i<=n;i++) if(!vis[i]) return false;
        return true;
    }
    // ��ȡδ�����ʹ�����ϲ������
    char get_top(int n){
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            return fav[i];
        }
        return 0;
    }
    // �ж���������˭���ܻ�ӭ
    char prefer(int n, char a, char b){
        for(int i=1;i<=n;i++){
            if(fav[i]==a) return a;
            if(fav[i]==b) return b;
        }
        return '#';
    }
    // ���캯������ʼ��Լ�����Ϊ��
    person(){name = date_to = '#';}
}man[MAXN], woman[MAXN];

// ��ȡ��ǰ���е����˱��
int get_free_man(int n){
    for(int i=1;i<=n;i++){
        if(man[i].date_to == '#') return i;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); // �ر�ͬ���������cin��cout�������Ч��
    cin.tie(NULL); cout.tie(NULL); // ���cin��cout�İ󶨣��ӿ���������ٶ�
    int n,i,j;
    char cur,tmp,s;
    cin>>n; // ��������
    // ������Ů���Ե�ϲ���б�
    for(i=1;i<=2*n;i++){
        cin>>cur>>s; 
        if(i<=n){
            man[i].name = cur;
            num[cur] = i;
        }
        else{
            woman[i-n].name = cur;
            num[cur] = i - n;
        }
        for(j=1;j<=n;j++){
            cin>>tmp; if(j<n) cin>>s;
            if(i<=n) man[i].fav[j] = tmp; // ����ǰϲ�����˴�������˵�ϲ���б���
            else woman[i-n].fav[j] = tmp; // ����ǰϲ�����˴����Ů�˵�ϲ���б���
        }
    }
    // ƥ�����
    int fman = get_free_man(n); // ��ȡ��ǰ��������
    char fname = man[fman].name; // ��ȡ��ǰ�������˵�����
    while(fman && !man[fman].all_vis(n)){ // ������п��������һ���Ů��δ�����ʹ�
        int to = num[man[fman].get_top(n)]; // ��ȡ��ǰ���˵���ϲ����δ�����ʹ���Ů��
        man[fman].vis[to] = true; // ��Ǹ�Ůʿ����ʿ���ʹ�
        if(woman[to].date_to != '#'){ // �����Ůʿ�Ѿ�����ʿƥ��
            char op_name = woman[to].date_to; // ��ȡ��Ůʿ��ǰ���ѵ�����
            char love = woman[to].prefer(n,op_name,fname); // �Ƚ������Ѻ͵�ǰ���ѵ�����
            if(love == fname){ // ���Ůʿ��ϲ��������
                man[num[op_name]].date_to = '#'; // ����ǰ���Ѻ͸�Ůʿ���ƥ��
                woman[to].date_to = fname; // ����Ůʿ��������ƥ��
                man[fman].date_to = woman[to].name; // ��ǵ�ǰ���˵�ƥ�����
            }
            else continue; // ���Ůʿ��ϲ����ǰ���ѣ��򲻽���ƥ��
        }
        else{ // �����Ůʿ��û�����ѣ���ֱ��ƥ��
            woman[to].date_to = fname; // ����Ůʿ��������ƥ��
            man[fman].date_to = woman[to].name; // ��ǵ�ǰ���˵�ƥ�����
        }
        fman = get_free_man(n); // �ҵ���һ��δƥ�������
        fname = man[fman].name; // ��ȡ��һ��δƥ������˵�����
    }
    // ���ƥ����
    for(i=1;i<=n;i++) cout<<"("<<man[i].name<<","<<man[i].date_to<<")"<<'\n';
    return 0;
}