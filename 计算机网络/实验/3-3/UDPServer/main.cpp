#include "UDPServer.h"

int main() {
	try {
		UINT port = 12720; // ���Ը�����Ҫ�޸Ķ˿ں�
		uint32_t windowSize;		   // ���ڴ�С

		std::cout << "Enter the Window Size: ";
		std::cin >> windowSize;

		UDPServer server(port, windowSize); // ����UDP������ʵ��
		server.Start(); // ����������
		server.Stop();  // ֹͣ������
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	system("pause");
	return 0;
}