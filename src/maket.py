class Robot:
    __cordinat = None
    def __init__(self, controler) -> None:
        print("Robot start...")
        self.controler = controler
    def get_command(self):
        self.controler.get()
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

class Controler:
    def get(self):
        print("Controler")

class ConsoleControler(Controler):
    def get(self):
        print("ConsoleControler")

class NetControler(Controler):
    def get(self):
        print("NetControler")

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

cont = NetControler()
rob = Robot(cont)
rob.get_command()