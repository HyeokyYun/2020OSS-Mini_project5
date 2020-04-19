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

int main(void) {
  int choice;
  int count = 0;
  Product plist[100];
  int curcount = 0;
  int searchChoice;
  count = loadData(plist);
  curcount = count;

  while(1){
	  choice = programMenu();
	  #ifdef DEBUG
	  	printf("Debug : %s %s %s %d. call the function programMenu()\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
	  #endif

	  if(choice == 0)break;
	  else if(choice == 1){
	  #ifdef DEBUG
	  	printf("Debug : %s %s %s %d. call the function listProduct(plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
	  #endif
		  if(count > 0){
			  listProduct(plist, curcount);
		  }
		  else {
			printf("==> 등록된 제품이 없습니다.\n");
			printf("==> 제품정보를 등록하세요.\n");
		  }
	  }
	  else if(choice == 2){
		  #ifdef DEBUG
		      printf("Debug : %s %s %s %d. call the function addProduct(&plist[curcount++])\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
		  #endif
		  count += addProduct(&plist[curcount++]);
	  }
	  else if(choice == 3){
		  if(count > 0){
		    #ifdef DEBUG
	  			printf("Debug : %s %s %s %d. call the function selectDataNo(&plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
	  		#endif
			int select = selectDataNo(plist, curcount);
			if(select == 0){
				printf("==> 수정이 취소됩니다.\n");
				continue;
			}
			#ifdef DEBUG
	  			printf("Debug : %s %s %s %d. call the function updateProduct(&plist[select - 1])\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
	  		#endif
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
			#ifdef DEBUG
	  			printf("Debug : %s %s %s %d. call the function selectDataNo(&plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
	  		#endif
			int select = selectDataNo(plist, curcount);
			if(select == 0){
				printf("==> 삭제가 취소됩니다.\n");
				continue;
			}
			printf("데이터를 삭제합니다. (Y/y)");
		  	scanf("%s", &deleteok);
		  	if(deleteok == 'y' || deleteok == 'Y'){
				#ifdef DEBUG
					printf("Debug : %s %s %s %d. call the function deleteProduct(&plist[select - 1])\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
				#endif
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
	  else if(choice == 5){
		  if(count > 0){
			  #ifdef DEBUG
					printf("Debug : %s %s %s %d. call the function saveData(plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
			  #endif
			  saveData(plist, curcount);
		  }
		  else {
			  printf("==> 저장할 제품정보가 없습니다.\n");
			  printf("    제품정보를 등록하세요.\n");
		  }
	  }
	  else if( choice == 6){
		  while(1){
			  if(count > 0){
				  #ifdef DEBUG
					printf("Debug : %s %s %s %d. call the function searchMenu()\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
			  	  #endif
				  searchChoice = searchMenu();
				  if(searchChoice == 0){
					  printf("검색기능을 종료합니다.\n");
					  break;
				  }
				  else if(searchChoice == 1){
					  #ifdef DEBUG
						printf("Debug : %s %s %s %d. call the function searchByName(plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
			  	  	  #endif
					  searchByName(plist,curcount);
				  }
				  else if(searchChoice == 2){
					  #ifdef DEBUG
						printf("Debug : %s %s %s %d. call the function searchByName(plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
			  	  	  #endif
					  searchByPrice(plist,curcount);
				  }
				  else if(searchChoice == 3){
					  #ifdef DEBUG
						printf("Debug : %s %s %s %d. call the function searchByName(plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
			  	  	  #endif
					  searchByStars(plist,curcount);
				  }
				  else if(searchChoice == 4){
					  #ifdef DEBUG
						printf("Debug : %s %s %s %d. call the function searchByName(plist, curcount)\n\n", __DATE__, __TIME__, __FILE__, __LINE__, choice);
			  	  	  #endif
					  searchByWeight(plist,curcount);
				  }
				  else printf("==> [%d]에 해당하는 메뉴는 없습니다.\n==>다시 입력하세요.\n", searchChoice);
			  }
			  else{
				  printf("==> 검색할 제품정보가 없습니다.\n");
				  printf("==> 제품정보를 등록하세요.\n");
			  }
		  }
	  }
	  else printf("==> [%d]에 해당하는 메뉴는 없습니다.\n==>다시 입력하세요.\n", choice);
  }
  printf("==> 프로그램을 종료합니다.\n");
}
