/* Complexity
 *   Time: O(n)
 *   Space: O(n)
 */

class Solution {
public:
    string simplifyPath(string path) {
        list<string> path_list;
        string result;

        for (int begin = 0, end = 0; end <= path.size(); ++end) {
            if (end == path.size() || path[end] == '/' && begin < end) {
                string token = path.substr(begin + 1, end - begin - 1);

                if (token == "..") {
                    if (!path_list.empty()) path_list.pop_back();
                } else if (token != "" && token != ".") path_list.push_back(token);

                begin = end;
            }
        }

        for (string& p: path_list) result += "/" + p;
        if (result == "") result = "/";

        return result;
    }
};
