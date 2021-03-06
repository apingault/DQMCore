  /// \file DQMEventCounterCycle.h
/*
 *
 * DQMEventCounterCycle.h header template automatically generated by a class generator
 * Creation date : mar. oct. 7 2014
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


#ifndef DQMEVENTCOUNTERCYCLE_H
#define DQMEVENTCOUNTERCYCLE_H

// -- dqm4hep headers
#include "dqm4hep/DQMCycle.h"

namespace dqm4hep
{

/** DQMEventCounterCycle class
 */ 
class DQMEventCounterCycle : public DQMCycle
{
public:
	/** Constructor
	 */
	DQMEventCounterCycle();

	/** Destructor
	 */
	~DQMEventCounterCycle();

	void onCycleStarted() { /* nop */ }
	void onCycleStopped() { /* nop */ }
	void onEventProcessed(const DQMEvent *const /*pEvent*/) { /* nop */ }
	bool isEndOfCycleReached() const;
}; 

} 

#endif  //  DQMEVENTCOUNTERCYCLE_H
