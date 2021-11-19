#include "statsCSV.h"
#include "Processing.h"

#define ARRAY_LENGTH 256

statsCSV::statsCSV()
{

}

statsCSV::statsCSV(std::vector<int> data)
{
	csvData = data;
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        statObject.histogram.push_back(0);
    }
}

statsCSV::~statsCSV()
{

}

int statsCSV::computeMinVal()
{
    if (csvData.size() < 1)
    {
        return 1;
    }

    int smallest_element = csvData[0]; 
    for (int i = 1; i < csvData.size(); i++)  
    {
        if (csvData[i] < smallest_element)
        {
            smallest_element = csvData[i];
        }
    }

    statObject.min = smallest_element;

    return 0;
}

int statsCSV::computeMaxVal()
{
    if (csvData.size() < 1)
    {
        return 1;
    }

    int largest_element = csvData[0]; 
    for (int i = 1; i < csvData.size(); i++)  
    {
        if (csvData[i] > largest_element)
        {
            largest_element = csvData[i];
        }
    }

    statObject.max = largest_element;

    return 0;
}

int statsCSV::computeMeanVal()
{
    if (csvData.size() < 1)
    {
        return 1;
    }

    float sum = 0.0f;
    for (int i = 0; i < csvData.size(); i++)  
    {
        sum = sum + csvData.at(i);
    }

    statObject.mean = sum / csvData.size();

    return 0;
}

int statsCSV::computeVariance()
{
    if (csvData.size() < 1)
    {
        return 1;
    }
    
    float numerator = 0.0f;
    for (int i = 0; i < csvData.size(); i++)
    {
        numerator = numerator + pow((csvData.at(i) - statObject.mean), 2);
    }

    statObject.variance = numerator / csvData.size();

    return 0;
}

int statsCSV::computeStandardDeviation()
{
    if (csvData.size() < 1)
    {
        return 1;
    }

    statObject.standardDeviation = sqrt(statObject.variance);

    return 0;
}

int statsCSV::computeHistogram()
{
    if (csvData.size() < 1)
    {
        return 1;
    }

    for (int i = 0; i < csvData.size(); i++)
    {
        statObject.histogram.at(csvData.at(i)) = statObject.histogram.at(csvData.at(i)) + 1;
    }

    return 0;
}

int statsCSV::getMinVal()const
{
    return statObject.min;
}

int statsCSV::getMaxVal()const
{
    return statObject.max;
}

float statsCSV::getMeanVal()const
{
    return statObject.mean;
}

float statsCSV::getVariance()const
{
    return statObject.variance;
}

float statsCSV::getStandardDeviation()const
{
    return statObject.standardDeviation;
}

#ifdef ADD_NEW_FUNCTION
int statsCSV::computeProbabilityDensity()
{
    if (csvData.size() < 1)
    {
        return 1;
    }

    float sum = 0.0f;

    for (int i = 0; i < statObject.histogram.size(); i++)
    {
        sum = sum + statObject.histogram.at(i);
    }

    for (int i = 0; i < statObject.histogram.size(); i++)
    {
        statObject.probabilityDensity.push_back(statObject.histogram.at(i) / sum);
    }

    return 0;
}
#endif