#pragma once

#include <fstream>
#include <random>
#include <utility>
#include <queue>
#include <mutex>
#include "UDP.h"

#define BUFFER_SIZE (DATA_SIZE + sizeof(Header))

class UDPClient : public UDP {
public:
	UDPClient(const std::string& serverIP, UINT serverPort, uint32_t window_size);
	~UDPClient();

	void SendFile(const std::string& filePath);

private:
	std::string serverIP;
	UINT serverPort;
	SOCKET clientSocket;
	sockaddr_in serverAddr;
	uint32_t window_size;
	bool isconnected = false;
	uint32_t nextseq = 0;
	uint32_t base = 0;
	uint32_t ackNum = 0;
	uint64_t totalBytesSent = 0;                     // ���͵����ֽ���
	bool running = false;
	ULONGLONG timer_start;
	std::queue<UDPPacket> sendBuffer;               // �洢�ѷ��͵���δȷ�ϵ����ݰ�
	std::mutex mtx;                                 // ���ڱ���������Դ�Ļ�����
	static const ULONGLONG timeoutMs = 200;			    // ��ʱʱ��

	void handshake();
	void waveHand();
	void sendPacket(uint32_t flags, uint32_t seq, uint32_t ack = UINT_MAX, const char* data = nullptr, uint16_t length = 0, bool resend = false);
	void sendFileData(const std::string& filePath);
	bool waitForPacket(uint32_t expectedFlag);
	static DWORD WINAPI receiveAck(LPVOID pParam);
	void Print(const std::string& info, Level lv = NOP);
	void PrintPacketInfo(const UDPPacket& packet, Level lv);
	void PrintsendBuffer();
};
