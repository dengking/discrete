
#include <vector>
namespace kai_seg_tree
{

    class SegTree
    {
    private:
        std::vector<int> tree;

    public:
        /// @brief
        /// call this method as buildSegTree(arr, 0, 0, n-1);
        /// Here arr[] is input array and n is its size.
        /// @param arr
        /// @param treeIndex
        /// @param lo low index
        /// @param hi high index
        void buildSegTree(std::vector<int> &arr, int treeIndex, int lo, int hi)
        {
            if (lo == hi)
            { // leaf node. store value in node.
                tree[treeIndex] = arr[lo];
                return;
            }

            int mid = lo + (hi - lo) / 2; // recurse deeper for children.
            buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
            buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);

            // merge build results
            tree[treeIndex] = merge(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
        }
        /// @brief sum
        /// @param i 
        /// @param j 
        /// @return 
        int merge(int i, int j)
        {
            return i + j;
        }
    };

}

int main(){
    int arr[] = { 18, 17, 13, 19, 15, 11, 20, 12, 33, 25 };
    
}