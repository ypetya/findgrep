//
// Created by Peter_Kiss on 2017. 05. 16..
//

#include <stdio.h>
#include <regex>
#include <fstream>
#include "WalkDirectoryTree.h"
#include "MeasureRuntime.h"

const int ARGUMENTS_LENGTH = 4;
const char *ARGUMENTS[] = {"program name",
                           "root directory",
                           "file extension",
                           "regular expression"};

bool helpNeeded(int argc, char **argv) {
    if (argc < ARGUMENTS_LENGTH) {
        printf("Please check input arguments!\n");
        for (int i = 0; i < ARGUMENTS_LENGTH; i++) {
            printf(" - %d. %s : %s\n", i, ARGUMENTS[i], i < argc ? argv[i] : "missing");
        }
        return true;
    }
    return false;
}

void grep(string fileName, string pattern) {
    regex pat{pattern};
    ifstream in(fileName);
    int lineno = 0;
    for(string line; getline(in,line);) {
        ++lineno;
        smatch matches;
        if(regex_search(line, matches, pat)) {
            printf( "%s:%d: %s\n", fileName.c_str(), lineno, matches[0]);
            if(1<matches.size() && matches[1].matched)
                printf("\t: %s\n", matches[1]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (!helpNeeded(argc, argv)) {
        MeasureRuntime mr;

        WalkDirectoryTree w(argv[1]);
        w.start(argv[2]);

        vector<string> files = w.getFileNames();
        for (vector<string>::iterator it = (files).begin(); it != (files).end(); it++) {
            grep((*it),argv[3]);
        }

        mr.stop();
    }
}
