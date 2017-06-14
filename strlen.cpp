#include <cstdlib>
#include <iostream>

size_t strlen(const char *str) 
{
	//const char *s;
	size_t result;
	for (auto s = str; *s != '\0'; ++s) 
	{
		 result = s - str;
	}
	return result;
}

//int main() 
//{
//	const char temp[] = { 'a','b','g','4','2','6','0','d','1','1','1','1','1','1','1','1','1','2','0' };
//	std::cout<<strlen(temp);
//}