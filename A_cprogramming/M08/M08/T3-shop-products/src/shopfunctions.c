#include "shopfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * \brief Returns a comparison value obtained by comparing the names of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details The name field of a Product is a string.
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns 0 if a == b
 * \returns a positive number if b should be placed before a
 */
int compareAlpha(const void* a, const void* b) {
	//const char* sa = (const char*)malloc(sizeof(a));
	//const char* sb = (const char*)malloc(sizeof(b));
	//sa = (const char*)a;
	//sb = (const char*)b;
	(void)a;
	(void)b;
	return strcmp((const char*)a, (const char*)b);
}

/**
 * \brief Returns a comparison value obtained by comparing in_stock of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details in_stock is an integer, and the products with higher stock should be
 *          placed before the products with lower stock. 
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns result of compareAlpha(a, b) if a == b
 * \returns a positive number if b should be placed before a
 */
int compareNum(const void* a, const void* b) {
	 
	const Product* pa = a;
	const Product* pb = b;
	int compalpha = compareAlpha(pa->name, pb->name);
	int res = pb->in_stock - pa->in_stock;
	if(res == 0)
	{
		return compalpha;
	}
	else
	{
		return res;
	}

	(void)a;
	(void)b;
	return 0;
}

const Product* findProduct(const Product* p_array,
						   const char* search_key,
						   int (*cmp)(const void*, const void*)) {
	int n = 0;
	while (p_array[n].name[0] != 0)
	{
		n++;
	}
	Product* p_item = bsearch(search_key, p_array, n, sizeof(p_array[0]), cmp);
	return p_item;
}
