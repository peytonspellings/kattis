#include <iostream>
using namespace std;

const int MAXV = 100;

class edge
{
public:
	int dest;
	edge * next;

	edge(int d, edge* n = 0) : dest(d), next(n)
	{}
};

class vertex
{
public:
	string name;
	long long nsquawk;
	edge* adj;

	vertex(string n="")
	{
		name = n;
		nsquawk = 0;
		adj = new edge(-1);	// dummy header
	}

	void addEdge(int w)
	{
		adj->next = new edge(w, adj->next);
	}
};

class graph
{
public:
	vertex vlist[MAXV];
	int nvert;

	graph()
	{
		nvert = 0;
	}

	int getVertexNum(string n)
	{
		for(int i=0; i<nvert; i++) {
			if(vlist[i].name == n)
				return i;
		}
		vlist[nvert++].name = n;
		return nvert-1;
	}

	void addEdge(string n1, string n2)
	{
		int v1 = getVertexNum(n1);
		int v2 = getVertexNum(n2);
		vlist[v1].addEdge(v2);
		vlist[v2].addEdge(v1);
	}

	void print(ostream& out)
	{
		for(int i=0; i<nvert; i++) {
			out << vlist[i].name << '(' << i << ')' << ":";
			for(edge* p=vlist[i].adj->next; p != 0; p = p->next)
				out << ' ' << vlist[p->dest].name;
			out << endl;
		}
	}
};
ostream& operator<<(ostream& out, graph g)
{
	g.print(out);
	return out;
}


int main()
{
	int n, m;
	string start, n1, n2;
	int time;

	cin >> n >> m >> start >> time;
		graph g;
		for(int i=0; i<m; i++) {
			cin >> n1 >> n2;
			g.addEdge(n1, n2);
		}
//cout << g << endl;
		int v = g.getVertexNum(start);
		g.vlist[v].nsquawk = 1;
		long long count[MAXV];
		for(int t=1; t<= time; t++) {
			for(int i=0; i<g.nvert; i++)
				count[i] = 0;
			for(int i=0; i<g.nvert; i++) {
				long long num = g.vlist[i].nsquawk;
				for(edge* p = g.vlist[i].adj->next; p != 0; p = p->next) {
					count[p->dest] += num;
				}
			}
			for(int i=0; i<g.nvert; i++) {
				g.vlist[i].nsquawk = count[i];
			}
		}
		for(int i=1; i<g.nvert; i++)
			count[0] += count[i];
		cout << count[0] << endl;

}
	
