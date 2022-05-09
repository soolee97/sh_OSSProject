#include <stdio.h>
#include <stdlib.h> 
#include "finance.h"

int main() {
    Data d[20] ; 
    int selectMenu ; 
    int count = 0 , index = 0 ;
    int balance;
    index = count ; 
    
    /* 프로그램 처음 실행 할 때 잔고 입력 */
    // 추후 로그인 기능 넣어서 맨 처음 회원가입 했을 때만 입력받게끔 설정할 것임
    
    printf("현재 잔고 입력: ");
    scanf("%d", &balance);
    
    while(1){
        selectMenu = showMenu () ; 

        if(selectMenu == 0) { //0. exit
            printf("종료\n") ; 
            break ; 
        }
        else if (selectMenu == 1) { //1. list log 
            listData(d, index) ;
        }
        else if (selectMenu == 2) { //2. add data
            balance = createData(&d[index++] , balance) ; 
            compareData(d, index);
            count++;
        }
        else if (selectMenu == 3) { //3. update data
            listData(d, index);
            updateData(d, index);
        }
        else if (selectMenu == 4) { //4. delete data 
            listData(d, index);
            deleteData(d, index) ; 
            count--;
        }

    }

}
