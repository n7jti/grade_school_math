// (C) Alan Ludwig. All Rights Reserved.

#include "gsmath.h"

uint64_t mul(uint32_t u, uint32_t v)
{
    // Let's split this int half-word digits
    // This code is endian specific, for sure!
    uint32_t d1[2]{};
    uint32_t d2[2]{};
    uint32_t p[4]{};
    uint32_t carry = 0;

    
    d1[0] = u & 0x0000FFFF;
    d1[1] = (u & 0xFFFF0000) >> 16;

    d2[0] = v & 0x0000FFFF;
    d2[1] = (v & 0xFFFF0000) >> 16;

    // Now, the grade-school multiplication
    for (int i = 0; i < 2; i++)
    {
        carry = 0;
        for (int j = 0; j < 2; j++)
        {
            p[i + j] += carry + d1[j] * d2[i];
            carry = p[i + j] >> 16;
            p[i + j] = p[i + j] % (1 << 16); 
        }
        p[i + 2] = carry;
    }

    uint64_t product = 0;
    for (int i = 0; i < 4; i++)
    {
        product += static_cast<uint64_t>(p[i]) << (16 * i);
    }

    return product;
}