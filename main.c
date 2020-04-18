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
