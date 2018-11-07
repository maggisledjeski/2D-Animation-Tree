#include "includes.h"
#include "prototypes.h"
#include "structs.h"

/*calculates the intersection of the polygon edge from vertex s to vertex p with clipBoundary
 * clipBoundary defined by two vertices, creating an edge*/
void Intersect(vertex first, vertex second, vertex *clipBoundary, vertex *intersectPt)
{
	if(clipBoundary[0].y == clipBoundary[1].y) {		/*horizontal*/
		intersectPt->y = clipBoundary[0].y;
		intersectPt->x = first.x + (clipBoundary[0].y - first.y) *
			(second.x - first.x) / (second.y - first.y);
	} else {							/*vertical*/
		intersectPt->x = clipBoundary[0].x;
		intersectPt->y = first.y + (clipBoundary[0].x - first.x) *
			(second.y - first.y) / (second.x - first.x);
	}
}

/*returns TRUE if the vertex is on the inside of the clip boundary, where "inside" is defined as 
 * "to the left of the clip boundary when one looks from the first vertex to the second vertex
 * of the clip boundary"*/
bool Inside(vertex testVertex, vertex *clipBoundary)
{
	if (clipBoundary[1].x > clipBoundary[0].x)	/*bottom*/
		if (testVertex.y >= clipBoundary[0].y)
			return true;
	if (clipBoundary[1].x < clipBoundary[0].x)	/*top*/
		if (testVertex.y <= clipBoundary[0].y)
			return true;
	if (clipBoundary[1].y > clipBoundary[0].y)	/*right*/
		if (testVertex.x <= clipBoundary[1].x)
			return true;
	if (clipBoundary[1].y < clipBoundary[0].y)	/*left*/
		if (testVertex.x >= clipBoundary[1].x)
			return true;
	return false;
}

/*this function is used to place the new vertex into the outVertexArray*/
void Output(vertex newVertex, int *outLength, vertex *outVertexArray)
{
	(*outLength)++;
	outVertexArray[*outLength - 1].x = newVertex.x;
	outVertexArray[*outLength - 1].y = newVertex.y;
}

/*takes in array inVertexArray, and creates outVertexArray/new polygon that has been clipped*/ 
/*s is the start of the edge, p is the end of the edge*/
void shClip(vertex *inVertexArray, vertex *outVertexArray, int inLength, int *outLength, vertex *clip_boundary)
{
	vertex s, p, i;
	int j;
	cout << "sh1" << endl;
	*outLength = 0;
	cout << "sh2" << endl;
	s = inVertexArray[inLength - 1];	/* Start with the last vertex in inVertexArray */
	for (j = 0; j < inLength; j++) {
		cout << "sh3" << endl;
		p = inVertexArray[j];	/* Now s and p correspond to the vertices in Fig.3.33 */
		cout << "sh4" << endl;
		if (Inside(p, clip_boundary)) {	/* Cases 1 and 4 */
			cout << "sh5" << endl;
			if (Inside(s, clip_boundary)){
				cout << "sh6" << endl;
				Output(p, outLength, outVertexArray);	/* Case 1 */
				cout << "sh7" << endl;
			}else {						/* Case 4 */
				Intersect(s, p, clip_boundary, &i);
				Output(i, outLength, outVertexArray);
				Output(p, outLength, outVertexArray);
			}
		} else if(Inside(s, clip_boundary)) {			/* Cases 2 and 3 */
			Intersect(s, p, clip_boundary, &i);		/* Case 2 */
			Output(i, outLength, outVertexArray);
		}							/* No action for case 3 */
		s = p;					/* Advance to next pair of vertices */
	}
}

void Clip(vertex *inArray, vertex *outArray)
{
	/*bring in or create place for the arrays that will be changed*/
	extern int *outputLength;
	int startNum = 5;
	
	struct vertex *bb = (struct vertex *) malloc((2)*sizeof(struct vertex));
	vertex bbs, bbe;
	bbs.x = 100;
	bbs.y = 100;
	*(bb + 0 ) = bbs;
	bbe.x = 900;
	bbe.y = 900;
	*(bb + 1) = bbe;
	cout << "start" << endl;
	/*bottom clip
 	* shClip(inputArray, outputArray, clipBoundary)	*/
	shClip(inArray, outArray, startNum, outputLength, bb);
	cout << "end" << endl;
	/*right clip
 	* shClip(outputArray, inputArray, clipBoundary)	*/
	//shClip();
	/*top clip
 	* shClip(inputArray, outputArray, clipBoundary) */
	//shClip();
	/*left clip
 	* shClip(outputArray, inputArray, clipBoundary) */
	//shClip();
	glutPostRedisplay();

}

