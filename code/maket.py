class Robot:
    __cordinat = None
    def __init__(self) -> None:
        print("Robot start...")
    def set_cordinat(cord):
        __cordinat = cord
    def calculat_way():
        pass
    def move():
        pass
    def clear():
        pass

class Camera:
    def __init__(self) -> None:
        print("Camera start...")
    def get_img():
        pass

class System:
    
    def __init__(self) -> None:
        print("System start...")
        self.robot = Robot()
        self.camera = Camera()
    def detect():
        pass
    def calculate_coordinates():
        pass
    def transfer_coordinates():
        pass

sys = System()