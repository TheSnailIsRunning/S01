#include <stdio.h>
#include <string.h>
//#include <unistd.h>
#define MAXSIZE 1024
int main(int argc, char *argv[])
{
	FILE * oriFile;
	FILE * desFile;
	if(argc != 3){
		printf("para is error!");
		return 0;
	}

	
	/* if it's not a path create the file */
	/*if(access(argv[2], F_OK) != 0){
		printf("path or file is not exist!"); 
	}*/
	/* open original file and get comment */
	
	oriFile = fopen(argv[1], "rb");
	if(oriFile != NULL){

		/* desfileName */
		char desFlName[MAXSIZE];
		
		//int c;
		char arr[MAXSIZE];
		strncpy(desFlName, argv[2], MAXSIZE);
		
		desFile = fopen(desFlName,"wb");
		if(desFile == NULL){
			printf("create or open the file unsuccessfully!\n");
			printf("the program is done....");
			return 0;
		}
		while(fgets(arr, MAXSIZE, oriFile) != NULL && arr[0] != '\0'){
			if(fputs(arr, desFile) == EOF){
				printf("copying error!\n");
				break;
			}else{
				printf("copying ....\n");
			}
		}
		fclose(desFile);
		printf("copy completely!\n");
		fclose(oriFile);
		return 0;
	}else{
		printf("open the file error!\n");
		return 0;
	}

}