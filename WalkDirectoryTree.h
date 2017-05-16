//
// Created by Peter_Kiss on 2017. 05. 04..
//

#ifndef CPP_UTILILTIES_WALKDIRECTORYTREE_H
#define CPP_UTILILTIES_WALKDIRECTORYTREE_H

#include <dirent.h>
#include <vector>
#include <string>

using namespace std;

class WalkDirectoryTree {

private:
    vector<string> files;
    vector<string> next;

    bool hasExtension = false;
    char * extension;

public:
    WalkDirectoryTree(const char * directory);
    void start();
    void start(char *extension);

    vector<string> getFileNames();
private:
    bool scanOneDirectory();

    bool isJsFile(dirent *ent);
};


#endif //CPP_UTILILTIES_WALKDIRECTORYTREE_H
