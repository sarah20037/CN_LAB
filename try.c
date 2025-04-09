#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int simu(){
	return rand()%10<7;
}

int main(){
	int total=10;
	int done=0;
	int window;
	while (done<=total){
		window=done+4;
		if (window>total)
			window=total+1;
		for(int i=done;i<window;i++){
			printf("sending %d packet\n",i);
		}
		sleep(1);
		for(int i=done;i<window;i++){
			if(simu()){
				printf("got %d packet\n",i);
				done++;
				sleep(1);
			}else{
				printf("didnt get packet\n");
				sleep(1);
				break;
			}
		}
	}return 0;
}