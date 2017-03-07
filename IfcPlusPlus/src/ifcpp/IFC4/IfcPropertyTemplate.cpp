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
#include "include/IfcComplexPropertyTemplate.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertySetTemplate.h"
#include "include/IfcPropertyTemplate.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcText.h"

// ENTITY IfcPropertyTemplate 
IfcPropertyTemplate::IfcPropertyTemplate() { m_entity_enum = IFCPROPERTYTEMPLATE; }
IfcPropertyTemplate::IfcPropertyTemplate( int id ) { m_id = id; m_entity_enum = IFCPROPERTYTEMPLATE; }
IfcPropertyTemplate::~IfcPropertyTemplate() {}
shared_ptr<IfcPPObject> IfcPropertyTemplate::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcPropertyTemplate> copy_self( new IfcPropertyTemplate() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createGUID32_wstr().c_str() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	return copy_self;
}
void IfcPropertyTemplate::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCPROPERTYTEMPLATE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ");";
}
void IfcPropertyTemplate::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcPropertyTemplate::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcPropertyTemplate, expecting 4, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2] );
	m_Description = IfcText::createObjectFromSTEP( args[3] );
}
void IfcPropertyTemplate::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcPropertyTemplateDefinition::getAttributes( vec_attributes );
}
void IfcPropertyTemplate::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcPropertyTemplateDefinition::getAttributesInverse( vec_attributes_inverse );
	if( m_PartOfComplexTemplate_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> PartOfComplexTemplate_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_PartOfComplexTemplate_inverse.size(); ++i )
		{
			if( !m_PartOfComplexTemplate_inverse[i].expired() )
			{
				PartOfComplexTemplate_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcComplexPropertyTemplate>( m_PartOfComplexTemplate_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "PartOfComplexTemplate_inverse", PartOfComplexTemplate_inverse_vec_obj ) );
	}
	if( m_PartOfPsetTemplate_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> PartOfPsetTemplate_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_PartOfPsetTemplate_inverse.size(); ++i )
		{
			if( !m_PartOfPsetTemplate_inverse[i].expired() )
			{
				PartOfPsetTemplate_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcPropertySetTemplate>( m_PartOfPsetTemplate_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "PartOfPsetTemplate_inverse", PartOfPsetTemplate_inverse_vec_obj ) );
	}
}
void IfcPropertyTemplate::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcPropertyTemplateDefinition::setInverseCounterparts( ptr_self_entity );
}
void IfcPropertyTemplate::unlinkFromInverseCounterparts()
{
	IfcPropertyTemplateDefinition::unlinkFromInverseCounterparts();
}
