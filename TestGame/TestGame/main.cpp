#include <iostream>
#include <cstdint>

#include "../../OS/src/GamepadMsg.h"

using namespace std;

int main()
{
	CommandFrame message;

    cerr << "Test game started\nWaiting for input...\n";

    while( 1 )
	{
		std::cin >> message.cmd;
		cerr << "x:" << message.acc.x << '\n';
		cerr << "y:" << message.acc.y << '\n';
		cerr << "z:" << message.acc.z << '\n';
		cerr << "other:" << message.acc.other << '\n';
	}

    return 0;
}
