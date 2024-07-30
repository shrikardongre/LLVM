#include<iostream>
#include<string>
using namespace std;

enum Token {
  tok_eof = -1,

  // commands
  tok_def = -2,
  tok_extern = -3,

  // primary
  tok_identifier = -4,
  tok_number = -5,
};

static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;   

static int gettok()
{
    static int Lastchar=' ' ;
    while (isspace(Lastchar)){
            Lastchar=getchar();
    }
    if (isalpha(Lastchar)){
        IdentifierStr=Lastchar;
        while(isalnum((Lastchar=getchar()))){
            IdentifierStr+=Lastchar;
        }
        if (IdentifierStr == "def"){
           return tok_def;
        }
        if (IdentifierStr == "extern"){
           return tok_extern;
        }
           return tok_identifier;
        
    }

   
    if (isdigit(Lastchar) || Lastchar == '.') {   
    std::string NumStr;
    do {
    NumStr += Lastchar;
    Lastchar = getchar();
    }

     while (isdigit(Lastchar) || Lastchar == '.');

      NumVal = strtod(NumStr.c_str(), 0);
      return tok_number;
}
   if (Lastchar == '#') {
  // Comment until end of line.
  do
    Lastchar = getchar();
  while (Lastchar != EOF && Lastchar != '\n' && Lastchar != '\r');

  if (Lastchar != EOF){
    return gettok();
}
   }
  if (Lastchar == EOF){
    return tok_eof;
  }
  // Otherwise, just return the character as its ascii value.
  int ThisChar = Lastchar;
  Lastchar = getchar();

   return ThisChar;
}

int main ()
{
  while(true){
    int tok=gettok();
    cout<<"got token" <<tok<<endl;
  }
  return 0;
}
