
void mySort(int data[], unsigned int nDataItems)
{
  int i, j, a;
for (i = 0; i < nDataItems; ++i){
   for (j = i + 1; j < nDataItems; ++j){
      if (data[i] > data[j]){
         a = data[i];
         data[i] = data[j];
         data[j] = a;
      }
   }
}
}
