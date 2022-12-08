// largest sum of contiguous subarray
int kadanesAlgorithm(vector<int> &arr){
    int max_sum = arr[0];
    int previous_sum = arr[0];
    for(int i=1;arr.size()>i;i++){
        previous_sum = max(arr[i],previous_sum+arr[i]);
        max_sum = max(max_sum,previous_sum);
    }
    return max_sum;
}