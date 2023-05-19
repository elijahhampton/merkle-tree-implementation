#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

std::string sha_256(const std::string &str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    // Convert each byte of the hash to a two-digit hexadecimal representation using std::hex and std::setfill('0') manipulators
    // The resulting hash is then obtained by converting the hashStream to a string.
    std::stringstream hashStream;
    hashStream << std::hex << std::setfill('0');
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
    {
        hashStream << std::setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return hashStream.str();
}