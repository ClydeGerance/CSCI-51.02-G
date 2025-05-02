#include<bits/stdc++.h>

using namespace std;

using iii = tuple<int,int,int>;
using ii = pair<int,int>;

#define ARRIVAL  0
#define BURST    1
#define PRIORITY 2

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << t << endl;
        int N, Q; string S; cin >> N >> S;
        vector<iii> process(N);

        if (S == "RR")
            cin >> Q;
        
        map<int,vector<int>> timeline;

        for (int i = 0; i < N; i++) {
            auto& [arrival, burst, priority] = process[i];
            cin >> arrival >> burst >> priority;
            timeline[arrival].push_back(i);
        }
        

        if (S == "FCFS") {
            int time = 0;
            for (auto [arrival, ids] : timeline) {
                time = max(time, arrival);
                for (int id : ids) {
                    int burst = get<BURST>(process[id]);
                    cout << time << " " << id+1 << " " << burst << "X" << endl;
                    time += burst;
                }
            }

        } else if (S == "SJF") {
            set<ii> job_queue;
            int time = 0;
            
            for (auto it = timeline.begin(); it != timeline.end(); it++) {
                auto [arrival, ids] = *it;
                time = max(time, arrival);
                int next_arrival = next(it) != timeline.end() ? next(it)->first : -1;
                
                for (int id : ids) {
                    int burst = get<BURST>(process[id]);
                    job_queue.insert({burst, id});
                }

                while (job_queue.size() > 0) {
                    if (next_arrival != -1 and time >= next_arrival) // if a new job arrives, break
                        break;
                    
                    auto [burst, id] = *(job_queue.begin());
                    cout << time << " " << id+1 << " " << burst << "X" << endl;
                    time += burst;
                    job_queue.erase(job_queue.begin());
                }
            }
                    
        } else if (S == "SRTF") {
            set<ii> job_queue;
            int time = 0;
            
            for (auto it = timeline.begin(); it != timeline.end(); it++) {
                auto [arrival, ids] = *it;
                time = max(time, arrival);
                int next_arrival = next(it) != timeline.end() ? next(it)->first : -1;
                
                for (int id : ids) {
                    int burst = get<BURST>(process[id]);
                    job_queue.insert({burst, id});
                }

                while (job_queue.size() > 0) {
                    if (next_arrival != -1 and time >= next_arrival) // if a new job arrives, break
                        break;
                    
                    auto [remaining_time, id] = *(job_queue.begin());
                    cout << time << " " << id+1 << " " << burst << "X" << endl;
                    time += burst;
                    job_queue.erase(job_queue.begin());
                }
            }

        } else if (S == "P") {

        } else if (S == "RR") {

        } else {
            cerr << "Please enter a valid scheduling algorithm." << endl;
            return 0;
        }

    }



    return 0;
}