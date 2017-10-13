  /// \file DQMMonitorElementManager.h
/*
 *
 * DQMMonitorElementManager.h header template automatically generated by a class generator
 * Creation date : lun. ao�t 17 2015
 *
 * This file is part of DQM4HEP libraries.
 * 
 * DQM4HEP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * DQM4HEP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with DQM4HEP.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef DQMMONITORELEMENTMANAGER_H
#define DQMMONITORELEMENTMANAGER_H

// -- dqm4hep headers
#include "dqm4hep/DQM4HEP.h"
#include "dqm4hep/DQMXmlHelper.h"
#include "dqm4hep/DQMStorage.h"
#include "dqm4hep/DQMDirectory.h"
#include "dqm4hep/DQMMonitorElement.h"
#include "dqm4hep/DQMCoreTool.h"

// -- root headers
#include "TH1F.h"
#include "TH1I.h"
#include "TH1S.h"
#include "TH1C.h"
#include "TH2F.h"
#include "TH2I.h"
#include "TH2S.h"
#include "TH2C.h"
#include "TH3F.h"
#include "TH3I.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TObject.h"
#include "TClass.h"

namespace dqm4hep
{

// Define the most common allocator helpers for user interface.
// Hide them from CINT since C++11 is not supported by ROOT version <= 5
#ifndef __CINT__

typedef allocator_helper<TObject, TH1F, const char*, const char *, int, float, float> TH1FAllocator;
typedef allocator_helper<TObject, TH1I, const char*, const char *, int, float, float> TH1IAllocator;
typedef allocator_helper<TObject, TH1C, const char*, const char *, int, float, float> TH1CAllocator;
typedef allocator_helper<TObject, TH1S, const char*, const char *, int, float, float> TH1SAllocator;

typedef allocator_helper<TObject, TH2F, const char*, const char *, int, float, float, int, float, float> TH2FAllocator;
typedef allocator_helper<TObject, TH2I, const char*, const char *, int, float, float, int, float, float> TH2IAllocator;
typedef allocator_helper<TObject, TH2C, const char*, const char *, int, float, float, int, float, float> TH2CAllocator;
typedef allocator_helper<TObject, TH2S, const char*, const char *, int, float, float, int, float, float> TH2SAllocator;

typedef allocator_helper<TObject, TH3F, const char*, const char *, int, float, float, int, float, float, int, float, float> TH3FAllocator;
typedef allocator_helper<TObject, TH3I, const char*, const char *, int, float, float, int, float, float, int, float, float> TH3IAllocator;

typedef allocator_helper<TObject, TProfile, const char*, const char *, int, float, float, float, float, Option_t*> TProfileAllocator;
typedef allocator_helper<TObject, TProfile2D, const char*, const char *, int, float, float, int, float, float, float, float, Option_t*> TProfile2DAllocator;

typedef allocator_helper<TObject, TScalarInt, int> TScalarIntAllocator;
typedef allocator_helper<TObject, TScalarFloat, float> TScalarFloatAllocator;
typedef allocator_helper<TObject, TScalarShort, short> TScalarShortAllocator;
typedef allocator_helper<TObject, TScalarString, std::string> TScalarStringAllocator;

typedef allocator_helper<TObject, TGraph> TGraphAllocator;
typedef allocator_helper<TObject, TGraphErrors> TGraphErrorsAllocator;

typedef allocator_helper<TObject, TDynamicGraph> TDynamicGraphAllocator;

#endif

class DQMStorage;
class DQMArchiver;
class DQMMonitorElement;
class DQMQualityTest;
class DQMQualityTestFactory;

/** DQMMonitorElementManager class
 */
class DQMMonitorElementManager 
{
	friend class DQMArchiver;

	typedef std::map<const std::string, DQMQualityTest *> DQMQualityTestMap;
	typedef std::map<const std::string, const DQMQualityTestFactory *> DQMQualityTestFactoryMap;

public:
	/** Constructor
	 */
	DQMMonitorElementManager();

	/** Destructor
	 */
	~DQMMonitorElementManager();

 	/////////////////////////
 	// DIRECTORY INTERFACE //
 	/////////////////////////

 	/** Go back to root directory
 	 */
 	void cd();

 	/** Go to directory 'dirName'
 	 */
 	StatusCode cd(const std::string &dirName);

 	/** Create the directory 'dirName'
 	 */
 	StatusCode mkdir(const std::string &dirName);

 	/** List the current directory content
 	 */
 	void ls(bool recursive = false);

 	/** Get the current directory name
 	 */
 	const std::string &pwd();

 	/** Navigate backward in the directory structure
 	 */
 	StatusCode goUp();

 	/** Remove the directory 'dirName'
 	 */
 	StatusCode rmdir(const std::string &dirName);

 	/** Get the current directory name (always defined)
 	 */
 	const std::string &getCurrentDirectoryName() const;

 	/** Get the current directory full path name (always defined)
 	 */
 	DQMPath getCurrentDirectoryFullPathName() const;

 	/** Get the full path name of the sub directory
 	 */
 	StatusCode getFullPathName(const std::string &subDirName, DQMPath &fullPathName) const;

	/** Whether the directory exists
	 */
 	bool dirExists(const std::string &dirName) const;

 public:

 	///////////////////////
 	// BOOKING INTERFACE //
 	///////////////////////

 	/** Book a ROOT histogram. The histogram must be valid and must be a built-in ROOT histogram.
 	 *  The two first arguments of the histogram constructor must the name and the title.
 	 *  Such a function should be used in DQMModule implementation by passing 'this' as first argument
 	 */
 	template <typename HistoType, typename ... Args>
 	StatusCode bookHistogram(DQMMonitorElementPtr &monitorElement, DQMMonitorElementType type, const std::string &directory, const std::string &name, const std::string &title,
 			const std::string &moduleName, allocator_helper<TObject, HistoType, const char *, const char *, Args...> allocator, Args ...args);

 	/** Book a generic ROOT TObject.
 	 *  Optionnal constructor may be passed using the variadic template arguments (Args...  args)
 	 *  Such a function should be used in DQMModule implementation by passing 'this' as first argument
 	 */
 	template <typename ObjectType, typename ... Args>
 	StatusCode bookObject(DQMMonitorElementPtr &monitorElement, DQMMonitorElementType type, const std::string &directory, const std::string &name, const std::string &title,
 			const std::string &moduleName, allocator_helper<TObject, ObjectType, Args...> allocator, Args ...args);

 	/** Book a monitor element from the xml element (DEPRECATED, use version with parameters map)
 	 */
 	StatusCode bookMonitorElement(const TiXmlElement *const pXmlElement, const std::string &moduleName,
 			const std::string &meName, DQMMonitorElementPtr &monitorElement);

 	/** Book a monitor element from the xml element
 	 */
	StatusCode bookMonitorElement(const TiXmlElement *const pXmlElement, const std::string &moduleName,
			DQMMonitorElementPtr &monitorElement, const DQMParameters &parameters);

 	/** Book a generic TObject. The TObject must be valid and must be a built-in ROOT object or
 	 *  a user defined class inheriting from TObject and providing a dictionary.
 	 *  Such a function should be used in DQMModule implementation by passing 'this' as first argument
 	 */
 	StatusCode bookObject(DQMMonitorElementPtr &monitorElement, const std::string &directory, const std::string &name, const std::string &title,
 			const std::string &moduleName, const std::string &className);

 public:

 	///////////////////////
 	// GETTERS INTERFACE //
 	///////////////////////

 	/** Get all the monitor elements already booked by this module in all the directories
 	 */
 	StatusCode getAllMonitorElements(DQMMonitorElementPtrList &monitorElementList) const;

 	/** Get the monitor element in the current directory (result by ptr reference)
 	 */
 	StatusCode getMonitorElement(const std::string &monitorElementName, DQMMonitorElementPtr &monitorElement) const;

 	/** Get the monitor element in the given directory (result by ptr reference)
 	 */
 	StatusCode getMonitorElement(const std::string &dirName, const std::string &monitorElementName, DQMMonitorElementPtr &monitorElement) const;

 	/** Get the monitor element in the current directory.
 	 *  The element is directly returned without any ptr check
 	 */
 	DQMMonitorElementPtr getMonitorElement(const std::string &monitorElementName) const;

 	/** Get the monitor element in the given directory.
 	 *  The element is directly returned without any ptr check
 	 */
 	DQMMonitorElementPtr getMonitorElement(const std::string &dirName, const std::string &monitorElementName) const;


 	////////////////////////
 	// DELETION INTERFACE //
 	////////////////////////

 	/** Delete the monitor element (by element ptr)
 	 */
 	StatusCode deleteMonitorElement(DQMMonitorElementPtr &monitorElement);

 	/** Delete the monitor element (by element name)
 	 */
 	StatusCode deleteMonitorElement(const std::string &dirName, const std::string &monitorElement);

 public:

 	////////////////////////////
 	// QUALITY TEST INTERFACE //
 	////////////////////////////

 	/** Register a new quality test.
 	 *  Ownership transfered to the manager.
 	 */
 	StatusCode registerQualityTestFactory(const std::string &qualityTestType, const DQMQualityTestFactory *const pQualityTestFactory);

 	/** Create a quality test from the xml element.
 	 *  The xml element must contain the attribute 'type' and 'name'
 	 */
 	StatusCode createQualityTest(TiXmlElement *const pXmlElement);

 	/** Add a quality test to a given monitor element.
 	 *
 	 *  The quality test must have been registered in the framework before
 	 *  calling this method.
 	 */
 	StatusCode addQualityTest(DQMMonitorElementPtr &monitorElement, const std::string &qualityTestName) const;

 	/** Remove a specific quality test attached to this monitor element
 	 */
 	StatusCode removeQualityTest(DQMMonitorElementPtr &monitorElement, const std::string &qualityTestName);

 	/** Remove all quality tests attached to this monitor element
 	 */
 	StatusCode removeQualityTests(DQMMonitorElementPtr &monitorElement);

 	/** Run all the quality test attached to this monitor element
 	 */
 	StatusCode runQualityTests(DQMMonitorElementPtr &monitorElement);

 	/** Run all the quality test attached to these monitor elements
 	 */
 	StatusCode runQualityTests(const DQMMonitorElementPtrList &monitorElementList);

 	/** Run a specific quality test attached to this monitor element
 	 */
 	StatusCode runQualityTest(DQMMonitorElementPtr &monitorElement, const std::string &qualityTestName);

 	/** Run all the quality test of all the monitor elements
 	 */
 	StatusCode runQualityTests();

 	/** Get all the quality test results
 	 */
 	StatusCode getQualityTestResults(DQMQualityTestResultMap &results) const;

 private:

 	/**
 	 */
 	StatusCode getQualityTest(const std::string &qualityTestName, DQMQualityTest *&pQualityTest) const;

 	/**
 	 */
 	StatusCode runQualityTests(const DQMMonitorElementList &monitorElementList);

// 	/**
// 	 */
// 	StatusCode createQualityTest(const std::string &type, const std::string &name, DQMQualityTest *&pQualityTest) const;

 public:

 	////////////////////////
 	// UITILITY FUNCTIONS //
 	////////////////////////

 	/** Reset all the monitor elements that have the given reset policy
 	 */
 	StatusCode resetMonitorElements(DQMResetPolicy policy) const;

 	/** Reset all the monitor elements of this module
 	 */
 	StatusCode resetMonitorElements() const;

 	/** Get the monitor element list for which the flag "setToPublish" is true
 	 */
 	StatusCode getMonitorElementListToPublish(DQMMonitorElementPtrList &monitorElementList) const;

 private:

 	/** Get the monitor element storage
 	 */
 	DQMStorage *getStorage() const;

 	DQMStorage                       *m_pMonitorElementStorage;
 	DQMQualityTestFactoryMap          m_qualityTestFactoryMap;
 	DQMQualityTestMap                 m_qualityTestMap;
};

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

template <typename HistoType, typename ... Args>
inline StatusCode DQMMonitorElementManager::bookHistogram(DQMMonitorElementPtr &monitorElement, DQMMonitorElementType type, const std::string &directory, const std::string &name, const std::string &title,
		const std::string &moduleName, allocator_helper<TObject, HistoType, const char *, const char *, Args...> allocator, Args ...args)
{
	monitorElement = NULL;
	TObject *pObject = NULL;

	if(name.empty() || DQMCoreTool::containsSpecialCharacters(name) || name.find("/") != std::string::npos)
		return STATUS_CODE_INVALID_PARAMETER;

	try
	{
		DQMDirectory *pDirectory = NULL;
		THROW_RESULT_IF(STATUS_CODE_SUCCESS, !=, m_pMonitorElementStorage->findDir(directory, pDirectory));
		std::string objectName = (pDirectory->getFullPathName() + name).getPath();

		// create the histogram first
		pObject = allocator.create(objectName.c_str(), title.c_str(), args...);

		if(NULL == pObject)
			throw StatusCodeException(STATUS_CODE_FAILURE);

		// and the monitor element
		monitorElement = std::make_shared<DQMMonitorElement>(pObject, type, name, title, moduleName);

		if(NULL == monitorElement)
			throw StatusCodeException(STATUS_CODE_FAILURE);

		// add it to the monitor element list of the module
		THROW_RESULT_IF(STATUS_CODE_SUCCESS, !=, m_pMonitorElementStorage->addMonitorElement(directory, monitorElement));
	}
	catch(StatusCodeException &exception)
	{
		LOG4CXX_ERROR( dqmMainLogger , "Couldn't create monitor element '" << name << "'. Status code exception caught : " << exception.toString() );

		if(NULL != pObject)
			delete pObject;

		return exception.getStatusCode();
	}

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

template <typename ObjectType, typename ... Args>
inline StatusCode DQMMonitorElementManager::bookObject(DQMMonitorElementPtr &monitorElement, DQMMonitorElementType type, const std::string &directory, const std::string &name, const std::string &title,
		const std::string &moduleName, allocator_helper<TObject, ObjectType, Args...> allocator, Args ...args)
{
	monitorElement = NULL;
	TObject *pObject = NULL;

	if(name.empty() || DQMCoreTool::containsSpecialCharacters(name) || name.find("/") != std::string::npos)
		return STATUS_CODE_INVALID_PARAMETER;

	try
	{
		DQMDirectory *pDirectory = NULL;
		THROW_RESULT_IF(STATUS_CODE_SUCCESS, !=, m_pMonitorElementStorage->findDir(directory, pDirectory));
		std::string objectName = (pDirectory->getFullPathName() + name).getPath();

		// create the histogram first
		pObject = allocator.create(args...);

		if(NULL == pObject)
			throw StatusCodeException(STATUS_CODE_FAILURE);

		// and the monitor element
		monitorElement = std::make_shared<DQMMonitorElement>(pObject, type, name, title, moduleName);

		if(NULL == monitorElement)
			throw StatusCodeException(STATUS_CODE_FAILURE);

		// add it to the monitor element list of the module
		THROW_RESULT_IF(STATUS_CODE_SUCCESS, !=, m_pMonitorElementStorage->addMonitorElement(directory, monitorElement));
	}
	catch(StatusCodeException &exception)
	{
		LOG4CXX_ERROR( dqmMainLogger , "Couldn't create monitor element '" << name << "'. Status code exception caught : " << exception.toString() );

		if(NULL != pObject)
			delete pObject;

		return exception.getStatusCode();
	}

	return STATUS_CODE_SUCCESS;
}


} 

#endif  //  DQMMONITORELEMENTMANAGER_H
