#include <iostream>
#include <fstream>
#include <string>
#include "IO.hpp"
#include <string>
#include <iostream>
#include <sstream>

using std::string;

class ReadENV{
    public:
    string getenv(){
      string env_path = ".env";
        IO io(env_path);
        std::fstream fileStream = io.getFileStream();
        std::stringstream buffer;
        buffer << fileStream.rdbuf();
        string content = buffer.str();
        return content;
    }
};
