#include<stdio.h>
#include<dirent.h>
int main(){
	DIR *dp;
	struct dirent *dptr;
	int b=mkdir("Dir1",0777);
	dp=opendir("Dir1");
	while(NULL!=(dptr=readdir(dp)))
	{
		printf("\%s\n",dptr->d_name);
		printf("\%d\n",dptr->d_type);
	}
	return 0;
}
