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
#include "include/IfcFace.h"
#include "include/IfcFaceBound.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTextureMap.h"

// ENTITY IfcFace 
IfcFace::IfcFace() { m_entity_enum = IFCFACE; }
IfcFace::IfcFace( int id ) { m_id = id; m_entity_enum = IFCFACE; }
IfcFace::~IfcFace() {}
shared_ptr<IfcPPObject> IfcFace::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcFace> copy_self( new IfcFace() );
	for( size_t ii=0; ii<m_Bounds.size(); ++ii )
	{
		auto item_ii = m_Bounds[ii];
		if( item_ii )
		{
			copy_self->m_Bounds.push_back( dynamic_pointer_cast<IfcFaceBound>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcFace::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCFACE" << "(";
	writeEntityList( stream, m_Bounds );
	stream << ");";
}
void IfcFace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcFace::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 1 ){ std::stringstream err; err << "Wrong parameter count for entity IfcFace, expecting 1, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReferenceList( args[0], m_Bounds, map );
}
void IfcFace::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcTopologicalRepresentationItem::getAttributes( vec_attributes );
	if( m_Bounds.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> Bounds_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_Bounds.begin(), m_Bounds.end(), std::back_inserter( Bounds_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "Bounds", Bounds_vec_object ) );
	}
}
void IfcFace::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcTopologicalRepresentationItem::getAttributesInverse( vec_attributes_inverse );
	if( m_HasTextureMaps_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> HasTextureMaps_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_HasTextureMaps_inverse.size(); ++i )
		{
			if( !m_HasTextureMaps_inverse[i].expired() )
			{
				HasTextureMaps_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcTextureMap>( m_HasTextureMaps_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasTextureMaps_inverse", HasTextureMaps_inverse_vec_obj ) );
	}
}
void IfcFace::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
}
void IfcFace::unlinkFromInverseCounterparts()
{
	IfcTopologicalRepresentationItem::unlinkFromInverseCounterparts();
}
