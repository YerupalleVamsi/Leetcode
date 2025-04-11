
int countSymmetricIntegers(int low, int high) {
    int count=0;
    if(low>9999){
        return 0;
    }
    for(int i=low;i<=high;i++){
        char num[6];
        snprintf(num, sizeof(num), "%d", i);
        int size=strlen(num);
