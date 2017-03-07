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
#include "include/IfcLampTypeEnum.h"

// TYPE IfcLampTypeEnum = ENUMERATION OF	(COMPACTFLUORESCENT	,FLUORESCENT	,HALOGEN	,HIGHPRESSUREMERCURY	,HIGHPRESSURESODIUM	,LED	,METALHALIDE	,OLED	,TUNGSTENFILAMENT	,USERDEFINED	,NOTDEFINED);
IfcLampTypeEnum::IfcLampTypeEnum() {}
IfcLampTypeEnum::~IfcLampTypeEnum() {}
shared_ptr<IfcPPObject> IfcLampTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcLampTypeEnum> copy_self( new IfcLampTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcLampTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCLAMPTYPEENUM("; }
	if( m_enum == ENUM_COMPACTFLUORESCENT )
	{
		stream << ".COMPACTFLUORESCENT.";
	}
	else if( m_enum == ENUM_FLUORESCENT )
	{
		stream << ".FLUORESCENT.";
	}
	else if( m_enum == ENUM_HALOGEN )
	{
		stream << ".HALOGEN.";
	}
	else if( m_enum == ENUM_HIGHPRESSUREMERCURY )
	{
		stream << ".HIGHPRESSUREMERCURY.";
	}
	else if( m_enum == ENUM_HIGHPRESSURESODIUM )
	{
		stream << ".HIGHPRESSURESODIUM.";
	}
	else if( m_enum == ENUM_LED )
	{
		stream << ".LED.";
	}
	else if( m_enum == ENUM_METALHALIDE )
	{
		stream << ".METALHALIDE.";
	}
	else if( m_enum == ENUM_OLED )
	{
		stream << ".OLED.";
	}
	else if( m_enum == ENUM_TUNGSTENFILAMENT )
	{
		stream << ".TUNGSTENFILAMENT.";
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
shared_ptr<IfcLampTypeEnum> IfcLampTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcLampTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcLampTypeEnum>(); }
	shared_ptr<IfcLampTypeEnum> type_object( new IfcLampTypeEnum() );
	if( boost::iequals( arg, L".COMPACTFLUORESCENT." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_COMPACTFLUORESCENT;
	}
	else if( boost::iequals( arg, L".FLUORESCENT." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_FLUORESCENT;
	}
	else if( boost::iequals( arg, L".HALOGEN." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_HALOGEN;
	}
	else if( boost::iequals( arg, L".HIGHPRESSUREMERCURY." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_HIGHPRESSUREMERCURY;
	}
	else if( boost::iequals( arg, L".HIGHPRESSURESODIUM." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_HIGHPRESSURESODIUM;
	}
	else if( boost::iequals( arg, L".LED." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_LED;
	}
	else if( boost::iequals( arg, L".METALHALIDE." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_METALHALIDE;
	}
	else if( boost::iequals( arg, L".OLED." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_OLED;
	}
	else if( boost::iequals( arg, L".TUNGSTENFILAMENT." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_TUNGSTENFILAMENT;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcLampTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
