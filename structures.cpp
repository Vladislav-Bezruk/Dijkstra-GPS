struct PATH {
	int len;
	int cur;
	
	int* path;
	
	PATH() {
	
	}
	
	PATH(int a) {
		len = a;
		
		cur = 0;
		
		path = new int[len];
		
		clear();
	}
	
	void fill(int n) {
		for (int i = 0; i < len; i++) {
			path[i] = n;
		}
	}
	
	void clear() {
		cur = 0;
		fill(0);	
	}
	
	void add(int n) {
		cur++;
		
		if (cur <= len) {
			path[cur - 1] = n;
		} else {
	
		int* newPath = new int[n + 1];
		
		newPath = path;
		newPath[cur - 1] = n;
		path = newPath;	
		
		len++;	
		}	
	}
	
	void print() {
		for (int i = 0; i < len; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	
	int find(int n) {
		for (int i = 0; i < cur; i++) {
			if (n == path[i]) {
				return i;
			}
		}
		return -1;	
	}
	
	bool isThere(int n) {
		if (find(n) != -1) {
			return true;
		}
		return false;
	}
};

struct PATH_ARR {
	int n;
	
	PATH* paths;
	
	PATH_ARR() {
		
	}
	
	PATH_ARR(int a, int l) {
		n = a;	
		
		paths = new PATH[n];
		
		for (int i = 0; i < n; i++) {
			paths[i] = PATH(l);
		}	
	}
	
	void print(char c) {
		printf("PATH_ARR %c:\n", c);
		
		for (int i = 0; i < n; i++) {
			printf("i = %d: ", i);
			
			for (int j = 0; j < paths[i].cur; j++) {
				printf("%d ", paths[i].path[j]);
			}
			
			printf("\n\n");
		}	
	
		printf("\n");
		
	}
};

struct GRAPH {
	int size;
	
	int** value;
	
	GRAPH(int a) {
		size = a;
		
		value = new int* [size];
		
		for (int i = 0; i < size; i++) {
			value[i] = new int[size];
		}
	}
	
	void print() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				printf("%d ", value[i][j]);
			}	
			printf("\n");
		}	
		
	}	
};
