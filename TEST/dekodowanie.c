#include "dekodowanie.h"
#include "konwersje.h"
#include "lancuchyznakowe.h"

#define NULL '\0'
#define MAX_KEYWORD_NR 3

struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
    {RST, "reset"}, {LD, "load"}, {ST, "store"}};
    
struct Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr = 0;

enum FunctionState{TOKEN, DELIMITER};

unsigned char ucFindTokensInString (char *pcString){
	
	enum FunctionState eState = DELIMITER;
	unsigned char ucTokenNr = 0;
	unsigned char ucCharCounter;
	unsigned char ucCurrentCharacter;
	
	for(ucCharCounter=0;;ucCharCounter++){
		ucCurrentCharacter = pcString[ucCharCounter];
		
		switch (eState){
			
			case TOKEN:
			{
				if(ucTokenNr == MAX_TOKEN_NR){
					return ucTokenNr;
				}	
				else if(ucCurrentCharacter == NULL){
					return ucTokenNr;
				}
				else if(ucCurrentCharacter != ' '){
					eState = TOKEN;
				}
				else{
					eState = DELIMITER;
				}
	      break;
			}
			
			case DELIMITER:
			{
				if(ucCurrentCharacter == NULL){
					return ucTokenNr;
				}
				else if(ucCurrentCharacter == ' '){
					eState = DELIMITER;
				}
				else{
					eState = TOKEN;
					asToken[ucTokenNr].uValue.pcString = pcString + ucCharCounter;
					ucTokenNr++;
				}
				break;
			}
		}
	}
}

enum Result eStringToKeyword (char pcStr[],enum KeywordCode *peKeywordCode){
	
	unsigned char ucKeywordCounter;
	
	for(ucKeywordCounter=0; ucKeywordCounter < MAX_KEYWORD_NR; ucKeywordCounter++){
		if(EQUAL == eCompareString(asKeywordList[ucKeywordCounter].cString, pcStr)){
			*peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}


	
void DecodeTokens(void){
	unsigned char ucTokenCounter;
	struct Token *psCurrentToken;
	
	enum KeywordCode eInKeyword;
	unsigned int uiInValue;
	
	for(ucTokenCounter = 0; ucTokenNr > ucTokenCounter; ucTokenCounter++){
		psCurrentToken = &asToken[ucTokenCounter];
		if(OK == eStringToKeyword(psCurrentToken -> uValue.pcString, &eInKeyword)){
			psCurrentToken -> eType = KEYWORD;
			psCurrentToken -> uValue.eKeyword = eInKeyword;
		}
		else if(OK == eHexStringToUInt(psCurrentToken -> uValue.pcString, &uiInValue)){
			psCurrentToken -> eType = NUMBER;
			psCurrentToken -> uValue.uiNumber = uiInValue;
		}
		
		else{
			psCurrentToken -> eType = STRING;
		}
	}
}


void DecodeMsg(char *pcString){
	
	ucTokenNr = ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, ' ', NULL);
	DecodeTokens();
	
}

char pcString[]="reset 0x10 woda";
int main(){
	
	
	DecodeMsg(pcString);
	
}

