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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcLagTime.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProcess.h"
#include "include/IfcRelSequence.h"
#include "include/IfcSequenceEnum.h"
#include "include/IfcText.h"

// ENTITY IfcRelSequence 
IfcRelSequence::IfcRelSequence() { m_entity_enum = IFCRELSEQUENCE; }
IfcRelSequence::IfcRelSequence( int id ) { m_id = id; m_entity_enum = IFCRELSEQUENCE; }
IfcRelSequence::~IfcRelSequence() {}
shared_ptr<IfcPPObject> IfcRelSequence::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcRelSequence> copy_self( new IfcRelSequence() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( createGUID32_wstr().c_str() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_RelatingProcess ) { copy_self->m_RelatingProcess = dynamic_pointer_cast<IfcProcess>( m_RelatingProcess->getDeepCopy(options) ); }
	if( m_RelatedProcess ) { copy_self->m_RelatedProcess = dynamic_pointer_cast<IfcProcess>( m_RelatedProcess->getDeepCopy(options) ); }
	if( m_TimeLag ) { copy_self->m_TimeLag = dynamic_pointer_cast<IfcLagTime>( m_TimeLag->getDeepCopy(options) ); }
	if( m_SequenceType ) { copy_self->m_SequenceType = dynamic_pointer_cast<IfcSequenceEnum>( m_SequenceType->getDeepCopy(options) ); }
	if( m_UserDefinedSequenceType ) { copy_self->m_UserDefinedSequenceType = dynamic_pointer_cast<IfcLabel>( m_UserDefinedSequenceType->getDeepCopy(options) ); }
	return copy_self;
}
void IfcRelSequence::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCRELSEQUENCE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RelatingProcess ) { stream << "#" << m_RelatingProcess->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_RelatedProcess ) { stream << "#" << m_RelatedProcess->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_TimeLag ) { stream << "#" << m_TimeLag->m_id; } else { stream << "$"; }
	stream << ",";
	if( m_SequenceType ) { m_SequenceType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	if( m_UserDefinedSequenceType ) { m_UserDefinedSequenceType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcRelSequence::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcRelSequence::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 9 ){ std::stringstream err; err << "Wrong parameter count for entity IfcRelSequence, expecting 9, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2] );
	m_Description = IfcText::createObjectFromSTEP( args[3] );
	readEntityReference( args[4], m_RelatingProcess, map );
	readEntityReference( args[5], m_RelatedProcess, map );
	readEntityReference( args[6], m_TimeLag, map );
	m_SequenceType = IfcSequenceEnum::createObjectFromSTEP( args[7] );
	m_UserDefinedSequenceType = IfcLabel::createObjectFromSTEP( args[8] );
}
void IfcRelSequence::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcRelConnects::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "RelatingProcess", m_RelatingProcess ) );
	vec_attributes.push_back( std::make_pair( "RelatedProcess", m_RelatedProcess ) );
	vec_attributes.push_back( std::make_pair( "TimeLag", m_TimeLag ) );
	vec_attributes.push_back( std::make_pair( "SequenceType", m_SequenceType ) );
	vec_attributes.push_back( std::make_pair( "UserDefinedSequenceType", m_UserDefinedSequenceType ) );
}
void IfcRelSequence::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcRelConnects::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelSequence::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcRelConnects::setInverseCounterparts( ptr_self_entity );
	shared_ptr<IfcRelSequence> ptr_self = dynamic_pointer_cast<IfcRelSequence>( ptr_self_entity );
	if( !ptr_self ) { throw IfcPPException( "IfcRelSequence::setInverseCounterparts: type mismatch" ); }
	if( m_RelatedProcess )
	{
		m_RelatedProcess->m_IsSuccessorFrom_inverse.push_back( ptr_self );
	}
	if( m_RelatingProcess )
	{
		m_RelatingProcess->m_IsPredecessorTo_inverse.push_back( ptr_self );
	}
}
void IfcRelSequence::unlinkFromInverseCounterparts()
{
	IfcRelConnects::unlinkFromInverseCounterparts();
	if( m_RelatedProcess )
	{
		std::vector<weak_ptr<IfcRelSequence> >& IsSuccessorFrom_inverse = m_RelatedProcess->m_IsSuccessorFrom_inverse;
		for( auto it_IsSuccessorFrom_inverse = IsSuccessorFrom_inverse.begin(); it_IsSuccessorFrom_inverse != IsSuccessorFrom_inverse.end(); )
		{
			shared_ptr<IfcRelSequence> self_candidate( *it_IsSuccessorFrom_inverse );
			if( self_candidate.get() == this )
			{
				it_IsSuccessorFrom_inverse= IsSuccessorFrom_inverse.erase( it_IsSuccessorFrom_inverse );
			}
			else
			{
				++it_IsSuccessorFrom_inverse;
			}
		}
	}
	if( m_RelatingProcess )
	{
		std::vector<weak_ptr<IfcRelSequence> >& IsPredecessorTo_inverse = m_RelatingProcess->m_IsPredecessorTo_inverse;
		for( auto it_IsPredecessorTo_inverse = IsPredecessorTo_inverse.begin(); it_IsPredecessorTo_inverse != IsPredecessorTo_inverse.end(); )
		{
			shared_ptr<IfcRelSequence> self_candidate( *it_IsPredecessorTo_inverse );
			if( self_candidate.get() == this )
			{
				it_IsPredecessorTo_inverse= IsPredecessorTo_inverse.erase( it_IsPredecessorTo_inverse );
			}
			else
			{
				++it_IsPredecessorTo_inverse;
			}
		}
	}
}
