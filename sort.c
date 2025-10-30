Bubble Sort

#include &lt;stdio.h&gt;

int main()
{
  int array[100], n, c, d, swap;

  printf(&quot;Enter number of elements\n&quot;);
  scanf(&quot;%d&quot;, &amp;n);

  printf(&quot;Enter %d integers\n&quot;, n);

  for (c = 0; c &lt; n; c++)
    scanf(&quot;%d&quot;, &amp;array[c]);

  for (c = 0 ; c &lt; n - 1; c++)
  {
    for (d = 0 ; d &lt; n - c - 1; d++)
    {
      if (array[d] &gt; array[d+1]) /* For decreasing order use &#39;&lt;&#39; instead of &#39;&gt;&#39; */
      {
        swap       = array[d];

        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf(&quot;Sorted list in ascending order:\n&quot;);

  for (c = 0; c &lt; n; c++)
     printf(&quot;%d\n&quot;, array[c]);

  return 0;
}
Insertion Sort

#include &lt;stdio.h&gt;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i &lt; n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j &gt;= 0 &amp;&amp; arr[j] &gt; key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}

int main() {
    int n, i;

    printf(&quot;Enter the number of elements: &quot;);
    scanf(&quot;%d&quot;, &amp;n);

    int arr[n];

    printf(&quot;Enter %d integers: &quot;, n);
    for (i = 0; i &lt; n; i++) {
        scanf(&quot;%d&quot;, &amp;arr[i]);
    }

    insertionSort(arr, n);

    printf(&quot;\nSorted array: &quot;);
    for (i = 0; i &lt; n; i++) {
        printf(&quot;%d &quot;, arr[i]);
    }

    return 0;
}

Quick Sort

#include &lt;stdio.h&gt;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j &lt;= high - 1; j++) {
        if (arr[j] &lt; pivot) {
            i++;
            swap(&amp;arr[i], &amp;arr[j]);
        }
    }
    
    swap(&amp;arr[i + 1], &amp;arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low &lt; high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[100], n, i;

    
    printf(&quot;Enter the number of elements: &quot;);
    scanf(&quot;%d&quot;, &amp;n);
    
    printf(&quot;Enter the elements:\n&quot;);
    for (i = 0; i &lt; n; i++) {
        scanf(&quot;%d&quot;, &amp;arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    printf(&quot;\nSorted array in ascending order:\n&quot;);
    for (i = 0; i &lt; n; i++) {
        printf(&quot;%d &quot;, arr[i]);
    }
    
    return 0;
}

Merge Sort

#include &lt;stdio.h&gt;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    
    while (i &lt; leftSize &amp;&amp; j &lt; rightSize) {
        if (left[i] &lt;= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    
    while (i &lt; leftSize)
        arr[k++] = left[i++];
    
    while (j &lt; rightSize)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int size) {
    if (size &lt; 2)
        return;
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    for (int i = 0; i &lt; mid; i++)
        left[i] = arr[i];
    
    for (int i = mid; i &lt; size; i++)
        right[i - mid] = arr[i];
    
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    
    merge(arr, left, mid, right, size - mid);
}

int main() {
    int arr[100], n, i;
    
    printf(&quot;Enter the number of elements: &quot;);

    scanf(&quot;%d&quot;, &amp;n);
    
    printf(&quot;Enter the elements:\n&quot;);
    for (i = 0; i &lt; n; i++) {
        scanf(&quot;%d&quot;, &amp;arr[i]);
    }
    
    mergeSort(arr, n);
    
    printf(&quot;\nSorted array in ascending order:\n&quot;);
    for (i = 0; i &lt; n; i++) {
        printf(&quot;%d &quot;, arr[i]);
    }
    
    return 0;
}
