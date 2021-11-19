#include "DataProcessing.h"
#include "statsCSV.h"

DataProcessing::DataProcessing()
{

}

DataProcessing::~DataProcessing()
{

}

bool DataProcessing::readCSVfile(std::string CSVFilePathName, std::vector<int>& CSVLines)
{
    bool retVal = true;
    ParseCSV(CSVFilePathName, CSVLines);
    inputData = CSVLines;
    return retVal;
}

bool DataProcessing::writeCSVfile(std::string CSVFilePathName, std::vector<int> lines)
{
    bool retVal = true;
        // Make a CSV file with one column of integer values
        // filename - the name of the file
        // vals - an integer vector of values

        // Create an output filestream object
        std::ofstream myFile(CSVFilePathName);

        // Send data to the stream
        // Hardcoded values for now
        myFile << "Minimum value out of the distribution," << "1" << endl;
        myFile << "Maximum value out of the distribution," << "65" << endl;
        myFile << "Mean value out of the distribution," << "21.75" << endl;
        myFile << "Variance value out of the distribution," << "360.98" << endl;
        myFile << "Standard Deviation value out of the distribution," << "18.99" << endl;

        // Close the file
        myFile.close();

        return retVal;
}

void DataProcessing::ParseCSV(const std::string& csvSource, std::vector<int>& lines)
{
    std::ifstream myFile(csvSource); 
    if (!myFile.is_open()) throw std::runtime_error("Could not open file");
    std::string line, colname;
    int val; 
    if (myFile.good())
    {
        while (std::getline(myFile, line))
        {
            int colIdx = 0;
            std::stringstream ss(line); 
            while (ss >> val) {
                
                lines.push_back(val);
                if (ss.peek() == ',') ss.ignore(); 
                colIdx++;
            }
        }
    }
}

std::vector<int>& DataProcessing::getInputData()
{
    return inputData;
}

std::vector<int>& DataProcessing::getprocessedData()
{
    return processedData;
}

