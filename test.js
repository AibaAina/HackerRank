// paths from a source to
// destination.
 
let v;
let adjList;
 
// A directed graph using
// adjacency list representation
function Graph(vertices) {
	// initialise vertex count
	v = vertices;

	// initialise adjacency list
	initAdjList();
}
 
// utility method to initialise
// adjacency list
function initAdjList() {
	adjList = new Array(v);

	for (let i = 0; i < v; i++) {
		adjList[i] = [];
	}
}
 
// add edge from u to v
function addEdge(u,v) {
	// Add v to u's list.
	adjList[u].push(v);
}
 
// Prints all paths from
// 's' to 'd'
function printAllPaths(s,d) {
	let isVisited = new Array(v);
	for( let i=0 ; i<v ; i++) 
		isVisited[i]=false;
	let pathList = [];

	// add source to path[]
	pathList.push(s);

	// Call recursive utility
	printAllPathsUtil(s, d, isVisited, pathList);
}
 
// A recursive function to print
// all paths from 'u' to 'd'.
// isVisited[] keeps track of
// vertices in current path.
// localPathList<> stores actual
// vertices in the current path
function printAllPathsUtil(u,d,isVisited,localPathList) {
	if (u == (d)) {
		parsingOutput(localPathList);
		// document.write(localPathList + '<br>');
		// console.log(localPathList);
		// if match found then no need to
		// traverse more till depth
		return;
	}

	// Mark the current node
	isVisited[u] = true;

	// Recur for all the vertices
	// adjacent to current vertex
	for (let i=0;i< adjList[u].length;i++) {
		if (!isVisited[adjList[u][i]]) {
			// store current node
			// in path[]
			localPathList.push(adjList[u][i]);
			printAllPathsUtil(adjList[u][i], d, isVisited, localPathList);

			// remove current node
			// in path[]
			localPathList.splice(localPathList.indexOf(adjList[u][i]),1);
		}
	}

	// Mark the current node
	isVisited[u] = false;
}

function parsingOutput(localPathList) {
	document.write("P" + localPathList[0]);
	for (let i=1 ; i<localPathList.length ; i++) {
		document.write("_P" + localPathList[i]);
	}
	document.write("<br>");
}

// Driver program
// Create a sample graph
Graph(4);
// addEdge(0, 1);
// addEdge(0, 2);
// addEdge(0, 3);
// addEdge(2, 0);
// addEdge(2, 1);
// addEdge(1, 3);
 
adjList[0] = [];
adjList[1] = [2,3,7];
adjList[2] = [1,3];
adjList[3] = [1,2,4,7];
adjList[4] = [3,5,6];
adjList[5] = [4,6,8];
adjList[6] = [4,5,8];
adjList[7] = [1,3];
adjList[8] = [5,6];

// adjList[0] = [];
// adjList[1] = ['P2','P3','P7'];
// adjList[2] = ['P1','P3'];
// adjList[3] = ['P1','P2','P4','P7'];
// adjList[4] = ['P3','P5','P6'];
// adjList[5] = ['P4','P6','P8'];
// adjList[6] = ['P4','P5','P8'];
// adjList[7] = ['P1','P3'];
// adjList[8] = ['P5','P6'];
 
console.log(adjList)
 
// arbitrary source
// let s = 1;
 
// arbitrary destination
// let d = 8;
 
// console.log(s + " to " + d);
// document.write("Following are all different paths from "+ s + " to " + d);
// printAllPaths(s, d);

for ( let i=1 ; i<9 ; i++ ) {
	for ( let j=i+1 ; j<9 ; j++) {
		let s=i;
		let d=j;
		console.log(s + " to " + d);
		document.write("<br>" + s + " to " + d + "<br>");
		printAllPaths(s, d);
	}
}
