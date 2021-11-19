#pragma once
#include "DataProcessing.h"
#include "statsCSV.h"

/// @brief Processing class for csv data processing
class Processing
{
	public:
		/// <summary>
		/// @brief : Default constructor of class
		/// </summary>
		Processing();
	
		/// <summary>
		///  @brief : Default distructor of class
		/// </summary>
		~Processing();

		///	<summary>
		/// @brief			:	Processing of input data 
		/// @return			:	void
		///	@details		:	This function is responsible for processing input data
		///	</summary>
		void processInputData();

		///	<summary>
		/// @brief			:	Processing function
		/// @return			:	void
		///	@details		:	This function is responsible for processing input data
		///	</summary>
		void process();

		///	<summary>
		/// @brief			:	Algo processing function
		/// @return			:	Computed statistics structure
		///	@details		:	This function is responsible for processing Algorithm
		/// \startuml
		/// !pragma layout smetana
		/// (*) --> "computeMinVal()"
		/// --> "computeMaxVal()"
		/// --> "computeMeanVal()"
		/// --> "computeVarianceVal()"
		/// --> "computeStandardDeviation()"
		/// --> "computeHistogram()"
#ifdef ADD_NEW_FUNCTION
		/// --> "computeProbabilityDensity()"
#endif
		/// --> (*)
		/// \enduml
		///	</summary>
		bool processAlgo();

		///	<summary>
		/// @brief			:	Processing the output 
		/// @return			:	void
		///	@details		:	This function is responsible for processing output
		///	</summary>
		void processOutput();

private:
	/// @brief Data process object
	DataProcessing processObject;

	///// @brief Data structure to contain stats
	//statsCSV statObject;
};