#include <iostream>
#include<string>
#include<cstring>
#include <queue>
#include <unordered_map>

using namespace std;

// 定义哈夫曼树的节点结构体
struct HuffmanNode {
    char ch; // 节点存储的字符
    int freq; // 节点出现的频率
    HuffmanNode* left, * right; // 左右子节点

    HuffmanNode(char _ch, int _freq) : ch(_ch), freq(_freq), left(nullptr), right(nullptr) {}
};

// 定义比较函数用于建立小根堆
struct CompareNodes {
    bool operator()(const HuffmanNode* lhs, const HuffmanNode* rhs) const {
        return lhs->freq > rhs->freq;
    }
};

// 构建哈夫曼树
HuffmanNode* buildHuffmanTree(const string& str) {
    // 统计字符出现频率
    unordered_map<char, int> freqMap;
    for (char ch : str) {
        ++freqMap[ch];
    }

    // 将每个字符及其出现频率封装成一个节点，并插入小根堆中
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;
    for (auto entry : freqMap) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    // 从小根堆中取出两个最小的节点，合并成一个新节点，并将新节点插入小根堆中，重复此操作直到只剩一个节点
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* newNode = new HuffmanNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    // 返回哈夫曼树的根节点
    return pq.top();
}

// 根据哈夫曼树生成编码表
void generateCodes(const HuffmanNode* root, string code, unordered_map<char, string>& codeMap) {
    if (!root) {
        return;
    }
    if (root->ch != '\0') {
        codeMap[root->ch] = code;
    }
    generateCodes(root->left, code + "0", codeMap);
    generateCodes(root->right, code + "1", codeMap);
}

// 编码字符串
string encode(const string& str, const unordered_map<char, string>& codeMap) {
    string result;
    for (char ch : str) {
        result += codeMap.at(ch);
    }
    return result;
}

// 解码字符串
string decode(const string& str, const HuffmanNode* root) {
    string result;
    const HuffmanNode* curr = root;
    for (char ch : str) {
        if (ch == '0') {
            curr = curr->left;
        }
        else if (ch == '1') {
            curr = curr->right;
        }
        if (curr->ch != '\0') {
            result += curr->ch;
            curr = root;
        }
    }
    return result;
}

// 释放哈夫曼树的所有节点
void freeHuffmanTree(HuffmanNode* root) {
    if (!root) {
        return;
    }
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    delete root;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    // 构建哈夫曼树和编码表
    HuffmanNode* root = buildHuffmanTree(str);
    unordered_map<char, string> codeMap;
    generateCodes(root, "", codeMap);

    // 输出编码表
    cout << "Huffman codes:" << endl;
    for (auto entry : codeMap) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // 编码字符串
    string encodedStr = encode(str, codeMap);
    cout << "Encoded string: " << encodedStr << endl;

    // 解码字符串
    string decodedStr = decode(encodedStr, root);
    cout << "Decoded string: " << decodedStr << endl;

    // 释放哈夫曼树
    freeHuffmanTree(root);

    return 0;
}