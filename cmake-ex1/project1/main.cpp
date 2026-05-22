#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {

    json my_json;
    my_json["project"] = "Cmake demo with JSON library";
    
    std::cout << my_json.dump(4) << std::endl;
    

    return 0;
}
