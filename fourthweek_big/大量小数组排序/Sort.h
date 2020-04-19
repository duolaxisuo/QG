/*打印数组*/
void printarray(int a[], int length)
{
  for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/*
*冒泡排序 ‘BubbleSort’
*从小到大
*通过比较相邻的两个数
*/
void BubbleSort(int a[], int length) //数组首地址和数组长度
{
  int temp;
  for (int i = 0; i < length; i++)
  { //第i+1轮比较，也意味着后面将要安排第i+1位数
    for (int j = 0; j < length - i - 1; j++)
    { //第一轮需要进行length-1轮相邻数的比较，就是length个数全都参与进来
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

/*
*选择排序 ‘SelectionSort’
*从小到大
*每次遍历选择出符合要求的数（从最后一位安排）
*/
void SelectionSort(int a[], int length)
{
  int temp, index = 0;
  for (int i = 0; i < length; i++)
  {
    temp = INT_MIN;                      //更新每次开始时的temp，不然会存储上一次循环中的最大数
    for (int j = 0; j < length - i; j++) //与冒泡的length-i-1不同，原因：单个选择出来的，不会因为其他的数排好位置，剩下一个自动排好
    {
      if (a[j] > temp)
      {
        temp = a[j]; //寻找最大值
        index = j;   //记录这次最大值的位置
      }
    }
    a[index] = a[length - i - 1]; //把需要插入的位置腾出来，并且保证腾出来的数不会丢失
    a[length - i - 1] = temp;     //在当前末尾需要的位置插入
  }
}

/*
*插入排序 ‘InsertionSort’
*从小到大
*从头开始，进行第i个数的排序时，假设前面的i-1个数已经排好序
*/
void InsectionSort(int a[], int length)
{
  int temp;
  for (int i = 1; i < length; i++)
  {
    for (int j = i; j > 0; j--) //自当前的位置向前
    {
      if (a[j] < a[j - 1]) //因为前面假设是有序的，所以需要小于前面一位才可进行交换
      {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        continue;
      }
      break; //continue和break优化了一点点
    }
  }
}

/*
*归并排序 ‘MergeSort’
*从小到大
*
*/
void MergeSort(int a[], int left, int right, int *tmp)
{
  if (left >= right)
    return;
  assert(a);
  //mid将数组二分
  int mid = left + ((right - left) >> 1);
  //左边归并排序,使得左子序列有序
  MergeSort(a, left, mid, tmp);
  //右边归并排序,使得右子序列有序
  MergeSort(a, mid + 1, right, tmp);
  //将两个有序子数组合并
  _Merge(a, left, mid, mid + 1, right, tmp);
}

void _Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
  int index = begin1;
  int i = begin1, j = begin2;
  //当划分的区间足够小时,begin1==end1,begin2==end2
  while (i <= end1 && j <= end2)
  {
    if (a[i] <= a[j])
      tmp[index++] = a[i++];
    else
      tmp[index++] = a[j++];
  }
  //将左边元素填充到tmp中
  while (i <= end1)
    tmp[index++] = a[i++];
  //将右边元素填充的tmp中
  while (j <= end2)
    tmp[index++] = a[j++];
  //将tmp中的数据拷贝到原数组对应的序列区间
  //end2-begin1+1
  memcpy(a + begin1, tmp + begin1, sizeof(int) * (end2 - begin1 + 1));
}

/*
*快速排序 ‘QuickSort’(递归版)
*从小到大
*从两端开始，但并不是同时，可以看做冒泡排序改进版
*/
void QuickSort(int a[], int left, int right) //数组首地址，左边界，右边界
{
  int x = left, y = right, mid = a[(right + left) / 2], temp; //mid是取数组中间的数
  while (x <= y)                                              // x在y的左边
  {
    while (a[x] < mid)
      x++; //x在mid的左边，x向右走，直到a[x]>=mid,此时a[x]左边都是小于mid的数,跳出循环时的a[x]>=mid
    while (a[y] > mid)
      y--;      //y在mid的右边，y向左走，直到a[y]<=mid,此时a[y]右边都是大于mid的数,跳出循环时的a[y]<=mid
    if (x <= y) //将a[x]与a[y]交换，保证在两个位置上的数符合要求
    {
      temp = a[x];
      a[x] = a[y];
      a[y] = temp;
      x++; //位置符合要求后，从下一位开始
      y--;
    } //当x<=y依然成立时继续这个过程
  }   //跳出循环时说明x>y而且a[mid]左边的数都小于它，右边的数都大于它,此时可以开始在[left,y]和[x,right]里面的排序
  //划分为小的区间重复以上过程
  if (x < right)
    QuickSort(a, x, right);
  if (y > left)
    QuickSort(a, left, y);
  //最终x==right,y==left时结束整个排序过程
}

/*
*计数排序 ‘CountSort’
*从小到大
*通过记录每个数字出现的次数来安排位置，适用于范围较小的数据
*/
void CountSort(int a[], int length)
{
  assert(a != NULL && length > 0);
  int min = a[0], max = a[0]; //需要数组内的最大值和最小值来确定范围,并且后面可以对应数字
  for (int i = 0; i < length; i++)
  {
    if (min > a[i])
    {
      min = a[i];
    }
    if (max < a[i])
    {
      max = a[i];
    }
  }
  int range = max - min + 1;

  //计数数组，用于统计数组a中各个不同数出现的次数
  //由于数组a中的数属于min...max之间，所以countArray的大小要够容纳range个int型的值
  int *countArray = (int *)calloc(range, sizeof(int));
  memset(countArray, 0, sizeof(int) * range); //需要初始化!!

  //统计数组a中各个不同数出现的次数，循环结束后countArray[i]表示数值i+min在a中出现的次数
  int index = 0, j = 0;
  for (index = 0; index < length; index++)
  {
    countArray[a[index] - min]++;
  }
  for (int i = 0; i < range; i++) //回收并且排序元素
  {
    while (countArray[i]--)
    {
      a[j++] = i + min;
    }
  }
  free(countArray);
}

/*
*基数排序 ‘RadixSort’
*从小到大
*从最低位开始，通过每次比较相应位数上的数(多关键字)，排序归到同一个桶里，直到最高位时终止
*/

void RadixSort(int a[], int length)
{
  int *radixArrays[10]; //分别为0~9的序列空间
  for (int i = 0; i < 10; i++)
  {
    radixArrays[i] = (int *)malloc(sizeof(int) * (length + 1)); //有可能全部数字都是同一个数字
    radixArrays[i][0] = 0;                                      //index为0处记录这组数据的个数
  }

  for (int pos = 1; pos <= MaxDec(a, 10); pos++) //从个位开始到最高位
  {
    for (int i = 0; i < length; i++) //分配过程
    {
      int num = GetNumInPos(a[i], pos); //得到相应位数上的数
      int index = ++radixArrays[num][0];
      radixArrays[num][index] = a[i];
    }

    for (int i = 0, j = 0; i < 10; i++) //收集
    {
      for (int k = 1; k <= radixArrays[i][0]; k++)
        a[j++] = radixArrays[i][k];
      radixArrays[i][0] = 0; //复位
    }
  }
}

int GetNumInPos(int num, int pos)
{
  int temp = 1;
  for (int i = 0; i < pos - 1; i++)
    temp *= 10;

  return (num / temp) % 10;
}

int MaxDec(int a[], int length) //得到数组中的最高位
{
  int max = a[0], dec = 0;
  for (int i = 0; i < length; i++)
  {
    if (max < a[i])
    {
      max = a[i];
    }
  }
  while (max)
  {
    dec++;
    max /= 10;
  }
  return dec;
}
