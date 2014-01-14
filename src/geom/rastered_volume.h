#pragma once

#include <array>
#include <memory>

using std::array;

namespace geom {

	/**
	 * To implement:
	 * 		- Block class
	 * 		- Block manager (for pointers)
	 * 		- Block pointer type
	 */

	/**
	 * Rules:
	 * 	- all volume instances are equally aligned
	 * 	- a block is given by its size and its central point
	 */

	template<typename P>
	struct Block {

		typedef std::shared_ptr<Block<P>> BlockPtr;

		P center;		// the center point of this block
		int size;		// the exponent of the size of this block
		bool full;		// a flag indicating whether this block is full

		array<array<array<BlockPtr,2>,2>,2> subBlocks;
	};

	class RasteredVolume {


	};

}
