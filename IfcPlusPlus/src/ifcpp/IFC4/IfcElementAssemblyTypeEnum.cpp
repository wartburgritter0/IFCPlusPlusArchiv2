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
#include "include/IfcElementAssemblyTypeEnum.h"

// TYPE IfcElementAssemblyTypeEnum = ENUMERATION OF	(ACCESSORY_ASSEMBLY	,ARCH	,BEAM_GRID	,BRACED_FRAME	,GIRDER	,REINFORCEMENT_UNIT	,RIGID_FRAME	,SLAB_FIELD	,TRUSS	,USERDEFINED	,NOTDEFINED);
IfcElementAssemblyTypeEnum::IfcElementAssemblyTypeEnum() {}
IfcElementAssemblyTypeEnum::~IfcElementAssemblyTypeEnum() {}
shared_ptr<IfcPPObject> IfcElementAssemblyTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcElementAssemblyTypeEnum> copy_self( new IfcElementAssemblyTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcElementAssemblyTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCELEMENTASSEMBLYTYPEENUM("; }
	if( m_enum == ENUM_ACCESSORY_ASSEMBLY )
	{
		stream << ".ACCESSORY_ASSEMBLY.";
	}
	else if( m_enum == ENUM_ARCH )
	{
		stream << ".ARCH.";
	}
	else if( m_enum == ENUM_BEAM_GRID )
	{
		stream << ".BEAM_GRID.";
	}
	else if( m_enum == ENUM_BRACED_FRAME )
	{
		stream << ".BRACED_FRAME.";
	}
	else if( m_enum == ENUM_GIRDER )
	{
		stream << ".GIRDER.";
	}
	else if( m_enum == ENUM_REINFORCEMENT_UNIT )
	{
		stream << ".REINFORCEMENT_UNIT.";
	}
	else if( m_enum == ENUM_RIGID_FRAME )
	{
		stream << ".RIGID_FRAME.";
	}
	else if( m_enum == ENUM_SLAB_FIELD )
	{
		stream << ".SLAB_FIELD.";
	}
	else if( m_enum == ENUM_TRUSS )
	{
		stream << ".TRUSS.";
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
shared_ptr<IfcElementAssemblyTypeEnum> IfcElementAssemblyTypeEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcElementAssemblyTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcElementAssemblyTypeEnum>(); }
	shared_ptr<IfcElementAssemblyTypeEnum> type_object( new IfcElementAssemblyTypeEnum() );
	if( boost::iequals( arg, L".ACCESSORY_ASSEMBLY." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_ACCESSORY_ASSEMBLY;
	}
	else if( boost::iequals( arg, L".ARCH." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_ARCH;
	}
	else if( boost::iequals( arg, L".BEAM_GRID." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_BEAM_GRID;
	}
	else if( boost::iequals( arg, L".BRACED_FRAME." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_BRACED_FRAME;
	}
	else if( boost::iequals( arg, L".GIRDER." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_GIRDER;
	}
	else if( boost::iequals( arg, L".REINFORCEMENT_UNIT." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_REINFORCEMENT_UNIT;
	}
	else if( boost::iequals( arg, L".RIGID_FRAME." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_RIGID_FRAME;
	}
	else if( boost::iequals( arg, L".SLAB_FIELD." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_SLAB_FIELD;
	}
	else if( boost::iequals( arg, L".TRUSS." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_TRUSS;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcElementAssemblyTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
