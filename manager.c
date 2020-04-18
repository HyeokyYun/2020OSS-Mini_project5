#include "manager.h"

void listProduct(Product *p, int count){
	printf("\n등록번호|     제품이름     |  제품중량(g)  |  제품가격(원)  |   10g/원   |  제품평점\n");
	printf("=====================================================================================\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1 && p[i].weight == -1) continue;
		printf("%5d", i+1);
		readProduct(p[i]);
	}
	printf("\n");
}

void readProduct2(Product p){
	if(p.price == -1 && p.weight == -1)return;
	p.avgweight = (p.price/p.weight)*10;
	
	printf("제품이름: %-4s\n", p.name);
	printf("제품중량: %-4.1f g\n", p.weight);
	printf("제품가격: %-4d 원(10g당: %d 원)\n", p.price, p.avgweight);
	printf("제품별점: ");
	for(int i=0 ; i<p.stars; i++){
   		printf("★ ");
	}
	printf("\n================================\n");
}

void listProduct2(Product *p, int count){
	printf("\n = = = [등록된 제품 목록] = = =\n");
	printf("================================\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1 && p[i].weight == -1)continue;
		printf("등록번호: %d\n", i+1);
		readProduct2(p[i]);
	}
	printf("\n");
}

int selectDataNo(Product *p, int count){
	int num;
	listProduct2(p, count);
	printf("작업할 제품번호(취소: 0): ");
	scanf("%d", &num);
	return num;
}
