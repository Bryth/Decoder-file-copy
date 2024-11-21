#include "filecpyheader.h"

namespace FilecpyNS
{
    // Function to search for a file in a directory
    bool searchFile(const std::string& srcPath, const std::string& DestPth)
    {
        DIR* dir;
        struct dirent* ent;
        std::vector <std::string> vsfileName2cpy;
        std::string GloSearchFileName;

        // Open directory
        if ((dir = opendir(srcPath.c_str())) == NULL) 
        {
            std::cerr << "Error opening directory: " << srcPath << std::endl;
            return false;
        }
        else 
        {
            // staging files name
            std::cout <<"staging all files in " << srcPath.c_str() << std::endl;

            // Iterate through directory entries
            while ((ent = readdir(dir)) != NULL)
            {
                //to avoid storing fullstops as directory item
                if((std::string(ent->d_name) == ".") || (std::string(ent->d_name) == "..")) continue;
                else
                vsfileName2cpy.push_back(std::string(ent->d_name));
            }
                
        }

        // sort all the file name in order
        if(vsfileName2cpy.size() > 1)
            sort(vsfileName2cpy.begin(), vsfileName2cpy.end());

        for(std::string SearchFileName : vsfileName2cpy)
        {
            //std::cout << SearchFileName << std::endl;
            GloSearchFileName = SearchFileName;

            if ((dir = opendir(srcPath.c_str())) == NULL) 
                std::cerr << "Error opening directory: " << srcPath << std::endl;

            // Iterate through directory entries
            while ((ent = readdir(dir)) != NULL) 
            { 
                // Check if file matches
                // cast ent->d_name to string
                if (std::string(ent->d_name) == SearchFileName)
                {  
                    std::string stradd1, stradd2;
                    stradd1 = srcPath +"\\" + SearchFileName;
                    stradd2 = DestPth + "\\" + SearchFileName;
                    FilecpyNS::copyfile(stradd1.c_str(), stradd2.c_str());

                    if(SearchFileName == vsfileName2cpy[vsfileName2cpy.size() - 1])
                    {
                        std::cout <<"Done !!!\n";
                        closedir(dir);
                        return true;  
                    }

                }
            }
        }


        // Close directory
        closedir(dir);

        // File not found
        std::cout << "File not found: " << GloSearchFileName << std::endl;
        return false;
    }
}


