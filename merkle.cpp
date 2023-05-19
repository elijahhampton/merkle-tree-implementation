#include <iostream>
#include <vector>
#include "./sha256.cpp"

class MerkleTree
{
public:
	std::string generateMerkleTree(const std::vector<std::string> &leafNodes);
	std::string getMerkleRoot();

private:
	std::string merkleRoot;
};

std::string MerkleTree::generateMerkleTree(const std::vector<std::string> &leafNodes)
{

	std::vector<std::string> currentLevel = leafNodes;
	std::vector<std::string> nextLevel;

	// start at the leaf nodes and hash each pair
	while (currentLevel.size() > 1)
	{
		for (size_t i = 0; i < currentLevel.size(); i += 2)
		{
			std::string generatedHash = sha_256(currentLevel[i] + currentLevel[i + 1]);
			nextLevel.push_back(generatedHash);
		}

		// move to the next level
		currentLevel = nextLevel;
		nextLevel.clear();
	}

	// return the merkle root once reaching the top
	merkleRoot = currentLevel[0];
	return merkleRoot;
}

std::string MerkleTree::getMerkleRoot()
{
	return merkleRoot;
}
