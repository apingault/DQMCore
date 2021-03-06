  /// \file DQMModuleApi.cc
/*
 *
 * DQMModuleApi.cc source template automatically generated by a class generator
 * Creation date : ven. oct. 31 2014
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

// -- dqm4hep headers
#include "dqm4hep/DQMModuleApi.h"
#include "dqm4hep/DQMModuleApplication.h"
#include "dqm4hep/DQMAnalysisModuleApplication.h"
#include "dqm4hep/DQMLogging.h"
#include "dqm4hep/DQMMonitorElement.h"
#include "dqm4hep/DQMMonitorElementManager.h"
#include "dqm4hep/DQMStorage.h"
#include "dqm4hep/DQMDirectory.h"
#include "dqm4hep/DQMModule.h"
#include "dqm4hep/DQMArchiver.h"
#include "dqm4hep/DQMAlertSystem.h"
#include "dqm4hep/DQMRun.h"
#include "dqm4hep/DQMCycle.h"
#include "dqm4hep/tinyxml.h"

namespace dqm4hep
{

void DQMModuleApi::cd(const DQMModule *const pModule)
{
	pModule->getModuleApplication()->getMonitorElementManager()->cd();
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::cd(const DQMModule *const pModule, const std::string &dirName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->cd(dirName);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::mkdir(const DQMModule *const pModule, const std::string &dirName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->mkdir(dirName);
}

//-------------------------------------------------------------------------------------------------

void DQMModuleApi::ls(const DQMModule *const pModule, bool recursive)
{
	pModule->getModuleApplication()->getMonitorElementManager()->ls(recursive);
}

//-------------------------------------------------------------------------------------------------

const std::string &DQMModuleApi::pwd(const DQMModule *const pModule)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->pwd();
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::goUp(const DQMModule *const pModule)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->goUp();
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::rmdir(const DQMModule *const pModule, const std::string &dirName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->rmdir(dirName);
}

//-------------------------------------------------------------------------------------------------

bool DQMModuleApi::dirExists(const DQMModule *const pModule, const std::string &dirName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->dirExists(dirName);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookRealHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			REAL_HISTOGRAM_1D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH1FAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookIntHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			INT_HISTOGRAM_1D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH1IAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookCharHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			CHAR_HISTOGRAM_1D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH1CAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookShortHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			SHORT_HISTOGRAM_1D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH1SAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookRealHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			REAL_HISTOGRAM_2D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH2FAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookIntHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			INT_HISTOGRAM_2D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH2IAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookCharHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			CHAR_HISTOGRAM_2D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH2CAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookShortHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			SHORT_HISTOGRAM_2D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH2SAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookRealHistogram3D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax,
		int nZBins, float zMin, float zMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			REAL_HISTOGRAM_3D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH3FAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax, nZBins, zMin, zMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookIntHistogram3D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax,
		int nZBins, float zMin, float zMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			INT_HISTOGRAM_3D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TH3IAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax, nZBins, zMin, zMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookProfile1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax, float yMin, float yMax, Option_t* option)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			PROFILE_1D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TProfileAllocator(), nXBins, xMin, xMax, yMin, yMax, option ));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookProfile2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax,
		float zMin, float zMax, Option_t* option)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			PROFILE_2D_ELEMENT_TYPE, ".", name, title, pModule->getName(), TProfile2DAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax, zMin, zMax, option));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookInt(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, const int &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			INT_ELEMENT_TYPE, ".", name, title, pModule->getName(), TScalarIntAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookFloat(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, const float &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			REAL_ELEMENT_TYPE, ".", name, title, pModule->getName(), TScalarFloatAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookShort(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, const short &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			SHORT_ELEMENT_TYPE, ".", name, title, pModule->getName(), TScalarShortAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookString(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &name, const std::string &title, const std::string &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			STRING_ELEMENT_TYPE, ".", name, title, pModule->getName(), TScalarStringAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookRealHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			REAL_HISTOGRAM_1D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH1FAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookIntHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			INT_HISTOGRAM_1D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH1IAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookCharHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			CHAR_HISTOGRAM_1D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH1CAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookShortHistogram1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, int nBins, float minimum, float maximum)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			SHORT_HISTOGRAM_1D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH1SAllocator(), nBins, minimum, maximum));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookRealHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			REAL_HISTOGRAM_2D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH2FAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookIntHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			INT_HISTOGRAM_2D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH2IAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookCharHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			CHAR_HISTOGRAM_2D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH2CAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookShortHistogram2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			SHORT_HISTOGRAM_2D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH2SAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookRealHistogram3D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax,
		int nZBins, float zMin, float zMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			REAL_HISTOGRAM_3D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH3FAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax, nZBins, zMin, zMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookIntHistogram3D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax,
		int nZBins, float zMin, float zMax)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			INT_HISTOGRAM_3D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TH3IAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax, nZBins, zMin, zMax));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookProfile1D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax, float yMin, float yMax, Option_t* option)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			PROFILE_1D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TProfileAllocator(), nXBins, xMin, xMax, yMin, yMax, option));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookProfile2D(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title,
		int nXBins, float xMin, float xMax,
		int nYBins, float yMin, float yMax,
		float zMin, float zMax, Option_t* option)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookHistogram(monitorElement,
			PROFILE_2D_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TProfile2DAllocator(), nXBins, xMin, xMax, nYBins, yMin, yMax, zMin, zMax, option));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookInt(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, const int &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			INT_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TScalarIntAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookFloat(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, const float &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			REAL_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TScalarFloatAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookShort(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, const short &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			SHORT_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TScalarShortAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookString(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &dirName, const std::string &name, const std::string &title, const std::string &value)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookObject(monitorElement,
			STRING_ELEMENT_TYPE, dirName, name, title, pModule->getName(), TScalarStringAllocator(), value));

	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::getAllMonitorElements(const DQMModule *const pModule, DQMMonitorElementPtrList &monitorElementList)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->getAllMonitorElements(monitorElementList);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::getMonitorElement(const DQMModule *const pModule, const std::string &monitorElementName, DQMMonitorElementPtr &monitorElement)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->getMonitorElement(monitorElementName, monitorElement);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::getMonitorElement(const DQMModule *const pModule, const std::string &dirName, const std::string &monitorElementName, DQMMonitorElementPtr &monitorElement)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->getMonitorElement(dirName, monitorElementName, monitorElement);
}

//-------------------------------------------------------------------------------------------------

DQMMonitorElementPtr DQMModuleApi::getMonitorElement(const DQMModule *const pModule, const std::string &monitorElementName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->getMonitorElement(monitorElementName);
}

//-------------------------------------------------------------------------------------------------

DQMMonitorElementPtr DQMModuleApi::getMonitorElement(const DQMModule *const pModule, const std::string &dirName, const std::string &monitorElementName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->getMonitorElement(dirName, monitorElementName);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::deleteMonitorElement(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement)
{
	std::string fullName = (monitorElement->getPath() + monitorElement->getName()).getPath();
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->deleteMonitorElement(monitorElement));
	pModule->getModuleApplication()->getMonitorElementSender()->removeAvailableMonitorElement(fullName);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::sendAlert(const DQMModule *const pModule, DQMAlertType type, const std::string &message)
{
	return pModule->getModuleApplication()->getAlertNotifier()->notify(type, message);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::sendAlert(const DQMModule *const pModule, DQMAlertType type, const std::string &message, const DQMMonitorElementPtr &monitorElement)
{
	return pModule->getModuleApplication()->getAlertNotifier()->notify(type, message, monitorElement);
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::resetMonitorElements(const DQMModule *const pModule, DQMResetPolicy policy)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->resetMonitorElements(policy);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::resetMonitorElements(const DQMModule *const pModule)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->resetMonitorElements();
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::registerQualityTestFactory(const DQMModule *const pModule, const std::string &qualityTestFactoryName, const DQMQualityTestFactory *const pQualityTestFactory)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->registerQualityTestFactory(qualityTestFactoryName, pQualityTestFactory);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::createQualityTest(const DQMModule *const pModule, TiXmlElement *const pXmlElement)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->createQualityTest(pXmlElement);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::addQualityTest(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &qualityTestName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->addQualityTest(monitorElement, qualityTestName);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::runQualityTests(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->runQualityTests(monitorElement);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::runQualityTest(const DQMModule *const pModule, DQMMonitorElementPtr &monitorElement, const std::string &qualityTestName)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->runQualityTest(monitorElement, qualityTestName);
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::runQualityTests(const DQMModule *const pModule)
{
	return pModule->getModuleApplication()->getMonitorElementManager()->runQualityTests();
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::getTimeSinceStartOfRun(const DQMAnalysisModule *const pModule, DQMTimeDuration &duration)
{
	DQMAnalysisModuleApplication *pApplication = dynamic_cast<DQMAnalysisModuleApplication *>(pModule->getModuleApplication());

	if( ! pApplication )
		return STATUS_CODE_INVALID_PARAMETER;

	DQMRun *pRun = pApplication->getCurrentRun();

	if( ! pRun )
		return STATUS_CODE_FAILURE;

	duration = pRun->getStartTime() - DQMCoreTool::now();

	return STATUS_CODE_FAILURE;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::getTimeSinceStartOfCycle(const DQMAnalysisModule *const pModule, DQMTimeDuration &duration)
{
	DQMAnalysisModuleApplication *pApplication = dynamic_cast<DQMAnalysisModuleApplication *>(pModule->getModuleApplication());

	if( ! pApplication )
		return STATUS_CODE_INVALID_PARAMETER;

	DQMCycle *pCycle = pApplication->getCycle();

	if( ! pCycle )
		return STATUS_CODE_FAILURE;

	duration = pCycle->getStartTime() - DQMCoreTool::now();

	return STATUS_CODE_FAILURE;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookMonitorElement(const DQMModule *const pModule, const TiXmlElement *const pXmlElement,
		const std::string &meName, DQMMonitorElementPtr &monitorElement)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookMonitorElement(pXmlElement, pModule->getName(), meName, monitorElement));
	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

//-------------------------------------------------------------------------------------------------

StatusCode DQMModuleApi::bookMonitorElement(const DQMModule *const pModule, const TiXmlElement *const pXmlElement,
		DQMMonitorElementPtr &monitorElement, const DQMParameters &parameters)
{
	RETURN_RESULT_IF(STATUS_CODE_SUCCESS, !=, pModule->getModuleApplication()->getMonitorElementManager()->bookMonitorElement(pXmlElement, pModule->getName(), monitorElement, parameters));
	pModule->getModuleApplication()->getMonitorElementSender()->addAvailableMonitorElement(monitorElement);

	return STATUS_CODE_SUCCESS;
}

} 

