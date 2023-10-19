// Offset allocator test
// https://github.com/aarni57/offalloc

#include "offalloc.h"

#include <stdio.h>
#include <stdlib.h>

static void do_something(uint32_t offset) {
    printf("do_something: offset %u\n", offset);
}

int main()
{
    oa_allocator_t allocator = { 0 };
    oa_create(&allocator, 65536, 1024);

    oa_allocation_t a;
    if (!oa_allocate(&allocator, 1337, &a))
        do_something(a.offset);

    oa_allocation_t b;
    if (!oa_allocate(&allocator, 123, &b))
        do_something(b.offset);

    oa_allocation_t c;
    if (!oa_allocate(&allocator, 574574, &c))
        do_something(c.offset);

    oa_storage_report_t r;
    oa_storage_report(&allocator, &r);

    oa_free(&allocator, &c);
    oa_free(&allocator, &b);
    oa_free(&allocator, &a);

    oa_destroy(&allocator);

    return EXIT_SUCCESS;
}
