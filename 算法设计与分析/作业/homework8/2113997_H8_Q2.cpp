#include <bits/stdc++.h>
using namespace std;

int nTimeA[25][65][65];
int tNodeTime[25][65][65];
int nCount, tA[25], tB[25], tATime[25], tBTime[25];
int tACount, tBCount;

// ����ÿ���ڵ�ִ�� A ����� B ��������ʱ��
void calcNodeTimeA() {
    // �������нڵ�
    for (int n = 1; n <= nCount; ++n) {
        int tempT[2][65][65];
        // ��ʼ����ʱ����
        memset(tempT, 31, sizeof(tempT));
        tempT[1][0][0] = tempT[0][0][0] = 0;
        // �������� A ����� B ��������
        for (int i = 0; i <= tACount; ++i) {
            for (int j = 0; j <= tBCount; ++j) {
                // �������ܷ�����ڵ� n �� A ��������
                for (int k = 1; k <= i; ++k) {
                    tempT[0][i][j] = min(tempT[0][i][j],
                                  tempT[1][i-k][j] + tATime[n] * k * k + tA[n]);
                }
                // �������ܷ�����ڵ� n �� B ��������
                for (int k = 1; k <= j; ++k) {
                    tempT[1][i][j] = min(tempT[1][i][j],
                                  tempT[0][i][j-k] + tBTime[n] * k * k + tB[n]);
                }
                // �����ʱ��洢�� nTimeA ������
                nTimeA[n][i][j] = min(tempT[0][i][j], tempT[1][i][j]);
            }
        }
    }
}

// ����ǰn���ڵ�ִ�� A ����� B ��������ʱ��
void calcTotalNodeTime() {
    // ��ʼ�� tNodeTime ����
    memset(tNodeTime, 31, sizeof(tNodeTime));
    // �����һ���ڵ�����
    for (int i = 0; i <= tACount; ++i) {
        for (int j = 0; j <= tBCount; ++j) {
            tNodeTime[1][i][j] = nTimeA[1][i][j];
        }
    }
    // �������нڵ�
    for (int n = 2; n <= nCount; ++n) {
        // �������� A ����� B ��������
        for (int i = 0; i <= tACount; ++i) {
            for (int j = 0; j <= tBCount; ++j) {
                // �������ܵ�����������
                for (int k = 0; k <= i; ++k) {
                    for (int l = 0; l <= j; ++l) {
                        tNodeTime[n][i][j] = min(tNodeTime[n][i][j],
                                      max(tNodeTime[n-1][k][l], nTimeA[n][i-k][j-l]));
                	}
            	}
        	}
    	}
	}
}

int main() {
	freopen("hpc.in", "r", stdin);
	freopen("hpc.out", "w", stdout);
	// �������������ͽڵ�����
	scanf("%d%d%d", &tACount, &tBCount, &nCount);
	// ����ÿ���ڵ����ز���
	for (int i = 1; i <= nCount; ++i) {
    	scanf("%d%d%d%d", &tA[i], &tB[i], &tATime[i], &tBTime[i]);
	}
	// ����ÿ���ڵ�ִ����������ʱ��
	calcNodeTimeA();
	// ����ǰn���ڵ�ִ����������ʱ��
	calcTotalNodeTime();
	// ������
	printf("%d", tNodeTime[nCount][tACount][tBCount]);
	return 0;
}
