#include "function.h"

int programMenu(){
	int menuNum;
	printf("\n===[작업선택메뉴]===\n");
	printf("1. 제품정보 조회 메뉴.\n");
	printf("2. 제품정보 등록 메뉴.\n");
	printf("3. 제품정보 수정 수정.\n");
	printf("4. 제품정보 삭제 메뉴.\n");
	printf("5. 제품정보 저장 메뉴.\n");
	printf("6. 제품정보 검색 메뉴.\n");
	printf("0. 프로그램 종료.\n");
	printf("=====================\n");
	printf("[원하는 작업]=> ");
	scanf("%d", &menuNum);
	printf("=====================\n");

	return menuNum;
}

  while(1){
	  choice = programMenu();
	  if(choice == 0)break;
	  else if(choice == 1){
		  if(count > 0){
			  listProduct(plist, curcount);
		  }
		  else {
			printf("==> 등록된 제품이 없습니다.\n");
			printf("==> 제품정보를 등록하세요.\n");
		  }
	  }
	  else if(choice == 2){
		  addProduct(&plist[curcount++]);
		  count ++;
	  }
	  else if(choice == 3){
		  if(count > 0){
			int select = selectDataNo(plist, curcount);
			if(select == 0){
				printf("==> 수정이 취소됩니다.\n");
				continue;
			}
			updateProduct(&plist[select - 1]);
		  }
		  else {
			printf("==> 등록된 제품이 없습니다.\n");
			printf("==> 제품정보를 등록하세요.\n");
		  }
	  }
	  else if (choice == 4){
		  char deleteok;
		  if(count > 0){
			int select = selectDataNo(plist, curcount);
			if(select == 0){
				printf("==> 삭제가 취소됩니다.\n");
				continue;
			}
			printf("데이터를 삭제합니다. (Y/y)");
		  	scanf("%s", &deleteok);
		  	if(deleteok == 'y' || deleteok == 'Y'){
			deleteProduct(&plist[select - 1]);
			count--;
		  	}
		  	else printf("==> 제품삭제를 취소합니다.\n");
	  	  }
		  else {
			printf("==> 등록된 제품이 없습니다.\n");
			printf("==> 제품정보를 등록하세요.\n");
		  }
  	  }
