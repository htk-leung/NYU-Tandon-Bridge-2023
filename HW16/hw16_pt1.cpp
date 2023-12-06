#include <string>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

void openInputFile(ifstream& infile) {
    string filename;                                    // set up vars
    cout << "Please enter name of file to check: ";     // solicit response
    cin >> filename;

    infile.open(filename);
    
    while(!infile) {                                    // while it's still wrong get new input
        cout << "Wrong filenamen\n"                     // get new input
            << "Please try again: ";
        cin >> filename;
        infile.clear();                                 // clear flag
        infile.open(filename);                          // open again
    }
}

void getRestOfWord(ifstream& infile, string& input) {
    char temp; 

    while(infile.get(temp) && isalpha(temp)) 
        input += string(1, temp);
    
    infile.putback(temp);
}

bool isOpening(ifstream& infile, string& input) {
    if(input == "{" || input == "[" || input == "(")
        return true;
    else if(input == "b") {                             // if b then while still an alphabet save to string 
        getRestOfWord(infile, input);
        if(input == "begin")                            // if string is begin 
            return true;
    }

    return false;
}

bool isClosing(ifstream& infile, string& input) {
    if(input == "}" || input == "]" || input == ")")
        return true;
    else if(input == "e") {                             // if e then while still an alphabet save to string 
        getRestOfWord(infile, input);
        if(input == "end")                              // if string is end 
            return true;
    }

    return false;
}

bool isBalanced(string top, string input) {
    if(top == "{" && input == "}")
        return true;
    else if(top == "[" && input == "]")
        return true;
    else if(top == "(" && input == ")")
        return true;
    else if(top == "begin" && input == "end")
        return true;

    return false;
}

bool checkSyntax(ifstream& infile) {
    string input;
    char temp;
    stack<string> stack;

    // go through file, input to temp
    while(infile.get(temp)) {                           
        input = temp;

        // if {  (  [ begin
        if(isOpening(infile, input))                    
            stack.push(input);
        
        // if not
        else if(isClosing(infile, input)) {
            if(stack.empty())                           // case: extra closing
                return false;

            string top = stack.top();                   // if }  )  ] end
            if(isBalanced(top, input))                  // if true, if false
                stack.pop();
            else
                return false;
        }
    }

    if(!stack.empty())                                  // case: extra opening                               
        return false;
    
    return true;                                       
}


int main() {
    ifstream infile;                                    // open ifstream object
    openInputFile(infile);
    bool iscorrect = checkSyntax(infile);
    cout << (iscorrect                                  // plug in obj to check syntax
            ? "\nIt's all good\n\n" 
            : "\nSomething is wrong\n\n");
    return 0;
}