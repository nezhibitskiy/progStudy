#include <iostream>
#include <sstream>

#define MAX_DATA_COUNT 10

class Data_c {
    /*Data_c(){
        x = 0;
        y = 0;
        z = 0;
    }*/
public:
    float x;
    float y;
    float z;
};

Data_c data[MAX_DATA_COUNT];

int main()
{
    std::string inputData = "0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.3 1.4 1.5 1.6";

    std::stringstream stream;

    stream << inputData;
    uint16_t i = 0;
    while (!stream.eof())
    {
        if (i % 3 == 0)
        {
            stream >> data[i / 3].x;
        }
        if (i % 3 == 1)
        {
            stream >> data[i / 3].y;
        }
        if (i % 3 == 2)
        {
            stream >> data[i / 3].z;
        }
        i++;
    }
    uint16_t j = i / 3;
    if (i % 3 != 0)
        j++;
    for (i = 0; i < j; i++)
    {
        std::cout << data[i].x << " " << data[i].y << " " << data[i].z << std::endl;
    }
}
