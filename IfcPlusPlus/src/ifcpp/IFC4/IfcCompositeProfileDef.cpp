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
#include "include/IfcCompositeProfileDef.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileDef.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

// ENTITY IfcCompositeProfileDef 
IfcCompositeProfileDef::IfcCompositeProfileDef() { m_entity_enum = IFCCOMPOSITEPROFILEDEF; }
IfcCompositeProfileDef::IfcCompositeProfileDef( int id ) { m_id = id; m_entity_enum = IFCCOMPOSITEPROFILEDEF; }
IfcCompositeProfileDef::~IfcCompositeProfileDef() {}
shared_ptr<IfcPPObject> IfcCompositeProfileDef::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcCompositeProfileDef> copy_self( new IfcCompositeProfileDef() );
	if( m_ProfileType ) { copy_self->m_ProfileType = dynamic_pointer_cast<IfcProfileTypeEnum>( m_ProfileType->getDeepCopy(options) ); }
	if( m_ProfileName ) { copy_self->m_ProfileName = dynamic_pointer_cast<IfcLabel>( m_ProfileName->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_Profiles.size(); ++ii )
	{
		auto item_ii = m_Profiles[ii];
		if( item_ii )
		{
			copy_self->m_Profiles.push_back( dynamic_pointer_cast<IfcProfileDef>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_Label ) { copy_self->m_Label = dynamic_pointer_cast<IfcLabel>( m_Label->getDeepCopy(options) ); }
	return copy_self;
}
void IfcCompositeProfileDef::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCCOMPOSITEPROFILEDEF" << "(";
	if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	writeEntityList( stream, m_Profiles );
	stream << ",";
	if( m_Label ) { m_Label->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcCompositeProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcCompositeProfileDef::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcCompositeProfileDef, expecting 4, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_ProfileType = IfcProfileTypeEnum::createObjectFromSTEP( args[0] );
	m_ProfileName = IfcLabel::createObjectFromSTEP( args[1] );
	readEntityReferenceList( args[2], m_Profiles, map );
	m_Label = IfcLabel::createObjectFromSTEP( args[3] );
}
void IfcCompositeProfileDef::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcProfileDef::getAttributes( vec_attributes );
	if( m_Profiles.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> Profiles_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_Profiles.begin(), m_Profiles.end(), std::back_inserter( Profiles_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "Profiles", Profiles_vec_object ) );
	}
	vec_attributes.push_back( std::make_pair( "Label", m_Label ) );
}
void IfcCompositeProfileDef::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcProfileDef::getAttributesInverse( vec_attributes_inverse );
}
void IfcCompositeProfileDef::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcProfileDef::setInverseCounterparts( ptr_self_entity );
}
void IfcCompositeProfileDef::unlinkFromInverseCounterparts()
{
	IfcProfileDef::unlinkFromInverseCounterparts();
}
