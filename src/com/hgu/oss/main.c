#include <stdio.h>
#include <stdlib.h> 
#include "finance.h"

int main() {
    Data d[20] ; 
    int selectMenu ; 
    int count = 0 , index = 0 ;
    index = count ; 

    while(1){
    selectMenu = showMenu () ; 

    if(selectMenu == 0) break ; //0. exit
    else if (selectMenu == 1) { //1. list log 
        listData(d, index) ;
    }
    else if (selectMenu == 2) { //2. add data
        count += creatData(&d[index++]) ; 
    }
    else if (selectMenu == 3) { //3. update data
        
    }
    else if (selectMenu == 4) { //4. delete data 
        deleteData(d, index) ; 
    }

    }

}
