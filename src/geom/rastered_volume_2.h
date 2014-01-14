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
	 * 		tree only contains bits - no position or size data; root stores position and size
	 * 		+: single point of knowledge
	 * 		-: needs to be kept track of when iterating through tree
	 */

	struct NodeData;
	typedef const NodeData* Node;

	class NodeManager;

	inline bool isFull(Node node) {
		return ((std::size_t)node) == 1;		// TODO: find correct alternative for size_t
	}

	inline bool isEmpty(Node node) {
		return node == 0;
	}

	inline Node getFull()  { return (Node)1; }
	inline Node getEmpty() { return (Node)0; }

	typedef array<array<array<Node,2>,2>,2> Grid;

	class NodeData {
		Grid subs;	// if this block has sub-nodes

		NodeData(const Grid& grid) : subs(grid) {};
		NodeData(const Grid&& grid) : subs(grid) {};

	public:

		bool isFull() const {
			return geom::isFull(this);
		}

		bool isEmpty() const {
			return geom::isEmpty(this);
		}
	};

	class NodeManager {

		Node empty();
		Node create(const Grid& grid);

	};


	class Volume {
		Node root;				// the root node of the rastering
		int size;				// the size of the root block (exponent)
		int x, y, z;			// the position of the root block in the grid (regarding the exponent)
	};



}
