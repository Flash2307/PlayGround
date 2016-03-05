#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	uint16_t message;

    cerr << "Test game started\nWaiting for input...\n";

    while( 1 )
	{
		std::cin >> message;
		cerr << "message:" << message << '\n';
	}

    return 0;
}
