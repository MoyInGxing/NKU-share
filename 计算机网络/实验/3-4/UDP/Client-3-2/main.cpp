#include "UDPClient.h"

int main(int argc, char* argv[]) {
#ifndef Lab3_4
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
		std::cout << "Enter the path of the file to send: ";
		std::cin >> filePath;
		client.SendFile(filePath);  // �����ļ�
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	system("pause");
#else
	try {
		uint32_t windowSize = static_cast<uint32_t>(std::stoul(argv[1]));
		UDPClient client("127.0.0.1", 12720, windowSize);
		std::string filePath = "1.jpg";
		client.SendFile(filePath);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
#endif
	return 0;
}