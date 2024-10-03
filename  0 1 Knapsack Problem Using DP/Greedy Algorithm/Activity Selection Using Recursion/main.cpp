#include <iostream>

using namespace std;
int numOfJobs;
struct job{
    char jodId[15];
    int startTime;
    int endingTime;
    int compatability;
}jobs[100];
void swapped(struct job *job1, struct job *job2){
    struct job temp = *job1;
    *job1 = *job2;
    *job2 = temp;
}
void bubble_sort(struct job jobs[], int num_jobs) {
    for (int i = 0; i < num_jobs; ++i) {
        for (int j = i+1; j < num_jobs; ++j) {
            if (jobs[i].endingTime > jobs[j].endingTime){
                swapped(&jobs[i], &jobs[j]);
            }
        }
    }
}

void Recurson(int i) {
     int m =i+1;
     while(m <= numOfJobs && jobs[m].startTime < jobs[i].endingTime){
         jobs[m].compatability = 0;
         ++m;
     }
     if(m <= numOfJobs){
         Recurson(m);
     } else{
         return;
     }
}

int main() {
    cout << "Enter the number of jobs: ";
    cin >> numOfJobs;
    printf("Enter the input \n");
    for (int i = 0; i < numOfJobs; ++i) {
        cin >> jobs[i].jodId >> jobs[i].startTime >> jobs[i].endingTime;
        jobs[i].compatability = 1;
    }
    printf("Given input is: \n");
    for (int i = 0; i < numOfJobs; ++i) {
        cout << jobs[i].jodId << " " << jobs[i].startTime << " " << jobs[i].endingTime << " " << jobs[i].compatability
             << endl;
    }

    bubble_sort(jobs, numOfJobs);

    printf("After sorting: \n");
    for (int i = 0; i < numOfJobs; ++i) {
        cout << jobs[i].jodId << " " << jobs[i].startTime << " " << jobs[i].endingTime << " " << jobs[i].compatability
             << endl;
    }

//    for (int i = 0; i < numOfJobs; ++i) {
//        if (jobs[i].compatability != 0) {
//            for (int j = i + 1; j < numOfJobs; ++j) {
//                if (jobs[i].endingTime > jobs[j].startTime) {}
//                jobs[j].compatability = 0;
//            }
//        }
//    }

    Recurson(0);


    printf("Greedy selection is:\n");
    for (int i = 0; i < numOfJobs; ++i) {
        if (jobs[i].compatability == 1) {
            cout << jobs[i].jodId << " " << jobs[i].startTime << " " << jobs[i].endingTime << " "
                 << jobs[i].compatability << endl;
        }
    }
    return 0;

}
