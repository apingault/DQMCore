  /// \file DQMRun.h
/*
 *
 * DQMRun.h header template automatically generated by a class generator
 * Creation date : dim. mars 29 2015
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


#ifndef DQMRUN_H
#define DQMRUN_H

// -- dqm4hep headers
#include "dqm4hep/DQM4HEP.h"

// -- xdrstream headers
#include "xdrstream/xdrstream.h"

// -- std headers
#include <ctime>
#include <string>

namespace dqm4hep
{

/** DQMRun class
 */ 
class DQMRun : public xdrstream::Streamable
{
public:
	/** Constructor with run number (optional)
	 */
	DQMRun(int runNumber = 0, const std::string &description = "", const std::string &detectorName = "");

	/** Destructor
	 */
	~DQMRun();

	/** Get the run number
	 */
	int getRunNumber() const;

	/** Get the start time
	 */
	DQMTimePoint getStartTime() const;

	/** Get the end time
	 */
	DQMTimePoint getEndTime() const;

	/** Get the run description
	 */
	const std::string &getDescription() const;

	/** Get the detector name related to this run
	 */
	const std::string &getDetectorName() const;

	/** Set the run number
	 */
	void setRunNumber(int runNumber);

	/** Set the start time
	 */
	void setStartTime(const DQMTimePoint &startTime);

	/** Set the end time
	 */
	void setEndTime(const DQMTimePoint &endTime);

	/** Set the run description
	 */
	void setDescription(const std::string &description);

	/** Set the detector name related to this run
	 */
	void setDetectorName(const std::string &detectorName);

	/** Set a parameter.
	 *  The template value is converted into string
	 */
	template <typename T>
	void setParameter(const std::string &key, const T &value);

	/** Get a parameter.
	 *  The value is converted into asked type.
	 *  If the parameter is not found, the value remains unchanged
	 */
	template <typename T>
	void getParameter(const std::string &key, T &value) const;

	/** Get the number of parameters
	 */
	unsigned int getNParameters() const;

	/** Get the parameters keys
	 */
	StringVector getParameterKeys() const;

	xdrstream::Status stream(xdrstream::StreamingMode mode, xdrstream::IODevice *pDevice,
			xdrstream::xdr_version_t version = 0);

protected:
	int                                    m_runNumber;
	DQMTimePoint                           m_startTime;
	DQMTimePoint                           m_endTime;
	std::string                            m_detectorName;
	std::string                            m_description;
	std::map<std::string, std::string>     m_parametersMap;

	friend std::ostream &operator <<(std::ostream &, const DQMRun &);
};

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

inline std::ostream &operator <<(std::ostream &out, const DQMRun &run)
{
	out << "DQMRun :\n"
		"  -> run number : " << run.getRunNumber() << "\n"
		"  -> detector : " << run.getDetectorName() << "\n"
		"  -> description : " << run.getDescription() << "\n"
		"  -> parameters : \n";

	for(auto iter = run.m_parametersMap.begin(), endIter = run.m_parametersMap.end() ;
			endIter != iter ; ++iter)
		out << "   * " << iter->first << " = " << iter->second << "\n";

	return out;
}

//-------------------------------------------------------------------------------------------------

inline int DQMRun::getRunNumber() const
{
	return m_runNumber;
}

//-------------------------------------------------------------------------------------------------

inline DQMTimePoint DQMRun::getStartTime() const
{
	return m_startTime;
}

//-------------------------------------------------------------------------------------------------

inline DQMTimePoint DQMRun::getEndTime() const
{
	return m_endTime;
}

//-------------------------------------------------------------------------------------------------

inline const std::string &DQMRun::getDescription() const
{
	return m_description;
}

//-------------------------------------------------------------------------------------------------

inline const std::string &DQMRun::getDetectorName() const
{
	return m_detectorName;
}

//-------------------------------------------------------------------------------------------------

inline void DQMRun::setRunNumber(int runNumber)
{
	m_runNumber = runNumber;
}

//-------------------------------------------------------------------------------------------------

inline void DQMRun::setStartTime(const DQMTimePoint &startTime)
{
	m_startTime = startTime;
}

//-------------------------------------------------------------------------------------------------

inline void DQMRun::setEndTime(const DQMTimePoint &endTime)
{
	m_endTime = endTime;
}

//-------------------------------------------------------------------------------------------------

inline void DQMRun::setDescription(const std::string &description)
{
	m_description = description;
}

//-------------------------------------------------------------------------------------------------

inline void DQMRun::setDetectorName(const std::string &detectorName)
{
	m_detectorName = detectorName;
}

//-------------------------------------------------------------------------------------------------

template <typename T>
inline void DQMRun::setParameter(const std::string &key, const T &value)
{
	m_parametersMap[key] = DQM4HEP::typeToString<T>(value);
}

//-------------------------------------------------------------------------------------------------

template <typename T>
inline void DQMRun::getParameter(const std::string &key, T &value) const
{
	std::map<std::string, std::string>::const_iterator findIter = m_parametersMap.find(key);

	if(m_parametersMap.end() == findIter)
		return;

	DQM4HEP::stringToType(findIter->second, value);
}

//-------------------------------------------------------------------------------------------------

template <>
inline void DQMRun::setParameter(const std::string &key, const std::string &value)
{
	m_parametersMap[key] = value;
}

//-------------------------------------------------------------------------------------------------

template <>
inline void DQMRun::getParameter(const std::string &key, std::string &value) const
{
	std::map<std::string, std::string>::const_iterator findIter = m_parametersMap.find(key);

	if(m_parametersMap.end() == findIter)
		return;

	value = findIter->second;
}

//-------------------------------------------------------------------------------------------------

inline unsigned int DQMRun::getNParameters() const
{
	return m_parametersMap.size();
}

} 

#endif  //  DQMRUN_H
