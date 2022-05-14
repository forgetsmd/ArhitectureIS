#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

using namespace std;


int main() {
  int sock;
  struct sockaddr_in addr;
  sock = socket(AF_INET, SOCK_DGRAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(768);
  addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

  int code;
  string response, x, y;
  char message[10];
  bool flag = true;
  while (flag) {
        cout << "Enter command"<< std::endl;
        cout << "Command list: " << std::endl <<
            "go to position-0, clean-1, off-2" << std::endl;
        cin >> code;
        while (code < 0 && code > 2) {
            std::cout << "Wrong command" << std::endl;
            std::cin >> code;
        }
        switch (code){
            case 0:
                cout << "Enter x: ";
                cin >> x;
                cout << endl <<"Enter y: ";
                cin >> y;
                break;
            case 2:
                cout << "Goodbye, Robot!" << endl;
                flag = false;
        }

    response = std::to_string(code) + " " + x + " " + y;
    strcpy(message, response.c_str());
    sendto(sock, message, sizeof(message), 0, (struct sockaddr *)&addr, sizeof(addr));
  }
  close(sock);
  return 0;
}
