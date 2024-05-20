#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point operator=(const Point &point)
	{
		this->x = point.x;
		this->y = point.y;
		return *this;
	}
};

class Solution {
public:
    bool isPathCrossing(string path) {
		Point origin; // 0, 0
		vector<pair<int, int>> adj;
		adj.push_back({origin.x, origin.y});
		for(const char &x : path)
		{
			if(x == 'S') {
				origin = Point(origin.x, origin.y - 1);
			}
			else if(x == 'N') {
				origin = Point(origin.x, origin.y + 1);
			}	
			else if(x == 'E') {
				origin = Point(origin.x + 1, origin.y);
			}
			else if(x == 'W') {
				origin = Point(origin.x - 1, origin.y);
			}
			// cout << origin.x << " - " << origin.y << "\n";
			for(const auto &v : adj) 
			{
				if(v.first == origin.x && v.second == origin.y) {
					return true;
				}
			}
			adj.push_back({origin.x, origin.y});
		}
		return false;
    }
};
int main()
{
	Solution s;
	if(s.isPathCrossing("NNEESSWW")) cout << "True\n";
	else cout << "False\n";
	return 0;
}