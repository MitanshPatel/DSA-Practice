// You are given n activities with their start and finish times.
// Select the maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time. 

// Examples:  
// Input: start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
// Output: 0 1 3 4
// Explanation: A person can perform at most four activities. The 
// maximum set of activities that can be executed 
// is {0, 1, 3, 4} [ These are indexes in start[] and finish[]


#include <bits/stdc++.h>
using namespace std;

// A job has a start time, finish time and profit.
struct Activitiy {
	int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
	return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activitiy arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr + n, activityCompare);

	cout << "Following activities are selected :\n";

	// The first activity always gets selected
	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish
		<< ")";

	// Consider rest of the activities
	for (int j = 1; j < n; j++) {
		// If this activity has start time greater than or
		// equal to the finish time of previously selected
		// activity, then select it
		if (arr[j].start >= arr[i].finish) {
			cout << ", (" << arr[j].start << ", "
				<< arr[j].finish << ")";
			i = j;
		}
	}
}

// Driver code
int main()
{
	Activitiy arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
						{ 0, 6 }, { 5, 7 }, { 8, 9 } };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printMaxActivities(arr, n);
	return 0;
}
