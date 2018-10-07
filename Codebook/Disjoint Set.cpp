class disjointSet {
    int group[100];
public:
    void init() {
        for(int i = 0; i < 100; ++i) {
            group[i] = i;
        }
    }
    int find(int i) {
        if(group[i] == i) { return i; }
        else { return group[i] = find(group[i]); }
    }
    int unit(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) { group[b] = a; }
    }
}djs;
