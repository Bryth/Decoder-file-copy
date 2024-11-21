#include "filecpyheader.h"

namespace FilecpyNS
{
    void copyfile(std::string sifSourceFile, std::string sofBinCpyFile)
    {
        std::ifstream ifSourceFile;
        std::ofstream ofBinCpyFile;

        std::vector <char> vcfromsrc;
        char chellofrom;
        
        //ifSourceFile.open("C:\\Users\\bright\\Desktop\\New Text Document.srt", std::ios::in | std::ios::binary);
        ifSourceFile.open(sifSourceFile, std::ios::in | std::ios::binary);

        if(ifSourceFile)
            std::cout << "yes we are in file 1" << std::endl;

        /*while(std::getline(ifSourceFile, chellofrom))
        {
            vcfromsrc.push_back(chellofrom);
            //std::cout << chellofrom << "am doing well" << std::endl;
        }*/

        while (ifSourceFile)
        {
            ifSourceFile.get(chellofrom);
            vcfromsrc.push_back(chellofrom);
        }

        //for(std::string hello : vcfromsrc)
        //   std::cout << hello << std::endl;

        //ofBinCpyFile.open("D:\\Faayor English church\\GHS\\New Text Document.txt", std::ios::out | std::ios::binary);
        ofBinCpyFile.open(sofBinCpyFile, std::ios::out | std::ios::binary);

        if(ofBinCpyFile)
            std::cout << "yes we are in file 2 " << std::endl;
        
        /*for(size_t i = 0; i < vcfromsrc.size(); i++)
        {
            ofBinCpyFile << vcfromsrc[i];
        }*/

        //for(size_t i = 0; i < vcfromsrc.size(); i++)
        //    ofBinCpyFile.put(vcfromsrc[i]);

        // write all content in binary form
        for(char insert : vcfromsrc) 
            ofBinCpyFile.put(insert);
    }
}


