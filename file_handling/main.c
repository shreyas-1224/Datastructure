#include<stdio.h>

/*int main(){
	FILE *fp,*fp2;
	fp=fopen("file.txt","r");
	fp2=fopen("newfile.txt","w");
	
	if(fp==NULL || fp2==NULL){
		printf("file could not opened");	
		return 0;
	}
	
	char c;
	c=fgetc(fp);
	while(c!=EOF){
		fputc(c,fp2);
		c=fgetc(fp);
	}
	printf("successful");
	return 1;
}
*/

int main(){
	FILE * fp;
	fp=fopen("newfile.txt","r+");
	if(fp==NULL){printf("234");return 0;}
	int a,b,c;
	fscanf(fp,"%d %d ",&a,&b);
	printf("%d %d\n",a,b);int i=0;
	while(fscanf(fp,"%d",&c)!=EOF){
		
			i++;
			printf("%d ",c);
			if(i==3){
				printf("\n");i=0;}
		
		
	}
	
	
	
	fclose(fp);

}
