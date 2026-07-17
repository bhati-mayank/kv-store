/* A KEY-VALUE STORE  */

// system header files
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
using namespace std;

// database class
class KeyValueStore{

private:
    // an hash map to store KEY-VALUE pair
    unordered_map< string, string > data;

public:

    // Insert or update the key-value pair in data
    void put(const string& key, const string& value){

        //inserting key-value pair
        data[key] = value;
    }

    // fetch the value associated to a key
    string get(const string& key) const {
        
        // check is key exists in the data 
        auto it = data.find(key);

        //if found
        if( it != data.end() )
            return it->second;
        
        // not found
        else 
            return "";
    }

    // to erase a key-value pair from data if exists
    bool remove(const string& key){

        // check if key exists
        auto it = data.find(key);

        // if not found
        if( it == data.end())
        {
            return false;
        }
        
        // if found
        data.erase(it);
        return true;
    }

    // to validate if a key-value pair exists in data
    bool exists(const string& key) const {

        return data.find(key) != data.end();
    }

    //to clear the current database
    void clear(){
        data.clear();
    }

    // get the size of the data set
    size_t size() const {
        return data.size();
    }

    // help section
    void help() const{
        printf("\nPUT value key\nGET key\nREMOVE key\nEXISTS key\nCLEAR\nSIZE\n\n");
    }
};


// Command class
struct Command{

public:
    string command;
    string key;
    string value;
};


//trim function
string trim(const string &input){

    //check if input is itself empty
    if(input == "")
        return "";

    string s;

    int i = 0;
    int j = input.size() - 1;



    // handle spaces and line characters
    while( i != input.size() &&  (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')){
        i++;
    }


    //check if string exists after front trimming
    if(i == input.size())
        return "";

    //handle spaces and line characters
    while(  j >= 0  &&  (input[j] == ' ' || input[j] == '\t' || input[j] == '\n')){
        j--;
    }

    return input.substr(i, j - i + 1);
}

// function to parse the input 
Command parse_input(const string& input){

    Command cmd;

    
    string comnd;
    string key;
    string value;
    
    //trim the input
    string trimmed = trim(input);

    //using stringstream for extracting commands
    stringstream ss;

    ss << trimmed;

    // extracting from input
    ss >> comnd;
    ss >> key;
    ss >> value;

    // initialising the Command object
    cmd.command = comnd;
    cmd.key = key;
    cmd.value = value;

    return cmd;

}


// function to process the commands
void process_Command(KeyValueStore& store, const Command& cmd){

    string command = cmd.command;
    string key     = cmd.key;
    string value   = cmd.value;

    //PUT
    if(command == "PUT" ){
        store.put(key, value);
        cout << "OK\n";
    }

    //GET
    else if(command == "GET"){
        string s = store.get(key);
        if(s == "")
            cout << "NOT FOUND\n";
        
        else 
            cout << s << '\n';
    }

    //REMOVE
    else if(command == "REMOVE"){
        bool flag = store.remove(key);

        if(!flag)
            cout << "INVALID\n";

        else
            cout << "OK\n";
    }

    //exists
    else if(command == "EXISTS"){
        bool flag = store.exists(key);

        if(!flag)
            cout << "NO\n";
        
        else 
            cout << "YES\n";
    }

    //clear
    else if(command == "CLEAR"){
        store.clear();

        cout << "OK\n";
    }

    //SIZE
    else if(command == "SIZE"){
        size_t size = store.size();

        cout << size;
    }

    else if(command == "HELP"){
        store.help();
    }

    //unknown command
    else {
        cout << "UNKNOWN COMMAND\n";
    }

}



/*=========================*/
/*      MAIN DRIVER      */
/*=========================*/

int main(){


    //creating an object of keyvaluestore class
    KeyValueStore store;

    // infinite loop for taking inputs from command prompt
    while(true){

    

        // input
        string input;

        cout << ">>" ;

        //read the input 
        getline(cin, input);

        // get the command out of input
        Command cmd = parse_input(input);

        printf("\n");

        //check if the cmd is EXIT
        if(cmd.command == "EXIT")
            break;

        //process the command
        process_Command(store, cmd);
    }
    return 0;
}
