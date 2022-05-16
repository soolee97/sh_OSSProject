#include <stdio.h>
#include <stdlib.h> 
#include "finance.h"

int main() {
    Data d[20] ; 
    int selectMenu ; 
    int count = 0 , index = 0 ;
    int balance;
    index = count ; 
    FILE* fp;
    FILE* fp2;
    char id[20];
    char pw[20];
    int opt;
    int check;
    
    fp = fopen("account.txt", "a");
    //fp2 = fopen("checkFirstBalance.txt", "a");
    while(1){
        opt = showLoginOpt();
        if(opt == 0){
            return 0;
        }
        else if(opt == 1){
            if(login()){}
            else {
                printf("아이디나 비밀번호가 잘못되었습니다.\n");
                continue;
            }
        }
        else if(opt == 2){
            if(makeAccount()){
                printf("회원가입에 성공하셨습니다! \n\n");
            }
            else {
                printf("회원가입에 실패했습니다 \n\n");
                continue;
            }
                
        }
        // 처음에만 현재 잔고 입력 
        while(1){
            //if(checkFirstBalance())
            //    break;
            printf("현재 잔고 입력: ");
            scanf("%d", &balance);
            if(balance>=0){
                //writeBalance();
                break;
            }
            else{
                printf("0이상의 숫자를 입력해주세요.\n");
            }
        }
    
        while(1){
            selectMenu = showMenu () ; 

            if(selectMenu == 0) { //0. exit
                printf("종료\n") ; 
                return 0; 
            }
            else if (selectMenu == 1) { //1. list log 
                listData(d, index) ;
            }
            else if (selectMenu == 2) { //2. add data
                balance = createData(&d[index++] , balance) ; 
                compareData(d, index);
                printPhrase();
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
            else if (selectMenu == 5) { //4. delete data 
                break;
            }

        }
    }
}
