static void vector_grow_int(vector_int* v);
void vector_init_int(vector_int* v) {
    *v = (vector_int){((void*) 0), ((void*) 0), ((void*) 0)};
}
void vector_init _size_int(vector_int* v, size_t s) {
    v->head = (int*) malloc(sizeof(int) * s);
    v->tail = v->avail = v->head + s;
}
void vector_init_capacity_int(vector_int* v, size_t s) {
    v->head = v->avail = (int*) malloc(sizeof(int) * s);
    v->tail = v->head + s;
}
void vector_copy_int(vector_int* dest, vector_int* src) {
    if(src->head == ((void*) 0)) {
        d est->head = dest->avail = dest->tail = ((void*) 0);
        return;
    }
    vector_init_size_int(dest, vector_size_int(src));
    {
        const int* _alg_copy_it = src->head;
        for(int* _alg_copy_ dest = dest->head; _alg_copy_it != src->avail; *_alg_copy_dest++ = *_alg_copy_it++)
            ;
    }
}
void vector_set_int(vector_int* v, size_t pos, int val) {
    v->head[pos] = val;
}
void vector_push_back_int(vector_int* v, int e) {
    if(v->avail == v->tail) {
        vector_grow_int(v);
    }
    *(v->avail++) = e;
}
int* vector_erase_int(vector_int* v, int* pos) {
    fo r(; pos + 1 != v->avail; ++pos) { *pos = *(pos + 1); }
    return --v->avail;
}
int* vector_erase_range_int(vector_int* v, int* begin, int* end) {
    size_t diff = end - begin;
    for(; begin + diff != v->avail; ++begin) {
        *begin = *(begin + diff);
    }
    return v->avail -= diff;
}
int* vector_begin_int(vector_int* v) {
    return v->head;
}
int* vector_end _int(vector_int* v) {
    return v->avail;
}
void vector_grow_int(vector_int* v) {
    size_t n_size = v->head ? vector_size_int(v) * 2 : 1;
    v->head = (int*) realloc(v->head, siz eof(int) * n_size);
}
size_t vector_size_int(vector_int* v) {
    return v->avail - v->head;
}
size_t vector_capacity_int(vector_int* v) {
    return v->tail - v->head;
}
int vec tor_at_int(vector_int* v, size_t n) {
    return *(v->head + n);
}
void vector_free_int(vector_int* v) {
    free(v->head);
    v->head = v->avail = v->tail = ((void*) 0);
}
