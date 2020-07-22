/*
Given start and end times of flights, get the maximum numvber of flights
at any point of time

Input 
2       5
4       8
9       18
17      20
18      21

output:
2
Copyright Lokeswara Rao Bonta - 2020
DS & Algo - Heap Section
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> flight_type;
    int maxNumOfFlights(vector<flight_type> &flight_times)
    {
        auto compare = [](flight_type flight1,
                          flight_type flight2) { return flight1.second > flight2.second; };
        int max_flights = 0; // maximum flights in air right now.
        sort(flight_times.begin(), flight_times.end(), [](flight_type pair1, flight_type pair2) { return (pair2.first > pair1.first); });
        priority_queue<flight_type, vector<flight_type>, decltype(compare)> pq(compare);
        for (auto flight : flight_times)
        {
            while (!pq.empty() && pq.top().second <= flight.first)
                pq.pop();
            pq.push(flight);
            max_flights = max(max_flights, (int)pq.size());
        }
        return max_flights;
    }
};

int main()
{
    vector<Solution::flight_type> flights;
    flights.push_back(make_pair(4, 8));
    flights.push_back(make_pair(2, 5));
    flights.push_back(make_pair(17, 20));
    flights.push_back(make_pair(18, 21));
    flights.push_back(make_pair(9, 18));
    Solution S;
    cout << S.maxNumOfFlights(flights) << endl;
}