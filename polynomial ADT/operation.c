#include<stdio.h>
#include<stdlib.h>
#include "list.h"

list poly_add(list head1,list head2){
	printf("recahed");
	list temp1=head1;
	list temp2=head2;
	list temp;init(&temp);
	
	while(temp1 && temp2){
			if(temp1->power > temp2->power ){
				append(&temp,temp1->coff,temp1->power);
				temp1=temp1->next;
			}
			else if(temp1->power < temp2->power){
				append(&temp,temp1->coff,temp2->power);
				temp2=temp2->next;
			}
			else{
				append(&temp,((temp1->coff)+(temp2->coff)),temp1->power);
				temp1=temp->next;
				temp2=temp2->next;
			}
	}
	list temp3;init(&temp3);
	if(temp1){temp3=temp1;}
	if(temp2){temp3=temp2;}
	while(temp3){
		append(&temp,temp3->coff,temp3->power);
		temp3=temp3->next;
	}
	
	
	return temp;
	traverse(temp);

}
