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
#include "include/IfcBoundingBox.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

// ENTITY IfcBoundingBox 
IfcBoundingBox::IfcBoundingBox() { m_entity_enum = IFCBOUNDINGBOX; }
IfcBoundingBox::IfcBoundingBox( int id ) { m_id = id; m_entity_enum = IFCBOUNDINGBOX; }
IfcBoundingBox::~IfcBoundingBox() {}
shared_ptr<IfcPPObject> IfcBoundingBox::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcBoundingBox> copy_self( new IfcBoundingBox() );
	if( m_Corner ) { copy_self->m_Corner = dynamic_pointer_cast<IfcCartesianPoint>( m_Corner->getDeepCopy(options) ); }
	if( m_XDim ) { copy_self->m_XDim = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_XDim->getDeepCopy(options) ); }
	if( m_YDim ) { copy_self->m_YDim = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_YDim->getDeepCopy(options) ); }
	if( m_ZDim ) { copy_self->m_ZDim = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_ZDim->getDeepCopy(options) ); }
	return copy_self;
}
void IfcBoundingBox::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCBOUNDINGBOX" << "(";
	if( m_Corner ) { stream << "#" << m_Corner->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_XDim ) { m_XDim->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_YDim ) { m_YDim->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_ZDim ) { m_ZDim->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcBoundingBox::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcBoundingBox::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcBoundingBox, expecting 4, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readEntityReference( args[0], m_Corner, map );
	m_XDim = IfcPositiveLengthMeasure::createObjectFromSTEP( args[1] );
	m_YDim = IfcPositiveLengthMeasure::createObjectFromSTEP( args[2] );
	m_ZDim = IfcPositiveLengthMeasure::createObjectFromSTEP( args[3] );
}
void IfcBoundingBox::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcGeometricRepresentationItem::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "Corner", m_Corner ) );
	vec_attributes.push_back( std::make_pair( "XDim", m_XDim ) );
	vec_attributes.push_back( std::make_pair( "YDim", m_YDim ) );
	vec_attributes.push_back( std::make_pair( "ZDim", m_ZDim ) );
}
void IfcBoundingBox::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcGeometricRepresentationItem::getAttributesInverse( vec_attributes_inverse );
}
void IfcBoundingBox::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
}
void IfcBoundingBox::unlinkFromInverseCounterparts()
{
	IfcGeometricRepresentationItem::unlinkFromInverseCounterparts();
}
