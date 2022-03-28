#include "iostream"
using namespace std;

struct Img
{
    int image[1024][768];
};

class Robot
{
private:
    int coordinat;
public:
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
    System sys;
    return 0;
}