#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//Brute force
class Solution {
public:
	
	int strStr(std::string &haystack, std::string &needle) {
		//by force
		int needlelen = needle.length();
		if (needlelen == 0)
			return 0;//return 0 when needle is empty 
		int haystacklen = haystack.length();
		
		for (int i = 0; i <= haystacklen - needlelen;++i ) 
		{
			if (needle == haystack.substr(i, needlelen))
			{
				return i;
			}
		}
		return -1;
	}
};
//The same destination with KMP algorithm
class KMPSolution {
public:
	int strStr(std::string &haystack, std::string &needle) {
		int haystacklen = haystack.length(), needlelen = needle.length();
		if (!needlelen) 
			return 0;
		std::vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < haystacklen; ) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			if (j == needlelen) return i - j;
			if (i < haystacklen && haystack[i] != needle[j]) {
				if (j) j = lps[j - 1];
				else i++;
			}
		}
		return -1;
	}
private:
	std::vector<int> kmpProcess(std::string& needle) {
		int n = needle.length();
		std::vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n; ) {
			if (needle[i] == needle[len])
				lps[i++] = ++len;
			else if (len) len = lps[len - 1];
			else lps[i++] = 0;
		}
		return lps;
	}
};
int main() 
{
	std::string s1("A character sequence");
	std::string s2("queue");
	KMPSolution test;
	std::cout<<test.strStr(s1, s2);
}