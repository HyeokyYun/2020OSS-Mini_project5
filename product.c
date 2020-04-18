#include "product.h"

int addProduct(Product *p){
	printf("[제품의 정보입력]\n");
	printf("제품의 이름: ");
	scanf(" %[^\n]*s", p->name);
	printf("제품의 가격: ");
	scanf("%d", &p->price);
	printf("제품의 중량: ");
	scanf("%f", &p->weight);
	while(1){
		printf("제품의 별점(1~5): ");
		scanf("%d", &p->stars);
		if(p->stars > 5 || p->stars < 1) printf("별점은 1~5까지 줄 수 있습니다. 다시 입력해주세요.\n");
		else break;
	}
	printf("==> 제품이 등록되었습니다.\n");

	return 1;
}

void readProduct(Product p){
	if(p.price == -1 && p.weight == -1)return;
	p.avgweight = (p.price/p.weight)*10;
	printf("     %-20s   %5.1f g        %-5d 원       %-5d 원       %-2d 점\n", p.name, p.weight, p.price, p.avgweight, p.stars);
}

int updateProduct(Product *p){
	printf("[제품의 수정 사항입력]\n");
	printf("제품의 이름: ");
	scanf(" %[^\n]*s", p->name);
	printf("제품의 가격: ");
	scanf("%d", &p->price);
	printf("제품의 중량: ");
	scanf("%f", &p->weight);
	while(1){
		printf("제품의 별점(1~5): ");
		scanf("%d", &p->stars);
		if(p->stars > 5 || p->stars < 1) printf("별점은 1~5까지 줄 수 있습니다. 다시 입력해주세요.\n");
		else break;
	}
	printf("==> 제품이 수정되었습니다.\n");
	return 1;
}

int deleteProduct(Product *p){
	p->weight = -1;
	p->price = -1;
	printf("==> 제품이 삭제되었습니다.\n");
	return 1;
}
