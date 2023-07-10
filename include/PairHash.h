#ifndef PAIRHASH_H
#define PAIRHASH_H

#include <functional>
#include <utility>


/*The PairHash structure overrides the operator() function to calculate the hash 
value by combining the hash values of the individual components of the pair using 
XOR. This ensures uniqueness and efficient hashing for coordinate pairs.
*/

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

#endif