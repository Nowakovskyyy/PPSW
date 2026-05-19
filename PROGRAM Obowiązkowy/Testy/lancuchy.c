#include "lancuchy.h"

#define NULL '\0'

void CopyString(char pcSource[], char pcDestination[]){
	
		unsigned char ucCharacterCounter;
		
		for(ucCharacterCounter=0; pcSource[ucCharacterCounter] != '\0'; ucCharacterCounter++ ){
			pcDestination[ucCharacterCounter] = pcSource[ucCharacterCounter];
		}
		pcDestination[ucCharacterCounter] = '\0';
}



//enum CompResult {DIFFERENT, EQUAL};
enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	
		unsigned char ucCharacterCounter;

    for(ucCharacterCounter=0; (pcStr1[ucCharacterCounter] != '\0') || (pcStr2[ucCharacterCounter] != '\0'); ucCharacterCounter++){ 
			if(pcStr1[ucCharacterCounter] != pcStr2[ucCharacterCounter]){   
				return DIFFERENT;
      }
    }
    return EQUAL;
}



void AppendString(char pcSourceStr[], char pcDestinationStr[]){
	
		unsigned char ucCharacterCounter;
	
		for(ucCharacterCounter = 0; pcDestinationStr[ucCharacterCounter] != '\0'; ucCharacterCounter++){
			
		}	
		CopyString(pcSourceStr, pcDestinationStr + ucCharacterCounter);
}



void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
	
		unsigned char ucCharacterCounter;
		
		for(ucCharacterCounter = 0; pcString[ucCharacterCounter] != '\0'; ucCharacterCounter++){
			if(pcString[ucCharacterCounter] == cOldChar){
				pcString[ucCharacterCounter] = cNewChar;
			}
		}
}
				
