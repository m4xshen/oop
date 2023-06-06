namespace Array {
  typedef struct {
    int *num_arr;
    int length;
  } Arr;

  void initilize(Arr &, int*, int);
  void showArray(Arr &);
  void add_num(Arr &);
  int count_n(Arr &);
}
