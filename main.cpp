#include "./merkle.cpp"
#include <vector>
#include <iostream>

int main()
{
    MerkleTree tree;
    std::vector<std::string> leafNodes;
    leafNodes.push_back("data1");
    leafNodes.push_back("data2");
    leafNodes.push_back("data3");
    leafNodes.push_back("data4");

    std::string merkleRoot = tree.getMerkleRoot();
    std::cout << merkleRoot << std::endl;

    merkleRoot = tree.generateMerkleTree(leafNodes);
    std::cout << merkleRoot << std::endl;

    merkleRoot = tree.getMerkleRoot();
    std::cout << merkleRoot << std::endl;
    return 0;
}