#pragma once

#include <WinSock2.h>
#include <iostream>
#include <string>
#include <ctime>

#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

using std::string;
using std::cout;
using std::endl;
using std::to_string;


// ����ͻ��ṹ��
struct Client {
	SOCKET sock;						// �׽���
	string username;					// �û���
	Client(SOCKET sock = INVALID_SOCKET, string username = "$") : sock(sock), username(username) {}
};

// �����ҷ�������
class ChatRoomServer {
public:
    ChatRoomServer(UINT port = 12720, UINT client = 64);    // ���캯��
    ~ChatRoomServer();  					                // ��������
    void Start();   				                        // ����������
    void Stop();    	                                    // �رշ�����
    void PrintInfo(const string& info);                     // �����־

private:
    // �����������س���
    UINT MAX_CLIENTS;		                    // ���ͻ�������
    UINT PORT;									// �������˿�
    constexpr static UINT BUFFER_SIZE = 1024;	// ��������С

    // �����������ر���
    SOCKET SockServer = INVALID_SOCKET;			// �������׽���
    Client* clients;				            // �ͻ�������
    HANDLE* hThreads;				            // �߳̾����ÿ���ͻ��˾���һ���߳�������
    UINT hpointer = 0;				            // �߳̾�������ָ��
    sockaddr_in addrServer;						// ��������ַ

    // �����������غ���
    void InitWinSock();							// ��ʼ��WinSock
    int find_pos();					            // ���ҿ��еĿͻ��˴��λ��
    UINT Online_Count();						// ��ȡ��������
    static DWORD WINAPI ClientHandler(LPVOID pParam);		// ÿ���ͻ����̺߳���
    void BroadcastMessage(const string& msg);   // ����Ϣ�㲥�����пͻ���
    string GetCurrTime();                       // ��ȡ��ǰʱ��
};

