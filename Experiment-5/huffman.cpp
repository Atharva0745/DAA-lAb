#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// A Huffman Tree node
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    // Constructor
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison function for the priority queue (min-heap)
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

// Function to build the Huffman Tree and return its root
HuffmanNode* buildHuffmanTree(const vector<char>& characters, const vector<int>& frequencies) {
    int n = characters.size();

    // Priority queue to store nodes of Huffman Tree
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the min heap
    for (int i = 0; i < n; i++) {
        minHeap.push(new HuffmanNode(characters[i], frequencies[i]));
    }

    // Iterate while the size of the heap is more than one
    while (minHeap.size() > 1) {
        // Remove two nodes with the lowest frequency
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes
        HuffmanNode* newNode = new HuffmanNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Add the new node to the heap
        minHeap.push(newNode);
    }

    // The remaining node in the heap is the root of the Huffman Tree
    return minHeap.top();
}

// Utility function to print the Huffman codes
void printHuffmanCodes(HuffmanNode* root, string code) {
    if (!root) return;

    // If this is a leaf node, then print the character and its code
    if (root->ch != '\0') {
        cout << root->ch << ": " << code << endl;
    }

    // Recur to left and right subtrees
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

int main() {
    // Example characters and their frequencies
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};

    // Build Huffman Tree
    HuffmanNode* root = buildHuffmanTree(characters, frequencies);

    // Print Huffman Codes
    cout << "Huffman Codes:\n";
    printHuffmanCodes(root, "");

    return 0;
}
