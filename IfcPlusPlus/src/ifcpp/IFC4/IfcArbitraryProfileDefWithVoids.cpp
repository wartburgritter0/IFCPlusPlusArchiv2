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
#include "include/IfcArbitraryProfileDefWithVoids.h"
#include "include/IfcCurve.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

// ENTITY IfcArbitraryProfileDefWithVoids 
IfcArbitraryProfileDefWithVoids::IfcArbitraryProfileDefWithVoids() { m_entity_enum = IFCARBITRARYPROFILEDEFWITHVOIDS; }
IfcArbitraryProfileDefWithVoids::IfcArbitraryProfileDefWithVoids( int id ) { m_id = id; m_entity_enum = IFCARBITRARYPROFILEDEFWITHVOIDS; }
IfcArbitraryProfileDefWithVoids::~IfcArbitraryProfileDefWithVoids() {}
shared_ptr<IfcPPObject> IfcArbitraryProfileDefWithVoids::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcArbitraryProfileDefWithVoids> copy_self( new IfcArbitraryProfileDefWithVoids() );
	if( m_ProfileType ) { copy_self->m_ProfileType = dynamic_pointer_cast<IfcProfileTypeEnum>( m_ProfileType->getDeepCopy(options) ); }
	if( m_ProfileName ) { copy_self->m_ProfileName = dynamic_pointer_cast<IfcLabel>( m_ProfileName->getDeepCopy(options) ); }
	if( m_OuterCurve ) { copy_self->m_OuterCurve = dynamic_pointer_cast<IfcCurve>( m_OuterCurve->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_InnerCurves.size(); ++ii )
	{
		auto item_ii = m_InnerCurves[ii];
		if( item_ii )
		{
			copy_self->m_InnerCurves.push_back( dynamic_pointer_cast<IfcCurve>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcArbitraryProfileDefWithVoids::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCARBITRARYPROFILEDEFWITHVOIDS" << "(";
	if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OuterCurve ) { stream << "#" << m_OuterCurve->m_id; } else { stream << "*"; }
	stream << ",";
	writeEntityList( stream, m_InnerCurves );
	stream << ");";
}
void IfcArbitraryProfileDefWithVoids::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcArbitraryProfileDefWithVoids::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 4 ){ std::stringstream err; err << "Wrong parameter count for entity IfcArbitraryProfileDefWithVoids, expecting 4, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_ProfileType = IfcProfileTypeEnum::createObjectFromSTEP( args[0] );
	m_ProfileName = IfcLabel::createObjectFromSTEP( args[1] );
	readEntityReference( args[2], m_OuterCurve, map );
	readEntityReferenceList( args[3], m_InnerCurves, map );
}
void IfcArbitraryProfileDefWithVoids::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcArbitraryClosedProfileDef::getAttributes( vec_attributes );
	if( m_InnerCurves.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> InnerCurves_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_InnerCurves.begin(), m_InnerCurves.end(), std::back_inserter( InnerCurves_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "InnerCurves", InnerCurves_vec_object ) );
	}
}
void IfcArbitraryProfileDefWithVoids::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcArbitraryClosedProfileDef::getAttributesInverse( vec_attributes_inverse );
}
void IfcArbitraryProfileDefWithVoids::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcArbitraryClosedProfileDef::setInverseCounterparts( ptr_self_entity );
}
void IfcArbitraryProfileDefWithVoids::unlinkFromInverseCounterparts()
{
	IfcArbitraryClosedProfileDef::unlinkFromInverseCounterparts();
}
