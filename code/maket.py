class Robot:
    __cordinat = None
    def set_cordinat(cord):
        __cordinat = cord
    def calculat_way():
        pass
    def move():
        pass
    def clear():
        pass

class Camera:
    def get_img():
        pass

class System:
    robot = Robot()
    camera = Camera()
    def detect():
        pass
    def calculate_coordinates():
        pass
    def transfer_coordinates():
        pass

robot = Robot()
print(robot.__cordinat)