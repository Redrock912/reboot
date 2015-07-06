#include <iostream>
#include <queue>

using namespace std;

int n = 4;
int w[10] = { 2, 5, 10, 5 };
int p[10] = { 40, 30, 50, 10 };
int w2[10] = {0, 2, 5, 10, 5 };
int p2[10] = {0, 40, 30, 50, 10 };
int temp[10] = {};
int W = 16;
int maxprofit;
int numbest;
int prm_node_cnt=0;
int nprm_node_cnt=0;

struct node{
	int i;
	int profit;
	int weight;
	float bound;
};

queue<node> Q;


class edge
{
public:
	int i;
	int j;
	int weight;
	edge()
	{

	}
	edge(int a, int b, int c)
	{
		i = a;
		j = b;
		weight = c;
	}

	void set(int a, int b, int c)
	{
		i = a;
		j = b;
		weight = c;
	}

};

class Matp
{
public:
	int row;
	int column;
	int **k;
	Matp()
	{

	}
	Matp(int a, int b)
	{
		this->row = a;
		this->column = b;
		k = new int*[row];
		for (int i = 0; i < row; i++)
		{
			k[i] = new int[column];
		}
	}

	int get(int row, int column){
		return k[row][column];
	}

	void set(int row, int column)
	{
		int a;
		for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++){
			cin >> a;
			k[i][j] = a;
		}
	}


};


bool promising(int i, int profit, int weight)
{
	size_t j, k;
	int totweight;
	float bound; // Node is promising only if we should expand to its children. 

	// There must be some capacity left for the children.   
	if (weight >= 1000)
		return false;
	else
	{
		j = i + 1;
		bound = (float)profit;
		totweight = weight;
		while (j <= n && totweight + w[j] <= 900)
		{
			// Grab as many items as possible.          
			totweight = totweight + w[j];
			bound = bound + p[j];
			++j;
		}
		k = j; // Use k for consistency with formula in text.       
		if (k <= n) // Grab fraction of kth item.            
			bound = bound + (W - totweight) * (p[k] / w[k]);

		return (bound > maxprofit);
	}
}


//// bfs ¿ë
float get_bound(int i, int profit, int weight)
{
	int j, k;
	int totweight;
	float bound; // Node is promising only if we should expand to its children. 

	// There must be some capacity left for the children.   
	if (weight >= W)
		return -1;
	else
	{
		j = i + 1;
		bound = (float)profit;
		totweight = weight;
		while (j <= n && totweight + w2[j] <= W)
		{
			// Grab as many items as possible.          
			totweight = totweight + w2[j];
			bound = bound + p2[j];
			++j;
		}
		k = j; // Use k for consistency with formula in text.       
		if (k <= n) // Grab fraction of kth item.            
			bound = bound + (W - totweight) * ((float)p2[k] / w2[k]);

		return bound;
	}
}

bool promising2(node u)
{
	if (u.weight >= W)
		return false;
	else
		return (u.bound > maxprofit);
}

node best;

void bfs_knapsack(int i, int profit, int weight)
{
	node v = { 0, profit, weight, 0 };
	v.bound = get_bound(v.i, v.profit, v.weight);
	if (promising2(v))
	{
		Q.push(v);
		prm_node_cnt++;
	}
	if (profit > maxprofit)
		maxprofit = profit;

	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();

		node u = { v.i + 1, v.profit + p2[v.i + 1], v.weight + w2[v.i + 1], 0 };
		u.bound = get_bound(u.i, u.profit, u.weight);
		
		if (promising2(u))
		{
			Q.push(u);
			prm_node_cnt++;
			if (u.profit > maxprofit)
			{
				maxprofit = u.profit;
				best = u;
			}
		}
		else{
			nprm_node_cnt++;
		}

		u = { v.i + 1, v.profit, v.weight, 0 };
		u.bound = get_bound(u.i, u.profit, u.weight);

		if (promising2(u))
		{
			Q.push(u);
			prm_node_cnt++;
			if (u.profit > maxprofit)
			{
				maxprofit = u.profit;
				best = u;
			}
		}
		else{
			nprm_node_cnt++;
		}
	}
}
void knapsack(size_t i, int profit, int weight)
{
	// This set is best so far. Set numbest to number of items considered.  
	// Set bestset to this solution.    
	if (weight <= W && profit > maxprofit)
	{
		maxprofit = profit;
		numbest = i;
	}

	if (promising(i, profit, weight))
	{
		++prm_node_cnt; // Count the number of promising node       
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
		knapsack(i + 1, profit, weight);
	}
	else
	{
		// Count the number of non-promising node       
		++nprm_node_cnt;
	}
}

int main()
{
	edge F[9];
	Matp path(9, 9);
	path.k[0][0] = 0;
	path.k[0][1] = 7;
	path.k[0][2] = 8;
	path.k[0][3] = 1000;
	path.k[0][4] = 1000;
	path.k[0][5] = 1000;
	path.k[0][6] = 1000;
	path.k[0][7] = 1000;
	path.k[1][0] = 1000;
	path.k[1][1] = 0;
	path.k[1][2] = 12;
	path.k[1][3] = 1000;
	path.k[1][4] = 4;
	path.k[1][5] = 1000;
	path.k[1][6] = 5;
	path.k[1][7] = 1000;
	path.k[2][0] = 1000;
	path.k[2][1] = 1000;
	path.k[2][2] = 0;
	path.k[2][3] = 4;
	path.k[2][4] = 1000;
	path.k[2][5] = 1000;
	path.k[2][6] = 7;
	path.k[2][7] = 1000;
	path.k[3][0] = 1000;
	path.k[3][1] = 1000;
	path.k[3][2] = 1000;
	path.k[3][3] = 0;
	path.k[3][4] = 1000;
	path.k[3][5] = 1000;
	path.k[3][6] = 1000;
	path.k[3][7] = 2;
	path.k[4][0] = 3;
	path.k[4][1] = 1000;
	path.k[4][2] = 1000;
	path.k[4][3] = 1000;
	path.k[4][4] = 0;
	path.k[4][5] = 1000;
	path.k[4][6] = 1000;
	path.k[4][7] = 1000;
	path.k[5][0] = 1000;
	path.k[5][1] = 7;
	path.k[5][2] = 1000;
	path.k[5][3] = 1000;
	path.k[5][4] = 5;
	path.k[5][5] = 0;
	path.k[5][6] = 1000;
	path.k[5][7] = 1000;
	path.k[6][0] = 1000;
	path.k[6][1] = 1000;
	path.k[6][2] = 1000;
	path.k[6][3] = 7;
	path.k[6][4] = 1000;
	path.k[6][5] = 17;
	path.k[6][6] = 0;
	path.k[6][7] = 1000;
	path.k[7][0] = 1000;
	path.k[7][1] = 1000;
	path.k[7][2] = 1000;
	path.k[7][3] = 1000;
	path.k[7][4] = 1000;
	path.k[7][5] = 8;
	path.k[7][6] = 9;
	path.k[7][7] = 0;
	knapsack(0, p[0], w[0]);
	//bfs_knapsack(0,0,0);
	cout << prm_node_cnt << endl;
	cout << nprm_node_cnt << endl;

	cout << maxprofit << endl;


	return 0;
}