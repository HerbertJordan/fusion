#pragma once

#include <array>
#include <vector>
#include <memory>

using std::array;
using std::vector;

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

	class Grid {

	public:

		typedef array<array<array<Node,2>,2>,2> Data;

	private:

		Data data;

	public:

		Grid() : data() {}

		Grid(const Data& data) : data(data) {}
		Grid(const Data&& data) : data(data) {}

		template<typename Lambda>
		bool any(const Lambda& fun) const {
			return
				fun(data[0][0][0]) ||
				fun(data[0][0][1]) ||

				fun(data[0][1][0]) ||
				fun(data[0][1][1]) ||

				fun(data[1][0][0]) ||
				fun(data[1][0][1]) ||

				fun(data[1][1][0]) ||
				fun(data[1][1][1]);
		}

		template<typename Lambda>
		bool all(const Lambda& fun) const {
			return
				fun(data[0][0][0]) &&
				fun(data[0][0][1]) &&

				fun(data[0][1][0]) &&
				fun(data[0][1][1]) &&

				fun(data[1][0][0]) &&
				fun(data[1][0][1]) &&

				fun(data[1][1][0]) &&
				fun(data[1][1][1]);
		}

		template<typename Lambda>
		void each(const Lambda& fun) const {

			fun(data[0][0][0]);
			fun(data[0][0][1]);

			fun(data[0][1][0]);
			fun(data[0][1][1]);

			fun(data[1][0][0]);
			fun(data[1][0][1]);

			fun(data[1][1][0]);
			fun(data[1][1][1]);

		}

	};

	class NodeData {

		friend class NodeManager;

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

		vector<Node> nodes;

	public:

		~NodeManager() {
			for(auto cur : nodes) delete cur;
		}

		Node createEmpty() {
			return geom::getEmpty();
		}

		Node createFull() {
			return geom::getFull();
		}

		Node create(const Grid& grid) {
			// check whether grid is empty
			if (grid.all(isEmpty)) return createEmpty();
			if (grid.all(isFull)) return createFull();
			return createUnchecked(grid);
		}

		Node createUnchecked(const Grid& grid) {
			Node res = new NodeData(grid);
			nodes.push_back(res);
			return res;
		}

	};


	class Volume {
		Node root;				// the root node of the rastering
		int size;				// the size of the root block (exponential)

		Volume incSize() const;
		Volume decSize() const;
	};


	Volume merge(Volume a, Volume b) {

		// Step 1: bring both volume to same scaling size

		// Step 2: merge volumes

		return Volume();
	}

}
