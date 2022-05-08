#include <stdio.h>

typedef struct {
        //char name[20] ; //사용자 이름 
        /*날짜 설정*/
        int year ; 
        int month ; 
        int date ; 
        /* 개인이 갖고 있는 돈관리 */
        int deposit ; //내가 하루에 얻은 돈 
        int balance ; //내가 가지고 있는 돈 
        int withdraw ; //내가 지출한 돈 
}Data ;

int listData(Data *d, int count) ;
int creatData (Data *d) ; 
int readData(Data d) ; 
int updateData(Data *d) ;
int deleteData(Data *d, int count) ; 

int showMenu() ; 

