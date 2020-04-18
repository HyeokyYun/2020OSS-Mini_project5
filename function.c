#include "function.h"

void saveData(Product *p, int count){
	FILE *fp;

	fp = fopen("Product_List.txt", "wt");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1 && p[i].weight == -1)continue;
		fprintf(fp, "%.1f %d %d %d %s\n",  p[i].weight, p[i].price, p[i].avgweight, p[i].stars,p[i].name);
	}
	fclose(fp);
	printf("=> 등록된 제품이 저장되었습니다.\n");
}

int loadData(Product *p){
	FILE *fp;
	
	fp = fopen("Product_List.txt", "rt");
	if(fp == NULL){
		printf("=> 저장된 파일이 없습니다.\n");
		return 0;
	}
	int count = 0;
	for(;;count++){
		fscanf(fp, "%f %d %d %d %[^\n]s", &p[count].weight, &p[count].price, &p[count].avgweight, &p[count].stars, p[count].name);
		if(feof(fp))break;
	}
	fclose(fp);
	printf("\n==> 저장된 제품목록을 로딩하였습니다.\n");
	return count;
}

int searchMenu(){
	int searchNum;
	printf("\n===[제품검색메뉴]===\n");
	printf("1. 이름으로 찾기\n");
	printf("2. 가격으로 찾기\n");
	printf("3. 평점으로 찾기\n");
	printf("4. 중량으로 찾기\n");
	printf("0. 검색기능 종료\n");
	printf("=====================\n");
	printf("==> 사용할 메뉴: ");
	scanf("%d", &searchNum);
	printf("=====================\n");
	

	return searchNum;
}

void searchByName(Product *p, int count){
	int nameCount = 0;
	char searchName[20];
	printf("[이름으로 제품검색]\n");
	printf("입력: ");
	scanf("%s", searchName);
	
	printf("\n== = = [등록된 제품 목록] = = ==\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1 && p[i].weight == -1)continue;
		if(strstr(p[i].name, searchName)){
			printf("이름에 \"%s\" 를 포함하는 제품(들)입니다.\n", searchName);
			
			readProduct2(p[i]);
			nameCount++;
		}
	}
	if(nameCount == 0){
		printf("==> 이름에 \"%s\" 를 포함하는 제품은 없습니다.\n", searchName);
	}
}

void searchByPrice(Product *p, int count){
	int priceCount = 0;
	int maxPrice = 0;
	int minPrice = 0;
	printf("[가격으로 제품검색]\n");
	printf("최소가격입력: ");
	scanf("%d", &minPrice);
	printf("최대가격입력: ");
	scanf("%d", &maxPrice);
	
	printf("\n[%d원 ~ %d원 사이의 제품목록]\n", minPrice, maxPrice);
	printf("================================\n");
	for(int i = 0; i < count; i++){
		if(p[i].price == -1 && p[i].weight == -1)continue;
		if(maxPrice >= p[i].price && minPrice <= p[i].price){
			readProduct2(p[i]);
			priceCount++;
		}
	}
	if(priceCount == 0){
		printf("==> 찾는 제품이 없습니다.\n");
	}
}
