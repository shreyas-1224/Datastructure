#include<stdio.h>
#include "dll.h"

/*int main(){
    list number1,number2;
    number(&number1,260);
    printf("\n");
    number(&number2,0);
    printf("\n%lld",addition(number1,number2));

}*/

int main(){
    list head,last;
    init(&head);
    init(&last);
    append(&head,&last,23);
    append(&head,&last,29933);
    append(&head,&last,2343);
    append(&head,&last,2533);
    append(&head,&last,2);
    _traverse(head);


    return 1;

}

