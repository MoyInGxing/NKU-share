#include "UDPClient.h"

int main(int argc, char* argv[]) {
#ifndef Lab3_4
	// ��������IP��ַ�Ͷ˿�
	string serverIP = "127.0.0.1"; // ���߷�������ʵ��IP��ַ
	UINT serverPort;               // �����������Ķ˿�
	cout << "Enter the server port: ";
	cin >> serverPort;
	// ����UDP�ͻ���ʵ��
	UDPClient client(serverIP, serverPort);

	try {
		// ��ȡҪ���͵��ļ�·��
		string filePath;
		cout << "Enter the path of the file to send: ";
		cin >> filePath;
		client.SendFile(filePath);  // �����ļ�
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	system("pause");
#else
	try {
		UDPClient client("127.0.0.1", 12720);
		std::string filePath = "1.jpg";
		client.SendFile(filePath);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
#endif
	return 0;
}