#include <iostream>

class Vec3D
{
    public:
        int x;
        int y;
        int z;
};

Vec3D vec1;
Vec3D vec2;

int main()
{
    int x{10};
    vec1.x = 10;
    vec1.y = 12;
    vec1.z = 25;

    std::cout << x << std::endl;

    return 0;
}