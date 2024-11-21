#include "filecpyheader.h"

namespace FilecpyNS
{
    void FileCpyMenu()
    {
        std::string sOptSel;
        std::cout << "This is the copy app, allign files on decoder USB" << std::endl;
        std::cout <<"Menu" << std::endl;
        std::cout << "1: copy files to USB" << std::endl;
        std::cout <<"The remaining MENU will be implemented soon, kindly select your option : ";
        std::getline(std::cin , sOptSel);
        
        if(sOptSel == "1")
        {
            std::string srcdir, desdir;
            std::cout <<"Key in file directory or location(src) : " <<std::endl;
            //input source directory for files
            std::getline(std::cin, srcdir);

            std::cout <<"Key in file directory or location (dest): " <<std::endl;
            // input destination for copied files
            std::getline(std::cin, desdir);
            //FilecpyNS::searchFile("E:\\DCLM\\GHS HYMNS\\GHS 1 - 50", "D:\\Faayor English church\\GHS\\GHS 1 - 50");
            FilecpyNS::searchFile(srcdir, desdir);
        }
    } 
}


