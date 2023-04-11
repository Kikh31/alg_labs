#include <iostream>
#include <vector>

using namespace std;

enum class Color {
    White, Grey, Black
};

int n, m, answer, dots;

void Visit(vector<vector<int> > &graph, Color *color, int u) {
    color[u] = Color::Grey;
    for (auto v: graph[u]) {
        if (color[v] == Color::White) {
            Visit(graph, color, v);
        }
    }
    color[u] = Color::Black;
}

void DFS(vector<vector<int> > &graph, Color *color) {
    for (int i = 1; i <= dots; i++) {
        color[i] = Color::White;
    }

    for (int i = 1; i <= dots; i++) {
        if (color[i] == Color::White) {
            answer++;
            Visit(graph, color, i);
        }
    }
}

int dotCount(string **flat) {
    int res = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (flat[i][j] == ".") {
                flat[i][j] = to_string(++res);
            }
        }
    }

    return res;
}

void mkGraph(string **flat, vector<vector<int> > &graph, Color *color) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (flat[i][j] != "#") {
                if (flat[i - 1][j] != "#") graph[ stoi(flat[i][j]) ].push_back( stoi(flat[i - 1][j]) );
                if (flat[i][j - 1] != "#") graph[ stoi(flat[i][j]) ].push_back( stoi(flat[i][j - 1]) );
                if (flat[i][j + 1] != "#") graph[ stoi(flat[i][j]) ].push_back( stoi(flat[i][j + 1]) );
                if (flat[i + 1][j] != "#") graph[ stoi(flat[i][j]) ].push_back( stoi(flat[i + 1][j]) );
            }
        }
    }
}

int main() {
    cin >> n >> m;

    string **flat = new string *[n];
    for (int i = 0; i < n; i++) {
        flat[i] = new string[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            flat[i][j] += x;
        }
    }

    dots = dotCount(flat);
    vector<vector<int> > graph(dots + 1);
    Color color[dots + 1];

    mkGraph(flat, graph, color);

    DFS(graph, color);

    cout << answer << '\n';
}