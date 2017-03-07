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
#include "include/IfcLabel.h"
#include "include/IfcTable.h"
#include "include/IfcTableColumn.h"
#include "include/IfcTableRow.h"

// ENTITY IfcTable 
IfcTable::IfcTable() { m_entity_enum = IFCTABLE; }
IfcTable::IfcTable( int id ) { m_id = id; m_entity_enum = IFCTABLE; }
IfcTable::~IfcTable() {}
shared_ptr<IfcPPObject> IfcTable::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcTable> copy_self( new IfcTable() );
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_Rows.size(); ++ii )
	{
		auto item_ii = m_Rows[ii];
		if( item_ii )
		{
			copy_self->m_Rows.push_back( dynamic_pointer_cast<IfcTableRow>(item_ii->getDeepCopy(options) ) );
		}
	}
	for( size_t ii=0; ii<m_Columns.size(); ++ii )
	{
		auto item_ii = m_Columns[ii];
		if( item_ii )
		{
			copy_self->m_Columns.push_back( dynamic_pointer_cast<IfcTableColumn>(item_ii->getDeepCopy(options) ) );
		}
	}
	return copy_self;
}
void IfcTable::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCTABLE" << "(";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_Rows );
	stream << ",";
	writeEntityList( stream, m_Columns );
	stream << ");";
}
void IfcTable::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcTable::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 3 ){ std::stringstream err; err << "Wrong parameter count for entity IfcTable, expecting 3, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_Name = IfcLabel::createObjectFromSTEP( args[0] );
	readEntityReferenceList( args[1], m_Rows, map );
	readEntityReferenceList( args[2], m_Columns, map );
}
void IfcTable::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	vec_attributes.push_back( std::make_pair( "Name", m_Name ) );
	if( m_Rows.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> Rows_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_Rows.begin(), m_Rows.end(), std::back_inserter( Rows_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "Rows", Rows_vec_object ) );
	}
	if( m_Columns.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> Columns_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_Columns.begin(), m_Columns.end(), std::back_inserter( Columns_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "Columns", Columns_vec_object ) );
	}
}
void IfcTable::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
}
void IfcTable::setInverseCounterparts( shared_ptr<IfcPPEntity> )
{
}
void IfcTable::unlinkFromInverseCounterparts()
{
}
