void printArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void fillArr(int arr[], int size, int num) {
	for (int i = 0; i < size; i++) {
		arr[i] = num;
	}
}

int findMin(int arr[], int size, int cond[]) {
	int iMin = -1;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0 && cond[i] == 0) {
			if (iMin == -1 || arr[iMin] > arr[i]) {
				iMin = i;
			}		
		}
	}
	
	return iMin;
}

void fillMin(GRAPH graph, int arr[], int A, int size, int cond[], PATH_ARR from) {
	
	for (int i = 0; i < size; i++) {
		if (cond[i] == false && i != A) {
			if (graph.value[A][i] > 0) {
				if (from.paths[i].cur == 0) {
					
					if (from.paths[i].isThere(A) == false) {
						from.paths[i].add(A);
					}
					
					arr[i] = graph.value[A][i] + arr[A] * (arr[A] > 0);
				} else if (arr[i] == (graph.value[A][i] + arr[A] * (arr[A] > 0))) {
					if (from.paths[i].isThere(A) == false) {
						from.paths[i].add(A);
					}
				} else if (arr[i] > (graph.value[A][i] + arr[A] * (arr[A] > 0))) {
					from.paths[i].cur = 0;
					from.paths[i].fill(-1);
					
					from.paths[i].add(A);
					
					arr[i] = graph.value[A][i] + arr[A] * (arr[A] > 0);
				}	
			} 
		}	
	}
}

bool canGet(PATH_ARR from, int A, int B) {
	if (from.paths[B].cur == 0) {
		return false;
	}
	return true;
}

int countPaths(PATH_ARR from, int A, int B) {
	if (A == B) {
		return 1;		
	}
	
	int count = canGet(from, A, B);
	
	if (count == 0) {
		return count;
	}
	
	count *= from.paths[B].cur;
	
	for (int i = 0; i < from.paths[B].cur; i++) {
		count *= countPaths(from, A, from.paths[B].path[i]);
	}
		
	return count;
}

bool isEVertex(int size, int A) {
	if (A >= size || A < 0) {
		return false;
	}
	return true;
}

PATH_ARR findWays(GRAPH graph, int A, int B) {
	
	if (isEVertex(graph.size, A) == false || isEVertex(graph.size, B) == false) {
		PATH_ARR paths(0, 0);
			
		return paths;
	}
	
	int cur = A;
	
	int flag = 1;
	
	int vis[graph.size] = { 0 };

	int dist[graph.size];
	
	fillArr(dist, graph.size, -1);
	
	PATH_ARR from(graph.size, graph.size);
	
	//fillMin(GRAPH graph, int arr[], int A, int size, bool cond[], PATH_ARR from)
	
	//fillMin(graph, dist, 0, graph.size, vis, from);
	
	//int i = 0;
		
	do {
		vis[cur] = 1;
		
		fillMin(graph, dist, cur, graph.size, vis, from);
		
		//printf("dist:\n");
		
		//printArr(dist, graph.size);
		
		cur = findMin(dist, graph.size, vis);
		
		if (cur == -1) {
			break;
			
			flag = 0;
		}
		
		//printf("i = %d, cur = %d\n", i, cur);
		
		//printf("vis:\n");
		
		//printArr(vis, graph.size);
		
		//printf("\n\n\n");	
		
		//i++;
	} while (cur != B);
	
	//from.print();
	
	//printf("count ways = %d\n", countPaths(from, A, B));
	
	if (flag == 0) {
		PATH_ARR paths(0, 0);
			
		return paths;
	} else {
		return from;
	}
}

PATH_ARR findWaysCond(GRAPH graph, PATH cond) {
	PATH_ARR* paths;
	
	int get = 1;
	
	paths = new PATH_ARR[cond.len - 1];
	
	for (int i = 0; i < cond.len - 1; i++) {
		paths[i] = PATH_ARR(graph.size, graph.size);
	}
	
	int A = cond.path[0], B;
	
	for (int i = 1; i < cond.len; i++) {
		B = cond.path[i];
		
		paths[i - 1] = findWays(graph, A, B);
		
		get *= canGet(paths[i - 1], A, B);
		
		A = cond.path[i];
	}
	
	printf("get = %d\n", get);
}
	

