#include "UDPClient.h"

int main() {
	// ��������IP��ַ�Ͷ˿�
	std::string serverIP = "127.0.0.1";     // ���߷�������ʵ��IP��ַ
	UINT serverPort = 12720;                // �����������Ķ˿�
	uint32_t windowSize;           // ���ڴ�С

	std::cout << "The server port: " << serverPort << std::endl;
	std::cout << "Enter the Window Size: ";
	std::cin >> windowSize;

	// ����UDP�ͻ���ʵ��
	UDPClient client(serverIP, serverPort, windowSize);

	try {
		// ��ȡҪ���͵��ļ�·��
		std::string filePath;
		while (true) {
			std::cout << "Enter the path of the file to send: ";
			std::cin >> filePath;
			if (filePath == "exit") break;
			client.SendFile(filePath);  // �����ļ�
		}
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	system("pause");
	return 0;
}