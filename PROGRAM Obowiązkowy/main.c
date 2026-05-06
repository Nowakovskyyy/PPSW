#include <LPC21xx.H>

#define NULL '\0'
#define HEX_bm 0x000F


enum Result {OK, ERROR};
enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
	
    unsigned char ucCharacterCounter;
    unsigned char ucCurrentCharacter;
	
    if((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL)){
		return ERROR;
    }
    
    *puiValue = 0;
    
    for(ucCharacterCounter = 2; pcStr[ucCharacterCounter] !=NULL ; ucCharacterCounter++){
			
        ucCurrentCharacter = pcStr[ucCharacterCounter];
			
        if (ucCharacterCounter == 6){
            return ERROR;
        }
				
				*puiValue = *puiValue << 4;
				
        if((ucCurrentCharacter >= '0') && (ucCurrentCharacter <= '9')){
					
            *puiValue = (*puiValue) | (ucCurrentCharacter - '0');
        }
        else if((ucCurrentCharacter >= 'A') && (ucCurrentCharacter <= 'F')){
					
            *puiValue = (*puiValue) | (ucCurrentCharacter - 'A' + 10);
        }
        else
        {
            return ERROR;
        }
    }
    return OK;
}

		unsigned int uiWartoscPoprawna = 0;
    enum Result eStatusPoprawny;

    unsigned int uiWartoscBledna = 0;
    enum Result eStatusBledny;
	
		unsigned int uiWartoscBledna1 = 0;
    enum Result eStatusBledny1;
	
		unsigned int uiWartoscBledna2 = 0;
    enum Result eStatusBledny2;

int main(void) {
    

 
    eStatusPoprawny = eHexStringToUInt("0x111A", &uiWartoscPoprawna);

    eStatusBledny = eHexStringToUInt("0x1111A", &uiWartoscBledna);
	
		eStatusBledny1 = eHexStringToUInt("1111A", &uiWartoscBledna1);
	
		eStatusBledny2 = eHexStringToUInt("11", &uiWartoscBledna2);


    
    while(1) {
        
    }
}
