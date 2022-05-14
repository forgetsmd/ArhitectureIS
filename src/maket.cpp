#include "iostream"
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

struct Img
{
    int image[1024][768];
};

enum Status {
    WAIT, 
    MOVE_TO, 
    ERROR, 
    CLEAN, 
    OFF, 
    };

class Controler
{
public:
    virtual string get_command() = 0;
};

class ConsoleControler: public Controler
{
public:
    string get_command(){
        int code = -1; //код команды
        string response, x, y;
        cout << "Enter command"<< std::endl;
        cout << "Command list: " << std::endl <<
            "go to position-0, clean-1, off-2" << std::endl;
        cin >> code;
        while (code < 0 && code > 2) {
            cout << "Wrong command" << std::endl;
            cin >> code;
        }
        switch (code) {
            case 0:
                cout << "Enter x: ";
                cin >> x;
                cout << endl <<"Enter y: ";
                cin >> y;
                break;
        }
        response = std::to_string(code) + " " + x + " " + y;
        return response;

    }
};

class NetControler: public Controler
{
private:
    int sock; //адрес сокета
    int bytes_read;
    struct sockaddr_in addr;
    char buf[10];


public:
    NetControler()
    {
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(768);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);

        if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        {
            perror("bind");
        }

    }

    string get_command()
    {
        cout << "Waiting for a command" << std::endl;
        string response;

        bytes_read = recvfrom(sock, buf, sizeof (buf), 0, NULL, NULL);
        buf[bytes_read + 1] = '\0';
        response = buf;

        return response;
    }
    

};


class Robot
{
private:
    Controler *cont;
    Status status;

    void move_to(int x, int y){
        cout << "Moving..." << endl;
        cout << "Position: " << x << " " << y << endl;
    }
    void clean()
    {
        cout << "Picture is cleaning" << endl;
    }

public:
    Robot(Controler *control)
    {
        cont = control;
        status = WAIT;
    }
    ~Robot(){
        delete cont;
    }
    // void get(){
    //     cont->get_command();
    //     }
    Status getStatus()
    {
        return status;
    }
    void getEvent(string commands)
    {
        istringstream stream_command(commands);
        int code;
        stream_command >> code;

        switch (status)
        {
        case WAIT:
            switch (code)
            {
            case 0:
                status = MOVE_TO;
                break;
            
            case 1:
                status = CLEAN;
                break;

            case 2:
                status = OFF;
                break;
            }
            break;
        
        case MOVE_TO:
            int x, y;
            stream_command >> x;
            stream_command >> y;
            move_to(x, y);
            status = WAIT;
            break;

        case CLEAN:
            clean();
            status = WAIT;
        }
    }

    void run()
    {
        string command;
        while(status != OFF)
        {
            if(status == WAIT)
            {
                command = cont->get_command();
            }
            getEvent(command);

        }
    }
    
    // void calculate_way(int coordinat){}
    // void move(int traject){}
    // void clear(){}
};

class Camera
{
public:
    Img get_img();
};

class System
{
private:
    Robot rob;
    Camera cam;
public:
    void detect()
    {
        cam.get_img();
    }
    void calculate_coordinates(Img img){}
    void transfer_coordinates(int coordinat){}

};

int main()
{
    
    Robot *rob;
    rob = new Robot(new NetControler);
    rob->run();

    return 0;
}