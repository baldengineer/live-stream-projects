from PIL import Image
import array
import os


def rgb332(r, g, b):
    r = r >> 5
    g = g >> 5
    b = b >> 6
    c = r << 5 | g << 2 | b
    return [c]


def rgb565(r, g, b):
    r = r >> 3
    g = g >> 2
    b = b >> 3
    c = r << 11 | g << 5 | b
    return [c >> 8, c & 0xff]


def convert(cvt, path, subpath):
    subpath = os.path.join(path, subpath)
    if not os.path.exists(subpath):
        os.mkdir(subpath)

    for _, _, filesnames in os.walk(path):
        for file in filesnames:
            if (os.path.splitext(file)[-1] != '.bmp'):
                continue
            im = Image.open(os.path.join(path, file))
            width, height = im.size
            v = [cvt(r, g, b) for (r, g, b) in im.getdata()]
            b = bytearray()
            b.append(width & 0xff)
            b.append(width >> 8)
            b.append(height & 0xff)
            b.append(height >> 8)
            for pair in v:
                for i in pair:
                    b.append(i)
            f = open(os.path.join(subpath, file), "wb")
            f.write(b)
            f.close()
        break

def choose():
    option = int(input("Enter (1) for 8-bit colour convert, Enter (2) for 16-bit colour convert\n"))
    if option == 1:
        pathname = 'rgb332'
        return rgb332, pathname
    elif option == 2:
        pathname = 'rgb565'
        return rgb565, pathname
    else:
        print("Invalid input!")

rgbtype, pathname = choose();
convert(rgbtype, 'bmp', pathname)
