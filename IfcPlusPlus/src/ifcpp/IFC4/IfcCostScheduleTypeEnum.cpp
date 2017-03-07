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
#include "include/IfcCostScheduleTypeEnum.h"

// TYPE IfcCostScheduleTypeEnum = ENUMERATION OF	(BUDGET	,COSTPLAN	,ESTIMATE	,TENDER	,PRICEDBILLOFQUANTITIES	,UNPRICEDBILLOFQUANTITIES	,SCHEDULEOFRATES	,USERDEFINED	,NOTDEFINED);
IfcCostScheduleTypeEnum::IfcCostScheduleTypeEnum() {}
IfcCostScheduleTypeEnum::~IfcCostScheduleTypeEnum() {}
shared_ptr<IfcPPObject> IfcCostScheduleTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcCostScheduleTypeEnum> copy_self( new IfcCostScheduleTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcCostScheduleTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCCOSTSCHEDULETYPEENUM("; }
	if( m_enum == ENUM_BUDGET )
	{
		stream << ".BUDGET.";
	}
	else if( m_enum == ENUM_COSTPLAN )
	{
		stream << ".COSTPLAN.";
	}
	else if( m_enum == ENUM_ESTIMATE )
	{
		stream << ".ESTIMATE.";
	}
	else if( m_enum == ENUM_TENDER )
	{
		stream << ".TENDER.";
	}
	else if( m_enum == ENUM_PRICEDBILLOFQUANTITIES )
	{
		stream << ".PRICEDBILLOFQUANTITIES.";
	}
	else if( m_enum == ENUM_UNPRICEDBILLOFQUANTITIES )
	{
		stream << ".UNPRICEDBILLOFQUANTITIES.";
	}
	else if( m_enum == ENUM_SCHEDULEOFRATES )
	{
		stream << ".SCHEDULEOFRATES.";
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
shared_ptr<IfcCostScheduleTypeEnum> IfcCostScheduleTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcCostScheduleTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcCostScheduleTypeEnum>(); }
	shared_ptr<IfcCostScheduleTypeEnum> type_object( new IfcCostScheduleTypeEnum() );
	if( boost::iequals( arg, L".BUDGET." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_BUDGET;
	}
	else if( boost::iequals( arg, L".COSTPLAN." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_COSTPLAN;
	}
	else if( boost::iequals( arg, L".ESTIMATE." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_ESTIMATE;
	}
	else if( boost::iequals( arg, L".TENDER." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_TENDER;
	}
	else if( boost::iequals( arg, L".PRICEDBILLOFQUANTITIES." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_PRICEDBILLOFQUANTITIES;
	}
	else if( boost::iequals( arg, L".UNPRICEDBILLOFQUANTITIES." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_UNPRICEDBILLOFQUANTITIES;
	}
	else if( boost::iequals( arg, L".SCHEDULEOFRATES." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_SCHEDULEOFRATES;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcCostScheduleTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
