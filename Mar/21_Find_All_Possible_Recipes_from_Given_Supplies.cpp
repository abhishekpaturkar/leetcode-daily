// 2115. Find All Possible Recipes from Given Supplies

// Kahn’s algorithm (BFS-based Topological Sorting)

// You are given three lists:

// recipes: A list of strings where each element represents the name of a recipe.
// ingredients: A list of lists, where ingredients[i] contains the list of ingredients required to make recipes[i].
// supplies: A list of strings representing the ingredients that are initially available.

// Objective:
// Find all the recipes that can be prepared using the given ingredients and initial supplies. A recipe can be prepared if all its required ingredients are either:
// Directly available in the supplies list, or
// Another recipe that can be prepared using available ingredients.

// Constraints:
// Each recipe can depend on multiple ingredients.
// Some ingredients may themselves be recipes.
// The dependencies between recipes form a directed graph.
// If a recipe depends on itself (directly or indirectly), it cannot be prepared.

// Return Value:
// Return a list of all possible recipes that can be prepared.
// The result should not contain duplicates.
// The order of recipes in the output does not matter.

// Example

// Input:
// recipes = ["bread", "sandwich", "burger"]
// ingredients = [["flour", "water"], ["bread", "ham"], ["bread", "lettuce", "cheese"]]
// supplies = ["flour", "water", "ham", "lettuce", "cheese"]

// Output:
// ["bread", "sandwich", "burger"]

// Explanation:
// "bread" can be made since its ingredients "flour" and "water" are available.
// "sandwich" can be made because "bread" (which can now be made) and "ham" are available.
// "burger" can be made since "bread", "lettuce", and "cheese" are all available

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<string>> adj;
            unordered_map<string, int> indegree;
            unordered_set<string> supply(supplies.begin(), supplies.end());
    
            for (int i = 0; i < recipes.size(); ++i) {
                indegree[recipes[i]] = 0;
                for (string& ingredient : ingredients[i]) {
                    if (supply.count(ingredient) == 0) {
                        adj[ingredient].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    }
                }
            }
    
            queue<string> q;
            for (auto& [recipe, indeg] : indegree) {
                if (indeg == 0) {
                    q.push(recipe);
                }
            }
    
            vector<string> res;
            while (!q.empty()) {
                string curr_recipe = q.front();
                q.pop();
                res.push_back(curr_recipe);
    
                for (string& next_recipe : adj[curr_recipe]) {
                    indegree[next_recipe]--;
                    if (indegree[next_recipe] == 0) {
                        q.push(next_recipe);
                    }
                }
            }
    
            return res;
        }
    };
    