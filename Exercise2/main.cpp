#include <iostream>
#include <fstream>
#include <iomanip>

double function(double x)
{
    return (3./4)*x - (7./4) ;       // (x-1)*(2+1)/(5-1) - 1
}


int main()
{
    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);

    if (ifstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }

    std::ofstream outFile("result.csv");
    std::string header = "# N Mean";
    outFile << header << std::endl;


    double val = 0;
    double sum = 0;
    unsigned int countVal = 0;
    double mean = 0;


    while(ifstr >> val)
    {
        double y = function(val);
        sum += y;
        countVal++;
        mean = sum/countVal;

        outFile << countVal << "  " << std::scientific << std::setprecision(16) << mean << std::endl;
    }

    ifstr.close();

    outFile.close();

    return 0;
}
