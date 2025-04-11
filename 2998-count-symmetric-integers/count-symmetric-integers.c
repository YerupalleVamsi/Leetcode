
int countSymmetricIntegers(int low, int high) {
    int count=0;
    if(low>9999){
        return 0;
    }
    for(int i=low;i<=high;i++){
        char num[6];
        snprintf(num, sizeof(num), "%d", i);
        int size=strlen(num);
        if(size==2 && i%11==0){
            count++;
        }
        if(size==4){
            int left=(num[0]-'0')+(num[1]-'0');
            int right=(num[2]-'0')+(num[3]-'0');
            if(left==right)
            count++;
        }


    }
    return count;
}