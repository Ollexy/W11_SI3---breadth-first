#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::vector<std::vector<int>> graph{ { 1, 2 }, {0,2}, {0,2,3},{2,4},{3} };

	int startUser = 0;
	int endUser = 4;

	std::queue<int> q;
	std::vector<bool>visited(5, false);
	int res = 1;

	q.push(startUser);
	visited[startUser] = true;

	while (!q.empty()) {
		int sz = q.size();

		for (int i{ 0 }; i < sz; i++) {
			int curUser = q.front();
			q.pop();

			for (auto frien : graph[curUser]) {
				if (frien == endUser) {
					std::cout << "Result = " << res << std::endl;
					return res;
				}
				if (visited[frien]) {
					continue;
				}
				q.push(frien);
				visited[frien] = true;
			}
		}
		res++;
	}

	return -1;
}