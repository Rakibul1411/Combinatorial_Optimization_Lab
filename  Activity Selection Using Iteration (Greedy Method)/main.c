#include <stdio.h>
struct job{
    char jobId[15];
    int startTime;
    int endTime;
    int compatility;
}jobs[100];

void bubbleSort(struct job pJob[100], int noOfjobs);

void swap(struct job *pJob, struct job *pJob1);

int main() {
    int numofJobs;
    scanf("%d", &numofJobs);
    for (int i = 0; i < numofJobs; ++i) {
        scanf("%s %d %d %d", &jobs[i].jobId, &jobs[i].startTime, &jobs[i].endTime, &jobs[i].compatility);
    }
    printf("\n\nGiven jobs is: \n");
    for (int i = 0; i < numofJobs; ++i) {
        printf("%s %d %d %d\n", jobs[i].jobId, jobs[i].startTime, jobs[i].endTime, jobs[i].compatility);
    }
    bubbleSort(jobs, numofJobs);
    printf("\n\nAfter sorting based on Ending time: \n");
    for (int i = 0; i < numofJobs; ++i) {
        printf("%s %d %d %d\n", jobs[i].jobId, jobs[i].startTime, jobs[i].endTime, jobs[i].compatility);
    }

    for (int i = 0; i < numofJobs; ++i) {
        if(jobs[i].compatility !=0) {
            for (int j = i+1; j < numofJobs; ++j) {
                if (jobs[i].endTime > jobs[j].startTime) {
                    jobs[j].compatility = 0;
                }
            }
        }
    }

    printf("\n\nGreedy Approaches: \n");
    for (int i = 0; i < numofJobs; ++i) {
        if(jobs[i].compatility==1){
            printf("%s %d %d %d\n", jobs[i].jobId, jobs[i].startTime, jobs[i].endTime, jobs[i].compatility);
        }
    }
    return 0;
}

void swap(struct job *Job1, struct job *Job2) {
    struct job temp = *Job1;
    *Job1 = *Job2;
    *Job2 = temp;
}

void bubbleSort(struct job pJob[], int noOfjobs) {
    for (int i = 0; i < noOfjobs; ++i) {
        for (int j = i+1; j < noOfjobs; ++j) {
            if(pJob[i].endTime > pJob[j].endTime){
                swap(&pJob[i], &pJob[j]);
            }
        }
    }
}


