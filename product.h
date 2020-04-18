#include <stdio.h>

typedef struct _product{
	char name[20];
	int price;
	float weight;
	int avgweight;
	int stars;
}Product;

int addProduct(Product *p);
void readProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
void saveData(Product *p, int count);
int loadData(Product *p);
int searchMenu();
void searchByName(Product *p, int count);
void searchByPrice(Product *p, int count);
void searchByStars(Product *p, int count);
void searchByWeight(Product *p, int count);
