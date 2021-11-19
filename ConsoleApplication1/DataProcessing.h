#pragma once
#include<math.h>
#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/// <summary>
/// @brief :  Class for Data Processing currently only designed for CSV operation
/// \startuml 
///	!pragma layout smetana
/// title __Data Processing Class Diagram__
///	class DataProcessing
/// {
/// std::vector<int> inputData;
/// std::vector<int> processedData;
/// 
///	writeCSVfile()
///	readCSVfile()
///	ParseCSV()
/// }
/// \enduml
/// </summary>
class DataProcessing
{
public :

	/// <summary>
	/// @brief : Default construtor of class
	/// </summary>
	DataProcessing();
	
	/// <summary>
	///  @brief : Default destructor of class
	/// </summary>
	 ~DataProcessing();

	///	<summary>
	/// @brief			:	CSV reading from input path
	/// @param[in]		:	std::string								CSVFilePathName
	/// @param[in,out]	:	std::vector <std::vector<string> >&		CSVLines
	/// @return			:	bool
	///	@details		:	This function is intended to reading of CSV file
	/// \startuml
	/// !pragma layout smetana
	/// readCSVfile --> ParseCSV : CSV FIle path
	/// ParseCSV --> readCSVfile : Read successful
	/// \enduml
	///	</summary>
	bool readCSVfile(std::string CSVFilePathName, std::vector<int>& CSVLines);
	
	///	<summary>
	/// @brief			:	CSV writing from input path
	/// @param[in]		:	std::string								CSVFilePathName
	/// @param[in,out]	:	std::vector <std::vector<string> >		CSVLines
	/// @return			:	bool
	///	@details		:	This function is intended to writing of CSV file
	///	</summary>
	bool writeCSVfile(std::string CSVFilePathName, std::vector<int> CSVLines);
	
	/// <summary>
	/// @brief			:	Parse CSV from input path
	/// @param[in]		:	const std::string&							csvSource
	/// @param[in,out]	:	std::vector <std::vector<std::string> >&	lines
	/// @return			:	void
	///	@details		:	This function is intended for parsing of CSV file
	///						This is called inside readCSV function
	///	</summary>
	void ParseCSV(const std::string& csvSource, std::vector<int>& lines);

	/// <summary>
	/// @brief			:	Getter function for input CSV data
	/// @param[in]		:	None
	/// @param[in,out]	:	None
	/// @return			:	std::vector<int>&
	///	@details		:	Getter function for input CSV data
	///	</summary>
	std::vector<int>& getInputData();

	/// <summary>
	/// @brief			:	Getter function for processed CSV data
	/// @param[in]		:	None
	/// @param[in,out]	:	None
	/// @return			:	std::vector<int>&
	///	@details		:	Getter function for processed CSV data
	///	</summary>
	std::vector<int>& getprocessedData();

private:
	/// @brief Data structure for input CSV data
	std::vector<int> inputData;

	/// @brief Data structure for processed CSV data
	std::vector<int> processedData;
};