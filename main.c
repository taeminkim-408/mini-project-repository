#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"
  int main(void){
      Data slist[100];
      int index = 0; 
      int count = 0;
      int menu;
      count = loadData(slist); /// 만들어야 하는 파일 1;

      index = count;
      while (1){
          menu = selectMenu();
          if (menu == 0) break;

          if(menu == 1){

          if(count > 0){
            listfruit(slist, index); 
          }
          else{
            printf("데이터가 없습니다.\n");
          } 
          }
        
          else if (menu == 2){
            addfruit(&slist[index++]);
            count++;

          }
          else if(menu == 3){
            int no = selectDataNo(slist, index);
            if(no == 0){
              printf("=> 취소됨!\n");
              continue;
             }
              updatefruit(&slist[no-1]);

  } 

        else if (menu == 4){
          int no = selectDataNo(slist, index);
              if(no == 0){
                printf("=> 취소됨!\n");
                  continue;
              }
              int deleteok;
                printf("정말로 삭제하시겠습니까?(삭제 :1)");
                scanf("%d", &deleteok);
              if(deleteok == 1){
              if(deletefruit(&slist[no-1])) count--;
                }
                }
        else if(menu==5){
            saveData(slist,index);
        }
        else if(menu==6){
            int check;
            printf("어떤 방식으로 검색하시겠습니다까?(1.이름 2.가격 3. 별점)");
            scanf("%d",&check);
            if(check==1){
              searchfruit1(slist, index);  
            }
            if(check==2){
              searchfruit2(slist, index);  
            }
            if(check==3){
              searchfruit3(slist, index);  
            }
          
        }
      }
                printf("종료됨!\n");
                return 0;// 끝나면 멈추기
  }
