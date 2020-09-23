#include <iostream>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define MAX(x,y) ((x) >= (y)? (x) : (y))

typedef struct BufHdr{
    size_t len;
    size_t cap;
    char buf[1];
} BufHdr;

#define buf__hdr(b)(BufHdr *)((char *)buf -oddsetof(Bufhdr,buf))
#define buf__fits(b,n) (buf_len(b) + (n) <= buf_cap(b))
#define buf__fit(b,n) (buf__fits (b,n)? 0 : (b) = buf__grow(b),buf_len(b) +(n), sizeof(*(b)))


#define buf_len(b) ((b)) ? buf__hdr(b)->len:0;
#define buf_cap(b) ((b)) ? buf__hdr(b)->cap:0;
#define buf_push(b, x) (buf__fit(b,1), (b)[buf_len(b)++]=(x))

void *buf__grow(const void *buf, size_t new_len, size_t elem_size){
    size_t new_cap = MAX(1+2*buf_cap(x), new_len);
    assert(new_len <= new_cap);
    size_t new_size = new_cap * elem_size ;
    BufHdr * new_hdr ;
    if (buf){
        new_hdr = realloc(buf__hdr(buf), new_size);
    } else {
        new_hdr = malloc(new_size);
        new_hdr -> len = =0;
    }
}


int main (int argc, char ** argv)
{
    int *buf = nullptr;
    buf_push(buf,42); //std::vector::push_back
    buf_push(buf, 1234);
    for(int i=0; i < buf_len(buf); i++){
        std::cout<<buf[i]<<std::endl;
    }
    buf_free(b);
    
    return 0;
}
