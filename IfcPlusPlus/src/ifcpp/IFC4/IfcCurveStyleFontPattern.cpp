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
#include "include/IfcCurveStyleFontPattern.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"

// ENTITY IfcCurveStyleFontPattern 
IfcCurveStyleFontPattern::IfcCurveStyleFontPattern() { m_entity_enum = IFCCURVESTYLEFONTPATTERN; }
IfcCurveStyleFontPattern::IfcCurveStyleFontPattern( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLEFONTPATTERN; }
IfcCurveStyleFontPattern::~IfcCurveStyleFontPattern() {}
shared_ptr<IfcPPObject> IfcCurveStyleFontPattern::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcCurveStyleFontPattern> copy_self( new IfcCurveStyleFontPattern() );
	if( m_VisibleSegmentLength ) { copy_self->m_VisibleSegmentLength = dynamic_pointer_cast<IfcLengthMeasure>( m_VisibleSegmentLength->getDeepCopy(options) ); }
	if( m_InvisibleSegmentLength ) { copy_self->m_InvisibleSegmentLength = dynamic_pointer_cast<IfcPositiveLengthMeasure>( m_InvisibleSegmentLength->getDeepCopy(options) ); }
	return copy_self;
}
void IfcCurveStyleFontPattern::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCCURVESTYLEFONTPATTERN" << "(";
	if( m_VisibleSegmentLength ) { m_VisibleSegmentLength->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_InvisibleSegmentLength ) { m_InvisibleSegmentLength->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcCurveStyleFontPattern::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcCurveStyleFontPattern::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 2 ){ std::stringstream err; err << "Wrong parameter count for entity IfcCurveStyleFontPattern, expecting 2, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_VisibleSegmentLength = IfcLengthMeasure::createObjectFromSTEP( args[0] );
	m_InvisibleSegmentLength = IfcPositiveLengthMeasure::createObjectFromSTEP( args[1] );
}
void IfcCurveStyleFontPattern::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcPresentationItem::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "VisibleSegmentLength", m_VisibleSegmentLength ) );
	vec_attributes.push_back( std::make_pair( "InvisibleSegmentLength", m_InvisibleSegmentLength ) );
}
void IfcCurveStyleFontPattern::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcPresentationItem::getAttributesInverse( vec_attributes_inverse );
}
void IfcCurveStyleFontPattern::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
}
void IfcCurveStyleFontPattern::unlinkFromInverseCounterparts()
{
	IfcPresentationItem::unlinkFromInverseCounterparts();
}
