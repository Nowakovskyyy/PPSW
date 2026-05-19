#include <stdio.h>
#include <string.h>

#include "dekodowanie.h"
#include "konwersje.h"
#include "lancuchy.h"

void TestOf_CopyString(void) {
  char cString1[] = "Test poprawnosci cop1";
  char cString2[25] = "";

  printf("CopyString\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie kopiuje
  CopyString(cString1, cString2);
  if (strcmp(cString2, cString1) == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eCompareString(void) {
  char cString1[] = "Testowy string 0x01";
  char cStringShorter[] = "Testowy string";
  char cStringLonger[] = "Testowy string 0x01 dlugi";
  char cDifferentString[] = "Testawy string 0x01";
  

  printf("eCompareString\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie działa przy tej samej dlugosci lancuchow
  if (eCompareString(cString1, cString1) == EQUAL) printf("OK\n"); else printf("Error\n");
    
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja poprawnie działa przy jednym dluzszym lancuchu
  if (eCompareString(cString1, cStringLonger) == DIFFERENT) printf("OK\n"); else printf("Error\n");
    
  printf("Test 3 - ");
  // Sprawdzenie czy funkcja poprawnie działa przy jednym krotszym lancuchu
  if (eCompareString(cString1, cStringShorter) == DIFFERENT) printf("OK\n"); else printf("Error\n");
    
  printf("Test 4 - ");
  // Sprawdzenie czy funkcja poprawnie działa przy błedzie w postaci innego znaku
  if (strcmp(cString1, cDifferentString) != 0 && eCompareString(cString1, cDifferentString) == DIFFERENT)
  printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_AppendString(void) {
  char cDestinationStr1[40] = "test ";
  char cDestinationStr2[40] = "";
  char cDestinationStr3[40] = "test";
  char cSourceStr1[] = "dzialania";
  char cSourceStr2[] = "";
  char cSourceStr3[] = "dzialania";
  

  printf("AppendString\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do niepustego lancucha
  AppendString(cSourceStr1, cDestinationStr1);
  if (strcmp(cDestinationStr1, "test dzialania") == 0) printf("OK\n"); else printf("Error\n");
  
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja poprawnie dodaje pusty lancuch do niepustego lancucha
  AppendString(cSourceStr2,cDestinationStr3);
  if (strcmp(cDestinationStr3, "test") == 0) printf("OK\n"); else printf("Error\n");

  printf("Test 3 - ");
  // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do pustego lancucha
  AppendString(cSourceStr3, cDestinationStr2);
  if (strcmp(cDestinationStr2, "dzialania") == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_ReplaceCharactersInString(void) {
  char cOldChar = 't';
  char cNewChar = 'l';
  char cNewString[] = "test stringu";

  printf("ReplaceCharactersInString\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie zamienia znak w lancuchu
  ReplaceCharactersInString(cNewString, cOldChar, cNewChar);
  if (strcmp(cNewString, "lesl slringu") == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_UIntToHexStr(void) {
  char cString[7];

  printf("UIntToHexStr\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie zamienia liczby 2479 (0x09AF) na lanuch znakowy, sprwadzenie koncowych przedzialow
  UIntToHexStr(0x09AF,cString);
  if (strcmp(cString, "0x09AF") == 0) printf("OK\n"); else printf("Error\n");
}

void TestOf_eHexStringToUInt(void) {
  char cWrongFormat1[] = "test";
  char cWrongFormat2[] = "0x";
  char cWrongFormat3[] = "0x12345";
  char cGoodFormat[] = "0xFDE8";
  unsigned int uiResult;

  printf("eHexStringToUInt\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie dziala dla niepoprawnych danych wejsciowych
  if (eHexStringToUInt(cWrongFormat1,&uiResult) == ERROR) printf("OK\n"); else printf("Error\n");
    
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja poprawnie dziala dla zbyt krotkiego lancucha wejsciowego
  if (eHexStringToUInt(cWrongFormat2,&uiResult) == ERROR) printf("OK\n"); else printf("Error\n");

  printf("Test 3 - ");
  // Sprawdzenie czy funkcja poprawnie dziala dla zbyt dlugiego lanucha wejsciowego
  if (eHexStringToUInt(cWrongFormat3,&uiResult) == ERROR) printf("OK\n"); else printf("Error\n");
 
  printf("Test 4 - ");
  // Sprawdzenie czy funkcja poprawnie konwertuje liczby na lanuch znakowy
  if ((eHexStringToUInt(cGoodFormat,&uiResult) == OK) && uiResult == 65000) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_AppendUIntToString(void) {
  char cDestinationStr1[10] = "Test";
  char cDestinationStr2[10] = "";
  unsigned int uiValue = 1;

  printf("AppendUIntToString\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie dodaje liczby do konca niepustego lancucha znakowego
  AppendUIntToString(uiValue, cDestinationStr1);
  if (strcmp(cDestinationStr1, "Test0x0001") == 0) printf("OK\n"); else printf("Error\n");
  
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja poprawnie dodaje liczby do konca pustego lancucha znakowego
  AppendUIntToString(uiValue, cDestinationStr2);
  if (strcmp(cDestinationStr2, "0x0001") == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_ucFindTokensInString(void) {
  char cString1[] = "test of this";
  char cString2[] = "     ";
  char cString3[] = " test of this";
  char cString4[] = "test  of this";
  
  printf("ucFindTokensInString\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie zlicza i wyszukuje delimitery
  ucTokenNr = ucFindTokensInString(cString1);
  if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"test of this") == 0) && (strcmp(asToken[1].uValue.pcString,"of this") == 0) && (strcmp(asToken[2].uValue.pcString,"this") == 0)) printf("OK\n"); else printf("Error\n");
  
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja dziala poprawnie dla lancucha znakowego skladajacego sie z samych delimiterow
  ucTokenNr = ucFindTokensInString(cString2);
  if (ucTokenNr == 0) printf("OK\n"); else printf("Error\n");
    
  printf("Test 3 - ");
  // Sprawdzenie czy funkcja dziala poprawnie dla delimiterem przed lancuchem znakowym
  ucTokenNr = ucFindTokensInString(cString3);
  if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"test of this") == 0) && (strcmp(asToken[1].uValue.pcString,"of this") == 0) && (strcmp(asToken[2].uValue.pcString,"this") == 0)) printf("OK\n"); else printf("Error\n");
    
  printf("Test 4 - ");
  // Sprawdzenie czy funkcja dziala poprawnie dla dwoch delimiterow miedzy dwoma tokenami
  ucTokenNr = ucFindTokensInString(cString4);
  if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"test  of this") == 0) && (strcmp(asToken[1].uValue.pcString,"of this") == 0) && (strcmp(asToken[2].uValue.pcString,"this") == 0)) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eStringToKeyword(void) {
  char cString1[] = "load";
  char cString2[] = "loooaddd";
  enum KeywordCode eTest;

  printf("eStringToKeyword\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja poprawnie zamienia slowa kluczowe na odpowiadajaca im wartosc enum
  if ((eStringToKeyword(cString1,&eTest) == OK) && eTest == LD) printf("OK\n"); else printf("Error\n");
    
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja dziala poprawnie przy slowie innym niz slowo kluczowe
  if (eStringToKeyword(cString2,&eTest) == ERROR) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_DecodeTokens(void) {
  char cString[] = "0x10 reset test";
  ucTokenNr = ucFindTokensInString(cString);
  ReplaceCharactersInString(cString, DELIMITER_CHARACTER, '\0');
  DecodeTokens();
  
  printf("DecodeTokens\n\n ");
  printf("Test 1 - :");
  // Sprawdzenie czy funkcja dziala poprawnie dla wejsciowego lancucha znakowego
  if ((asToken[2].eType == STRING) && (asToken[2].uValue.pcString == &cString[11])) printf("OK\n"); else printf("Error\n");
    
  printf("Test 2 - ");
  // Sprawdzenie czy funkcja dziala poprawnie dla wejsciowego slowa kluczowego
  if ((asToken[1].eType == KEYWORD) && (asToken[1].uValue.eKeyword = RST)) printf("OK\n"); else printf("Error\n");
    
  printf("Test 3 - ");
  // Sprawdzenie czy funkcja dziala poprawnie dla wejsciowej liczby
  if ((asToken[0].eType == NUMBER) && (asToken[0].uValue.uiValue = 0x10)) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_DecodeMsg(void) {
  char cStr[] = "test reset 0x10";

  printf("DecodeMsg\n\n ");
  printf("Test 1 - ");
  // Sprawdzenie czy funkcja dziala poprawnie dla wejsciowego lancucha znakowego (pelnej wiadomosci)
  DecodeMsg(cStr);
  if ((asToken[0].eType == STRING) && (strcmp("test",asToken[0].uValue.pcString) == 0) && (asToken[1].eType == KEYWORD) && (asToken[1].uValue.eKeyword = RST) && (asToken[2].eType == NUMBER) && (asToken[2].uValue.uiValue = 0x10)) printf("OK\n\n"); else printf("Error\n\n");
}

int main() {
  printf("TESTY FUNKCJI DO LANCUCHY ZNAKOWE\n\n ");
  TestOf_CopyString();
  TestOf_eCompareString();
  TestOf_AppendString();
  TestOf_ReplaceCharactersInString();
  
  printf("TESTY FUNKCJI DO KONWERSJI\n\n ");
  TestOf_UIntToHexStr();
  TestOf_eHexStringToUInt();
  TestOf_AppendUIntToString();
  
  printf("TESTY FUNKCJI DO DEKODOWANIA\n\n ");
  TestOf_ucFindTokensInString();
  TestOf_eStringToKeyword();
  TestOf_DecodeTokens();
  TestOf_DecodeMsg();
  
 return 0;
 



}