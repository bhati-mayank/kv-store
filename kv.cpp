/* A KEY-VALUE STORE  */

// system header files
#include <iostream>
#include <string>
#include <unordered_map>
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
};


// Command class
struct Command{

public:
    string command;
    string key;
    string value;
};

// function to parse the input 
Command parse_input(const string& input){

    Command cmd;



    return cmd;

}


// function to process the commands
void process_Command(KeyValueStore& store, Command& cmd){

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

        //process the command
        process_Command(store, cmd);
    }
    return 0;
}
