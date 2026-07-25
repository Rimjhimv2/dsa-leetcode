class SmallestInfiniteSet {
public:
    int curr = 1;
    set<int> st;

    int popSmallest() {
        if (!st.empty()) {
            int x = *st.begin();
            st.erase(st.begin());
            return x;
        }
        return curr++;
    }

    void addBack(int num) {
        if (num < curr)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */