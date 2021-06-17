#include"libOne.h"
struct POS {
    float x, y, z;
};
void gmain() {
    window(1000, 1000);
    const int num = 8;
    struct POS op[num] = {
        -1,1,-1,
        -1,-1,-1,
        1,-1,-1,
        1,1,-1,
        - 1,1,1,
        -1,-1,1,
        1,-1,1,
        1,1,1,
    };
    struct POS p[num];
    float deg = 0;
    angleMode(DEGREES);
    int state = 0;
    while (notQuit) {
        float s = sin(deg);
        float c = cos(deg);
        deg += 0.2;
        if (deg > 360) {
            deg = 0;
            ++state %= 2;
        }
        for (int i = 0; i < num; i++) {
            if (state == 0) {
                p[i].x = op[i].x * c + op[i].z * -s;
                p[i].y = op[i].y;
                p[i].z = op[i].x * s + op[i].z * c;
            }
            else {
                p[i].x = op[i].x;
                p[i].y = op[i].y * c + op[i].z * -s;
                p[i].z = op[i].y * s + op[i].z * c;
            }
            

            p[i].z += 5;

            p[i].x /= p[i].z;
            p[i].y /= p[i].z;
        }
        clear(217, 48, 92);
        mathAxis(1.2);
        stroke(224, 255, 204);
        strokeWeight(10);
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) %  4;
            mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
            mathLine(p[i+4].x, p[i+4].y, p[j+4].x, p[j+4].y);
            mathLine(p[i].x, p[i].y, p[i+4].x, p[i+4].y);
        }


    }
}
