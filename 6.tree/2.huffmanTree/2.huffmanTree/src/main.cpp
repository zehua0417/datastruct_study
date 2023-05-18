#include <iostream>
#include<string>
#include<cstring>
#include <queue>
#include <unordered_map>

using namespace std;

// ������������Ľڵ�ṹ��
struct HuffmanNode {
    char ch; // �ڵ�洢���ַ�
    int freq; // �ڵ���ֵ�Ƶ��
    HuffmanNode* left, * right; // �����ӽڵ�

    HuffmanNode(char _ch, int _freq) : ch(_ch), freq(_freq), left(nullptr), right(nullptr) {}
};

// ����ȽϺ������ڽ���С����
struct CompareNodes {
    bool operator()(const HuffmanNode* lhs, const HuffmanNode* rhs) const {
        return lhs->freq > rhs->freq;
    }
};

// ������������
HuffmanNode* buildHuffmanTree(const string& str) {
    // ͳ���ַ�����Ƶ��
    unordered_map<char, int> freqMap;
    for (char ch : str) {
        ++freqMap[ch];
    }

    // ��ÿ���ַ��������Ƶ�ʷ�װ��һ���ڵ㣬������С������
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;
    for (auto entry : freqMap) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    // ��С������ȡ��������С�Ľڵ㣬�ϲ���һ���½ڵ㣬�����½ڵ����С�����У��ظ��˲���ֱ��ֻʣһ���ڵ�
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

    // ���ع��������ĸ��ڵ�
    return pq.top();
}

// ���ݹ����������ɱ����
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

// �����ַ���
string encode(const string& str, const unordered_map<char, string>& codeMap) {
    string result;
    for (char ch : str) {
        result += codeMap.at(ch);
    }
    return result;
}

// �����ַ���
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

// �ͷŹ������������нڵ�
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
    // �������������ͱ����
    HuffmanNode* root = buildHuffmanTree(str);
    unordered_map<char, string> codeMap;
    generateCodes(root, "", codeMap);

    // ��������
    cout << "Huffman codes:" << endl;
    for (auto entry : codeMap) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // �����ַ���
    string encodedStr = encode(str, codeMap);
    cout << "Encoded string: " << encodedStr << endl;

    // �����ַ���
    string decodedStr = decode(encodedStr, root);
    cout << "Decoded string: " << decodedStr << endl;

    // �ͷŹ�������
    freeHuffmanTree(root);

    return 0;
}