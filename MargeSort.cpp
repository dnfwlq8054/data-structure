#include <iostream>
#include <vector>

void Marge(std::vector<int>& v, std::vector<int>& temp, int start, int mid, int end){
    for(int i = start; i <= end; i++){
        temp[i] = v[i];
    }
    //std::cout << "start = " << start << ", mid = " << mid << ", end = " << end << std::endl;;
    int mid_start = mid + 1;
    int idx = start;
    
    while(start <= mid && mid_start <= end){
        if(temp[start] <= temp[mid_start]){
            v[idx++] = temp[start++];
        }else{
            v[idx++] = v[mid_start++];
        }
    }

    for(int i = 0; i <= mid - start; i++){
        v[idx + i] = temp[start + i];
    }
}

void MargeSort(std::vector<int>& v, std::vector<int>& temp, int start, int end){
    if(start < end) {
        int mid = (end + start) / 2;
        MargeSort(v, temp, start, mid);
        MargeSort(v, temp, mid + 1, end);
        Marge(v, temp, start, mid, end);
    }

}

void print(std::vector<int>& v){
    for(auto n : v)
        std::cout << n << " ";
    std::cout << std::endl;
}

int main(){

    std::vector<int> v = {5, 100, 3, 1, 10, 54, 4, 6, 2, 7, 99};
    std::vector<int> temp(v.size());
    
    std::cout << "정렬 전 : ";
    print(v);
    MargeSort(v, temp, 0, v.size() - 1);
    std::cout << "정렬 후 : ";
    print(v);

    return 0;
}