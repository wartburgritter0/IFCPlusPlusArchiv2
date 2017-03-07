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
#include "include/IfcDoorStyleOperationEnum.h"

// TYPE IfcDoorStyleOperationEnum = ENUMERATION OF	(SINGLE_SWING_LEFT	,SINGLE_SWING_RIGHT	,DOUBLE_DOOR_SINGLE_SWING	,DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT	,DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT	,DOUBLE_SWING_LEFT	,DOUBLE_SWING_RIGHT	,DOUBLE_DOOR_DOUBLE_SWING	,SLIDING_TO_LEFT	,SLIDING_TO_RIGHT	,DOUBLE_DOOR_SLIDING	,FOLDING_TO_LEFT	,FOLDING_TO_RIGHT	,DOUBLE_DOOR_FOLDING	,REVOLVING	,ROLLINGUP	,USERDEFINED	,NOTDEFINED);
IfcDoorStyleOperationEnum::IfcDoorStyleOperationEnum() {}
IfcDoorStyleOperationEnum::~IfcDoorStyleOperationEnum() {}
shared_ptr<IfcPPObject> IfcDoorStyleOperationEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcDoorStyleOperationEnum> copy_self( new IfcDoorStyleOperationEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcDoorStyleOperationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCDOORSTYLEOPERATIONENUM("; }
	if( m_enum == ENUM_SINGLE_SWING_LEFT )
	{
		stream << ".SINGLE_SWING_LEFT.";
	}
	else if( m_enum == ENUM_SINGLE_SWING_RIGHT )
	{
		stream << ".SINGLE_SWING_RIGHT.";
	}
	else if( m_enum == ENUM_DOUBLE_DOOR_SINGLE_SWING )
	{
		stream << ".DOUBLE_DOOR_SINGLE_SWING.";
	}
	else if( m_enum == ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT )
	{
		stream << ".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT.";
	}
	else if( m_enum == ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT )
	{
		stream << ".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT.";
	}
	else if( m_enum == ENUM_DOUBLE_SWING_LEFT )
	{
		stream << ".DOUBLE_SWING_LEFT.";
	}
	else if( m_enum == ENUM_DOUBLE_SWING_RIGHT )
	{
		stream << ".DOUBLE_SWING_RIGHT.";
	}
	else if( m_enum == ENUM_DOUBLE_DOOR_DOUBLE_SWING )
	{
		stream << ".DOUBLE_DOOR_DOUBLE_SWING.";
	}
	else if( m_enum == ENUM_SLIDING_TO_LEFT )
	{
		stream << ".SLIDING_TO_LEFT.";
	}
	else if( m_enum == ENUM_SLIDING_TO_RIGHT )
	{
		stream << ".SLIDING_TO_RIGHT.";
	}
	else if( m_enum == ENUM_DOUBLE_DOOR_SLIDING )
	{
		stream << ".DOUBLE_DOOR_SLIDING.";
	}
	else if( m_enum == ENUM_FOLDING_TO_LEFT )
	{
		stream << ".FOLDING_TO_LEFT.";
	}
	else if( m_enum == ENUM_FOLDING_TO_RIGHT )
	{
		stream << ".FOLDING_TO_RIGHT.";
	}
	else if( m_enum == ENUM_DOUBLE_DOOR_FOLDING )
	{
		stream << ".DOUBLE_DOOR_FOLDING.";
	}
	else if( m_enum == ENUM_REVOLVING )
	{
		stream << ".REVOLVING.";
	}
	else if( m_enum == ENUM_ROLLINGUP )
	{
		stream << ".ROLLINGUP.";
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
shared_ptr<IfcDoorStyleOperationEnum> IfcDoorStyleOperationEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcDoorStyleOperationEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcDoorStyleOperationEnum>(); }
	shared_ptr<IfcDoorStyleOperationEnum> type_object( new IfcDoorStyleOperationEnum() );
	if( boost::iequals( arg, L".SINGLE_SWING_LEFT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SINGLE_SWING_LEFT;
	}
	else if( boost::iequals( arg, L".SINGLE_SWING_RIGHT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SINGLE_SWING_RIGHT;
	}
	else if( boost::iequals( arg, L".DOUBLE_DOOR_SINGLE_SWING." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SINGLE_SWING;
	}
	else if( boost::iequals( arg, L".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_LEFT;
	}
	else if( boost::iequals( arg, L".DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SINGLE_SWING_OPPOSITE_RIGHT;
	}
	else if( boost::iequals( arg, L".DOUBLE_SWING_LEFT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_SWING_LEFT;
	}
	else if( boost::iequals( arg, L".DOUBLE_SWING_RIGHT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_SWING_RIGHT;
	}
	else if( boost::iequals( arg, L".DOUBLE_DOOR_DOUBLE_SWING." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_DOUBLE_SWING;
	}
	else if( boost::iequals( arg, L".SLIDING_TO_LEFT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SLIDING_TO_LEFT;
	}
	else if( boost::iequals( arg, L".SLIDING_TO_RIGHT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_SLIDING_TO_RIGHT;
	}
	else if( boost::iequals( arg, L".DOUBLE_DOOR_SLIDING." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_SLIDING;
	}
	else if( boost::iequals( arg, L".FOLDING_TO_LEFT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_FOLDING_TO_LEFT;
	}
	else if( boost::iequals( arg, L".FOLDING_TO_RIGHT." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_FOLDING_TO_RIGHT;
	}
	else if( boost::iequals( arg, L".DOUBLE_DOOR_FOLDING." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_DOUBLE_DOOR_FOLDING;
	}
	else if( boost::iequals( arg, L".REVOLVING." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_REVOLVING;
	}
	else if( boost::iequals( arg, L".ROLLINGUP." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_ROLLINGUP;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcDoorStyleOperationEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
