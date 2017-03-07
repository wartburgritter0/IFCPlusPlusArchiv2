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
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/IfcPPBasicTypes.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcDistributionChamberElementTypeEnum.h"

// TYPE IfcDistributionChamberElementTypeEnum = ENUMERATION OF	(FORMEDDUCT	,INSPECTIONCHAMBER	,INSPECTIONPIT	,MANHOLE	,METERCHAMBER	,SUMP	,TRENCH	,VALVECHAMBER	,USERDEFINED	,NOTDEFINED);
IfcDistributionChamberElementTypeEnum::IfcDistributionChamberElementTypeEnum() {}
IfcDistributionChamberElementTypeEnum::~IfcDistributionChamberElementTypeEnum() {}
shared_ptr<IfcPPObject> IfcDistributionChamberElementTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcDistributionChamberElementTypeEnum> copy_self( new IfcDistributionChamberElementTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcDistributionChamberElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCDISTRIBUTIONCHAMBERELEMENTTYPEENUM("; }
	if( m_enum == ENUM_FORMEDDUCT )
	{
		stream << ".FORMEDDUCT.";
	}
	else if( m_enum == ENUM_INSPECTIONCHAMBER )
	{
		stream << ".INSPECTIONCHAMBER.";
	}
	else if( m_enum == ENUM_INSPECTIONPIT )
	{
		stream << ".INSPECTIONPIT.";
	}
	else if( m_enum == ENUM_MANHOLE )
	{
		stream << ".MANHOLE.";
	}
	else if( m_enum == ENUM_METERCHAMBER )
	{
		stream << ".METERCHAMBER.";
	}
	else if( m_enum == ENUM_SUMP )
	{
		stream << ".SUMP.";
	}
	else if( m_enum == ENUM_TRENCH )
	{
		stream << ".TRENCH.";
	}
	else if( m_enum == ENUM_VALVECHAMBER )
	{
		stream << ".VALVECHAMBER.";
	}
	else if( m_enum == ENUM_USERDEFINED )
	{
		stream << ".USERDEFINED.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcDistributionChamberElementTypeEnum> IfcDistributionChamberElementTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcDistributionChamberElementTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcDistributionChamberElementTypeEnum>(); }
	shared_ptr<IfcDistributionChamberElementTypeEnum> type_object( new IfcDistributionChamberElementTypeEnum() );
	if( boost::iequals( arg, L".FORMEDDUCT." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_FORMEDDUCT;
	}
	else if( boost::iequals( arg, L".INSPECTIONCHAMBER." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_INSPECTIONCHAMBER;
	}
	else if( boost::iequals( arg, L".INSPECTIONPIT." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_INSPECTIONPIT;
	}
	else if( boost::iequals( arg, L".MANHOLE." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_MANHOLE;
	}
	else if( boost::iequals( arg, L".METERCHAMBER." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_METERCHAMBER;
	}
	else if( boost::iequals( arg, L".SUMP." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_SUMP;
	}
	else if( boost::iequals( arg, L".TRENCH." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_TRENCH;
	}
	else if( boost::iequals( arg, L".VALVECHAMBER." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_VALVECHAMBER;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
