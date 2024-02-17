#include "coin.hpp"

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

using namespace std;

int main()
{
    Coin coin;
    cout << "Welcome to flip a coin application" << endl;
    cout << "To flip a coin, press 'F' or 'f'" << endl;
    cout << "To check coin's state press 'S' or 's'" << endl;

    // event loop
    for (;;)
    {
        Sleep(200);
        if (_kbhit())
        {
            switch (_getch())
            {
                case 'F':
                case 'f':
                    cout << "'F', coin flipped: "<< coin.FlipCoin() << endl;
                    break;
                case 'S':
                case 's':
                    cout << "'S', coin state: " << coin.GetCoinState() << endl;
                    break;
                case '\33':  // <Esc> key
                    cout << endl << "'ESC', GoodBye";
                    _exit(0);
                    break;
            }
        }
    }
    return 0;
}