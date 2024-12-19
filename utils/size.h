#ifndef SIZE_H
#define SIZE_H

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

class Size {
private:
    fs::path currDir;
    long int size;

public:
    Size();
    Size(fs::path path);
    void getSize();
    std::string getSize(fs::path path);
};

#endif

