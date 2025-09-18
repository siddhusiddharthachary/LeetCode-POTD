class TaskManager {
public:
    unordered_map<int,int> taskForUser;
    unordered_map<int,int> taskPriority;
    priority_queue<tuple<int,int,int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task:tasks){
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskForUser[taskId] = userId;
        taskPriority[taskId] = priority;
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskForUser[taskId];
        taskPriority[taskId] = newPriority;
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        taskForUser.erase(taskId);
        taskPriority.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId, userId] = pq.top();
            pq.pop();
            if(taskPriority.find(taskId)!=taskPriority.end() && taskPriority[taskId]==priority){
                rmv(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
