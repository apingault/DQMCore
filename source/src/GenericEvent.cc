/// \file DQMGenericEvent.cc
/*
 *
 * DQMGenericEvent.cc source template automatically generated by a class generator
 * Creation date : lun. mars 7 2016
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
#include "dqm4hep/GenericEvent.h"
#include "dqm4hep/StreamingHelper.h"
#include "dqm4hep/Plugin.h"

namespace dqm4hep {

  namespace core {

    DQM_PLUGIN_DECL( GenericEventStreamer , "GenericEventStreamer" )

    GenericEvent::GenericEvent() :
      m_eventNumber(0),
      m_runNumber(0),
      m_timeStamp(0)
    {
      /* nop */
    }

    //-------------------------------------------------------------------------------------------------

    GenericEvent::GenericEvent(int eventNumber) :
		    m_eventNumber(eventNumber),
		    m_runNumber(0),
		    m_timeStamp(0)
    {
      /* nop */
    }

    //-------------------------------------------------------------------------------------------------

    GenericEvent::GenericEvent(int runNumber, int eventNumber) :
		    m_eventNumber(eventNumber),
		    m_runNumber(runNumber),
		    m_timeStamp(0)
    {
      /* nop */
    }

    //-------------------------------------------------------------------------------------------------

    GenericEvent::~GenericEvent()
    {
      /* nop */
    }

    //-------------------------------------------------------------------------------------------------

    void GenericEvent::setEventNumber(int eventNumber)
    {
      m_eventNumber = eventNumber;
    }

    //-------------------------------------------------------------------------------------------------

    int GenericEvent::getEventNumber() const
    {
      return m_eventNumber;
    }

    //-------------------------------------------------------------------------------------------------

    void GenericEvent::setRunNumber(int runNumber)
    {
      m_runNumber = runNumber;
    }

    //-------------------------------------------------------------------------------------------------

    int GenericEvent::getRunNumber() const
    {
      return m_runNumber;
    }

    //-------------------------------------------------------------------------------------------------

    void GenericEvent::setTimeStamp(int64_t timeStamp)
    {
      m_timeStamp = timeStamp;
    }

    //-------------------------------------------------------------------------------------------------

    int64_t GenericEvent::getTimeStamp() const
    {
      return m_timeStamp;
    }

    //-------------------------------------------------------------------------------------------------

    void GenericEvent::setDetectorName(const std::string &detectorName)
    {
      m_detectorName = detectorName;
    }

    //-------------------------------------------------------------------------------------------------

    const std::string &GenericEvent::getDetectorName() const
    {
      return m_detectorName;
    }

    //-------------------------------------------------------------------------------------------------

    void GenericEvent::setDescription(const std::string &description)
    {
      m_description = description;
    }

    //-------------------------------------------------------------------------------------------------

    const std::string &GenericEvent::getDescription() const
    {
      return m_description;
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::setValues(const std::string &key, const IntVector &vals)
    {
      return this->setValuesPrivate(key, m_intValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::setValues(const std::string &key, const FloatVector &vals)
    {
      return this->setValuesPrivate(key, m_floatValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::setValues(const std::string &key, const DoubleVector &vals)
    {
      return this->setValuesPrivate(key, m_doubleValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::setValues(const std::string &key, const StringVector &vals)
    {
      return this->setValuesPrivate(key, m_stringValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::getValues(const std::string &key, IntVector &vals) const
    {
      return this->getValuesPrivate(key, m_intValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::getValues(const std::string &key, FloatVector &vals) const
    {
      return this->getValuesPrivate(key, m_floatValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::getValues(const std::string &key, DoubleVector &vals) const
    {
      return this->getValuesPrivate(key, m_doubleValues, vals);
    }

    //-------------------------------------------------------------------------------------------------

    template <>
    StatusCode GenericEvent::getValues(const std::string &key, StringVector &vals) const
    {
      return this->getValuesPrivate(key, m_stringValues, vals);
    }

    //-------------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------

    GenericEventStreamer::GenericEventStreamer()
    {
      /* nop */
    }

    //-------------------------------------------------------------------------------------------------

    GenericEventStreamer::~GenericEventStreamer()
    {
      /* nop */
    }

    //-------------------------------------------------------------------------------------------------

    Event *GenericEventStreamer::createEvent() const
    {
      EventBase<GenericEvent> *pEventBase = new EventBase<GenericEvent>();
      pEventBase->setEvent(new GenericEvent());

      return pEventBase;
    }

    //-------------------------------------------------------------------------------------------------

    StatusCode GenericEventStreamer::write(const Event *const pEvent, xdrstream::IODevice *pDevice)
    {
      const GenericEvent *pGenericEvent = pEvent->getEvent<GenericEvent>();

      if(NULL == pGenericEvent)
        return STATUS_CODE_INVALID_PARAMETER;

      // write event info
      if( ! XDR_TESTBIT( pDevice->write<int32_t>( & pGenericEvent->m_eventNumber ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( pDevice->write<int32_t>( & pGenericEvent->m_runNumber ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( pDevice->write<int64_t>( & pGenericEvent->m_timeStamp ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( pDevice->write( & pGenericEvent->m_detectorName ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( pDevice->write( & pGenericEvent->m_description ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      // write event contents
      const GenericEvent::IntVectorMap &intVals(pGenericEvent->m_intValues);
      if( ! XDR_TESTBIT( StreamingHelper::write( pDevice , intVals ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( StreamingHelper::write( pDevice , pGenericEvent->m_floatValues ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( StreamingHelper::write( pDevice , pGenericEvent->m_doubleValues ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      if( ! XDR_TESTBIT( StreamingHelper::write( pDevice , pGenericEvent->m_stringValues ) , xdrstream::XDR_SUCCESS ) )
        return STATUS_CODE_FAILURE;

      return STATUS_CODE_SUCCESS;
    }

    //-------------------------------------------------------------------------------------------------

    StatusCode GenericEventStreamer::read(Event *&pEvent, xdrstream::IODevice *pDevice)
    {
      pEvent = NULL;

      GenericEvent *pGenericEvent = new GenericEvent();
      EventBase<GenericEvent> *pGenericEventBase = new EventBase<GenericEvent>();
      pGenericEventBase->setEvent(pGenericEvent);

      try
      {
        // write event info
        if( ! XDR_TESTBIT( pDevice->read<int32_t>( & pGenericEvent->m_eventNumber ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        if( ! XDR_TESTBIT( pDevice->read<int32_t>( & pGenericEvent->m_runNumber ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        if( ! XDR_TESTBIT( pDevice->read<int64_t>( & pGenericEvent->m_timeStamp ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        if( ! XDR_TESTBIT( pDevice->read( & pGenericEvent->m_detectorName ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        if( ! XDR_TESTBIT( pDevice->read( & pGenericEvent->m_description ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        // write event contents
        if( ! XDR_TESTBIT( StreamingHelper::read( pDevice , pGenericEvent->m_intValues ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        if( ! XDR_TESTBIT( StreamingHelper::read( pDevice , pGenericEvent->m_floatValues ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);

        if( ! XDR_TESTBIT( StreamingHelper::read( pDevice , pGenericEvent->m_doubleValues ) , xdrstream::XDR_SUCCESS ) )
          throw StatusCodeException(STATUS_CODE_FAILURE);
      }
      catch(StatusCodeException &exception)
      {
        if( ! pGenericEventBase->isOwner() )
          delete pGenericEvent;

        delete pGenericEventBase;

        return STATUS_CODE_FAILURE;
      }

      pEvent = pGenericEventBase;

      return STATUS_CODE_SUCCESS;
    }

    //-------------------------------------------------------------------------------------------------

    StatusCode GenericEventStreamer::write(const Event *const pEvent, const std::string &subEventIdentifier, xdrstream::IODevice *pDevice)
    {
      return this->write(pEvent, pDevice);
    }

  }

} 
