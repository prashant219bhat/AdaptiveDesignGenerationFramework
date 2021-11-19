#include "Processing.h"
#include "statsCSV.h"

Processing::Processing()
{

}

Processing::~Processing()
{

}

void Processing:: processInputData()
{
    std::string InputCSVFile = "D:\\Projects\\Hackathon\\TestApplicationDoxy\\TestDoxyGen\\Debug\\InputData.csv";
    std::vector<int> Data;
    processObject.readCSVfile(InputCSVFile, Data);
}

void Processing::process()
{
    processInputData();
    bool statObject = processAlgo();
    processOutput();
}

bool Processing:: processAlgo()
{
    statsCSV statsObject(processObject.getInputData());
    statsObject.computeMinVal();
    statsObject.computeMaxVal();
    statsObject.computeMeanVal();
    statsObject.computeVariance();
    statsObject.computeStandardDeviation();
    statsObject.computeHistogram();
#ifdef ADD_NEW_FUNCTION
    statsObject.computeProbabilityDensity();
#endif
    return true;
}

void Processing:: processOutput()
{
    std::string OutputCSVFile = "D:\\Projects\\Hackathon\\TestApplicationDoxy\\TestDoxyGen\\Debug\\OutputData.csv";
    std::vector<int> lines;
    processObject.writeCSVfile(OutputCSVFile, lines);
}