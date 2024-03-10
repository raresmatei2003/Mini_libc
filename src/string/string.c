// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	if (destination == NULL)
		return NULL;

	char *aux = destination;

	for (; *source != '\0'; aux++, source++)
		*aux = *source;

	*aux = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	if (destination == NULL)
		return NULL;

	char *aux = destination;

	for (; *source != '\0' && len > 0; source++, aux++, len--)
		*aux = *source;

	for(; len > 0; aux++, len--)
		*aux = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat().*/

	if (destination == NULL)
		return NULL;

	char *aux = destination + strlen(destination);

	for (; *source != '\0'; aux++, source++)
		*aux = *source;

	*aux = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	if (destination == NULL)
		return NULL;

	char *aux = destination + strlen(destination);

	for (; *source != '\0' && len > 0; source++, aux++, len--)
		*aux = *source;

	*aux = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++)
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;

	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	else if (*str1 == '\0')
		return -1;
	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	for (; *str1 != '\0' && *str2 != '\0' && len > 0; str1++, str2++, len--)
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;

	if (len == 0)
		return 0;

	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	else if (*str1 == '\0')
		return -1;
	return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	if (str == NULL)
		return NULL;

	for (; *str != c && *str != '\0'; str++)
		;

	if (*str)
		return (char *)str;
	else
		return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	char *aux = (char *)str;
	str += strlen(str) - 1;

	for (; *str != c && str != aux; str--)
		;

	if (str != aux)
		return (char *)str;
	else
		return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	size_t poz;

	for(poz = 0; poz <= strlen(haystack) - strlen(needle); poz++)
	{
		if(strncmp(haystack + poz, needle, strlen(needle)) == 0)
			return (char *)(haystack + poz);
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	size_t poz = strlen(haystack) - strlen(needle) + 1;

	do
	{
		poz--;
		if(strncmp(haystack + poz, needle, strlen(needle)) == 0)
			return (char *)(haystack + poz);
	}while(poz > 0);

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	void *aux = destination;

	for (; num; num--, aux++, source++)
		*((char *)aux) = *((char *)source);

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	void *buff = malloc(num * sizeof(char));

	memcpy(buff, source, num);
	memcpy(destination, buff, num);

	free(buff);
	buff = NULL;

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */

	for (; *((char *)ptr1) != '\0' && *((char *)ptr2) != '\0' && num > 0; ptr1++, ptr2++, num--)
	{
		if (*((char *)ptr1) - *((char *)ptr2) != 0)
			return (int)(*((char *)ptr1) - *((char *)ptr2));
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	for (; num > 0; source++, num--)
		*((unsigned char *)source) = (unsigned char)value;
	return source;
}
