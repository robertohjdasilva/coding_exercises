vector <int> findSignatureCounts(vector <int> arr) {
    int size = (int) arr.size ();
    if (size == 0) return {};
    
    vector<int> signatures (size, 1);
    
    for (int student = 0; student < size; student++) {
      // student and nextIndex are 0-based
      // arr[i] provides a 1-based index
      int nextIndex = arr[student] - 1;
      while (nextIndex != student) {
        signatures[student]++;
        nextIndex = arr[nextIndex] - 1;
      }
    }
    return signatures;  
}
