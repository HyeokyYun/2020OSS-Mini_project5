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
