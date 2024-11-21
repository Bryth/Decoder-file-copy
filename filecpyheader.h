#ifndef FILECPYHEADER_H
#define FILECPYHEADER_H

    #include <string>
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <dirent.h>
    #include <algorithm>

    namespace FilecpyNS
    {
        void copyfile(std::string sifSourceFile, std::string sofBinCpyFile);
        bool searchFile(const std::string& srcPath, const std::string& DestPth);
        void FileCpyMenu();
    }


#endif