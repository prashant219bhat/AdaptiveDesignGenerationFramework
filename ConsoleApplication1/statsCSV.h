#pragma once
#include <vector>
#include "Processing.h"

#define ADD_NEW_FUNCTION

/// @brief Structure to manage statistics of csv data
typedef struct
{
    /// @brief Minimum value of the input data array
    int min;
    /// @brief Maximum value of the input data array
    int max;
    /// @brief Mean value of the input data array
    float mean;
    /// @brief Variance of the input data array
    float variance;
    /// @brief Standard deviation of input data array
    float standardDeviation;
    /// @brief Histogram of input data array
    std::vector<int> histogram;
    /// @brief Probability density distribution of input array
    std::vector<float> probabilityDensity;
}stats;

/// <summary>
/// @brief :  Class to compute and manage various statistics of CSV data.
/// \startuml 
///	!pragma layout smetana
///	class statsCSV
/// {
/// std::vector<int> csvData;
/// stats statObject;
/// 
///	computeMinVal()
///	computeMaxVal()
///	computeMeanVal()
/// computeVariance()
/// computeStandardDeviation();
/// computeHistogram();
#ifdef ADD_NEW_FUNCTION
/// computeProbabilityDensity();
#endif
/// getMinVal();
/// getMaxVal();
/// getMeanVal();
/// getVariance();
/// getStandardDeviation();
/// }
/// \enduml
/// </summary>
class statsCSV {
public:
    statsCSV();
    /// <summary>
    /// @brief : Parameterized constructor of class statsCSV
    /// </summary>
    statsCSV(std::vector<int> csvData);

	/// <summary>
    ///  @brief : Default distructor of class
    /// </summary>
    ~statsCSV();

    ///	<summary>
    /// @brief			:	Performs Minimum value computation on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the minimum value of the input array
    ///	</summary>
    int computeMinVal();

    ///	<summary>
    /// @brief			:	Performs Maximum value computation on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the maximum value of the input array
    ///	</summary>
    int computeMaxVal();

    ///	<summary>
    /// @brief			:	Performs Mean value computation on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the mean value of the input array
    ///	</summary>
    int computeMeanVal();

    ///	<summary>
    /// @brief			:	Performs Variance value computation on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the variance value of the input array
    ///	</summary>
    int computeVariance();

    ///	<summary>
    /// @brief			:	Performs Standard Deviation value computation on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the maximum value of the input array
    /// \startuml
    /// !pragma layout smetana
    /// (*) --> "Compute Mean value"
    /// --> "Compute Sum of square of differences
    /// i.e (x-mean)^2"
    /// --> (*)
    /// \enduml
    ///	</summary>
    int computeStandardDeviation();

    ///	<summary>
    /// @brief			:	Performs Histogram value computation on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the histogram of the input array
    ///	</summary>
    int computeHistogram();

#ifdef ADD_NEW_FUNCTION
    ///	<summary>
    /// @brief			:	Compuate Probability Density Distribution on the CSV data
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	0 if SUCCESS, 1 if FAILURE
    ///	@details		:	This function computes the Probability Density Distribution of the input array
    ///	</summary>
    int computeProbabilityDensity();
#endif

    ///	<summary>
    /// @brief			:	Getter function for MINIMUM VALUE
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	MINIMUM VALUE
    ///	@details		:	This function returns the minimum of the input array
    ///	</summary>
    int getMinVal()const;

    ///	<summary>
    /// @brief			:	Getter function for MAXIMUM VALUE
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	MAXIMUM VALUE
    ///	@details		:	This function returns the MAXIMUM of the input array
    ///	</summary>
    int getMaxVal()const;

    ///	<summary>
    /// @brief			:	Getter function for MEAN VALUE
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	MEAN VALUE
    ///	@details		:	This function returns the mean of the input array
    ///	</summary>
    float getMeanVal()const;

    ///	<summary>
    /// @brief			:	Getter function for VARIANCE VALUE
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	VARIANCE VALUE
    ///	@details		:	This function returns the variance of the input array
    ///	</summary>
    float getVariance()const;

    ///	<summary>
    /// @brief			:	Getter function for STD VALUE
    /// @param[in]		:	None
    /// @param[in,out]	:	None
    /// @return			:	STD VALUE
    ///	@details		:	This function returns the standard deviation of the input array
    ///	</summary>
    float getStandardDeviation()const;

private:
    /// @brief Data structure to hold csv Data
    std::vector<int> csvData;

    /// @brief Data structure to contain various data statistical attributes
    stats statObject;
};