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
#include "include/IfcClassificationSelect.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialClassificationRelationship.h"

// ENTITY IfcMaterialClassificationRelationship 
IfcMaterialClassificationRelationship::IfcMaterialClassificationRelationship() { m_entity_enum = IFCMATERIALCLASSIFICATIONRELATIONSHIP; }
IfcMaterialClassificationRelationship::IfcMaterialClassificationRelationship( int id ) { m_id = id; m_entity_enum = IFCMATERIALCLASSIFICATIONRELATIONSHIP; }
IfcMaterialClassificationRelationship::~IfcMaterialClassificationRelationship() {}
shared_ptr<IfcPPObject> IfcMaterialClassificationRelationship::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcMaterialClassificationRelationship> copy_self( new IfcMaterialClassificationRelationship() );
	for( size_t ii=0; ii<m_MaterialClassifications.size(); ++ii )
	{
		auto item_ii = m_MaterialClassifications[ii];
		if( item_ii )
		{
			copy_self->m_MaterialClassifications.push_back( dynamic_pointer_cast<IfcClassificationSelect>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_ClassifiedMaterial ) { copy_self->m_ClassifiedMaterial = dynamic_pointer_cast<IfcMaterial>( m_ClassifiedMaterial->getDeepCopy(options) ); }
	return copy_self;
}
void IfcMaterialClassificationRelationship::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCMATERIALCLASSIFICATIONRELATIONSHIP" << "(";
	stream << "(";
	for( size_t ii = 0; ii < m_MaterialClassifications.size(); ++ii )
	{
		if( ii > 0 )
		{
			stream << ",";
		}
		const shared_ptr<IfcClassificationSelect>& type_object = m_MaterialClassifications[ii];
		if( type_object )
		{
			type_object->getStepParameter( stream, true );
		}
		else
		{
			stream << "$";
		}
	}
	stream << ")";
	stream << ",";
	if( m_ClassifiedMaterial ) { stream << "#" << m_ClassifiedMaterial->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcMaterialClassificationRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcMaterialClassificationRelationship::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 2 ){ std::stringstream err; err << "Wrong parameter count for entity IfcMaterialClassificationRelationship, expecting 2, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readSelectList( args[0], m_MaterialClassifications, map );
	readEntityReference( args[1], m_ClassifiedMaterial, map );
}
void IfcMaterialClassificationRelationship::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	if( m_MaterialClassifications.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> MaterialClassifications_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_MaterialClassifications.begin(), m_MaterialClassifications.end(), std::back_inserter( MaterialClassifications_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "MaterialClassifications", MaterialClassifications_vec_object ) );
	}
	vec_attributes.push_back( std::make_pair( "ClassifiedMaterial", m_ClassifiedMaterial ) );
}
void IfcMaterialClassificationRelationship::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
}
void IfcMaterialClassificationRelationship::setInverseCounterparts( shared_ptr<IfcPPEntity> )
{
}
void IfcMaterialClassificationRelationship::unlinkFromInverseCounterparts()
{
}
