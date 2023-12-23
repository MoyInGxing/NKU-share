#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool inf; // �Ƿ�Ϊ����Զ��
    Point(int x, int y) : x(x), y(y), inf(false) {}
    Point(bool inf) : x(0), y(0), inf(inf) {}  // ���ڴ�������Զ��
    bool operator==(const Point& other) const {
        if(inf != other.inf) return false;
        if(inf && other.inf) return true;
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const { return !(*this == other); }
};



class EllipticCurve {
public:
    int a, b, p;
    Point ZERO; // ��������Զ��

    EllipticCurve(int a, int b, int p) : a(a), b(b), p(p), ZERO(true) {}

    // �����Լ��
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

    // ��չŷ������㷨����Ԫ
    int inverse(int a,int m){
        while(a < 0) a += m; 
        a %= m; 
        if(gcd(a, m) != 1) {
            cout << "No inverse";
            exit(1);
        }
        int r, q, s1 = 1, s2 = 0, s3, t1 = 0, t2 = 1, t3 = 1, mt = m;
        while(1){
            r = m % a; q = m / a;
            if(!r) break;
            m = a; a = r;
            s3 = s1 - q * s2;
            t3 = t1 - q * t2;
            s1 = s2; s2 = s3;
            t1 = t2; t2 = t3;
        }
        while(t3 < 0) t3 += mt;
        return t3 % mt;
    }

    // �ж��Ƿ�Ϊ��Բ����
    bool isEllipticCurve() {
        return (4 * a * a * a + 27 * b * b) % p != 0;
    }

    // �жϵ��Ƿ���������
    bool isOnCurve(const Point& P) {
        if (P== ZERO) return true;
        return (P.y * P.y - P.x * P.x * P.x - a * P.x - b) % p == 0;
    }

    // ����P+P
    Point doublePoint(const Point& P) {
        if (P.y == 0) return ZERO;
        int s = ((3 * P.x * P.x + a) * inverse(2 * P.y, p)) % p;
        while(s < 0) s += p;
        int xR = (s * s - 2 * P.x) % p;
        while(xR < 0) xR += p;
        int yR = (s * (P.x - xR) - P.y) % p;
        while(yR < 0) yR += p;
        return Point(xR, yR);
    }

    // ��������֮��
    Point addPoints(const Point& P, const Point& Q) {
        if (P == ZERO) return Q;
        if (Q == ZERO) return P;
        if (P == Q) return doublePoint(P);
        if (P.x == Q.x) return ZERO;
        int s = ((Q.y - P.y) * inverse(Q.x - P.x, p)) % p;
        while(s < 0) s += p; 
        int xR = (s * s - P.x - Q.x) % p;
        while(xR < 0) xR += p;
        int yR = (s * (P.x - xR) - P.y) % p;
        while(yR < 0) yR += p;
        return Point(xR, yR);
    }

    // ʹ�ñ���-���㷨����mP 
    Point multiplyPoint(const Point& P, int m) {
        Point R = ZERO;
        Point Q = P;
        while (m) {
            if (m & 1){
                R = addPoints(R, Q);
            }
            m >>= 1;
            if (m) Q = doublePoint(Q);
        }
        return R;
    }

    // �����Ľ�
    int orderOfPoint(const Point& P) {
        if (!isOnCurve(P)) return -1;
        if (P == ZERO) return INT_MAX;
        Point Q = P;
        int order = 1;
        while (Q != ZERO) {
            Q = addPoints(P, Q);
            order++;
        }
        return order;
    }

    // �������ߵĽ�
    int orderOfCurve() {
        vector<Point> points = allPoints();
        return points.size();
    }

    // ���������ϵ����е�
    vector<Point> allPoints() {
        vector<Point> points{ZERO};
        for (int x = 0; x < p; x++) {
            for(int y = 0; y < p; y++) {
                if (isOnCurve(Point(x, y))) {
                    points.push_back(Point(x, y));
                }
            }
        }
        return points;
    }
};


int main() {
    // ����һ����Բ���� y^2 = x^3 + ax + b (mod p)
    int a = 4, b = 4, p = 2773;
    EllipticCurve curve(a, b, p); // ���������ֱ�Ϊ a, b, p
    printf("y^2 = x^3 + %dx + %d (mod %d)\n", a, b, p);
    printf("Is elliptic curve: %s\n", curve.isEllipticCurve() ? "Yes" : "No");

    // ���������� P, Q
    Point P(1, 3);
    Point Q(1, 3);

    // ������������Ƿ���������
    printf("P(%d, %d) is on curve: %s\n", P.x, P.y, curve.isOnCurve(P) ? "Yes" : "No");
    printf("Q(%d, %d) is on curve: %s\n", Q.x, Q.y, curve.isOnCurve(Q) ? "Yes" : "No");

    // ��������֮�� R = P + Q
    Point R = curve.addPoints(P, Q);
    printf("R = P + Q = (%d, %d)\n", R.x, R.y);

    // ����2P
    Point twoP = curve.doublePoint(P);
    printf("2P = (%d, %d)\n", twoP.x, twoP.y);

    // ����kP
    int k = 3;
    Point kP = curve.multiplyPoint(P, k);
    printf("%dP = (%d, %d)\n", k, kP.x, kP.y);

    // �����P�Ľ�
    int orderP = curve.orderOfPoint(P);
    printf("Order of P: %d\n", orderP);

    // �������ߵĽ�
    int orderCurve = curve.orderOfCurve();
    printf("Order of curve: %d\n", orderCurve);

    // ���������ϵ����е�
    vector<Point> points = curve.allPoints();
    printf("All points on curve:\n");
    for (const Point& point : points) {
        if(point == curve.ZERO) printf("O\n");
        else printf("(%d, %d)\n", point.x, point.y);
    }
    printf("The number of points on curve: %llu\n", points.size());
    system("pause");
    return 0;
}
