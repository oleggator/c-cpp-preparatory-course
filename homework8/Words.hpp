#include <vector>
#include <initializer_list>
#include <map>
#include <string>

class Words {
public:

    Words(std::initializer_list<std::string> initializerList);

private:
    //std::vector<std::string> filesPaths;
    std::map<std::string, size_t> words;

};
