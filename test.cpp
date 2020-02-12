#include "appfort.h"
#include <jni.h>
#include "appfort_rpc.h"
#include "appfort_ssdeep.h"
#include "fuzzy.h"

template<typename TNext> struct ZInt64 : TValue<long long, TNext> {};
template<typename TNext> struct ZUint64 : TValue<unsigned long long, TNext> {};

template<typename TNext> struct ZInt32 : TValue<int, TNext> {};
template<typename TNext> struct ZUint32 : TValue<unsigned int, TNext> {};

template<typename TNext> struct ZInt16 : TValue<short, TNext> {};
template<typename TNext> struct ZUint16 : TValue<unsigned short, TNext> {};

template<typename TNext> struct ZInt8 : TValue<char, TNext> {};
template<typename TNext> struct ZUint8 : TValue<uint8, TNext> {};
template<typename T>

// client-side code
FORCEINLINE void RPC_clientCalculation(T arg, char *path)
{
    char *appfort_hash = (char *)malloc(0);
    auto appfort_ssdeep<arg> seed{};
    
    // call server
    FILE *stream = fopen(path, "rb");
    
    // genereate seed
    //
    //
    //
    
    appfort_hash = RPC_serverCalculation(stream, seed);
    
    // send to server
    RPC_serverProcess(appfort_hash);
}

FORCEINLINE char *RPC_serverCalculation(FILE *stream, uint32_t seed)
{
#ifdef APPFORT_SERVER
    // implementation fuzzy lop
    unsigned int bi = 0;
    if ((state->flags & FUZZY_STATE_SIZE_FIXED) && state->fixed_size != total_fixed_length)
    {
        errno = EINVAL;
        return -1;
    }
    state->flags |= FUZZY_STATE_SIZE_FIXED;
    state->fixed_size = total_fixed_length;
    while ((uint_least64_t)SSDEEP_BS(bi) * SPAMSUM_LENGTH < total_fixed_length)
    {
        ++bi;
        if (bi == NUM_BLOCKHASHES - 2)
            break;
    }
    ++bi;
    state->bhendlimit = bi;

    fuzzy_update_stream(stream);
    
    // do opaque predicates
    //
    //
    //
    //
    //
    //
    
    discriminant_analysis(hash);
    calculate_hash(hash);
    return hash;
    
#endif    
}
