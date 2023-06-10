#include<bits/stdc++.h>
using namespace std;

struct Event {
    int time;
    bool isArrival;
};

int getMaxPersonsAtTime(vector<Event>& events) {
    int maxPersons = 0;
    int currentPersons = 0;

    for (const auto& event : events) {
        if (event.isArrival) {
            currentPersons++;
            maxPersons = max(maxPersons, currentPersons);
        } else {
            currentPersons--;
        }
    }

    return maxPersons;
}

int main() {
    int n;
    //cout << "Enter the number of persons: ";
    cin >> n;
    vector<Event> events;
    //cout << "Enter the arrival and departure times for each person:\n";
    for (int i = 0; i < n; i++) {
        int arrival, departure;
        //cout << "Person " << (i + 1) << ":\n";
        //cout << "  Arrival time: ";
        cin >> arrival;
        //cout << "  Departure time: ";
        cin >> departure;

        events.push_back({arrival, true});
        events.push_back({departure, false});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {return a.time < b.time;});

    int maxPersons = getMaxPersonsAtTime(events);
    cout<< maxPersons <<endl;
    return 0;
}

