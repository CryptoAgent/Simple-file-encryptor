#include "stdio.h"
#include "string.h"

unsigned char keyword[]={"key"};

int main(int argc,char * argv[]){

	if(argc<3){
		printf("Two argument needed!\r\n");
		return 1;
	}else if(argc>3){
		printf("Too many arguments!\r\n");
		return 1;
	}
	FILE * fpointer;
	if(!strcmp(argv[1],"encr")){
		
		fpointer = fopen(argv[2],"rb");
		if(fpointer == NULL){
			printf("Unable to open file\r\n");
			return 1;
		}
		fseek(fpointer,0,SEEK_END);
		long len = ftell(fpointer);
		rewind(fpointer);
		unsigned char input[len];
		unsigned char encr[len];
		fread(input,len,1,fpointer);
		int cnt = 0;
		for(int i = 0;i<len;i++){
			if(cnt>=3){
				cnt = 0;
			}
			input[i]^=keyword[cnt];
			encr[i]=input[i];
			cnt++;
		}
		FILE * newfile = fopen("encrypted_file","wb");
		fwrite(encr,1,len,newfile);
		fclose(newfile);



	}else if(!strcmp(argv[1],"decr")){
		
		fpointer = fopen(argv[2],"rb");
		if(fpointer == NULL){
			printf("Unable to open file\r\n");
			return 1;
		}
		fseek(fpointer,0,SEEK_END);
		long len = ftell(fpointer);
		rewind(fpointer);
		unsigned char input[len];
		unsigned char encr[len];
		fread(input,len,1,fpointer);
		int cnt = 0;
		for(int i = 0;i<len;i++){
			if(cnt>=3){
				cnt = 0;
			}
			input[i]^=keyword[cnt];
			encr[i]=input[i];
			cnt++;
		}
		FILE * newfile = fopen("decrypted_file","wb");
		fwrite(encr,1,len,newfile);
		fclose(newfile);


	}else {
		printf("No such mode!\r\n");
		return 1;
	}
	fclose(fpointer);

	return 0;
}