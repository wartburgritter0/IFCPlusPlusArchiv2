/* -*-c++-*- IFC++ www.ifcquery.com
*
MIT License

Copyright (c) 2017 Fabian Gerold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcTime.h"
#include "include/IfcTimePeriod.h"

// ENTITY IfcTimePeriod 
IfcTimePeriod::IfcTimePeriod() { m_entity_enum = IFCTIMEPERIOD; }
IfcTimePeriod::IfcTimePeriod( int id ) { m_id = id; m_entity_enum = IFCTIMEPERIOD; }
IfcTimePeriod::~IfcTimePeriod() {}
shared_ptr<IfcPPObject> IfcTimePeriod::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcTimePeriod> copy_self( new IfcTimePeriod() );
	if( m_StartTime ) { copy_self->m_StartTime = dynamic_pointer_cast<IfcTime>( m_StartTime->getDeepCopy(options) ); }
	if( m_EndTime ) { copy_self->m_EndTime = dynamic_pointer_cast<IfcTime>( m_EndTime->getDeepCopy(options) ); }
	return copy_self;
}
void IfcTimePeriod::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCTIMEPERIOD" << "(";
	if( m_StartTime ) { m_StartTime->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_EndTime ) { m_EndTime->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcTimePeriod::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcTimePeriod::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 2 ){ std::stringstream err; err << "Wrong parameter count for entity IfcTimePeriod, expecting 2, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_StartTime = IfcTime::createObjectFromSTEP( args[0] );
	m_EndTime = IfcTime::createObjectFromSTEP( args[1] );
}
void IfcTimePeriod::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	vec_attributes.push_back( std::make_pair( "StartTime", m_StartTime ) );
	vec_attributes.push_back( std::make_pair( "EndTime", m_EndTime ) );
}
void IfcTimePeriod::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
}
void IfcTimePeriod::setInverseCounterparts( shared_ptr<IfcPPEntity> )
{
}
void IfcTimePeriod::unlinkFromInverseCounterparts()
{
}
