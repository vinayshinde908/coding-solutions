#include <bits/stdc++.h>
using namespace std; 
typedef struct node {
    node *children[26];
    bool isLeaf;
}node;
 
node *getNode(void) {
    node *pNode = NULL;
    pNode = (node *)malloc(sizeof(node));
    if (pNode) {
        pNode->isLeaf = false;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}
 
void insert(node *root, const char *key) {
    int level, length = strlen(key), index;
    node *temp = root;
    for (level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!temp->children[index])
            temp->children[index] = getNode();
 
        temp = temp->children[index];
    }
    temp->isLeaf = true;
}
 
void search(node *root, const char *key, char *str) {
    int i, length = strlen(key), index;
    node *temp = root;
    for (i = 0; i < length; i++) {
        index = key[i] - 'a';
		if(temp->children[index])
			str[i] = 'a' + index;
        else {
			str[i] = 'a' + index;
			break;
		}
        temp = temp->children[index];
    }
	if(i == length) str[0] = '\0';
	else str[i+1] = '\0';
	return;
}
 
int main() {
	int n;
	char c, s[200005], p[200005];
	vector<string> negs;
	set<string> ans;
	set<string>::iterator it;
	string str;
    node *root = getNode();
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf(" %c%s", &c, s);
		str = s;
		if(c == '+') insert(root, s);
		if(c == '-') negs.push_back(str);
	}
	for(int i = 0; i < negs.size(); i++) {
		search(root, negs[i].c_str(), p);
		str = p;
		ans.insert(str);
		if(str.size() == 0) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%lu\n", ans.size());
	for(it = ans.begin(); it != ans.end(); it++) 
		printf("%s\n",(*it).c_str());
    return 0;
}
