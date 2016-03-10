#include "CollisionGrid.h"

#include <algorithm>
#include <iostream>
#include <cassert>

std::ostream& operator<<( std::ostream& out_, const Circle& circle_ )
{
	return out_ << "Circle { x: " << circle_.posX << ", y: " << circle_.posY << ", r: " << circle_.ray << " } ";
}

CollisionGrid::CollisionGrid( size_t width_, size_t height_, size_t edgeSize_ ) :
	width( width_ ),
	height( height_ ),
	edgeSize( edgeSize_ )
{
	grid.resize( edgeSize );

	std::for_each( grid.begin(), grid.end(),
	[ this ]( GridRowArrayType& row_ )
	{
		row_.resize( edgeSize );
	});
}

size_t CollisionGrid::rowIndex( const Circle& circle_ ) const
{
	return (size_t)( circle_.posY / ( height / edgeSize ) );
}

size_t CollisionGrid::columnIndex( const Circle& circle_ ) const
{
	return (size_t)( circle_.posX / ( width / edgeSize ) );
}

void CollisionGrid::collide( const Circle& circle_, std::vector< const Circle* >& collisions_ ) const
{
	size_t row = rowIndex( circle_ );
	size_t column = columnIndex( circle_ );

	assert( row < edgeSize );
	assert( column < edgeSize );

	std::for_each( grid[ row ][ column ].begin(), grid[ row ][ column ].end(),
	[ &circle_, &collisions_ ]( const CirclePtrType& pCircle_ )
	{
		if( distance( circle_, *pCircle_ ) < squareRadius( circle_, *pCircle_ ) )
		{
			collisions_.push_back( pCircle_.get() );
		}
	});
}

bool CollisionGrid::isOutOfGrid( const Circle& circle_ ) const
{
	size_t row = rowIndex( circle_ );
	size_t column = columnIndex( circle_ );

	return row >= edgeSize || column >= edgeSize;
}

CirclePtrType CollisionGrid::append( CirclePtrType&& pCircle_ )
{
	assert( pCircle_ != nullptr );

	size_t row = rowIndex( *pCircle_ );
	size_t column = columnIndex( *pCircle_ );

	assert( row < edgeSize );
	assert( column < edgeSize );

	CirclePtrType nextCircle = std::make_unique< Circle >( *pCircle_ );
	nextCircle->pNext = pCircle_.get();

	grid[ row ][ column ].push_back( std::move( pCircle_ ) );

	return std::move( nextCircle );
}
