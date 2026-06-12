#include <bits/stdc++.h>
using namespace std;

struct User {
    string name;
    int budget;
    int energy;
    set<string> tags;
    bool active = true;
};

struct Activity {
    int id;
    string name;
    int cost;
    int duration;
    int energy;
    string tag;
};

struct Input {
    int N, D, H;
    vector<User> users;
    map<int, Activity> activities;
    vector<string> events;
};

static Input readInput() {
    Input in;
    cin >> in.N >> in.D >> in.H;
    in.users.resize(in.N);
    for (int i = 0; i < in.N; i++) {
        int k;
        cin >> in.users[i].name >> in.users[i].budget >> in.users[i].energy >> k;
        for (int j = 0; j < k; j++) {
            string t; cin >> t;
            in.users[i].tags.insert(t);
        }
        in.users[i].active = true;
    }
    int A; cin >> A;
    for (int i = 0; i < A; i++) {
        Activity a;
        cin >> a.id >> a.name >> a.cost >> a.duration >> a.energy >> a.tag;
        in.activities[a.id] = a;
    }
    int E; cin >> E;
    cin.ignore();
    for (int i = 0; i < E; i++) {
        string line;
        getline(cin, line);
        while (!line.empty() && (line.back() == '\r' || line.back() == ' ')) line.pop_back();
        in.events.push_back(line);
    }
    return in;
}

static string formatDay(int day, vector<int> ids, int cost, int sat) {
    if (ids.empty()) {
        return "Day " + to_string(day) + ": REST | cost=0 satisfaction=0";
    }
    sort(ids.begin(), ids.end());
    string s = "Day " + to_string(day) + ": ";
    for (size_t i = 0; i < ids.size(); i++) {
        if (i) s += ' ';
        s += to_string(ids[i]);
    }
    s += " | cost=" + to_string(cost) + " satisfaction=" + to_string(sat);
    return s;
}

struct ParsedEvent {
    string type;
    int day;
    string target;
    int val;
};

static ParsedEvent parseEventLine(const string& line) {
    stringstream ss(line);
    ParsedEvent ev;
    ss >> ev.type >> ev.day >> ev.target;
    ev.val = 0;
    if (ev.type == "FATIGUE" || ev.type == "BUDGET") {
        ss >> ev.val;
    }
    return ev;
}

static string solve(Input in) {
    string out;
    
    vector<vector<User>> state_users(in.D + 1, in.users);
    vector<set<string>> state_weather(in.D + 1);
    
    vector<vector<int>> actual_plan(in.D + 1);
    vector<int> actual_cost(in.D + 1, 0);
    vector<int> actual_sat(in.D + 1, 0);

    auto computeDayPlan = [&](int day, const set<int>& consumed_ids) -> tuple<vector<int>, int, int> {
        int min_budget = 2e9;
        int min_energy = 2e9;
        bool anyone_active = false;

        for (const auto& u : state_users[day]) {
            if (u.active) {
                anyone_active = true;
                if (u.budget < min_budget) min_budget = u.budget;
                if (u.energy < min_energy) min_energy = u.energy;
            }
        }

        if (!anyone_active) {
            return {vector<int>(), 0, 0};
        }

        vector<Activity> eligible;
        for (const auto& pair : in.activities) {
            const auto& act = pair.second;
            if (consumed_ids.count(act.id) == 0 && state_weather[day].count(act.tag) == 0) {
                eligible.push_back(act);
            }
        }

        vector<int> best_ids;
        int best_cost = 0;
        int best_sat = 0;

        int M = eligible.size();
        if (M > 20) M = 20;

        for (int mask = 1; mask < (1 << M); ++mask) {
            int current_cost = 0;
            int current_energy = 0;
            int current_duration = 0;
            vector<int> current_ids;

            for (int i = 0; i < M; ++i) {
                if ((mask >> i) & 1) {
                    current_cost += eligible[i].cost;
                    current_energy += eligible[i].energy;
                    current_duration += eligible[i].duration;
                    current_ids.push_back(eligible[i].id);
                }
            }

            if (current_duration > in.H || current_cost > min_budget || current_energy > min_energy) {
                continue;
            }

            int current_sat = 0;
            for (int id : current_ids) {
                const string& tag = in.activities[id].tag;
                for (const auto& u : state_users[day]) {
                    if (u.active && u.tags.count(tag)) {
                        current_sat++;
                    }
                }
            }

            sort(current_ids.begin(), current_ids.end());

            bool replace = false;
            if (best_ids.empty() && best_cost == 0 && best_sat == 0) {
                replace = true;
            } else if (current_sat != best_sat) {
                replace = (current_sat > best_sat);
            } else if (current_cost != best_cost) {
                replace = (current_cost < best_cost);
            } else {
                replace = (current_ids < best_ids);
            }

            if (replace) {
                best_ids = current_ids;
                best_cost = current_cost;
                best_sat = current_sat;
            }
        }

        return {best_ids, best_cost, best_sat};
    };

    auto runPlanningFrom = [&](int start_day) {
        set<int> consumed_ids;
        for (int d = 1; d < start_day; ++d) {
            for (int id : actual_plan[d]) {
                consumed_ids.insert(id);
            }
        }

        for (int d = start_day; d <= in.D; ++d) {
            auto [ids, cost, sat] = computeDayPlan(d, consumed_ids);
            actual_plan[d] = ids;
            actual_cost[d] = cost;
            actual_sat[d] = sat;

            for (int id : ids) {
                consumed_ids.insert(id);
            }
        }
    };

    runPlanningFrom(1);
    out += "=== PLAN ===\n";
    for (int day = 1; day <= in.D; day++) {
        out += formatDay(day, actual_plan[day], actual_cost[day], actual_sat[day]) + "\n";
    }

    for (size_t idx = 0; idx < in.events.size(); ++idx) {
        string event_line = in.events[idx];
        if (event_line.empty()) continue;
        
        ParsedEvent ev = parseEventLine(event_line);
        out += "=== EVENT " + to_string(idx + 1) + ": " + event_line + " ===\n";

        for (int d = ev.day; d <= in.D; ++d) {
            if (ev.type == "WEATHER") {
                state_weather[d].insert(ev.target);
            } else {
                for (auto& u : state_users[d]) {
                    if (u.name == ev.target) {
                        if (ev.type == "DROP")     u.active = false;
                        if (ev.type == "FATIGUE")  u.energy = ev.val;
                        if (ev.type == "BUDGET")   u.budget = ev.val;
                    }
                }
            }
        }

        runPlanningFrom(ev.day);

        for (int d = ev.day; d <= in.D; ++d) {
            out += formatDay(d, actual_plan[d], actual_cost[d], actual_sat[d]) + "\n";
        }
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Input in = readInput();
    cout << solve(in);
    return 0;
}
