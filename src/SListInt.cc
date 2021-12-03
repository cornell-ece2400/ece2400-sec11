//========================================================================
// SListInt.cc
//========================================================================
// Implementation for ListInt

#include <cstdio>

#include "SListInt.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// SListInt Default Constructor
//------------------------------------------------------------------------

SListInt::SListInt()
{
  m_head_p = nullptr;
}

//------------------------------------------------------------------------
// SListInt Destructor
//------------------------------------------------------------------------

SListInt::~SListInt()
{
  while ( m_head_p != nullptr ) {
    Node* temp_p = m_head_p->next_p;
    delete m_head_p;
    m_head_p = temp_p;
  }
}

//------------------------------------------------------------------------
// SListInt Copy Constructor
//------------------------------------------------------------------------

SListInt::SListInt( const SListInt& lst )
{
  // We must make sure head pointer is initialized correctly, otherwise
  // push_front will not work correctly.

  m_head_p = nullptr;

  // Iterate through each element of the given lst and use push_front to
  // add it to this list.

  Node* curr_p = lst.m_head_p;
  while ( curr_p != nullptr ) {
    push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // We now have all elements in this list, but they are in the reverse
  // order, so we can call reverse to ensure that this list is an exact
  // copy of the given list.

  reverse_v1();
}

//------------------------------------------------------------------------
// SListInt Swap
//------------------------------------------------------------------------

void SListInt::swap( SListInt& lst )
{
  ece2400::swap( m_head_p, lst.m_head_p );
}

//------------------------------------------------------------------------
// SListInt Overloaded Assignment Operator
//------------------------------------------------------------------------

SListInt& SListInt::operator=( const SListInt& lst )
{
  SListInt tmp( lst ); // create temporary copy of given list
  swap( tmp );         // swap this list with temporary list
  return *this;        // destructor called for temporary list
}

//------------------------------------------------------------------------
// SListInt::push_front
//------------------------------------------------------------------------

void SListInt::push_front( int v )
{
  Node* new_node_p   = new Node;
  new_node_p->value  = v;
  new_node_p->next_p = m_head_p;
  m_head_p           = new_node_p;
}

//------------------------------------------------------------------------
// SListInt::size
//------------------------------------------------------------------------

int SListInt::size() const
{
  int   size   = 0;
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    size++;
    curr_p = curr_p->next_p;
  }

  return size;
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int SListInt::at( int idx ) const
{
  Node* curr_p = m_head_p;
  for ( int i = 0; i < idx; i++ )
    curr_p = curr_p->next_p;

  return curr_p->value;
}

//------------------------------------------------------------------------
// SListInt::at
//------------------------------------------------------------------------

int& SListInt::at( int idx )
{
  Node* curr_p = m_head_p;
  for ( int i = 0; i < idx; i++ )
    curr_p = curr_p->next_p;

  return curr_p->value;
}

//------------------------------------------------------------------------
// SListInt::reverse_v1
//------------------------------------------------------------------------

void SListInt::reverse_v1()
{
  int n = size();
  for ( int i = 0; i < n/2; i++ )
    ece2400::swap( at(i), at((n-1)-i) );
}

//------------------------------------------------------------------------
// SListInt::reverse_v2
//------------------------------------------------------------------------

void SListInt::reverse_v2()
{
  // Step 1. Create temporary list
  SListInt lst;

  // Step 2. Push front all values from this list onto temporary list
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    lst.push_front( curr_p->value );
    curr_p = curr_p->next_p;
  }

  // Step 3. Swap this list with temporary list
  swap( lst );
}

//------------------------------------------------------------------------
// SListInt::print
//------------------------------------------------------------------------

void SListInt::print() const
{
  Node* curr_p = m_head_p;
  while ( curr_p != nullptr ) {
    std::printf( "%d ", curr_p->value );
    curr_p = curr_p->next_p;
  }
  std::printf( "\n" );
}

