#include "iostream"
using namespace std;

struct Img
{
    int image[1024][768];
};

class Controler
{
public:
    virtual void get_command(){
        cout << "Controler";
    }
};

class ConsoleControler: public Controler
{
public:
    void get_command(){
        cout << "ConsoleControler";
    }
};

class NetControler: public Controler
{
public:
    void get_command(){
        cout << "NetControler";
    }
};


class Robot
{
private:
    int coordinat;
    Controler *cont;
public:
    Robot(Controler *control)
    {
        cont = control;
    }
    void get(){
        cont->get_command();
        }
    void set_coordinat(int coor){coordinat = coor;}
    void calculate_way(int coordinat){}
    void move(int traject){}
    void clear(){}
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
    void transfer_coordinates(int coordinat)
    {
        rob.set_coordinat(coordinat);
    }

};

int main()
{
    
    Robot rob(new ConsoleControler);
    rob.get();

    return 0;
}