#ifndef INCLUDED_MULTIPLY_CONST_HPP
#define INCLUDED_MULTIPLY_CONST_HPP

#include "sync_block.hpp"

namespace gr {
namespace blocks {
template <class T>
class multiply_const : virtual public sync_block
{
    T d_k;
    const size_t d_vlen;


public:
    multiply_const(T k, size_t vlen = 1);
    ~multiply_const();

    virtual work_return_code_t work(std::vector<block_work_input>& work_input,
                                    std::vector<block_work_output>& work_output);

    const T k();
    void set_k(T k);
};

typedef multiply_const<std::int16_t> multiply_const_ss;
typedef multiply_const<std::int32_t> multiply_const_ii;
typedef multiply_const<float> multiply_const_ff;
typedef multiply_const<gr_complex> multiply_const_cc;

} // namespace blocks
} // namespace gr
#endif