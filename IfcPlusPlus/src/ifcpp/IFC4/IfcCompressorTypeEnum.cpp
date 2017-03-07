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
#include "include/IfcCompressorTypeEnum.h"

// TYPE IfcCompressorTypeEnum = ENUMERATION OF	(DYNAMIC	,RECIPROCATING	,ROTARY	,SCROLL	,TROCHOIDAL	,SINGLESTAGE	,BOOSTER	,OPENTYPE	,HERMETIC	,SEMIHERMETIC	,WELDEDSHELLHERMETIC	,ROLLINGPISTON	,ROTARYVANE	,SINGLESCREW	,TWINSCREW	,USERDEFINED	,NOTDEFINED);
IfcCompressorTypeEnum::IfcCompressorTypeEnum() {}
IfcCompressorTypeEnum::~IfcCompressorTypeEnum() {}
shared_ptr<IfcPPObject> IfcCompressorTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcCompressorTypeEnum> copy_self( new IfcCompressorTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcCompressorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCCOMPRESSORTYPEENUM("; }
	if( m_enum == ENUM_DYNAMIC )
	{
		stream << ".DYNAMIC.";
	}
	else if( m_enum == ENUM_RECIPROCATING )
	{
		stream << ".RECIPROCATING.";
	}
	else if( m_enum == ENUM_ROTARY )
	{
		stream << ".ROTARY.";
	}
	else if( m_enum == ENUM_SCROLL )
	{
		stream << ".SCROLL.";
	}
	else if( m_enum == ENUM_TROCHOIDAL )
	{
		stream << ".TROCHOIDAL.";
	}
	else if( m_enum == ENUM_SINGLESTAGE )
	{
		stream << ".SINGLESTAGE.";
	}
	else if( m_enum == ENUM_BOOSTER )
	{
		stream << ".BOOSTER.";
	}
	else if( m_enum == ENUM_OPENTYPE )
	{
		stream << ".OPENTYPE.";
	}
	else if( m_enum == ENUM_HERMETIC )
	{
		stream << ".HERMETIC.";
	}
	else if( m_enum == ENUM_SEMIHERMETIC )
	{
		stream << ".SEMIHERMETIC.";
	}
	else if( m_enum == ENUM_WELDEDSHELLHERMETIC )
	{
		stream << ".WELDEDSHELLHERMETIC.";
	}
	else if( m_enum == ENUM_ROLLINGPISTON )
	{
		stream << ".ROLLINGPISTON.";
	}
	else if( m_enum == ENUM_ROTARYVANE )
	{
		stream << ".ROTARYVANE.";
	}
	else if( m_enum == ENUM_SINGLESCREW )
	{
		stream << ".SINGLESCREW.";
	}
	else if( m_enum == ENUM_TWINSCREW )
	{
		stream << ".TWINSCREW.";
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
shared_ptr<IfcCompressorTypeEnum> IfcCompressorTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcCompressorTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcCompressorTypeEnum>(); }
	shared_ptr<IfcCompressorTypeEnum> type_object( new IfcCompressorTypeEnum() );
	if( boost::iequals( arg, L".DYNAMIC." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_DYNAMIC;
	}
	else if( boost::iequals( arg, L".RECIPROCATING." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_RECIPROCATING;
	}
	else if( boost::iequals( arg, L".ROTARY." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_ROTARY;
	}
	else if( boost::iequals( arg, L".SCROLL." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_SCROLL;
	}
	else if( boost::iequals( arg, L".TROCHOIDAL." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_TROCHOIDAL;
	}
	else if( boost::iequals( arg, L".SINGLESTAGE." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_SINGLESTAGE;
	}
	else if( boost::iequals( arg, L".BOOSTER." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_BOOSTER;
	}
	else if( boost::iequals( arg, L".OPENTYPE." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_OPENTYPE;
	}
	else if( boost::iequals( arg, L".HERMETIC." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_HERMETIC;
	}
	else if( boost::iequals( arg, L".SEMIHERMETIC." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_SEMIHERMETIC;
	}
	else if( boost::iequals( arg, L".WELDEDSHELLHERMETIC." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_WELDEDSHELLHERMETIC;
	}
	else if( boost::iequals( arg, L".ROLLINGPISTON." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_ROLLINGPISTON;
	}
	else if( boost::iequals( arg, L".ROTARYVANE." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_ROTARYVANE;
	}
	else if( boost::iequals( arg, L".SINGLESCREW." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_SINGLESCREW;
	}
	else if( boost::iequals( arg, L".TWINSCREW." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_TWINSCREW;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcCompressorTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
