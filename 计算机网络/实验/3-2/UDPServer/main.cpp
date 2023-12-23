#include "UDPServer.h"

int main() {
    try {
		UINT port = 12720; // 可以根据需要修改端口号
		UDPServer server(port);
		server.Start(); // 启动服务器
		server.Stop();  // 停止服务器
    } 
	catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    system("pause");
    return 0;
}
