#include "UDPServer.h"

int main(int argc, char* argv[]) {
#ifndef Lab3_4
	try {
		UINT port = 12720; // ���Ը�����Ҫ�޸Ķ˿ں�
		uint32_t windowSize;		   // ���ڴ�С

		std::cout << "Enter the Window Size: ";
		std::cin >> windowSize;

		UINT delay = 50;
		double drop = 0.03;

		UDPServer server(port, windowSize, delay, drop); // ����UDP������ʵ��
		server.Start(); // ����������
		server.Stop();  // ֹͣ������
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	system("pause");
#else
	try {
		uint32_t windowSize = static_cast<uint32_t>(std::stoul(argv[1]));
		UINT delay = static_cast<uint32_t>(std::stoul(argv[2]));
		double drop = std::stod(argv[3]);
		UDPServer server(12720, windowSize, delay, drop);
		server.Start();
		server.Stop();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
#endif
	return 0;
}