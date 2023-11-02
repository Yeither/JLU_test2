//
// Created by Administrator on 2023/10/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
class AOE{
public:
    AOE(std::vector<std::vector<int>> aoemat){
        MAX_TRACE.push_back(0);
        MAX_TRACK.push_back(0);
        topo_sort.resize(10);
        AOEMat.resize(10); for (auto& it : AOEMat) { it.resize(10); }
        std::vector<std::vector<int>> judge;
        judge.resize(10); for (auto& it : judge) { it.resize(10);}
        for (int i = 0; i < aoemat.size(); ++i) {
            for (int j = 0; j < aoemat[0].size(); ++j) {
                if (aoemat[i][j]==INT_MAX||aoemat[i][j]==0)judge[i][j]=0;
                else judge[i][j]=1;
            }
        }
        for (int i = 0; i < judge[0].size(); ++i) {
            if(!(std::find(topo_sort.begin(), topo_sort.end(), i) == topo_sort.end())){
                bool if_topo=true;
                for (int j = 0; j < judge.size(); ++j) {
                    if(judge[j][i])if_topo = false;
                }
                if(if_topo){
                    topo_sort.push_back(i);
                    for (int j = 0; j < judge.size(); ++j) {
                        judge[i][j]=0;
                    }
                    i=0;
                }
            }
        }
        if(topo_sort.size()<aoemat.size()){
            std::cerr<<"not Topological mat";
        }
        else{
            for (int i = 0; i < aoemat[0].size(); ++i) {
                for (int j = 0; j < aoemat.size(); ++j) {
                    AOEMat[j][i]=aoemat[j][topo_sort[i]];
                }
            }
        }
    }

    int find_distance(int end){
        int trace=0;
        for (int i = end-1; i >= 0 ; --i) {
            if(AOEMat[i][end]!=INT_MAX){
                if(trace < MAX_TRACE[i]+AOEMat[i][end]){
                    trace = MAX_TRACE[i]+AOEMat[i][end];
                    MAX_TRACK[end]=i;
                }
            }
        }
        return 0;
    }

    void find_main_track(){
        for (int i = 1; i < AOEMat.size()-1; ++i) {
            find_distance(i);
        }
    }
    void show(){
        for(auto it:MAX_TRACE)std::cout<<it<<" "<<std::endl;
        for(auto it:MAX_TRACK)std::cout<<it<<" "<<std::endl;
    }
    std::vector<std::vector<int>> AOEMat;
    std::vector<int> topo_sort;
    std::vector<int> MAX_TRACE;
    std::vector<int> MAX_TRACK;
};

int main(){
    int arr[10][10]={{0,5,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                     {INT_MAX,0,INT_MAX,INT_MAX,3,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                     {INT_MAX,INT_MAX,INT_MAX,3,6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,3,INT_MAX,1,4,INT_MAX,INT_MAX},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,4,2,INT_MAX,INT_MAX,INT_MAX},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,4},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,5,INT_MAX},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2,INT_MAX},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,2},
                     {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX}};
    std::vector<std::vector<int>> map;
    map.resize(10);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            map[i].push_back(arr[i][j]);
        }
    }
    AOE a(map);
    a.find_main_track();
    a.show();

}