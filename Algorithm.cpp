
#include<iostream>
#include<ctime>
#include<algorithm>

#define POPSIZE 60
#define MAXGEN  4000
#define BSTSZE  6
#define WSTSZE  6

Algorithm::Algorithm(
    const unordered_map<int, Room*>& rooms,
    const unordered_map<string, Course*>& courses,
    const unordered_map<string, Teacher*>& teachers,
    const unordered_map<string, StudentSection*>& sections,
    const vector<Lecture*>& lectures
):
    rooms(rooms),
    courses(courses),
    teachers(teachers),
    sections(sections),
    lectures(lectures)
{

        seed = time(nullptr);

        populationSize = POPSIZE;
        maxGenerations = MAXGEN;

        bestSize    = BSTSZE;
        worstSize   = WSTSZE;

        population.resize( populationSize );
        newPopulation.resize( populationSize );

}

//destructor
Algorithm::~Algorithm(){

    bestFitness = 0.0;
    avgFitness  = 0.0;
    
    for(auto& i: population){
        delete i;
    }

    for(auto& j: newPopulation){
        delete j;
    }

    population.clear();
    newPopulation.clear();

}


void Algorithm::initialize(){

    for(int i = 0; i < populationSize; i++){
        delete population[i];
        population.at(i) = new Schedule(
            seed, rooms, courses, teachers, sections, lectures
        );
        population.at(i)->initialize();
    }

    currentGeneration = 0;

    calculateFitness();
}

//Main Execution of the algorithm
void Algorithm::run(){

    while(
        bestFitness < 1.0 &&
        currentGeneration < maxGenerations
        //also a time limit to break the loop
    ){
        reproduction();
        if(currentGeneration%500 == 0){
            cout << endl;
            cout << "gen: " << currentGeneration
            << " B: " << bestFitness
            << " A:" << avgFitness;
            cout << endl;
        }

        
        currentGeneration++;
    }
   
    cout << "GEN: " << currentGeneration << endl;
    population.front()->printSchedule(true);
}


void Algorithm::calculateFitness(){

    
    sortBestAndWorst();

    double sum = 0.0;

    //add up fitness of every schedule
    for(const auto& i: population){
        sum += i->getFitness();
    }

    //sum / number = avg
    avgFitness =  (double) sum / populationSize;

   
}

//fitness propotionate selection returns index of schedule
int Algorithm::rouletteSelection(){

    double x = r8_uniform_ab ( 0.0, 1.0, seed );
    if( x < population.at(0)->cumulativeProb ) return 0;

    for (int j = 0; j < populationSize - 1; j++ ){
        if (
            x >= population.at(j)->cumulativeProb &&
            x < population.at(j + 1)->cumulativeProb
            ){
            return j+1;
            }
    }
    //to avoid compiler warnings
    return 0;
}

//tournament selection returns index of schedule
int Algorithm::tournamentSelection(int selectionPressure = 10){

   
    int maxIndex = 0;

    double maxFitness = 0.0;

   
    unordered_set<int> participants;

    while( participants.size() < selectionPressure )
    {
        int y = i4_uniform_ab(0, populationSize - 1, seed);
        bool inserted = participants.insert(y).second;

        //skip to next iteration if it was not inserted
        if(!inserted)   continue;
        if( population[y]->getFitness() > maxFitness){
            maxIndex = y;
            maxFitness = population[y]->getFitness();
        }
    }

    return maxIndex;
}

void Algorithm::reproduction(){

    int one, two;

  
    for(int i = 0; i < populationSize; i++){

        
        one = tournamentSelection();

        //copy it to the new generation
        delete newPopulation[i];
        newPopulation.at(i) = new Schedule( *(population.at(one)) );

    }

    
    for(int j = bestSize; j < populationSize; j += 2){

        
        one     = i4_uniform_ab(0, populationSize - 1, seed);
        two     = i4_uniform_ab(0, populationSize - 1, seed);

        Schedule &schedule1 = *( newPopulation.at(one) );
        Schedule &schedule2 = *( newPopulation.at(two) );

        crossover(schedule1, schedule2, seed);

        
        schedule1.mutation();
        schedule2.mutation();

        
        *( population.at(j) )      = schedule1;
        *( population.at(j+1) )    = schedule2;

    }

   
    calculateFitness();

}

void Algorithm::sortBestAndWorst(){


    
    partial_sort(   population.rbegin(),
                    population.rbegin() + worstSize,
                    population.rend(),
                    compareSchedulesAsc);

    
    {
        int i = 0; auto it = population.rbegin();
        for(; i < worstSize && it != population.rend();
            i++, it++){
            delete *( it );
            *( it ) = new Schedule(
                seed, rooms, courses, teachers, sections, lectures
            );
            (*it)->initialize();
        }

    }

    
    partial_sort(   population.begin(),
                    population.begin() + bestSize,
                    population.end(),
                    compareSchedulesDesc);

    //assign best fitness of the first chromosome
    bestFitness = population.front()->getFitness();

}