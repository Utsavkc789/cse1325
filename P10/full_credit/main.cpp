#include "puzzle.h"
#include "solver.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  // std::sort
#include <thread>
#include <mutex>
std::mutex m;

int const num_threads = 2 ;



void puzzle_solver(std::vector<Puzzle> puzzles,std::vector<Solution>& solutions){
        for(auto puzzle: puzzles){
            for(std::string word:puzzle){
                Solver solver{puzzle};
                Solution s = solver.solve(word);
                m.lock();
                solutions.push_back(s);
                m.unlock();
                }}}


int main(int argc, char* argv[]) {

    // Load the puzzles
    typedef std::vector<Puzzle> P;
    
    std::vector<P> puzzles;
    
    for(int i=1; i<argc; i++){
        try{
            std::string filename = std::string(argv[i]);
            std::ifstream ifs{filename};
            
            if(puzzles.size() < num_threads){
                P sub;
                sub.push_back(Puzzle{filename,ifs});
                puzzles.push_back(sub);
                }
                
             else{
                puzzles.at(i%num_threads).push_back(Puzzle{filename,ifs});
                }
                }
                
          catch(std::exception& e){
                std::cerr << "Unable to open the file" << argv[i] << ": " << e.what() << std::endl;
                }
                }
                     
          std::array<std::thread,num_threads> _threads;
          std::vector<Solution> solutions;
          
          for(int i=0; i<num_threads; i++) _threads[i] = std::thread{puzzle_solver,puzzles.at(i),std::ref(solutions)};
          
          for(std::thread& t: _threads)
          t.join();
          
          std::sort(solutions.begin(),solutions.end());
          for(Solution& s:solutions) std::cout << s << std::endl;
           
                 
}
    
    
