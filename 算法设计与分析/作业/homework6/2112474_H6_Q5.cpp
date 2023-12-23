#include <bits/stdc++.h>
using namespace std;
struct node
{
    double x;
    double y;
};
bool cmpx(node a, node b) // �Զ���sort��������ʽ����x��С����
{
    return a.x > b.x;
}
bool cmpy(node a, node b) // �Զ���sort��������ʽ����y��С����
{
    return a.y > b.y;
}
double dis(node n1, node n2) // ���뺯��
{
    return (n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y);
}
pair<node, node> closestpairrec(vector<node> &px, vector<node> &py, int l, int r) // l��r�ֱ���p��������Ҷ˵�
{
    if (r - l + 1 <= 3) // �������С������ֱ�ӱ����ҵ���̵��
    {
        double min = 10000000;
        pair<node, node> res;
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                double t = dis(px[i], px[j]);
                if (t < min) // ������Сֵ
                {
                    res.first = px[i];
                    res.second = px[j];
                    min = t;
                }
            }
        }
        return res;
    }
    else
    {
        int mid = (l + r) / 2;
        pair<node, node> resq = closestpairrec(px, py, l, mid);                     // ���q����(����)����̵��
        pair<node, node> resr = closestpairrec(px, py, mid + 1, r);                 // ���r����(�Ұ��)����̵��
        pair<node, node> res;                                                       // ��������������̵��
        double m = min(dis(resq.first, resq.second), dis(resr.first, resr.second)); // ��¼��������������̵�Լ�ľ���
        double x = px[mid].x;                                                       // �ֽ���L
        vector<node> s;
        for (int i = l; i <= r; i++)
        {
            if (abs(px[i].x - x) <= m)
                s.push_back(py[i]);
        } // �����м�����s
        double mt = 999999;
        pair<node, node> rest;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size() && j - i <= 7; j++) // ����ÿ��s�еĵ㼰�������߸��㣬��������̵������
            {
                if (dis(s[i], s[j]) < mt)
                {
                    rest.first = s[i];
                    rest.second = s[j];
                    mt = dis(s[i], s[j]);
                }
            }
        }
        if (mt < m) // �������if���ж���̵����Ĳ��ֵĵ��
            return rest;
        else if (dis(resq.first, resq.second) < dis(resr.first, resr.second))
            return resq;
        else
            return resr;
    }
}

pair<node, node> closestpair(vector<node> &points)
{
    vector<node> px(points), py(points); // ����Էֱ�x��y�Ĵ�С����
    sort(px.begin(), px.end(), cmpx);
    sort(py.begin(), py.end(), cmpy);
    pair<node, node> res = closestpairrec(px, py, 0, points.size() - 1); // ����rec�������ҵ���̵��
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<node> p(n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    pair<node, node> result;
    result = closestpair(p);
    printf("%.2lf", dis(result.first, result.second));
    return 0;
}