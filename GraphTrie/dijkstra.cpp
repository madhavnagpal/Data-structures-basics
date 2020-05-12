// I am Nothing , You are nothing
// Krishna is Everything
// Jai Shree Krishna

#include <bits/stdc++.h>
using namespace std;
#define int long long
void letsStart();

class Graph
{
public:
    unordered_map< char, list< pair< char, int > > > h;

    void addEdge(char u, char v, int wt)
    {
        h[u].push_back({v, wt});
        h[v].push_back({u, wt});
    }
    void Print()
    {
        for (auto node : h)
        {
            cout << node.first << "-->";
            for (auto children : node.second)
            {
                cout << "(" << children.first << "," << children.second << ") ";
            }
            cout << endl;
        }
    }

    void ssspD(char src)
    {
        set<pair<int, char>> s;
        map<char, int> distance;

        for (auto node : h)
            distance[node.first] = INT_MAX;

        distance[src] = 0;

        s.insert({0, src});

        while (!s.empty())
        {
            auto p = *(s.begin());

            int parentDist = p.first;
            char parent = p.second;
            s.erase(s.begin());

            for (auto children : h[parent])
            {
                char child = children.first;
                int edge = children.second;

                if (distance[child] > parentDist + edge)
                {
                    auto f = s.find({distance[child], child});
                    distance[child] = parentDist + edge;
                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    s.insert({distance[child], child});
                }
            }
        }

        //print dis
        for (auto node : h)
            cout << "distance of " << node.first << " from " << src << " :" << distance[node.first] << endl;
    }
};

int32_t main()
{
    // letsStart();
    Graph g;
    g.addEdge('A', 'B', 1);
    g.addEdge('B', 'C', 2);
    g.addEdge('C', 'D', 3);
    g.addEdge('D', 'A', 8);
    g.addEdge('A', 'C', 4);

    cout << "Printing Graph" << endl;
    g.Print();

    cout << "Shortest Paths" << endl;
    g.ssspD('A');

    return 0;
}

void letsStart()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
