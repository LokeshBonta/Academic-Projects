#include<iostream>
#include<string.h>

class String{
public:
   // 2 - Constructor
   String(): data(nullptr), len(0){
       std::cout << "Constructor 1 is called" << std::endl;
   }
   // 3 - Another Constructor
   String(char *data_){
       std::cout << "2nd constructor" << std::endl;
       data = new char[strlen(data_) + 1];
       len = strlen(data_) + 1;
       strcpy(data, data_); 
   }
   // 4 - Copy Constructor
   // & in the argument is main because it might call repeated copie  ---infinite loop
   String(const String &str){
      std::cout << "copy constructor" << std::endl;
      len = str.get_len();
      data = new char[len + 1];
      strcpy(data, str.data);
      std::cout << len << "   " << str.data << "    " << data << std::endl;
   }
   // 5 - Copy Assignment Operator
   void operator = (const String &str){
       std::cout << "copy assignment operator" << std::endl;
       len = str.get_len();
       data = new char[len + 1];
       strcpy(data, str.data);
       std::cout << len << "   " << str.data << "    " << data << std::endl;
   }
   int get_len() const{
       //len = 5 ; // this is invalid as const member function
       return len;
   }
   // 6 - Destructor
   ~String(){
       std::cout << "Destructor is called" << std::endl;
       delete [] data;
   }

private:
  // 1 - what are class members
  char *data;
  int len;
};


int main(){
  String str; // default constructor
  String str2("lokesh is"); // constructor 2
  String str3(str2); // Copy Constructor
  String str4 = str2; // Copy Constructor again
  String str5;
  str5 = str2;

  auto str6 = new String[5]; // diff between new and new[]
  delete []str6; // diff between delete and delete []
  return 0;
}