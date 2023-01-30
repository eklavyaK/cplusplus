while(true){
        if(st.count(end))break;
        st.insert(end);
        if(end+arr[end]<=n && end+arr[end]>=1 && next[end]>=0)end = next[end];
        else  break;
    }