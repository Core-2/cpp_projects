#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <vector>
#include <stdio.h>
#include <thread>
#include <chrono>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

void sendAndReceiveData(string, char*);
void dataToVector(string);

vector<vector<char>> recvVector(1, vector<char>(1));

bool isFirst = true;
bool isEscPushed = false;
bool isDataReceived = false;
string receivedData;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	string url;

	if (argc != 2) {
		printf("Программу можно запустить из консоли следующим образом:\n");
		printf("%s <имя хоста>\n", argv[0]);
		printf("Например: %s www.google.com\n", argv[0]);
		return 1;
	}
	else {
		url = (string)argv[1];
	}
	
	string get_http = "GET / HTTP/1.1\r\nHost: " + url + "\r\n\r\n"; 

	thread sendRecvThrd(sendAndReceiveData, get_http, argv[1]);

	while(true) {
		if (!receivedData.empty()) {
			if (isDataReceived) {
				dataToVector(receivedData);
				receivedData.clear();
				if (recvVector[0].empty()) break;
				vector<char>::iterator iter{ recvVector[0].begin() };
				while (iter != recvVector[0].end()) {
					cout << *iter;
					++iter;
					if (GetAsyncKeyState(VK_ESCAPE)) {
						isEscPushed = true;
						break;
					}
				}
				recvVector[0].clear();
				isDataReceived = false;
				if (isEscPushed) break;
				printf("\n\nДанные с сайта успешно получены.\n");
				printf("В течение 30 секунд будет повторный HTTP-запрос.\n");
				printf("Нажмите ESC, чтобы остановить программу.\n");
			}
		}	
		if (GetAsyncKeyState(VK_ESCAPE)) {
			isEscPushed = true;
			break;
		}
	}
	sendRecvThrd.join();
	printf("\n\nНажата кнопка ESC. Закрытие программы...\n");
}


/*------------------------------Функции----------------------------------*/


void sendAndReceiveData(string httpGet, char* address) {
	while (true) {
		WSADATA wsaData;
		int iResult;
		struct addrinfo* result = NULL, * ptr = NULL, hints;
		const char* port{ "80" };

		iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			printf("Ошибка в WSAStartup(): %d\n", iResult);
			receivedData = "1";
			break;
		}

		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = 0;

		iResult = getaddrinfo(address, port, &hints, &result);
		if (iResult != 0) {
			printf("Ошибка в getaddrinfo(): %d\n", iResult);
			WSACleanup();
			receivedData = "1";
			break;
		}

		ptr = result;

		SOCKET ConnectSocket = INVALID_SOCKET;
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("Ошибка в socket(): %ld\n", WSAGetLastError());
			freeaddrinfo(result);
			WSACleanup();
			receivedData = "1";
			break;
		}

		if (!isFirst) {
			for (int i = 0; i < 60; i++) {
				if (!isEscPushed) {
					this_thread::sleep_for(chrono::milliseconds(500));
				}
				else {
					break;
				}
			}	
		}
		else {
			isFirst = false;
		}

		if (isEscPushed) break;

		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			printf("Не удалось подключиться к серверу: %d\n", WSAGetLastError());
			cout << iResult << endl;
			WSACleanup();
			receivedData = "1";
			break;
		}
		send(ConnectSocket, httpGet.c_str(), strlen(httpGet.c_str()), 0);
		iResult = shutdown(ConnectSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("Ошибка shutdown(): %d\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			receivedData = "1";
			break;
		}

		int nDataLength;
		char buffer[10000];

		while ((nDataLength = recv(ConnectSocket, buffer, size(buffer), 0)) > 0) {
			for (int i = 0; buffer[i] >= 32 || buffer[i] == '\n' || buffer[i] == '\r'; i++) {
				receivedData += buffer[i];
			}
		}
		if (nDataLength == SOCKET_ERROR) {
			printf("Ошибка при получении данных: %ld\n", WSAGetLastError());
			closesocket(ConnectSocket);
			WSACleanup();
			receivedData = "1";
			break;
		}
		isDataReceived = true;
		closesocket(ConnectSocket);
		WSACleanup();
		if (isEscPushed) break;
	}
}



void dataToVector(string str) {
	if (str == "1") {
		recvVector[0].clear();
	}
	else {
		copy(str.begin(), str.end(), back_inserter(recvVector[0]));
	}
}