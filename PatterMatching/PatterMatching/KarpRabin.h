#ifndef KARPRABIN_H
#define KARPRABIN_H

int KarpRabin(char* Text, int TextSize, int Start,
	char* pattern, int PatternSize);

int Hash(char* String, int Size);
int ReHash(char* String, int Start, int Size, int HahPrev,
	int Coefficient);

#endif