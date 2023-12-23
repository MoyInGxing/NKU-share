#include "UDPClient.h"

int main() {
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
        while (true) {
            cout << "Enter the path of the file to send: ";
            cin >> filePath;
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
