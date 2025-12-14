#include <iostream>
#include <cstdlib>

extern "C" {

    int __stdcall outrad(char* ptr) 
    {
        if (ptr == nullptr)
        {
            std::cout << std::endl;
        }
        for (int i = 0; ptr[i] != '\0'; i++)
            std::cout << ptr[i];
        return 0;
    }

    int __stdcall outlich(int value)
    {
        std::cout << value;
        return 0;
    }


    int __stdcall mypow(char* ptr, int num, int exponent) 
    {
        int res = 1;
        for (int i = 0; i < exponent; i++)
        {
            if (res * num > 127 || res * num < -128)
            {
                std::cout << "Переполнение в функции pow" << std::endl;
                return res > 0 ? 127 : -128;
            }
            res *= num;
        }
        return res;
    }

    int __stdcall myabs(char* ptr, int value)
    {
        return value < 0 ? -value : value;
    }

    void _pause() 
    {
        system("pause");
    }
}
