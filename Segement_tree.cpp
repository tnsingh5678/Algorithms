#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;
    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2*node, start, mid);
            build(data, 2*node+1, mid+1, end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return 0;  
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_sum = query(2*node, start, mid, left, right);
        int right_sum = query(2*node+1, mid+1, end, left, right);
        return left_sum + right_sum;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4*n);  
        build(data, 1, 0, n-1);
    }

    
    int range_query(int left, int right) {
        return query(1, 0, n-1, left, right);
    }

    
    void point_update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    
    SegmentTree segTree(data);
    cout << "Sum of range [1, 3]: " << segTree.range_query(1, 3) << endl;

    segTree.point_update(2, 6);
    
    cout << "Sum of range [1, 3] after update: " << segTree.range_query(1, 3) << endl;

    return 0;
}
