/*Oscar Linkedlist*/
//#include "pch.h";
#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
#include <random>   // C++11 亂數庫
#include <vector>   // std::vector
#include <numeric>  // std::iota
#include <map>      //std::map
#include <unordered_map>  //std::unordered_map
#include <unordered_set>  //std::unordered_set
#include <stack>    //stack    
#include"MyStack.h"

using namespace std;

// 顯式實例化模板以便在 DLL 中包含特定類型
template class DLL_API MyStack<int>;
template class DLL_API MyStack<std::string>;

enum LeetcodeExam {
    Leetcodexxx,

    None,
};

enum DFS_enum {
    Preorder_recursion,
    Preorder_stack,
    PreorderMorris,
    Inorder_recursion,
    Inorder_stack,
    InorderMorris,
    Postorder_recursion,
    Postorder_stack,
    PostMorris,
    Levelorder_recursion,
    Levelorder_queue,

    N_ary_preorder_recursion,
    N_ary_preorder_stack,
    N_ary_inorder_recursion,
    N_ary_inorder_stack,
    N_ary_postorder_recursion,
    N_ary_postorder_stack,
};
std::unordered_map<DFS_enum, std::string> dfsEnumMap = {
        {Preorder_recursion, "Preorder_recursion"},
        {Preorder_stack, "Preorder_stack"},
        {PreorderMorris, "Preorder_Morris"},
        {Inorder_recursion, "Inorder_recursion"},
        {Inorder_stack, "Inorder_stack"},
        {InorderMorris, "Inorder_Morris"},
        {Postorder_recursion, "Postorder_recursion"},
        {Postorder_stack, "Postorder_stack"},
        {PostMorris, "Postorder_Morris"},
        {Levelorder_recursion, "Levelorder_recursion"},
        {Levelorder_queue, "Levelorder_queue"},

        { N_ary_preorder_recursion, "N_ary_preorder_recursion" },
        { N_ary_preorder_stack, "N_ary_preorder_stack" },
        { N_ary_inorder_recursion, "N_ary_inorder_recursion" },
        { N_ary_inorder_stack, "N_ary_inorder_stack" },
        { N_ary_postorder_recursion, "N_ary_postorder_recursion" },
        { N_ary_postorder_stack, "N_ary_postorder_stack" },

};

std::string dfsEnumToString(DFS_enum type) {
    auto it = dfsEnumMap.find(type);
    return it != dfsEnumMap.end() ? it->second : "Unknown";
}


#ifndef NOBUILDING_DLL  //#ifdef BUILDING_DLL
int main()
{
    #pragma region Leetcode program Test
    //try case
    LeetcodeExam ExamEnum = Leetcodexxx;    //ChangeForExam
    //intput
    vector<int> vInput1 = { 7,13,11,10,1 };
    vector<int> vInput2 = { 7,13,11,10,1 };
    vector<vector<int>> vvInput1 = { {1,2} ,{2,3},{3,4},{1,3} };
    string strinput1 = "bab";
    string strinput2 = "xaabacxcabaaxcabaax";
    int iInput1 = 0; int iInput2 = 0;
    //output
    int Ans = 0; vector<int> AnsVector; string AnsStr = ""; bool Ansbool = false;
    MyStack<int>* Implementation = new MyStack<int>();
    switch (ExamEnum)
    {
    case Leetcodexxx:
        //AnsVector = Implementation->Leetcode_Sol_21(vInput1, iInput1, 1);
        break;

    default:
        break;
    }
    #pragma endregion

    #pragma region DataStructure_Test
    std::cout << "一、DFS Start：" << endl;
    // Test the stack implementation
     MyStack<int> stack;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Print top element
    std::cout << "Top element: " << stack.top() << std::endl;

    // Pop elements
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;

    // Check stack size
    std::cout << "Stack size: " << stack.size() << std::endl;

    #pragma endregion

    #pragma region DFS
    std::cout <<"\n\r" << "二、DFS Start："<< endl;

    #pragma region Binary Tree
    /*
        A   
       / \
      B   C
     / \   \
    D   E   F
    */
    TreeNode<char>* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->right->right = new TreeNode('F');
    DFS<char> DFS_ut;
    vector<char> result_DFS;
    vector<vector<char>> result_BFS;

    //Preorder_recursion
    DFS_enum tryforDFS = Preorder_recursion;
    string DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.preorder(root, result_DFS);       
    DFS_ut.clear(result_DFS, DFS_strMethod);
    //Preorder_stack
    tryforDFS = Preorder_stack;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.preorder_stack(root, result_DFS);        //sol 1.
    DFS_ut.clear(result_DFS, DFS_strMethod);
    DFS_ut.preorder_stack2(root, result_DFS);       //sol 2.
    DFS_ut.clear(result_DFS, DFS_strMethod + "2");
    tryforDFS = PreorderMorris;                     //sol 3.
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.preorder_Morris(root, result_DFS);       
    DFS_ut.clear(result_DFS, DFS_strMethod);
    
    std::cout << endl;
    //Inorder_recursion
    tryforDFS = Inorder_recursion;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.inorder(root, result_DFS);       
    DFS_ut.clear(result_DFS, DFS_strMethod);
    //Inorder_stack
    tryforDFS = Inorder_stack;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.inorder_stack(root, result_DFS);         //sol 1.
    DFS_ut.clear(result_DFS, DFS_strMethod);
    DFS_ut.inorder_stack2(root, result_DFS);        //sol 2.
    DFS_ut.clear(result_DFS, DFS_strMethod + "2");
    tryforDFS = InorderMorris;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.inorder_Morris(root, result_DFS);        //sol 3.
    DFS_ut.clear(result_DFS, DFS_strMethod);
    std::cout << endl;

    //Postorder_recursion
    tryforDFS = Postorder_recursion;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.postorder(root, result_DFS);     
    DFS_ut.clear(result_DFS, DFS_strMethod);
    //Postorder_stack
    tryforDFS = Postorder_stack;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.postorder_stack(root, result_DFS);   //sol 1.
    DFS_ut.clear(result_DFS, DFS_strMethod);
    DFS_ut.postorder_stack2(root, result_DFS);   //sol 2.
    DFS_ut.clear(result_DFS, DFS_strMethod + "2");
    DFS_ut.postorder_stack3(root, result_DFS);   //sol 3.
    DFS_ut.clear(result_DFS, DFS_strMethod + "3");
    tryforDFS = PostMorris;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    DFS_ut.postorder_Morris(root, result_DFS);   //sol 4.
    DFS_ut.clear(result_DFS, DFS_strMethod);
    std::cout << endl;

    //Levelorder_recursion(非常不建議寫)
    DFS_ut.levelorder(root, result_BFS);
    result_BFS.clear();
    //Levelorder_queue
    tryforDFS = Levelorder_queue;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    vector<char> result_BFS_NoRecursion;
    DFS_ut.levelorder_queue(root, result_BFS_NoRecursion);
    DFS_ut.clear(result_BFS_NoRecursion, DFS_strMethod);
    std::cout << endl;
    #pragma endregion 

    #pragma region N-ary Tree
    /*
        
                   1
          /     |     |     \
         2      3      4      5
              / \      |     / \
             6   7     8    9  10
                 |     |    |
                 11    12   13
                 |
                 14


    1
    ├── 2
    ├── 3
    │    ├── 6
    │    └── 7
    │           └── 11
    │                   └── 14
    ├── 4
    │    └── 8
    │           └── 12
    └── 5
           ├── 9
           │    └── 13
           └── 10

    */
    Node<int>* N_ary_Root = new Node<int>(1, 
    {
        new Node<int>(2),
        new Node<int>(3, {
            new Node<int>(6),
            new Node<int>(7, {
                new Node<int>(11, {
                    new Node<int>(14)
                })
            })
        }),
        new Node<int>(4, {
            new Node<int>(8, {
                new Node<int>(12)
            })
        }),
        new Node<int>(5, {
            new Node<int>(9, {
                new Node<int>(13)
            }),
            new Node<int>(10)
        })
    });
    DFS<int> N_ary_DFS_ut;
    vector<int> N_ary_ans;

    //N_ary_Preorder_recursion
    tryforDFS = N_ary_preorder_recursion;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    N_ary_DFS_ut.N_ary_preorder(N_ary_Root, N_ary_ans);
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);
    //N_ary_Preorder_stack
    tryforDFS = N_ary_preorder_stack;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    N_ary_DFS_ut.N_ary_preorder_stack(N_ary_Root, N_ary_ans);
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);

    //N_ary_Inorder_recursion
    tryforDFS = N_ary_inorder_recursion;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    //補充：這個只是讓你看Inorder比較開方式題目，因為左->根->右，但你的根不知道要擺在中間的哪個地方，所以撰寫兩種方式思考其實根擺在中間的哪個地方都能寫
    N_ary_DFS_ut.N_ary_inorder(N_ary_Root, N_ary_ans,0);//倒數第二時，才把根排進去
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);
    N_ary_DFS_ut.N_ary_inorder(N_ary_Root, N_ary_ans,1);//中間時，把根排進去
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);
    //N_ary_Inorder_stack
    tryforDFS = N_ary_inorder_stack;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    N_ary_DFS_ut.N_ary_inorder_stack(N_ary_Root, N_ary_ans);//中間時，把根排進去
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);
    N_ary_DFS_ut.N_ary_inorder_stack2(N_ary_Root, N_ary_ans);//中間時，把根排進去
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);

    //N_ary_Postorder_recursion
    tryforDFS = N_ary_postorder_recursion;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    N_ary_DFS_ut.N_ary_postorder(N_ary_Root, N_ary_ans);
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);
    //N_ary_Postorder_stack
    tryforDFS = N_ary_postorder_stack;
    DFS_strMethod = dfsEnumToString(tryforDFS);
    N_ary_DFS_ut.N_ary_postorder_stack(N_ary_Root, N_ary_ans);
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod);
    N_ary_DFS_ut.N_ary_postorder_stack2(N_ary_Root, N_ary_ans);
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod + "2");
    N_ary_DFS_ut.N_ary_postorder_stack3(N_ary_Root, N_ary_ans);
    N_ary_DFS_ut.clear(N_ary_ans, DFS_strMethod + "3");


    #pragma endregion

    #pragma endregion


    std::cout << "\n\r" << "三、Other func test：" << endl;
    #pragma region Array
    std::cout << "Array：" << endl;
    vector<int> prefix_test = { 3, 5, 2, 1, 7 };
    std::cout << "題目：";
    for (auto num : prefix_test)
        std::cout << num << " ";
    //法一：
    std::cout << "\n法一、靜態陣列：" << endl;
    int prefix[5] = {};//✅int prefix[5]; ❌int prefix[nums.size()] = int[5](); => nums.size()：動態宣告，不能用在靜態上
    prefix[0] = prefix_test[0]; std::cout << prefix[0] << " ";
    for (int i = 1; i < prefix_test.size(); i++) {
        prefix[i] = prefix[i - 1] + prefix_test[i];
        std::cout << prefix[i] << " ";
    }
    //法二：
    std::cout << "\n法二、指向陣列指標 (int(*)[5])：" << endl;
    int (*prefix1)[5] = new int[1][5];//❌1.int (*prefix)[5]; => 因為你的指標沒有初始化 2.new int[1][nums.size()]：動態宣告，不能用在靜態上，但可以new int[nums.size()][5]
    std::cout << "a、(*prefix1)[i] 型式：" << endl;
    (*prefix1)[0] = prefix_test[0]; std::cout << (*prefix1)[0] << " ";
    for (int i = 1; i < prefix_test.size(); i++) {
        (*prefix1)[i] = (*prefix1)[i - 1] + prefix_test[i];
        std::cout << (*prefix1)[i] << " ";
    }
    //or
    for (int i = 0; i < 5; i++) (*prefix1)[i] = 0;
    std::cout << "\nb、prefix1[0][i] 型式：" << endl;
    prefix1[0][0] = prefix_test[0]; std::cout << prefix1[0][0] << " ";
    for (int i = 1; i < prefix_test.size(); i++) {
        prefix1[0][i] = prefix1[0][i - 1] + prefix_test[i];
        std::cout << prefix1[0][i] << " ";
    }

    //法三：
    std::cout << "\n法三、指向陣列指標 (int*)：" << endl;
    int* prefix2 = new int[prefix_test.size()];
    std::cout << "a、 *(prefix2 + i) 型式：" << endl;
    *prefix2 = prefix_test[0];  std::cout << *prefix2 << " ";//❌*prefix[0] = nums[0];
    for (int i = 1; i < prefix_test.size(); i++) {
        *(prefix2 + i) = *(prefix2 + i - 1) + prefix_test[i];
        std::cout << *(prefix2 + i) << " ";
    }
    //or
    for (int i = 0; i < 5; i++) *(prefix2 + i) = 0;
    std::cout << "\nb、 prefix2[i] 型式：" << endl;
    prefix2[0] = prefix_test[0]; std::cout << prefix2[0] << " ";
    for (int i = 1; i < prefix_test.size(); i++) {
        prefix2[i] = prefix2[i - 1] + prefix_test[i];
        std::cout << prefix2[i] << " ";
    }
    //法四：
    std::cout << "\n法四、vector：" << endl;
    vector<int> prefix3(prefix_test.size());
    prefix3[0] = prefix_test[0]; std::cout << prefix3[0] << " ";
    for (int i = 1; i < prefix_test.size(); i++) {
        prefix3[i] = prefix3[i - 1] + prefix_test[i];
        std::cout << prefix3[i] << " ";
    }

    std::cout << endl;
    #pragma endregion

    #pragma region random_device
    //srand(time(nullptr)); // 用目前時間作為隨機種子
    int randomNumber = rand() % 100 + 1; // 產生 1~100 之間的數字

    //比 rand() 更隨機，適合密碼學、模擬等需求。
    std::random_device rd;  // 取得隨機種子（硬體隨機數）
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 演算法
    std::uniform_int_distribution<int> dist(1, 100); // 產生範圍 1~100
    int randomNumber2 = dist(gen);
    #pragma endregion

    #pragma region vector
    std::vector<int>vec1(10);               // 建立 100 個元素未初始化
    std::vector<int> vec2(10, 0);           // 建立 100 個元素，每個都是 0
    std::vector<int> vec3(10);
    std::iota(vec3.begin(), vec3.end(), 0);  // 填入 0 到 99 (也可以)
    #pragma endregion

    #pragma region Map
    // 自訂比較函數（降序排列）
    struct Descending {
        bool operator()(int a, int b) const {
            return a > b; // 讓 key 由大到小排序
        }
    };
    std::map<int, std::string, Descending> m1;

    // 自訂相等函數
    struct MyEqual {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.first == b.first && a.second == b.second; //first 是key，second是value
        }
    };

    // 自訂 hash 函數
    /* size_t：
    size_t 是 C/C++ 裡的一種 無符號整數類型，專門用來表示物件的大小或索引。它的具體大小取決於你的系統架構：
    32 位元系統：size_t 是 4 bytes（32 位元），範圍是 0 ~ 4,294,967,295
    64 位元系統：size_t 是 8 bytes（64 位元），範圍是 0 ~ 18,446,744,073,709,551,615
    📝 重點：
    無符號：保證為正數，因為負的大小沒有意義
    跨平台：根據編譯器與硬體架構自動調整大小
    */
    struct MyHash {
        std::size_t operator()(const std::pair<int, int>& p) const {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);//^ 是 XOR（異或運算）
        }
    };

    /*
    ✅XOR (^)：用來混合 p.first 和 p.second 的哈希值，使得 unordered_map 的 key 分佈更均勻。
    ✅ << 1 左移：讓 p.second 的 bit pattern 變化，降低碰撞機率。
    ✅ 可能的進一步優化：可以用 * 31 等技巧來減少模式碰撞。
    ✅ 效果：這樣的設計可以讓 unordered_map<std::pair<int, int>> 減少哈希碰撞，提升存取速度。
    */
    struct PairHash {
        size_t operator()(const std::pair<int, int>& p) const {
            return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
        }
    };

    std::unordered_map<std::pair<int, int>, std::string, MyHash, MyEqual> umap;
    umap[std::make_pair(1, 2)] = "apple";
    umap[std::make_pair(3, 4)] = "banana";

    for (const auto& [key, value] : umap) {
        std::cout << "(" << key.first << ", " << key.second << "): " << value << '\n';
    }

    //Lambda 排序
    auto cmp = [](int a, int b) { return a > b; };
    std::map<int, std::string, decltype(cmp)> m(cmp);//decltype 精確獲取表達式的原始類型，不會調整型別。

    //插入(insert / operator[] / emplace)
    m.insert({ 4, "dog" });  // 插入 (不覆蓋)
    m[5] = "elephant";     // 插入 (會覆蓋舊值)
    m.emplace(6, "fox");   // 插入 (更高效)

    //查找(find / count)
    if (m.find(3) != m.end()) std::cout << "找到 key 3\n";
    if (m.count(3)) std::cout << "key 3 存在\n";

    //遍歷(for / iterator)
    for (const auto& [key, value] : m) { std::cout << key << ": " << value << '\n'; }
    for (auto it = m.begin(); it != m.end(); ++it) { std::cout << it->first << ": " << it->second << '\n'; }

    //刪除(erase)
    m.erase(2); // 刪除 key 為 2 的元素
    m.clear();  // 清空整個 map
    #pragma endregion

    #pragma region Set

    #pragma endregion

    #pragma region for
    //1.基本 for 迴圈 (經典寫法)
    for(int i = 0;i < vec1.size();i++)
        std::cout << vec1[i] << " ";  // 輸出每個元素
    //2.範圍 for 迴圈 (range-based for loop)
    for (int n : vec1) 
        std::cout << n << " ";        // 輸出每個元素
    //3.使用 auto 自動推導型別
    //只讀取並遍歷 (不修改)
    for (auto n : vec1) 
        std::cout << n << " ";        // 輸出每個元素

    //讀取並修改每個元素(使用 & 參考)
    for (auto& n : vec1) 
        std::cout << n << " ";        // 輸出每個元素

    //讀取並使用 const (避免修改)
    for (const auto& n : vec1) 
        std::cout << n << " ";        // 輸出每個元素
    //4.使用 auto 搭配迭代器(iterator)
    for (auto it = vec1.begin(); it != vec1.end(); ++it) { // ✅ 使用迭代器遍歷(auto = std::vector<int>::iterator)
        std::cout << *it << " ";
    }
    //上述等同此
    for (int* it = &vec1[0]; it != &vec1[vec1.size()-1]; ++it) {//vec12[vec12.size()] out of the range
        std::cout << *it << " ";
    }
    #pragma endregion

    return 0;
}
#endif

#pragma endregion


#pragma region Leetcode xxx. Description
//Leetcode xxx. Description
template<typename T>
void MyStack<T>::Leetcode_Sol_xxx(int& nums, int _solution) {
    switch (_solution)
    {
    case 1:
        return DataStructure_xxx(nums);
    default:
        return ; // 確保所有路徑都有回傳值
    }

    return ;
}

template<typename T>
void MyStack<T>::DataStructure_xxx(int& nums) {
    return;
}
#pragma endregion

#pragma endregion















