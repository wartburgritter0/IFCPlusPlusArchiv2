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
#include "include/IfcApplication.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOrganization.h"

// ENTITY IfcApplication 
IfcApplication::IfcApplication() { m_entity_enum = IFCAPPLICATION; }
IfcApplication::IfcApplication( int id ) { m_id = id; m_entity_enum = IFCAPPLICATION; }
IfcApplication::~IfcApplication() {}
shared_ptr<IfcPPObject> IfcApplication::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcApplication> copy_self( new IfcApplication() );
	if( m_ApplicationDeveloper ) { copy_self->m_ApplicationDeveloper = dynamic_pointer_cast<IfcOrganization>( m_ApplicationDeveloper->getDeepCopy(options) ); }
	if( m_Version ) { copy_self->m_Version = dynamic_pointer_cast<IfcLabel>( m_Version->getDeepCopy(options) ); }
	if( m_ApplicationFullName ) { copy_self->m_ApplicationFullName = dynamic_pointer_cast<IfcLabel>( m_ApplicationFullName->getDeepCopy(options) ); }
	if( m_ApplicationIdentifier ) { copy_self->m_ApplicationIdentifier = dynamic_pointer_cast<IfcIdentifier>( m_ApplicationIdentifier->getDeepCopy(options) ); }
	return copy_self;
}
void IfcApplication::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCAPPLICATION" << "(";
	if( m_ApplicationDeveloper ) { stream << "#" << m_ApplicationDeveloper->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_Version ) { m_Version->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ApplicationFullName ) { m_ApplicationFullName->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ApplicationIdentifier ) { m_ApplicationIdentifier->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcApplication::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcApplication::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcApplication, expecting 4, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReference( args[0], m_ApplicationDeveloper, map );
	m_Version = IfcLabel::createObjectFromSTEP( args[1] );
	m_ApplicationFullName = IfcLabel::createObjectFromSTEP( args[2] );
	m_ApplicationIdentifier = IfcIdentifier::createObjectFromSTEP( args[3] );
}
void IfcApplication::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	vec_attributes.push_back( std::make_pair( "ApplicationDeveloper", m_ApplicationDeveloper ) );
	vec_attributes.push_back( std::make_pair( "Version", m_Version ) );
	vec_attributes.push_back( std::make_pair( "ApplicationFullName", m_ApplicationFullName ) );
	vec_attributes.push_back( std::make_pair( "ApplicationIdentifier", m_ApplicationIdentifier ) );
}
void IfcApplication::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
}
void IfcApplication::setInverseCounterparts( shared_ptr<IfcPPEntity> )
{
}
void IfcApplication::unlinkFromInverseCounterparts()
{
}
