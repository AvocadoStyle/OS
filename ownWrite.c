#define __NR_write 4

unsigned int my_write(int std, char *buff, unsigned int size)
{
	unsigned int res;
	/*asm volatile or __asm__*/
	asm volatile ( "int $0x80"
	: "=a" (res)
	: "a" (__NR_write), "b" (std), "c" (buff), "d" (size)
	:"memory" 
	);

	return res;
}


int main()
{
	char buff[] = "heybye";
	my_write(1, buff, 6);

	return 0;
}
