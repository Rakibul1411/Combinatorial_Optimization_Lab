#include <stdio.h>
 int numOfJobs;
 struct job{
    char jobName[20];
    int startTime, endTime;
    int compitability;

}jobs[100];
void readInput(){
    scanf("%d", &numOfJobs);
    for(int i=0; i<numOfJobs; ++i)
    {
        scanf(" %d %d %d", jobs[i].jobName, &jobs[i].startTime, &jobs[i].endTime);
        jobs[1].compitability=1;
    }
    for(int i=0; i<numOfJobs; ++i)
    {
        printf(" %d %d %d %d", jobs[i].jobName, jobs[i].startTime, jobs[i].endTime, jobs[i].compitability);

    }

}
int main() {
    //freopen("INPUT.txt", "r", stdin);
    readInput();
}
