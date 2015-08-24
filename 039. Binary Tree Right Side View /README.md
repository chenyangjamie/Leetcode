# Leetcode

第一个思路是广度优先搜索BFS，卡在了想着怎么判断哪个node是每层的最后一个node。反过来思考，每次先push root->right，这样每次第一个node就是需要输出的node。