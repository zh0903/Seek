#include<bits/stdc++.h>
using namespace std;
struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode* > neighbor;
	UndirectedGraphNode(int val) :label(val) {}
};

class soluton
{
public:
	soluton();
	~soluton();
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (node=NULL)
		{
			return NULL;
		}

		map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;
		//establish index search

		queue<UndirectedGraphNode*> q;
		q.push(node);


		//clone the root
		UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
		cloneMap[node] = cloneNode;

		while (!q.empty())
		{
			UndirectedGraphNode* temp=q.front();
			q.pop();
			for (size_t i = 0; i < temp->neighbor.size(); i++)
			{
				UndirectedGraphNode* adj = temp->neighbor[i];
				if (cloneMap.find(adj)==cloneMap.end())
				{
					UndirectedGraphNode * newnode = new UndirectedGraphNode(adj->label);
					cloneMap[temp]->neighbor.push_back(newnode);
					cloneMap[adj] = newnode;

					q.push(adj);
				}
				else
				{
					cloneMap[temp]->neighbor.push_back(cloneMap[adj]);
				}

			}
		}

		return cloneNode;
	}
private:

};

soluton::soluton()
{
}

soluton::~soluton()
{
}


class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int current = 0;
		int start = gas.size(); //start from the end to beginning.   gas.size and 0 is the same position
		int total = 0;

		do
		{
			if (total+gas[current]-cost[current]>=0)
			{
				++current;
				total += gas[current] - cost[current];

			}
			else 
			{
				--start;
				total += (gas[start] - cost[start]);
			}

		} while (current!=start);

		do {
			if (total + gas[current] - cost[current] >= 0) {
				total += (gas[current] - cost[current]);
				current++; // can go from current to current+1
			}
			else {
				start--; //not enough gas, try to start the one before origin start point.
				total += (gas[start] - cost[start]);  // ie 4->5 cost +gas4 
			}
		} while (current != start);

		return total >= 0 ? start % gas.size() : -1;
	}
};