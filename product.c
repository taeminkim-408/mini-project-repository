#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"


 void readfruit(Data *s){
      printf("%8s %4d %4dg %4d",s->name,s->price,s->weight,s->starchoose);
  }

void saveData(Data *s, int count){
    FILE *fp;
    fp = fopen("menu.txt", "wt");
    for(int i = 0; i < count; i++){
      if(s[i].price == -1) continue;
      fprintf(fp,"%s %d %d %d\n",s->name,s->price,s->weight,s->starchoose);
    }
    fclose(fp);
    printf("=> 저장됨! ");
}

int loadData(Data *s){
    int count = 0, i;
    FILE *fp;
    fp = fopen("menu.txt", "rt");
    if(fp == NULL)printf("데이터 없음\n");
    else{
      for(i=0; i < 100; i++){
        fscanf(fp,"%s",s[i].name);
        fscanf(fp, "%d", &s[i].price);
        fscanf(fp, "%d", &s[i].weight);
        fscanf(fp, "%d", &s[i].starchoose);
        
       if(feof(fp)) break;
        
    }
      fclose(fp);
      printf("=> 로딩 성공!\n");
      return i;
    }
    return i;
    
}





int addfruit(Data *s){
    printf("추가할 과일은? ");
    scanf("%[^\n]",s->name);
    printf("과일의 총 무게는? ");
    scanf("%d",&s->weight);
    printf("가격은? ");
    scanf("%d",&s->price);
    printf("해당 별점은?(5점 만점)");
    scanf("%d",&s->starchoose);
  return 1;
  };

  void listfruit(Data *s, int count){
     printf("***찰리와 초콜릿 공장 뺨치는 달콤새콤 과일가게***\n");
     printf("상품명    가격   총량   별점(5점만점)\n");
    printf("=========================================\n");
    for(int i =0; i <count ; i++){
        if(s[i].price == -1) continue;
        printf("%2d ", i+1);
        readfruit(&s[i]);
        printf("\n");
    }
        printf("\n");
  
  }

 


int selectDataNo(Data *s, int count){
  int no;
  listfruit(s, count);
  printf("번호는 (취소 :0)? ");
  scanf("%d", &no);
  getchar();
  return no;
  }

  int updatefruit(Data *s){
    printf("새로 추가할 과일은? ");
    scanf("%[^\n]",s->name);
    printf("과일의 총 무게는? ");
    scanf("%d",&s->weight);
    printf("가격은? ");
    scanf("%d",&s->price);
    printf("해당 별점은?");
    scanf("%d",&s->starchoose);
  return 1;
  };
int deletefruit(Data *s){
     
      s->price = -1;
      printf("=> 삭제됨");
      return 1;;
  }


int selectMenu(){
      
      int menu;
      printf("\n*** 과일 상품 ***\n");
      printf("1. 판매중인 과일 조회\n");
      printf("2. 과일추가\n");
      printf("3. 판매중인 과일수정\n");
      printf("4. 판매중인 과일삭제\n");
      printf("5. 저장\n");
      printf("6. 과일 검색\n");
      printf("0. 종료\n\n");
      printf("=> 원하는 메뉴는? ");
      scanf("%d", &menu);
      getchar();
    
      return menu;
  }
void searchfruit1(Data *s, int count){
  int scnt = 0;
  char search[20];
    printf("검색할 과일이름은? ");
    scanf("%s", search);
    printf("*****************\n");
    printf("================================\n");
  for(int i =0; i <count ; i++){
    if(s[i].price == -1) continue;
    if(strstr(s[i].name, search)){
    printf("%2d ", i+1);
    readfruit(&s[i]);
    printf("\n");
    scnt++;
 }
 }
if(scnt == 0) printf("=> 검색된 데이터 없음!");
 printf("\n");
}
void searchfruit2(Data *s, int count){
  int scnt = 0;
  int search;
    printf("검색할 과일 가격은? ");
    scanf("%d", &search);
    printf("*****************\n");
    printf("================================\n");
  for(int i =0; i <count ; i++){
    if(s[i].price == -1) continue;
    if(s[i].price==search){
    printf("%2d ", i+1);
    readfruit(&s[i]);
    printf("\n");
    scnt++;
 }
 }
if(scnt == 0) printf("=> 검색된 데이터 없음!");
 printf("\n");
}
void searchfruit3(Data *s, int count){
  int scnt = 0;
  int search;
    printf("검색할 별점 수는? ");
    scanf("%d", &search);
    printf("*****************\n");
    printf("================================\n");
  for(int i =0; i <count ; i++){
    if(s[i].price == -1) continue;
    if(s[i].starchoose== search){
    printf("%2d ", i+1);
    readfruit(&s[i]);
    printf("\n");
    scnt++; }//해결해보장
 }
if(scnt == 0) printf("=> 검색된 데이터 없음!");
 printf("\n");
}// 나오게 하기
