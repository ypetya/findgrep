//
// Created by Peter_Kiss on 2017. 05. 04..
//
// using "string" 2.6ms
// using c strings 0.4ms
#include <cstdio>
#include <dirent.h>
#include <string>
#include <cstring>

#include "WalkDirectoryTree.h"

#define DEBUG(msg)


string appendDir(string dir1, char *subDir) {
    string s1(dir1), s2("\\"), s3(subDir);
    return s1 + s2 + s3;
}

inline bool isdir(struct dirent *ent) {
    return ent->d_type == 16 && strlen(ent->d_name) > 2;
}

bool WalkDirectoryTree::isJsFile(struct dirent *ent) {
    if(hasExtension) {
        char *ext = strstr(ent->d_name, extension);
        return strlen(ent->d_name) > 2 && ext;
    } else {
        return strlen(ent->d_name) > 2;
    }
}

bool WalkDirectoryTree::scanOneDirectory() {
    if (next.size() == 0) return false;
    string directory = (next.front());
    next.erase(next.begin());

    DIR *dir;
    struct dirent *ent;
    DEBUG(printf("%s : ", directory.c_str()));

    if ((dir = opendir(directory.c_str())) != NULL) {
        DEBUG(printf("ok\n"));
        while ((ent = readdir(dir)) != NULL) {
            if (isdir(ent)) {
                next.push_back(appendDir(directory, ent->d_name));
            } else if (isJsFile(ent)) {
                files.push_back(appendDir(directory, ent->d_name));
            }
        }
        closedir(dir);
        return true;
    } else {
        DEBUG(printf("err\n"));
        return false;
    }
}

WalkDirectoryTree::WalkDirectoryTree(const char *directory) {
    this->next.push_back(string(directory));
}

void WalkDirectoryTree::start(char * extension) {
    this->extension = extension;
    this->hasExtension=true;
    WalkDirectoryTree::start();
}

void WalkDirectoryTree::start() {
    int i = 0;
    while (scanOneDirectory()) i++;
    printf(" %d directories\n %u files\n", i, (unsigned int) files.size());
}

vector<string> WalkDirectoryTree::getFileNames() {
    return files;
}
