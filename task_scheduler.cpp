#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Task {
 string id;
 int priority;
 int burst;
 int remaining;
 int waiting;
};
bool comparePriority(Task a, Task b) {
 return a.priority < b.priority;
}
void applyAging(vector<Task>& tasks, int currentIndex) {
 for (int i = 0; i < tasks.size(); i++) {
 if (i != currentIndex && tasks[i].remaining > 0) {
 tasks[i].waiting++;
 if (tasks[i].waiting >= 4 && tasks[i].priority > 0) {
 tasks[i].priority--; // Improve priority
 tasks[i].waiting = 0;
 }
 }
 }
}
int main() {
 vector<Task> tasks = {
 {"A", 1, 5, 5, 0},
 {"B", 4, 3, 3, 0},
 {"C", 3, 4, 4, 0}
 };
int time = 0;
 int timeSlice = 2;
 cout << "Execution Order:\n";
 while (true) {
 bool done = true;
 for (auto &t : tasks) {
 if (t.remaining > 0) done = false;
 }
 if (done) break;
 sort(tasks.begin(), tasks.end(), comparePriority);
 for (int i = 0; i < tasks.size(); i++) {
 if (tasks[i].remaining > 0) {
 int runTime = min(timeSlice, tasks[i].remaining);
 cout << "Task " << tasks[i].id << " runs from "
 << time << " to " << time + runTime << endl;
 time += runTime;
 tasks[i].remaining -= runTime;
 tasks[i].waiting = 0;
 applyAging(tasks, i);
break;
 }
 }
 }
return 0;
}
