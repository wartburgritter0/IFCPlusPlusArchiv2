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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterialLayer.h"
#include "include/IfcMaterialLayerSet.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

// ENTITY IfcMaterialLayerSet 
IfcMaterialLayerSet::IfcMaterialLayerSet() { m_entity_enum = IFCMATERIALLAYERSET; }
IfcMaterialLayerSet::IfcMaterialLayerSet( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYERSET; }
IfcMaterialLayerSet::~IfcMaterialLayerSet() {}
shared_ptr<IfcPPObject> IfcMaterialLayerSet::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcMaterialLayerSet> copy_self( new IfcMaterialLayerSet() );
	for( size_t ii=0; ii<m_MaterialLayers.size(); ++ii )
	{
		auto item_ii = m_MaterialLayers[ii];
		if( item_ii )
		{
			copy_self->m_MaterialLayers.push_back( dynamic_pointer_cast<IfcMaterialLayer>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_LayerSetName ) { copy_self->m_LayerSetName = dynamic_pointer_cast<IfcLabel>( m_LayerSetName->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	return copy_self;
}
void IfcMaterialLayerSet::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCMATERIALLAYERSET" << "(";
	writeEntityList( stream, m_MaterialLayers );
	stream << ",";
	if( m_LayerSetName ) { m_LayerSetName->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcMaterialLayerSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcMaterialLayerSet::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcMaterialLayerSet, expecting 3, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReferenceList( args[0], m_MaterialLayers, map );
	m_LayerSetName = IfcLabel::createObjectFromSTEP( args[1] );
	m_Description = IfcText::createObjectFromSTEP( args[2] );
}
void IfcMaterialLayerSet::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcMaterialDefinition::getAttributes( vec_attributes );
	if( m_MaterialLayers.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> MaterialLayers_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_MaterialLayers.begin(), m_MaterialLayers.end(), std::back_inserter( MaterialLayers_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "MaterialLayers", MaterialLayers_vec_object ) );
	}
	vec_attributes.push_back( std::make_pair( "LayerSetName", m_LayerSetName ) );
	vec_attributes.push_back( std::make_pair( "Description", m_Description ) );
}
void IfcMaterialLayerSet::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcMaterialDefinition::getAttributesInverse( vec_attributes_inverse );
}
void IfcMaterialLayerSet::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcMaterialDefinition::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcMaterialLayerSet> ptr_self = dynamic_pointer_cast<IfcMaterialLayerSet>( ptr_self_entity );
	if( !ptr_self ) { throw IfcPPException( "IfcMaterialLayerSet::setInverseCounterparts: type mismatch" ); }
	for( size_t i=0; i<m_MaterialLayers.size(); ++i )
	{
		if( m_MaterialLayers[i] )
		{
			m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse = ptr_self;
		}
	}
}
void IfcMaterialLayerSet::unlinkFromInverseCounterparts()
{
	IfcMaterialDefinition::unlinkFromInverseCounterparts();
	for( size_t i=0; i<m_MaterialLayers.size(); ++i )
	{
		if( m_MaterialLayers[i] )
		{
			shared_ptr<IfcMaterialLayerSet> self_candidate( m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse );
			if( self_candidate.get() == this )
			{
				weak_ptr<IfcMaterialLayerSet>& self_candidate_weak = m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse;
				self_candidate_weak.reset();
			}
		}
	}
}
