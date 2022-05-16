#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "finance.h"
#include <time.h>

void buffer(void){
        while(getchar()!='\n') ;
}

int createData (Data *d, int money) {
    printf("\n**데이터 입력**\n");
    printf("년도 : ") ;
    scanf("%d", &d->year);
    printf("월 : ") ;
    scanf("%d", &d->month);
    printf("일 : ") ;
    scanf("%d", &d->date);
    printf("수입: ") ;
    scanf("%d", &d->deposit); 
    printf("지출: ") ;
    scanf("%d", &d->withdraw);
    getchar();
    printf("한줄 메모: ");
    fgets(d->memo, 100,stdin);
    d->balance = money + d->deposit - d->withdraw ;
    printf("%d원 남았습니다.\n", d->balance);
    return d->balance ; 
} 

int listData(Data *d, int count) {
    if(count != 0){
        printf("**조회**\n") ;
        for(int i=0; i<count; i++){
            if(d[i].balance == -1) continue ; 
            else {
                printf("%d) ", i+1);
                readData(d[i]) ;
            }
        }
        return 1;
    }
    else printf("No data exist yet \n") ;
    return 0;
}

int readData(Data d) {
    printf("날짜 : %d %d %d %s", d.year, d.month, d.date, d.memo) ;
    printf("   남은 잔고 : %d\n", d.balance) ; 
    return 1;
}

int updateData(Data *d, int count) {
    int num;
    printf("**정보 수정**\n") ;
    printf("수정할 번호를 입력: ");
    scanf("%d", &num);
    if(num > count || num < 0){
        printf("번호를 잘못 입력하셨습니다.\n");
        return 0;
    }
    printf("년도 : ") ;
    scanf("%d", &d[num-1].year) ;
    printf("월 : ") ;
    scanf("%d", &d[num-1].month) ;
    printf("일 : ") ;
    scanf("%d", &d[num-1].date) ;
    printf("수입 : ") ;
    scanf("%d", &d[num-1].deposit) ;
    printf("지출 : ") ;
    scanf("%d", &d[num-1].withdraw) ;
    printf("한줄 메모 : ") ;
    scanf("%s", d[num-1].memo) ;
    
    d->balance = d->deposit - d->withdraw ;
    return 1 ; 
}

int deleteData(Data *d, int count) {

    int num;
    printf("**삭제**\n") ;
    printf("삭제할 번호 입력: ");
    scanf("%d", &num);
    d[num-1].balance = -1 ;
    printf("** 삭제 완료 ! **\n") ;
    return 1;
}

int showMenu() {
    int menu ;
    printf("\n------가계부 프로그램-------\n");
    printf("1. 기록 조회\n") ; //readData
    printf("2. 기록 쓰기\n") ; //updateData
    printf("3. 기록 수정\n") ; //updateData
    printf("4. 기록 삭제\n") ; //deleteData 
    printf("5. 로그아웃\n") ; //deleteData 
    printf("0. 종료 \n") ;
    printf("=>   ") ;
    scanf("%d", &menu) ;
    return menu ; 
}

void compareData(Data *d, int count){
    int withdraw;
    if(count>1){
        withdraw = (d[count-2].withdraw + d[count-2].deposit) - (d[count-1].withdraw + d[count-1].deposit);
    if(withdraw < 0)
        printf("전보다 %d원 더 쓰셨습니다.\n", -1*withdraw);
    else
        printf("전보다 %d원 덜 쓰셨습니다.\n", withdraw);
    }
}

int login(){
    char id[20];
    char pw[20];
    char read_id[20];
    char read_pw[20];
    FILE* fp = fopen("account.txt", "r");
    printf("ID: ");
    scanf("%s", id);
    printf("PW: ");
    scanf("%s", pw);
    while(!feof(fp)){
        fgets(read_id, 20, fp);
        read_id[strlen(read_id)-1] = '\0';
        fgets(read_pw, 20, fp);
        read_pw[strlen(read_pw)-1] = '\0';
        if((!strcmp(id,read_id)) && (!strcmp(pw,read_pw))){
            printf("-----------------------로그인 성공-----------------------\n");
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int makeAccount(){
    char id[20];
    char pw[20];
    FILE* fp = fopen("account.txt", "a");
    printf("ID: ");
    scanf("%s", id);
    printf("PW: ");
    scanf("%s", pw);

    fprintf(fp, "%s\n%s\n", id, pw);
    fclose(fp);
    fp = fopen("checkFirstBalance.txt", "w");

    return 1;
}

int showLoginOpt(){
    int choice;
    printf("0. 종료\n");
    printf("1. 로그인\n");
    printf("2. 회원가입\n");
    printf("=> ");
    scanf("%d", &choice);
    
    return choice;
}

void printPhrase(){
    char phrase[5][100] = {
        "오늘 하루도 수고 많았어요.\n",
        "내일은 더 행복한 하루가 될 거에요.\n",
        "티끌 모아 태산!\n",
        "오늘 하루 돈을 가치있게 쓰셨나요?.\n",
        "내일 또 기록해봐요!\n"
    };

    srand(time(NULL));
    printf("%s" , phrase[rand()%5]);
}
/*
int checkFirstBalance(){
    int flag;
    FILE *fp = fopen("checkFirstBalance.txt", "r");
    fscanf(fp, "%d", &flag);
    if(flag==1){
        fclose(fp);    
        return 1;
    }
    else 
        fclose(fp);    
    return 0;
}
void writeBalance(){
    FILE *fp = fopen("checkFirstBalance.txt", "a");
    fprintf(fp, "%d", 1);
    fclose(fp);
}
*/