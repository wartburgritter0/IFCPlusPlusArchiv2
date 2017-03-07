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
#include "include/IfcBoolean.h"
#include "include/IfcColour.h"
#include "include/IfcCurveFontOrScaledCurveFontSelect.h"
#include "include/IfcCurveStyle.h"
#include "include/IfcLabel.h"
#include "include/IfcSizeSelect.h"

// ENTITY IfcCurveStyle 
IfcCurveStyle::IfcCurveStyle() { m_entity_enum = IFCCURVESTYLE; }
IfcCurveStyle::IfcCurveStyle( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLE; }
IfcCurveStyle::~IfcCurveStyle() {}
shared_ptr<IfcPPObject> IfcCurveStyle::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcCurveStyle> copy_self( new IfcCurveStyle() );
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_CurveFont ) { copy_self->m_CurveFont = dynamic_pointer_cast<IfcCurveFontOrScaledCurveFontSelect>( m_CurveFont->getDeepCopy(options) ); }
	if( m_CurveWidth ) { copy_self->m_CurveWidth = dynamic_pointer_cast<IfcSizeSelect>( m_CurveWidth->getDeepCopy(options) ); }
	if( m_CurveColour ) { copy_self->m_CurveColour = dynamic_pointer_cast<IfcColour>( m_CurveColour->getDeepCopy(options) ); }
	if( m_ModelOrDraughting ) { copy_self->m_ModelOrDraughting = dynamic_pointer_cast<IfcBoolean>( m_ModelOrDraughting->getDeepCopy(options) ); }
	return copy_self;
}
void IfcCurveStyle::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCCURVESTYLE" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_CurveFont ) { m_CurveFont->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_CurveWidth ) { m_CurveWidth->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_CurveColour ) { m_CurveColour->getStepParameter( stream, true ); } else { stream << "$" ; }
	stream << ",";
	if( m_ModelOrDraughting ) { m_ModelOrDraughting->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcCurveStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcCurveStyle::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 5 ){ std::stringstream err; err << "Wrong parameter count for entity IfcCurveStyle, expecting 5, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_Name = IfcLabel::createObjectFromSTEP( args[0] );
	m_CurveFont = IfcCurveFontOrScaledCurveFontSelect::createObjectFromSTEP( args[1], map );
	m_CurveWidth = IfcSizeSelect::createObjectFromSTEP( args[2], map );
	m_CurveColour = IfcColour::createObjectFromSTEP( args[3], map );
	m_ModelOrDraughting = IfcBoolean::createObjectFromSTEP( args[4] );
}
void IfcCurveStyle::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcPresentationStyle::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "CurveFont", m_CurveFont ) );
	vec_attributes.push_back( std::make_pair( "CurveWidth", m_CurveWidth ) );
	vec_attributes.push_back( std::make_pair( "CurveColour", m_CurveColour ) );
	vec_attributes.push_back( std::make_pair( "ModelOrDraughting", m_ModelOrDraughting ) );
}
void IfcCurveStyle::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcPresentationStyle::getAttributesInverse( vec_attributes_inverse );
}
void IfcCurveStyle::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
}
void IfcCurveStyle::unlinkFromInverseCounterparts()
{
	IfcPresentationStyle::unlinkFromInverseCounterparts();
}
