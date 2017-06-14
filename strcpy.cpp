#include <iostream>
#include <cstdlib>
#include <assert.h>
char* strcp(char* to, const char *from) 
{
	assert(to != NULL && from != NULL);

	char* p = to;
	while ((*p++ = *from++) != '\0')
	{
		;
	}
	return to;
}
//int main() 
//{
//	char to[5] = {'h','a','h','a'};
//	char from[5] = {'h','e','h','e'};
//	strcp(to,from);
//	/*while (*to != '\0') 
//	{
//		++to;
//		std::cout << *to;
//	}*/
//}
