#ifndef __VECTEX1_H__
#define __VECTEX1_H__

typedef struct _vect_t {
  double* data;
  unsigned int max_size;
  unsigned int actual_size;
}  * vect_t;

vect_t vect_new(unsigned int n);
vect_t vect_append(double e, vect_t table);
vect_t vect_remove_nlast(int n, vect_t table);
vect_t vect_delete(vect_t table);

#endif
