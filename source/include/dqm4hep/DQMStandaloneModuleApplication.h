  /// \file DQMStandaloneModuleApplication.h
/*
 *
 * DQMStandaloneModuleApplication.h header template automatically generated by a class generator
 * Creation date : mer. ao�t 26 2015
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


#ifndef DQMSTANDALONEMODULEAPPLICATION_H
#define DQMSTANDALONEMODULEAPPLICATION_H

// -- dqm4hep headers
#include "dqm4hep/DQM4HEP.h"
#include "dqm4hep/DQMModuleApplication.h"
#include "dqm4hep/DQMCycle.h"

namespace dqm4hep
{

class DQMTimerCycle;
class DQMArchiver;

/** DQMStandaloneModuleApplication class
 */
class DQMStandaloneModuleApplication : public DQMModuleApplication, public DQMCycleListener
{
public:
	/** Settings class
	 */
	class Settings
	{
	public:
		/** Constructor
		 */
		Settings();

		/** Print settings
		 */
		void print(const std::string &moduleLogStr);

	public:
		std::string        m_settingsFileName;

		unsigned int       m_sleepTime;
		float              m_cyclePeriod;

		std::string        m_moduleType;
		std::string        m_moduleName;
		std::string        m_monitorElementCollector;

		std::string        m_archiveDirectory;
		bool               m_openArchive;

	};
	/** Constructor
	 */
	DQMStandaloneModuleApplication();

	/** Destructor
	 */
	~DQMStandaloneModuleApplication();

	/** Get the application type ("StandaloneModule")
	 */
	const std::string &getType() const;

	/** Get the application name ( module name)
	 */
	const std::string &getName() const;

	/** Set the parameters to replace while reading settings
	 */
	void setReplacementParameters(const DQMParameters &parametersMap);

	/** Read settings from a xml file.
	 *  Initialize the application. Declare all the services,
	 *  load the shared libraries, configure the active module
	 */
	StatusCode readSettings( const std::string &settingsFile );

	/** Run the application.
	 */
	StatusCode run();

private:
	// from cycle listener
	void onEventProcessed(const DQMCycle *const /*pCycle*/, const DQMEvent *const /*pEvent*/) { /* nop */ }
	void onCycleStarted(const DQMCycle *const pCycle);
	void onCycleStopped(const DQMCycle *const pCycle);

private:
	// bool                          m_stopFlag;
	// bool                          m_isInitialized;

	// the cycle to process
	DQMTimerCycle                *m_pTimerCycle;
	DQMArchiver                  *m_pArchiver;

	// user settings
	Settings                      m_settings;
	DQMParameters                 m_replacementParameters;

	std::string                   m_name;
	std::string                   m_type;
	std::string                   m_moduleLogStr;
}; 

} 

#endif  //  DQMSTANDALONEMODULEAPPLICATION_H
