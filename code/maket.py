import cv2 as cv
import numpy as np

hsv_min = np.array((0, 54, 5), np.uint8)
hsv_max = np.array((187, 255, 253), np.uint8)

def resizing(img ,new_width=None, new_height=None, interp=cv.INTER_LINEAR):
    h, w = img.shape[:2]

    if new_width is None and new_height is None:
        return img

    if new_width is None:
        ratio = new_height / h
        dimension = (int(w * ratio), new_height)

    else:
        ratio = new_width / w
        dimension = (new_width, int(h * ratio))

    res_img = cv.resize(img, dimension, interpolation=interp)
    return res_img

def find_contours(img):
    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)  # меняем цветовую модель с BGR на HSV
    thresh = cv.inRange(hsv, hsv_min, hsv_max)  # применяем цветовой фильтр
    print(thresh.copy(), cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    contours0, hierarchy = cv.findContours(thresh.copy(), cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    # перебираем все найденные контуры в цикле
    for cnt in contours0:
        rect = cv.minAreaRect(cnt)  # пытаемся вписать прямоугольник
        box = cv.boxPoints(rect)  # поиск четырех вершин прямоугольника
        box = np.int0(box)  # округление координат
        cv.drawContours(img, [box], 0, (255, 0, 0), 2)  # рисуем прямоугольник
    img = resizing(img, new_width=600, new_height=800)

    cv.imshow('contours', img)  # вывод обработанного кадра в окно
    cv.waitKey()
    cv.destroyAllWindows()

path = r'/ArhitectureIS/src/example.jpg' # for docker
#path = r'src/example.jpg' # for VS Code
img = cv.imread(path)
print(img)
find_contours(img)
