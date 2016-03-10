#ifndef COLLISIONGRID_H_INCLUDED
#define COLLISIONGRID_H_INCLUDED

#include <memory>
#include <vector>

struct Circle
{
	Circle( double posX_, double posY_, double ray_ ) :
		posX( posX_ ),
		posY( posY_ ),
		ray( ray_ ),
		pNext( nullptr )
	{

	}

	double posX;
	double posY;
	double ray;
	Circle* pNext;
};

std::ostream& operator<<( std::ostream& out_, const Circle& circle_ );

inline double distance( const Circle& lhs_, const Circle& rhs_ )
{
	return	( lhs_.posX - rhs_.posX ) * ( lhs_.posX - rhs_.posX ) +
			( lhs_.posY - rhs_.posY ) * ( lhs_.posY - rhs_.posY );
}

inline double squareRadius( const Circle& lhs_, const Circle& rhs_ )
{
	return ( lhs_.ray + rhs_.ray ) * ( lhs_.ray + rhs_.ray );
}

typedef std::unique_ptr< Circle > CirclePtrType;
typedef std::vector< const Circle* > CirclePtrArrayType;

class CollisionGrid
{
public:
	CollisionGrid( size_t width_, size_t height, size_t edgeSize );

	size_t rowIndex( const Circle& circle_ ) const;
	size_t columnIndex( const Circle& circle_ ) const;
	bool isOutOfGrid( const Circle& circle_ ) const;

	void collide( const Circle& circle_, CirclePtrArrayType& collisions_ ) const;
	CirclePtrType append( CirclePtrType&& circle_ );
private:
	typedef std::vector< std::vector< CirclePtrType > > GridRowArrayType;

	std::vector< GridRowArrayType > grid;
	size_t width;
	size_t height;
	size_t edgeSize;
};

typedef std::shared_ptr< CollisionGrid > SharedCollisionGridType;

#endif // COLLISIONGRID_H_INCLUDED
