for(int i=0;i<arr.size();i++){
        //using moores algo will Only work if there exists a majority element in the array(occurenece>[n/2])
        if(count==0){
            elem=arr[i];
        }else if(arr[i]==elem){
            count++;
        }else{
            count--;
        }
    }
    cout<<"the majority element is :"<<elem;