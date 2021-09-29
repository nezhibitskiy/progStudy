#include <iostream>

#define X_SIZE 6 
#define Y_SIZE 6 

typedef enum Direction
{
    DIRECTION_START     = 0,
    DIRECTION_RIGHT     = 1,
    DIRECTION_UP        = 2,
    DIRECTION_LEFT      = 3,
    DIRECTION_DOWN      = 4
} Direction_t;

int inputArr[Y_SIZE][X_SIZE] = { {1, 0, 0, 0, 0, 0},
                                 {0, 1, 0, 1, 1, 1},
                                 {0, 0, 1, 0, 1, 0},
                                 {1, 0, 0, 0, 1, 0},
                                 {0, 1, 1, 1, 0, 0},
                                 {1, 0, 0, 0, 0, 1}};

int islands[Y_SIZE][X_SIZE] =  { {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0} };

int tmpArr[6][6];



bool checkBorder(int x, int y, Direction_t direction)
{
    if (x == 0 || x == 5 || y == 0 || y == 5)
    {
        if (inputArr[y][x] == 1)
            return true;
        else return false;
    }
    else if (inputArr[y][x] == 1)
    {
        switch (direction)
        {
        case(DIRECTION_START):
            if (checkBorder(x - 1, y, DIRECTION_LEFT))
                return true;
            else if (checkBorder(x, y - 1, DIRECTION_UP))
                return true;
            else if (checkBorder(x + 1, y, DIRECTION_RIGHT))
                return true;
            else if (checkBorder(x, y + 1, DIRECTION_DOWN))
                return true;
            break;
        case (DIRECTION_LEFT):
            if (checkBorder(x - 1, y, DIRECTION_LEFT))
                return true;
            else if (checkBorder(x, y - 1, DIRECTION_UP))
                return true;
            else if (checkBorder(x, y + 1, DIRECTION_DOWN))
                return true;
            break;
        case (DIRECTION_UP):
            if (checkBorder(x - 1, y, DIRECTION_LEFT))
                return true;
            else if (checkBorder(x, y - 1, DIRECTION_UP))
                return true;
            else if (checkBorder(x + 1, y, DIRECTION_RIGHT))
                return true;
            break;
        case(DIRECTION_RIGHT):
            if (checkBorder(x, y - 1, DIRECTION_UP))
                return true;
            else if (checkBorder(x + 1, y, DIRECTION_RIGHT))
                return true;
            else if (checkBorder(x, y + 1, DIRECTION_DOWN))
                return true;
            break;
        case(DIRECTION_DOWN):
            if (checkBorder(x - 1, y, DIRECTION_LEFT))
                return true;
            else if (checkBorder(x + 1, y, DIRECTION_RIGHT))
                return true;
            else if (checkBorder(x, y + 1, DIRECTION_DOWN))
                return true;
            break;
        }
    }
    return false;
}

int main()
{
    for (unsigned int i = 0; i < X_SIZE; i++)
        for (unsigned int j = 0; j < Y_SIZE; j++)
            tmpArr[j][i] = inputArr[j][i];

    for (unsigned int i = 0; i < X_SIZE; i++)
        for (unsigned int j = 0; j < Y_SIZE; j++)
            if (inputArr[j][i] == 1)
            {
                if (!checkBorder(i, j, DIRECTION_START))
                {
                    islands[j][i] = 1;
                    inputArr[j][i] = 0;
                }
            }

    for (unsigned int i = 0; i < Y_SIZE; i++)
    {
        for (unsigned int j = 0; j < X_SIZE; j++)
            std::cout << tmpArr[i][j] << " ";
        std::cout << "    ";
        for (unsigned int j = 0; j < X_SIZE; j++)
            std::cout << islands[i][j] << " ";
        std::cout << "    ";
        for (unsigned int j = 0; j < X_SIZE; j++)
            std::cout << inputArr[i][j] << " ";
        std::cout << std::endl;
    }

}
