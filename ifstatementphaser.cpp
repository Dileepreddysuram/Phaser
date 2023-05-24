#include<bits/stdc++.h>
using namespace std;
bool Check1(char ch)
{
 if (ch == ' ')
 return (true);
 return false;
}
bool Checkid(char* st1)
{
 if (st1[0] == '0' || st1[0] == '1' || st1[0] == '2' ||
 st1[0] == '3' || st1[0] == '4' || st1[0] == '5' ||
 st1[0] == '6' || st1[0] == '7' || st1[0] == '8' ||
 st1[0] == '9' || Check1(st1[0]) == true)
 return (false);
 return (true);
}
char* subSting(char* st1, int left, int right)
{
 int i;
 char* subSt1 = (char*)malloc(
 sizeof(char) * (right - left + 2));
 for (i = left; i <= right; i++)
 subSt1[i - left] = st1[i];
 subSt1[right - left + 1] = '\0';
 return (subSt1);
}
bool CheckIsOperator(char ch)
{
 if (ch == '>' || ch == '<' ||
 ch == '=' || ch == '!')
 return (true);
 return (false);
}
bool CheckIsOperator3(char ch)
{
 if (ch == '=')
 return (true);
 return (false);
}
bool CheckIsOperator2(char ch){
 if(ch == '+' || ch == '-' || ch == '*' ||
 ch == '/' )
 return true;
 return false;
}
bool CheckBrac(char ch){
 if(ch == '{')
 return true;
 return false;
}
bool CheckSc(char ch){
 if(ch == ';')
 return true;
 return false;
}
bool CheckIsKeyword(char* st1)
{
 if (!strcmp(st1, "if"))
 return (true);
 return false;
}
void SyntaxCheck(char* st1)
{
 int right =0, left =0;
 int len = strlen(st1);
 for(int i=0;i<=len;i++){ // Parsing all the spaces at the start, before if 
keyword
 if(st1[i]==' '){
 left=i;
 right=left;
 continue;
 }
 else{
 break;
 }
 }
 if(st1[left+1]=='i'){ // Checking if the first non-space character starts 
with i
 char* subSt1 = subSting(st1,left+1,right+2);
 if(CheckIsKeyword(subSt1)){ // Checking the if keyword using by taking it
as sub string
 int count1 =0;
 int count2 =0;
 int count3 =0;
 int count4 =0;
 int opp =0;
 left = left+3;
 right = left;
 while(right <= len && left <= right){ // Parsing each character after 
if keyword
 if(Check1(st1[left])){
 left = left+1;
 right = left;
 //cout<<st1[left]<<endl;
 continue;
 }
 else if(st1[left] == '('){ // Checking the ( bracket
 count1++;
 //cout<<"Count1 is :"<<count1<<endl;
 left = left+1;
 right = left;
 continue;
 }
 else if(count1==0 && st1[left] != '('){
 cout<<" if must be followed by ( "<<endl;
 }
 else if(Check1(st1[left])==false && 
CheckIsOperator(st1[left])==false && CheckIsOperator2(st1[left])==false && 
st1[left] != ')' && st1[left] != '{' && st1[left] != '}' && st1[left] != ';'){
 //countty++;
 right++;
 char* subSt1 = subSting(st1, left, right - 1);
 //cout<< subSt1;
 if (Checkid(subSt1) == true && Check1(st1[right - 1]) == false)
{
 left = right;
 //cout<<countty;
 continue;
 }
 }
 else if (Checkid(subSt1) == false && Check1(st1[right - 1]) == 
false)
 cout<<subSt1<<" IS NOT A VALID IDENTIFIER\n"<<endl;
 if((CheckIsOperator(st1[left])==true || 
CheckIsOperator2(st1[left])==true) && opp <3){ // Checking the Operators
 //cout<<"==";
 if(CheckIsOperator(st1[left+1]) || 
CheckIsOperator2(st1[left+1])){
 right = left+1;
 //cout<<"Hey";
 //cout<<st1[left+1];
 //cout<<st1[right];
 if(CheckIsOperator3(st1[right]) ) {
 right = left;
 opp =2;
 left = left+2;
 right = left;
 //cout<<"valid"<<endl;
 continue;
 }
 else if(st1[left] != st1[right]) {
 right = left;
 opp =2;
 left = left+2;
 right = left;
 //cout<<"valid"<<endl;
 continue;
 }
 else if(st1[left] == st1[right] && (count1==count2)){
 opp=2;
 left = left+2;
 right = left;
 //cout<<"Here";
 //cout<<st1[left]<<endl;
 continue;
 }
 else{
 cout<<"Invalid Operators"<<endl;
 }
 }
 else{
 opp++;
 left = left+1;
 right = left;
 continue;
 }
 }
 if(st1[left] == ')'){ // Checking the ) bracket
 count2++;
 //cout<<"Working";
 left = left+1;
 right = left;
 continue;
 }
 if((count1==count2) && CheckBrac(st1[left])==true){ // Checking 
the { bracket
 count3++;
 opp=0;
 if(count3>1){
 cout<<"More than 1 { is not allowed"<<endl;
 }
 else{
 //cout<<"Hello";
 left=left+1;
 right=left;
 continue;
 }
 }
// if(CheckIsOperator2(st1[left])==true){
// cout<<"there"<<endl;
// }
 if(CheckSc(st1[left])==true ){ // Checking the ;
 count4++;
 //cout<<"Hey";
 if(count4>1 && count3<1){
 cout<<"{ is missing"<<endl;
 }
 else{
 left=left+1;
 right=left;
 continue;
 }
 }
// if(st1[right]!='}'){
// if(count4>1){
// if(st1[right]=='}'){
// cout<<endl<<"Your syntax is correct";
// break;
// }
// else{
// cout<<endl<<"The statement must end with }";
// break;
// }
// }
// else if((count4==0) && CheckSc(st1[right])){
// cout<<endl<<"Your syntax is correct";
// break;
// }
//
//
// }
 if((left = len-1) && st1[right]!='}'){ // Checking the Ending 
syntax
 if(count4==1){
 for(int i=left;i<len;i++){
 if(Check1(st1[i])){
 continue;
 }
 else if(Check1(st1[i])==false && st1[i] != '}'){
 cout<<"If must end with }"<<endl;
 }
 else if(Check1(st1[i])==false && st1[i] == '}'){
 cout<<"It is correct"<<endl;
 }
 }
 }
 else if(count4>1 && st1[len-1] != '}'){
 cout<<"Must end with }"<<endl;
 }
 }
 else if((left = len-1) && st1[right]=='}' && count3==1){
 cout<<"Correct syntax"<<endl;
 break;
 }
 } // Checking 
the (, ) brackets matching
 if(count1>count2){
 cout<<endl<<") is missing"<<endl;
 }
 else if(count2>count1){
 cout<<endl<<"( is missing for ) bracket";
 }
 }
 else{
 cout<<"If statement must start with if keyword"<<endl;
 }
 }
}
int main()
{
 // maximum length of string is 100 here
 char St[100] = " if (a==b) { a++; b++; }"; // User Input
 SyntaxCheck(St); // calling the parse function
 return (0);
}