class Router {
public:
    deque<vector<int>> packets;
    unordered_set<string> seen;
    unordered_map<int, deque<int>> destAndTimestamps;
    string createKey(int src, int dest, int timestamp) {
        return to_string(src)+"#"+to_string(dest)+"#"+to_string(timestamp);
    }

    int memLimit;
    Router(int memoryLimit) { this->memLimit = memoryLimit; }
    bool addPacket(int source, int destination, int timestamp) {
        string key = createKey(source, destination, timestamp);
        if (seen.count(key)) {
            return false;
        }
        if (packets.size() == memLimit) {
            auto& pkt = packets.front();
            string oldKey = createKey(pkt[0], pkt[1], pkt[2]);
            seen.erase(oldKey);
            auto& timestamps = destAndTimestamps[pkt[1]];
            auto it = lower_bound(timestamps.begin(), timestamps.end(), pkt[2]);
            if (it != timestamps.end() && *it == pkt[2]) {
                timestamps.erase(it);
            }
            packets.pop_front();
        }
        packets.push_back({source, destination, timestamp});
        seen.insert(key);
        auto& timestamps = destAndTimestamps[destination];
        timestamps.insert(
            upper_bound(timestamps.begin(), timestamps.end(), timestamp),
            timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty())
            return {};
        auto pkt = packets.front();
        string key = createKey(pkt[0], pkt[1], pkt[2]);
        seen.erase(key);
        auto& timestamps = destAndTimestamps[pkt[1]];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), pkt[2]);
        if (it != timestamps.end() && *it == pkt[2]) {
            timestamps.erase(it);
        }
        packets.pop_front();
        return pkt;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& timestamps = destAndTimestamps[destination];
        auto left = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto right = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return distance(left, right);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
