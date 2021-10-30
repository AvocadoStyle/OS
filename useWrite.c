#include <unistd.h>

#define STDOUT 1


int main()
{
	char buff[] = "hey\n";
	write(STDOUT, buff, 4);
	return 0;
}
