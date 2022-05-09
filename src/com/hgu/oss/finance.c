#include <stdio.h>
#include <stdlib.h> 
#include "finance.h"

int creatData (Data *d) {
    printf("\n**Set data**\n") ;
    printf("Year : ") ;
    scanf("%d", &d->year) ;
    printf("month : ") ;
    scanf("%d", &d->month) ;
    printf("date : ") ;
    scanf("%d", &d->date) ;
    printf("how much money do you have (won) ? ") ;
    scanf("%d", &d->deposit) ;
    printf("How much did you spend today? ") ;
    scanf("%d", &d->withdraw) ;
    d->balance = d->balance + d->deposit - d->withdraw ;

    return 1 ; 
} 

int listData(Data *d, int count) {
    if(count != 0){
        printf("**Fainance Log**\n") ;
        for(int i=0; i<count; i++){
            if(d[i].balance == -1) continue ; 
            else readData(d[i]) ;
        }
    }
    else printf("No data exist yet \n") ;
}

int readData(Data d) {
    printf("date : %d %d %d. ", d.year, d.month, d.date) ;
    printf("money left : %d", d.balance) ; 
}

int updateData(Data *d) {
    printf("Update NewData\n") ;
    printf("Year : ") ;
    scanf("%d", d->year) ;
    printf("month : ") ;
    scanf("%d", d->month) ;
    printf("date : ") ;
    scanf("%d", d->date) ;
    printf("how much money do you have (won) ? ") ;
    scanf("%d", d->deposit) ;
    printf("How much did you spend today? ") ;
    scanf("%d", d->withdraw) ;
    d->balance = d->balance + d->deposit - d->withdraw ;
    return 1 ; 
}

int deleteData(Data *d, int count) {
    int year, month, date ; 
    printf("** Delete Fianance Data **\n") ;
    printf("Delete Year : ") ;
    scanf("%d", &year) ;
    printf("Delete Month : ") ; 
    scanf("%d", &month) ; 
    printf("Delete date : ") ;
    scanf("%d", &date) ;
    for(int i=0; i<count; i++){
        if(d[i].year == year && d[i].month == month && d[i].date == date){
            d[i].balance = -1 ;
            printf("** Data Deleted ! **\n") ;
        }
        else continue ;
    }
}

int showMenu() {
    int menu ;
    printf("\n------Finance Care Program-------\n");
    printf("1. Show my total deposit\n") ; //readData
    printf("2. Add today's withdraws\n") ; //updateData
    printf("3. Edit deposit\n") ; //updateData
    printf("4. Delete my deposit \n") ; //deleteData 
    printf("0. Exit \n") ;
    printf("=> choose menu ? ") ;
    scanf("%d", &menu) ;
    return menu ; 
}
