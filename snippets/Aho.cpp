//included with transition
#include <array>
#include <queue>
#include <string>
#include <vector>

constexpr int K = 26;
struct Vertex {
    std::array<int, K> next;
    bool terminal = false;
    int terminal_idx = -1;
    int p = -1;
    char pch;
    int depth = 0;
    int link = 0;
    int next_terminal = 0;
    std::array<int, K> go;

    Vertex(int p, char ch, int depth) : p(p), pch(ch), depth(depth) {
        std::fill(next.begin(), next.end(), 0);
        std::fill(go.begin(), go.end(), 0);
    }
};

class AhoCorasick {
public:
    AhoCorasick() : t(1, {-1, '$', 0}) {}

    void add_string(std::string const& s, int idx) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t[v].next[c]) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch, t[v].depth + 1);
            }
            v = t[v].next[c];
        }
        t[v].terminal = true;
        t[v].terminal_idx = idx;
    }

    void push_links() {
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            auto& cur = t[v];
            auto& link = t[cur.link];
            q.pop();
            cur.next_terminal = link.terminal ? cur.link : link.next_terminal;

            for (int c = 0; c < K; c++) {
                if (cur.next[c]) {
                    t[cur.next[c]].link = v ? link.next[c] : 0;
                    q.push(cur.next[c]);
                } else {
                    cur.next[c] = link.next[c];
                }
            }
        }
    }

    int transition(int idx, char c) {
        return t[idx].next[c - 'a'];
    }

    Vertex const& getInfo(int idx) {
        return t[idx];
    }

private:
    std::vector<Vertex> t;
};



//version basic :
const int MAXN = 404, MOD = 1e9 + 7, sigma = 26;
 
int term[MAXN], len[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;
void add_str(string s)
{
    int cur = 0;
    for(auto c: s)
    {
        if(!to[cur][c - 'a'])
        {
            to[cur][c - 'a'] = sz++;
            len[to[cur][c - 'a']] = len[cur] + 1;
        }
        cur = to[cur][c - 'a'];
    }
    term[cur] = cur; 
}
 
void push_links()
{
    int que[sz];
    int st = 0, fi = 1;
    que[0] = 0;
    while(st < fi)
    {
        int V = que[st++];
        int U = link[V];
        if(!term[V]) term[V] = term[U];
        for(int c = 0; c < sigma; c++)
            if(to[V][c])
            {
                link[to[V][c]] = V ? to[U][c] : 0;
                que[fi++] = to[V][c];
            }
            else
            {
                to[V][c] = to[U][c];
            }
    }
}



//map version :
const int MAXN = 1e6 + 42;
 
map<char, int> to[MAXN];
int link[MAXN], que[MAXN], sz = 1;
 
void add_str(string s, int k)
{
    int v = 0;
    for(auto c: s)
    {
        if(!to[v][c]) to[v][c] = sz++;
        v = to[v][c];
    }
}
 
void push_links()
{
    link[0] = -1;
    int st = 0, fi = 1;
    que[0] = 0;
    while(st < fi)
    {
        int v = que[st++];
        for(auto it: to[v])
        {
            int u = it.second;
            int c = it.first;
            int j = link[v];
            while(j != -1 && !to[j][c]) j = link[j];
            if(j != -1) link[u] = to[j][c];
            que[fi++] = u;
        }
    }
}