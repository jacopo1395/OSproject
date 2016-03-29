//====================================
//			LOG WRITER
//====================================

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> //write()
#include <string.h>//warning strlen strcat
#include <fcntl.h>// serve per le opzioni di apertura del file

#include "common.h"
#include "log.h"


//  file descriptor for server log
FILE* file;

void logMsg(char* toWrite) {

    int ret;
    
    file = fopen(NOME_FILE,"w"); 
    if(file==NULL)ret=-1; else ret=0;
	ERROR_HELPER(ret,"Errore apertura file log.txt");
	
    //	getting current time and date
    time_t mytime;
    mytime = time(NULL);

    //	gestione segnali
    //sigset_t maschera;
	char* date=ctime(&mytime);
    
    ret = fprintf(file,"%s%s\n\n\n",date,toWrite);
    ERROR_HELPER(ret, "Errore scrittura operazione server su file");
    
    ret=fclose(file);
    ERROR_HELPER(ret,"Errore chiusura file");

}

void resetLog(){
	int ret;
	//	cancella tutto il file di log
	FILE * f;
	//se il file esiste lo resetto
	 if ((f = fopen(NOME_FILE, "r"))>0){
        ret = remove(NOME_FILE);
		ERROR_HELPER(ret, "Errore cancellazione file");
    }
    
    
}