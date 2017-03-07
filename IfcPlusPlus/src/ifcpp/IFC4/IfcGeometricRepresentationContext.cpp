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
#include "include/IfcAxis2Placement.h"
#include "include/IfcCoordinateOperation.h"
#include "include/IfcDimensionCount.h"
#include "include/IfcDirection.h"
#include "include/IfcGeometricRepresentationContext.h"
#include "include/IfcGeometricRepresentationSubContext.h"
#include "include/IfcLabel.h"
#include "include/IfcReal.h"
#include "include/IfcRepresentation.h"

// ENTITY IfcGeometricRepresentationContext 
IfcGeometricRepresentationContext::IfcGeometricRepresentationContext() { m_entity_enum = IFCGEOMETRICREPRESENTATIONCONTEXT; }
IfcGeometricRepresentationContext::IfcGeometricRepresentationContext( int id ) { m_id = id; m_entity_enum = IFCGEOMETRICREPRESENTATIONCONTEXT; }
IfcGeometricRepresentationContext::~IfcGeometricRepresentationContext() {}
shared_ptr<IfcPPObject> IfcGeometricRepresentationContext::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcGeometricRepresentationContext> copy_self( new IfcGeometricRepresentationContext() );
	if( m_ContextIdentifier ) { copy_self->m_ContextIdentifier = dynamic_pointer_cast<IfcLabel>( m_ContextIdentifier->getDeepCopy(options) ); }
	if( m_ContextType ) { copy_self->m_ContextType = dynamic_pointer_cast<IfcLabel>( m_ContextType->getDeepCopy(options) ); }
	if( m_CoordinateSpaceDimension ) { copy_self->m_CoordinateSpaceDimension = dynamic_pointer_cast<IfcDimensionCount>( m_CoordinateSpaceDimension->getDeepCopy(options) ); }
	if( m_Precision ) { copy_self->m_Precision = dynamic_pointer_cast<IfcReal>( m_Precision->getDeepCopy(options) ); }
	if( m_WorldCoordinateSystem ) { copy_self->m_WorldCoordinateSystem = dynamic_pointer_cast<IfcAxis2Placement>( m_WorldCoordinateSystem->getDeepCopy(options) ); }
	if( m_TrueNorth ) { copy_self->m_TrueNorth = dynamic_pointer_cast<IfcDirection>( m_TrueNorth->getDeepCopy(options) ); }
	return copy_self;
}
void IfcGeometricRepresentationContext::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCGEOMETRICREPRESENTATIONCONTEXT" << "(";
	if( m_ContextIdentifier ) { m_ContextIdentifier->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ContextType ) { m_ContextType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_CoordinateSpaceDimension ) { m_CoordinateSpaceDimension->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_Precision ) { m_Precision->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_WorldCoordinateSystem ) { m_WorldCoordinateSystem->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_TrueNorth ) { stream << "#" << m_TrueNorth->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcGeometricRepresentationContext::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcGeometricRepresentationContext::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 6 ){ std::stringstream err; err << "Wrong parameter count for entity IfcGeometricRepresentationContext, expecting 6, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_ContextIdentifier = IfcLabel::createObjectFromSTEP( args[0] );
	m_ContextType = IfcLabel::createObjectFromSTEP( args[1] );
	m_CoordinateSpaceDimension = IfcDimensionCount::createObjectFromSTEP( args[2] );
	m_Precision = IfcReal::createObjectFromSTEP( args[3] );
	m_WorldCoordinateSystem = IfcAxis2Placement::createObjectFromSTEP( args[4], map );
	readEntityReference( args[5], m_TrueNorth, map );
}
void IfcGeometricRepresentationContext::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcRepresentationContext::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "CoordinateSpaceDimension", m_CoordinateSpaceDimension ) );
	vec_attributes.push_back( std::make_pair( "Precision", m_Precision ) );
	vec_attributes.push_back( std::make_pair( "WorldCoordinateSystem", m_WorldCoordinateSystem ) );
	vec_attributes.push_back( std::make_pair( "TrueNorth", m_TrueNorth ) );
}
void IfcGeometricRepresentationContext::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcRepresentationContext::getAttributesInverse( vec_attributes_inverse );
	if( m_HasSubContexts_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> HasSubContexts_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_HasSubContexts_inverse.size(); ++i )
		{
			if( !m_HasSubContexts_inverse[i].expired() )
			{
				HasSubContexts_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcGeometricRepresentationSubContext>( m_HasSubContexts_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasSubContexts_inverse", HasSubContexts_inverse_vec_obj ) );
	}
	if( m_HasCoordinateOperation_inverse.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> HasCoordinateOperation_inverse_vec_obj( new IfcPPAttributeObjectVector() );
		for( size_t i=0; i<m_HasCoordinateOperation_inverse.size(); ++i )
		{
			if( !m_HasCoordinateOperation_inverse[i].expired() )
			{
				HasCoordinateOperation_inverse_vec_obj->m_vec.push_back( shared_ptr<IfcCoordinateOperation>( m_HasCoordinateOperation_inverse[i] ) );
			}
		}
		vec_attributes_inverse.push_back( std::make_pair( "HasCoordinateOperation_inverse", HasCoordinateOperation_inverse_vec_obj ) );
	}
}
void IfcGeometricRepresentationContext::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcRepresentationContext::setInverseCounterparts( ptr_self_entity );
}
void IfcGeometricRepresentationContext::unlinkFromInverseCounterparts()
{
	IfcRepresentationContext::unlinkFromInverseCounterparts();
}
