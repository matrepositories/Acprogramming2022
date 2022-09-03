#include "shop.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * \brief Writes the products in the shop into the specified binary file. 
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_binary(const char* filename, const Product* shop) {
	FILE* f = fopen(filename, "wb");
	if(!f)
    {
        return 1;
    }
	int n = 0;
	while (shop[n].name[0] != 0)
	{
		n++;
	}
	fwrite(shop, sizeof(Product), n, f);
    fclose(f);
	return 0;
	}



/**
 * \brief Reads the shop products from the specified binary file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 */
Product* read_binary(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if(!f)
    {
        return NULL;
    }
	int i = 0;
	Product *dynarray = calloc(1, sizeof(Product)); //+1 ja NULL
	
	
	while(fread(&dynarray[i], sizeof(Product), 1, f))
	{
		dynarray = realloc(dynarray, (i + 2) * sizeof(Product));
		memset(&dynarray[i + 1], 0, sizeof(Product));
		//dynarray[i] = malloc(sizeof(Product));
		i++;
	}
	//dynarray = realloc(dynarray, (i + 1) * sizeof(Product));
	fclose(f);
	return dynarray;
	}
	

/**
 * \brief  Writes the shop products into a text file.
 * 
 * \details The file writes each product as follows.
 * 
 *          <product-name> <price> <in-stock>
 * 
 *       In other words, the structure fields are separated with a space, and the array 
 *       elements are separated by a newline. Because the data items are separated by a 
 *       space, the product name should not have spaces in it.
 * 
 *       The last array element (with the name of null character) should not be 
 *       written into the file.
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_plaintext(const char* filename, const Product* shop) {
	FILE *f = fopen(filename, "w");
	int k = 0;
	int n = 0;
	if (!f)
	{
		return 1;
	}
	while (shop[n].name[0] != 0)
	{
		n++;
	}
	while(k < n)
	{
		fprintf(f, "%s %f %d\n", shop[k].name, shop[k].price, shop[k].in_stock);
		/*fwrite(shop[k].name, sizeof(Product), 1, f);
		fputc(' ', f);
		fwrite(shop[k].in_stock, sizeof(Product), 1, f);
		fputc(' ', f);
		fwrite(shop[k].price, sizeof(Product), 1, f);
		fputc('\n', f);*/
		k++;
	}
	fclose(f);
	return 0;
	}

/**
 * \brief Reads the shop products from the specified text file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 *
 * \note You can parse each line using sscanf function.
 */
Product* read_plaintext(const char* filename) {
	FILE *f = fopen(filename, "r");
	if (!f)
	{
		return NULL;
	}
	int i = 0;
	int bignumber = 10000;
	char* s1 = calloc(1, bignumber);

	Product *dynarray = calloc(1, sizeof(Product)); //+1 ja NULL
	while(fgets(s1, bignumber, f))
	{
		dynarray = realloc(dynarray, (i + 1) * sizeof(Product));
		memset(&dynarray[i], 0, sizeof(Product));
		sscanf(s1, "%s %f %d\n", dynarray[i].name, &dynarray[i].price, &dynarray[i].in_stock);
		i++;
	}
	dynarray = realloc(dynarray, (i + 1) * sizeof(Product));
	memset(&dynarray[i], 0, sizeof(Product));
	fclose(f);
	free(s1);
	return dynarray;
	}
