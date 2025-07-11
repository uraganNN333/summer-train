#include <iostream>
#include <fstream>

using namespace std;

struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream fff("1.bmp", ios::binary);
    ofstream ggg("rez.bmp", ios::binary);

    if (!fff) {
        cout << "Не удалось открыть файл 1.bmp.\n";
        exit(1);
    }
    if (!ggg) {
        cout << "Не удалось создать файл rez.bmp.\n";
        exit(1);
    }

    char buf[100];
    color bg, rect;
    int w, h;

    fff.read((char*)&buf, 18);
    ggg.write((char*)&buf, 18);
    fff.read((char*)&w, 4); cout << "w=" << w;
    fff.read((char*)&h, 4); cout << ", h=" << h;
    w = 256; ggg.write((char*)&w, 4);
    h = 256; ggg.write((char*)&h, 4);
    fff.read((char*)&buf, 28);
    ggg.write((char*)&buf, 28);

    cout << "\nЦвет фона (B G R):\n";
    int cr, cg, cb;
    cin >> cb >> cg >> cr;
    bg = { (unsigned char)cr, (unsigned char)cg, (unsigned char)cb };

    cout << "\nЦвет фигуры (B G R):\n";
    cin >> cb >> cg >> cr;
    rect = { (unsigned char)cr, (unsigned char)cg, (unsigned char)cb };

    int size_width, size_height;
    cout << "\nРазмер фигуры (width height):\n";
    cin >> size_width >> size_height;


    int point_x = w - size_width;
    int point_y = h - size_height;

    for (int cartesian_y = 0; cartesian_y < h; ++cartesian_y) {
        for (int cartesian_x = 0; cartesian_x < w; ++cartesian_x) {
            if (cartesian_x >= point_x &&
                cartesian_x < point_x + size_width &&
                cartesian_y >= point_y &&
                cartesian_y < point_y + size_height) {
                ggg.write((char*)&rect, sizeof(rect));
            }
            else {
                ggg.write((char*)&bg, sizeof(bg));
            }
        }
    }

    fff.close();
    ggg.close();
    cout << "\nИзображение успешно создано!\n";
    return 0;
}
