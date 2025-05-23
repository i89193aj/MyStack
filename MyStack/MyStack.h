#pragma once
// 定義宏區區分 DLL 的導入與導出
#define BUILDING_DLL

#ifdef BUILDING_DLL
#define DLL_API __declspec(dllexport)  // 導出符號
#else
#define DLL_API __declspec(dllimport)  // 導入符號
#endif

#include <string>
#include <iostream>
#include <vector>       // 若成員變數用到 std::vector
#include <map>          // 若有 std::map 變數
#include <unordered_map>// 若有 std::unordered_map 變數
#include <stdexcept>  // for std::out_of_range
#include <utility>    // for std::swap, std::move
#include <stack>        //stack
#include <queue>        //queue


using namespace std;


// 節點類定義
//template<typename T>
//class DLL_API Node {
//public:
//    T val;
//    Node<T>* next;
//    Node<T>* random;
//
//    Node(T val) : val(val), next(nullptr), random(nullptr) {}
//    Node(T val, Node<T>* next) : val(val), next(next), random(nullptr) {}
//    Node(T val, Node<T>* next, Node<T>* random) : val(val), next(next), random(random) {}
//
//};
// 
// 節點類定義
template<typename T>
class DLL_API Node {
public:
    T val;
    vector<Node<T>*> children;

    Node<T>() :val(T()) {}
    Node(T _val) :val(_val) {}
    Node(T _val, vector<Node<T>*> _children) :val(_val), children(_children) {}
};

/* struct(預設public)
template<typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T prev) : val(prev), left(NULL), right(NULL) {}
};
*/

            


template<typename T>
class DLL_API TreeNode {
public:
    T val;
    TreeNode<T>* left;  //非線性，所以用指標
    TreeNode<T>* right;
    TreeNode() :val(T()), left(nullptr), right(nullptr) {}
    TreeNode(T _val) :val(_val), left(nullptr), right(nullptr) {}
    TreeNode(T _val, TreeNode<T>* _Left) :val(_val), left(_Left), right(nullptr) {}
    TreeNode(T _val, TreeNode<T>* _Left, TreeNode<T>* _Right) :val(_val), left(_Left), right(_Right) {}
};

// MyStack 類定義
template <typename T>
class DLL_API MyStack {
private:
    vector<T> container;
public:
    MyStack() = default;

    bool empty() const {
        return container.empty();
    }

    size_t size() const{
        return container.size();
    }

    T& top() {
        if (empty()) throw std::out_of_range("Stack is empty");
        return container.back();
    }

    const T& top()  const {
        if (empty()) throw std::out_of_range("Stack is empty");
        return container.back();
    }

    void push(const T& _val) {
        container.push_back(_val);
    }
    //不加const 是因為它裡面會搬移，就會動到原本的值
    void push(T&& _val) {
        container.push_back(std::move(_val));
    }

    //parameter pack
    template<typename...T>
    void emplace(T&&...args) {
        container.emplace_back(std::forward<T>(args)...);
    }

    T pop() {
        if (empty()) throw std::out_of_range("Stack is empty");
        T value = container.back();
        container.pop_back();
        return value;
    }

    //只交換vector
    void swap(MyStack& _other) {
        container.swap(_other.container);
    }

    #pragma region friend
    /*
    1.從開頭開始 => 比 a[0] < b[0]
    2.如果相等，就繼續比 a[1] < b[1]，直到某一個 a[i] < b[i] 就回傳 true
    3.如果都一樣，會比長度：短的比較小 (長度是最晚比較的!!)
    */
    friend bool operator<(const MyStack& a, const MyStack& b) {
        return a.container < b.container;
    }

    friend bool operator<=(const MyStack& a, const MyStack& b) {
        return a.container <= b.container;
    }

    friend bool operator==(const MyStack& a, const MyStack& b) {
        return a.container == b.container;
    }

    friend bool operator!=(const MyStack& a, const MyStack& b) {
        return a.container != b.container;
    }

    friend bool operator>(const MyStack& a, const MyStack& b) {
        return a.container > b.container;
    }

    friend bool operator>=(const MyStack& a, const MyStack& b) {
        return a.container >= b.container;
    }
    // Non-member swap
    friend void swap(MyStack& a, MyStack& b) {
        a.swap(b);
    }
    #pragma endregion
    
    /*MyStack();
    MyStack(const MyStack& _DataStructure);
    ~MyStack();*/

    // ======= Leetcode Solutions =======
    void Leetcode_Sol_xxx(int& nums, int _solution);
    void DataStructure_xxx(int& nums);



    // ======= Leetcode Solutions =======
};

// DFS 
template <typename T>
class DLL_API DFS {
private:
    int height(TreeNode<T>* _Root) {
        if (!_Root) return 0;
        return 1 + std::max(height(_Root->left), height(_Root->right));
    }
    void printLevel(TreeNode<T>* _Root, int _level, std::vector<std::vector<T>>& _result) {
        if (!_Root) return;
        if (_level == 1) {
            _result.back().push_back(_Root->val);
        }
        else {
            printLevel(_Root->left, _level - 1, _result);
            printLevel(_Root->right, _level - 1, _result);
        }
    }

    /*N-ary Tree preorder*/
    void preorder_recur(vector<T>& _result, Node<T>* _Root) {
        if (!_Root) return;

        _result.push_back(_Root->val);
        for (auto child : _Root->children)
            preorder_recur(_result, child);
    }
    /*N-ary Tree Inorder*/
    void Inorder_Recur(vector<T>& _result, Node<T>* _Root) {
        if (!_Root) return;
        int n = _Root->children.size();

        if (n) {
            // 處理所有子節點除了最後一個子節點
            for (int i = 0; i < n - 1; ++i) {
                Inorder_Recur(_result,_Root->children[i]);
            }
        }

        // 訪問當前節點
        _result.push_back(_Root->val);

        // 處理最後一個子節點
        if (n) {
            Inorder_Recur(_result,_Root->children[n - 1]);
        }
    }
    /*N-ary Tree Inorder*/
    void Inorder_Recur2(std::vector<T>& _result, Node<T>* _Root) {
        if (!_Root) return;
        int n = _Root->children.size();

        for (int i = 0; i < n / 2; ++i) {
            Inorder_Recur2(_result, _Root->children[i]);
        }

        _result.push_back(_Root->val);

        for (int i = n / 2; i < n; ++i) {
            Inorder_Recur2(_result, _Root->children[i]);
        }
    }
    /*N-ary Tree postorder*/
    void postorder_Recur(vector<int>& _result, Node<T>* _Root) {
        if (!_Root) return;

        for (int i = 0; i < _Root->children.size(); i++)
            postorder_Recur(_result, _Root->children[i]);

        _result.push_back(_Root->val);

    }

    void reverseAddPath(std::vector<T>& result, TreeNode<T>* from, TreeNode<T>* to) {
        reversePath(from, to);

        // 把這段反轉的路徑的值加到 result
        TreeNode<T>* node = to;
        while (true) {
            result.push_back(node->val);
            if (node == from) break;
            node = node->right;
        }

        // 恢復路徑
        reversePath(to, from);
    }
    void reversePath(TreeNode<T>* from, TreeNode<T>* to) {
        if (from == to) return;

        TreeNode<T>* prev = from;
        TreeNode<T>* curr = from->right;
        TreeNode<T>* next = nullptr;

        while (prev != to) {
            next = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }
        //if (from == to) return;
        //TreeNode<T>* prev = nullptr;
        //TreeNode<T>* curr = from;
        //TreeNode<T>* next = nullptr;

        //while (curr != to) {
        //    if (curr == nullptr) break; // 防止 null 導致 crash 或無限 loop
        //    next = curr->right;
        //    curr->right = prev;
        //    prev = curr;
        //    curr = next;
        //}
        //curr->right = prev;
    }
public:
    DFS() = default;
    #pragma region Binary Tree 
    /*Recursion For Preorder*/
    void preorder(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;
        _result.push_back(_Root->val);
        preorder(_Root->left, _result);
        preorder(_Root->right, _result);
    }
    /*Stack For Preorder(No Recursion)*/
    void preorder_stack(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        std::stack<TreeNode<T>*> stk;
        stk.push(_Root);    //最源頭的根

        while (!stk.empty()) {
            TreeNode<T>* cur = stk.top(); stk.pop();
            _result.push_back(cur->val);            //根：把子節點當作一下個父節點
            // 先右再左，因為 stack 是 LIFO
            if (cur->right) stk.push(cur->right);   //右
            if (cur->left) stk.push(cur->left);     //左
        }
    }
    /*Stack For Preorder(No Recursion) => 依照觀察寫入taversal結果，返回推規則(這種寫法：你已經規則所以寫出來的)*/
    void preorder_stack2(TreeNode<T>* _Root, std::vector<T>& _result) {
        TreeNode<T>* cur = _Root;
        std::stack<TreeNode<T>*> stk;
        while (cur || !stk.empty()) {
            while (cur) {
                _result.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(); stk.pop();
            cur = cur->right;
        }
    }
    /*Morris Preorder Traversal，t = O(n)，s = O(1)*/
    void preorder_Morris(TreeNode<T>* root, std::vector<T>& result) {
        TreeNode<T>* cur = root;

        while (cur) {
            if (!cur->left) {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else {
                // 找左子樹中最右邊的節點（中序前驅）
                TreeNode<T>* pred = cur->left;
                while (pred->right && pred->right != cur)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = cur;  // 建立臨時鏈接
                    result.push_back(cur->val);
                    cur = cur->left;
                }
                else {
                    pred->right = nullptr;  // 移除臨時鏈接
                    cur = cur->right;
                }
            }
        }
    }


    /*Recursion For Inorder*/
    void inorder(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        inorder(_Root->left, _result);
        _result.push_back(_Root->val);
        inorder(_Root->right, _result);
    }
    /*Stack For Inorder(No Recursion)*/
    void inorder_stack(TreeNode<T>* _Root, std::vector<T>& _result) {
        std::stack<TreeNode<T>*> stk;
        TreeNode<T>* cur = _Root;//這行兩個優勢 func較大時 1.程式可讀性 2.程式不會失真(找的到原來的_Root指向的最初位置)

        while (cur || !stk.empty()) {

            //左：跑到每個最節點左邊最底部的子節點
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            //根：此時cur一定是nullpter，所以跑回當前節點的根(因為stk.top()就是他的父節點 = 他的根)
            cur = stk.top(); stk.pop();
            _result.push_back(cur->val);
            //右：從父節點往右跑到子節點
            cur = cur->right;
        }
    }
    /*Stack<pair<TreeNode*, bool> For Inorder(No Recursion)*/
    void inorder_stack2(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        std::stack<std::pair<TreeNode<T>*, bool>> stk;
        stk.push({ _Root, false });  // 第二個參數表示「是否已經訪問過左子樹」

        while (!stk.empty()) {
            auto [node, visited] = stk.top(); stk.pop();

            if (!node) continue;

            if (visited) {
                _result.push_back(node->val);  // 左子樹已處理，現在處理根
            }
            else {
                if (node->right) stk.push({ node->right, false }); // 右
                stk.push({ node, true });                          // 中（等左處理完再處理）
                if (node->left) stk.push({ node->left, false });   // 左
            }
        }
    }
    /*Morris Inorder Traversal，t = O(n)，s = O(1)*/
    void inorder_Morris(TreeNode<T>* root, std::vector<T>& result) {
        TreeNode<T>* cur = root;

        while (cur) {
            if (!cur->left) {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else {
                // 找左子樹中最右邊的節點（中序前驅）
                TreeNode<T>* pred = cur->left;
                while (pred->right && pred->right != cur)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = cur;  // 建立臨時鏈接
                    cur = cur->left;
                }
                else {
                    pred->right = nullptr;  // 移除臨時鏈接
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }

    /*Recursion For Postorder*/
    void postorder(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        postorder(_Root->left, _result);
        postorder(_Root->right, _result);
        _result.push_back(_Root->val);
    }
    /*Stack For Postorder(No Recursion) => Leetcode 標準做法*/
    void postorder_stack(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        stack<TreeNode<T>*> stk;
        TreeNode<T>* prev = nullptr;    // 技巧
        TreeNode<T>* cur = _Root;       // 移出 while
        stk.push(cur);

        while (!stk.empty()) {
            cur = stk.top();           //TreeNode<T>* cur = stk.top(); //這種雖然號的資源很少，但還是會耗掉stack的回收資源

            // 從下往上回來
            if ((!cur->left && !cur->right) || (prev && (prev == cur->left || prev == cur->right))) {
                _result.push_back(cur->val);
                stk.pop();
                prev = cur;
            }
            else {  //left、right
                //stack：FILO，他只有單個stack，所以就直接顛倒，push：根->左->左；pop：左->右->根
                if (cur->right) stk.push(cur->right);   //right
                if (cur->left) stk.push(cur->left);     //left
            }
        }
    }
    /*Stack For Postorder(No Recursion) => Two Stack：1.按taversal 2.s2只記錄"根"，這樣s2.pop()回來一定是按Postorder結果所要的順序返回*/
    void postorder_stack2(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        stack<TreeNode<T>*> s1, s2;
        TreeNode<T>* cur = _Root;  // 只宣告一次 node
        s1.push(cur);
        //O(n)
        while (!s1.empty()) {
            //stack：FILO(所以：s1.pop順序：左->右->根 -> out => s2.push：in->根->右->左) => s2：pop()才會是左->右->根
            if (cur->left) s1.push(cur->left);   //左
            if (cur->right) s1.push(cur->right); //右
            s2.push(cur);                        //根

            cur = s1.top(); s1.pop();
        }

        //O(n)，s2 中的順序就是 postorder
        while (!s2.empty()) {
            cur = s2.top(); s2.pop();
            _result.push_back(cur->val);
        }
    }
    /*Stack For Postorder(No Recursion) => 依照觀察寫入taversal結果，返回推規則(這種寫法：你已經規則所以寫出來的)*/
    void postorder_stack3(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        stack<TreeNode<T>*> stk;
        TreeNode<T>* cur = _Root;               //找尋新的節點
        TreeNode<T>* lastVisited = nullptr;     //找尋

        while (cur || !stk.empty()) {
            //左：往走心走到底(這種寫法，就是為什麼我說是知道規則回推回來的 => 因為postorder最後還是由最左邊的node開始寫data)
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode<T>* peek = stk.top();  //偷看堆疊頂端的元素但不移除它(有點像是next or lead)
                //右：如果右子樹存在且還沒處理過
                if (peek->right && lastVisited != peek->right) {
                    cur = peek->right;
                }
                else {  //根：push_back出來
                    _result.push_back(peek->val);
                    lastVisited = peek;
                    stk.pop();
                }
            }
        }
    }
    /*Morris Post Traversal，t = O(n)，s = O(1)*/
    void postorder_Morris(TreeNode<T>* _Root, std::vector<T>& _result) {
        // 虛擬節點，讓 root 成為第一個節點
        TreeNode<T> dummy(0);
        dummy.left = _Root;
        TreeNode<T>* cur = &dummy;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                cur = cur->right;
            }
            else {
                // 找到前驅節點（左子樹最右邊的節點）
                TreeNode<T>* predecessor = cur->left;
                while (predecessor->right != nullptr && predecessor->right != cur) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    // 第一次經過，設置線索
                    predecessor->right = cur;
                    cur = cur->left;
                }
                else {
                    // 第二次經過，處理左子樹到前驅的反向路徑
                    reverseAddPath(_result, cur->left, predecessor);
                    predecessor->right = nullptr;
                    cur = cur->right;
                }
            }
        }
    }

    /*Recursion For Levelorder => 非常複雜，不建議寫*/
    void levelorder(TreeNode<T>* _Root, std::vector<std::vector<T>>& _result) {
        cout << "Levelorder_recursion" << "：" << endl;

        int h = height(_Root);
        for (int i = 1; i <= h; ++i) {
            _result.push_back({});
            printLevel(_Root, i, _result);
        }

        int _layer = 1;
        for (std::vector<T>& vec : _result) {
            clear_BFS(vec, _layer);
            _layer++;
        }
    }
    /*Queue For Levelorder(No Recursion)*/
    void levelorder_queue(TreeNode<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        queue<TreeNode<T>*> q;
        q.push(_Root);

        while (!q.empty()) {
            TreeNode<T>* cur = q.front(); q.pop();
            _result.push_back(cur->val);

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }


    void clear(std::vector<T>& _result, const string& _Method) {
        cout << _Method << "：";
        for (const T& c : _result) {
            cout << c << " ";  // 輸出順序
            _result.pop_back();
        }
        cout << endl;
    }
    void clear_BFS(std::vector<T>& _result, const int& _layer) {
        cout << "第" + std::to_string(_layer) + "層 => ";
        for (const T& c : _result) {
            cout << c << " ";  // 輸出順序
        }
        cout << endl;
    }
    #pragma endregion

    #pragma region N-ary Tree 
    /*Recursion For Preorder*/
    void N_ary_preorder(Node<T>* _Root, std::vector<T>& _result) {
        preorder_recur(_result, _Root);
    }
    /*Stack For Preorder(No Recursion)*/
    void N_ary_preorder_stack(Node<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;
        stack<Node<T>*> stk;
        Node<T>* cur = _Root;
        stk.push(cur);

        while (!stk.empty()) {
            cur = stk.top(); stk.pop();
            _result.push_back(cur->val);
            // 注意：要倒著加子節點，因為 stack 是後進先出
            for (int i = cur->children.size() - 1; i >= 0; --i) {
                stk.push(cur->children[i]);
            }
        }       
    }

    /*Recursion For Inorder*/
    void N_ary_inorder(Node<T>* _Root, std::vector<T>& _result,const int& _mthd) {
        switch (_mthd) {
        case 0:
            Inorder_Recur(_result, _Root);
            break;
        case 1:
            Inorder_Recur2(_result, _Root);
            break;
        }
    }
    /*Stack For Inorder(No Recursion)*/
    void N_ary_inorder_stack(Node<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        struct Frame {
            Node<T>* node;
            int idx;
            bool selfDone;
        };

        stack<Frame> stk;
        stk.push({ _Root, 0, false });

        while (!stk.empty()) {
            Frame& top = stk.top();
            Node<T>* curr = top.node;
            int n = curr->children.size();
            int mid = n / 2;

            if (top.idx < mid) {
                // 遍歷前半部分子節點
                stk.push({ curr->children[top.idx], 0, false });
                ++top.idx;
            }
            else if (!top.selfDone) {
                // 處理自己
                _result.push_back(curr->val);
                top.selfDone = true;
            }
            else if (top.idx < n) {
                // 遍歷後半部分子節點
                stk.push({ curr->children[top.idx], 0, false });
                ++top.idx;
            }
            else {
                // 所有都處理完畢，退棧
                stk.pop();
            }
        }
    }
    /*Stack For Inorder(No Recursion)*/
    void N_ary_inorder_stack2(Node<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;

        stack<pair<Node<T>*, int>> stk;
        stk.push({ _Root, 0 });

        while (!stk.empty()) {
            auto& [node, idx] = stk.top();
            int n = node->children.size();
            int mid = n / 2;

            if (idx < mid) {
                // 前半 children
                stk.push({ node->children[idx], 0 });
                ++idx;
            }
            else if (idx == mid) {
                // 中間：自己
                _result.push_back(node->val);
                ++idx;
            }
            else if (idx < n) {
                // 後半 children
                stk.push({ node->children[idx], 0 });
                ++idx;
            }
            else {
                // 結束處理
                stk.pop();
            }
        }
    }


    /*Recursion For Postorder*/
    void N_ary_postorder(Node<T>* _Root, std::vector<T>& _result) {
        postorder_Recur(_result, _Root);
    }
    /*Stack For Postorder(No Recursion) */
    void N_ary_postorder_stack(Node<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;
        stack<Node<T>*> stk;
        Node<T>* cur = _Root;
        Node<T>* prev = nullptr;
        stk.push(cur);

        while (!stk.empty()) {
            cur = stk.top();
            if (cur->children.empty()
                || find(cur->children.begin(), cur->children.end(), prev) != cur->children.end()) {
                _result.push_back(cur->val);
                prev = cur;
                stk.pop();
            }
            else {
                for (auto it = cur->children.rbegin(); it != cur->children.rend(); it++) {
                    stk.push(*it);
                }
            }
        }
        /*
        時間複雜度： O(N × C)，N: 節點數量、C: 每個節點最多的 children 數
        空間複雜度： O(H)，H: 樹的高度（最深的節點深度)
        */
    }
    /*Stack For Postorder(No Recursion) */
    void N_ary_postorder_stack2(Node<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;
        stack<Node<T>*> stk;
        Node<T>* cur = _Root;
        Node<T>* prev = nullptr;
        stk.push(cur);

        while (!stk.empty()) {
            cur = stk.top(); stk.pop();
            _result.push_back(cur->val);

            for (auto child : cur->children) {
                stk.push(child);
            }
        }

        reverse(_result.begin(), _result.end());

        /*
        時間複雜度： O(N)
        空間複雜度： O(N)
        N：節點數量
        */
    }
    /*Stack For Postorder(No Recursion) */
    void N_ary_postorder_stack3(Node<T>* _Root, std::vector<T>& _result) {
        if (!_Root) return;
        stack<Node<T>*> stk;
        Node<T>* cur = _Root;
        Node<T>* prev = nullptr;
        stk.push(cur);

        while (!stk.empty()) {
            cur = stk.top(); stk.pop();
            _result.push_back(cur->val);

            for (auto child : cur->children) {
                stk.push(child);
            }
        }

        reverse(_result.begin(), _result.end());

        /*
        時間複雜度： O(N)，N：節點數量
        空間複雜度： O(H)，H：數深度
        */
    }


    /* N_ary_postorder
    解法	            時間複雜度	空間複雜度	    備註
    遞迴 DFS	        O(N)	    O(H)	    簡潔直觀，但可能 stack overflow（H 是高度）
    非遞迴 + reverse	O(N)	    O(N)	    最快，不需要額外 find()、不怕遞迴爆棧
    非遞迴 + find	    O(N × C)	O(H)	    find() 成本高，除非每個節點 child 很少
    */
    #pragma endregion

};

// 顯示實例化模板，以便在 DLL 中生成特定類型
extern template class DLL_API MyStack<int>;
extern template class DLL_API MyStack<std::string>;

#pragma region OOP
/*
class Base {
public:
    virtual void foo() = 0;  // 純虛擬函式
};

class Derived : public Base {
    // ❌ 沒有覆寫 foo()，所以仍然是抽象類別
};

class MoreDerived : public Derived {
public:
    void foo() override {  // ✅ MoreDerived 有覆寫 foo()
        std::cout << "MoreDerived foo()" << std::endl;
    }
};

如果你想建立該類的物件，子類就「一定要」覆寫純虛擬函式。
如果子類仍然是抽象類別，就不一定要覆寫純虛擬函式。
C++11 之後允許純虛擬函式 = 0 但仍提供函式體，可作為預設行為。
*/
#pragma endregion


