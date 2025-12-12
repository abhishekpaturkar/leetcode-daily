// 3433. Count Mentions Per User

class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {

        // Sort by timestamp, and OFFLINE before MESSAGE when equal
        sort(events.begin(), events.end(),
             [](const vector<string> &a, const vector<string> &b)
             {
                 int t1 = stoi(a[1]);
                 int t2 = stoi(b[1]);

                 if (t1 != t2)
                     return t1 < t2;

                 // Same timestamp → OFFLINE before MESSAGE
                 if (a[0] == "OFFLINE" && b[0] == "MESSAGE")
                     return true;
                 if (a[0] == "MESSAGE" && b[0] == "OFFLINE")
                     return false;

                 return false;
             });

        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        vector<int> backOnlineTime(numberOfUsers, -1);

        for (auto &event : events)
        {
            string type = event[0];
            int timestamp = stoi(event[1]);

            // Update auto-online users first
            for (int i = 0; i < numberOfUsers; i++)
            {
                if (!online[i] && backOnlineTime[i] != -1 && timestamp >= backOnlineTime[i])
                {
                    online[i] = true;
                    backOnlineTime[i] = -1;
                }
            }

            if (type == "OFFLINE")
            {
                int id = stoi(event[2]);
                online[id] = false;
                backOnlineTime[id] = timestamp + 60;
            }
            else
            { // MESSAGE
                string msg = event[2];

                if (msg == "ALL")
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        mentions[i]++;
                    }
                }
                else if (msg == "HERE")
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        if (online[i])
                            mentions[i]++;
                    }
                }
                else
                {
                    // Parse tokens: id0 id1 id2 ...
                    stringstream ss(msg);
                    string tok;

                    while (ss >> tok)
                    {
                        if (tok.rfind("id", 0) == 0)
                        { // starts with "id"
                            int uid = stoi(tok.substr(2));
                            mentions[uid]++; // count duplicates too
                        }
                    }
                }
            }
        }

        return mentions;
    }
};
