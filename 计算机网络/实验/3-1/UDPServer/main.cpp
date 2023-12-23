#include "UDPServer.h"

int main() {
    try {
		UINT port = 12720; // ���Ը�����Ҫ�޸Ķ˿ں�
		UDPServer server(port);
		server.Start(); // ����������
		server.Stop();  // ֹͣ������
    } 
	catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    system("pause");
    return 0;
}
