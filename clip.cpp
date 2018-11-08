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
    printf("In Output with outLength = %i\n", *outLength);
	(*outLength)++;
    printf("In Output with outLength = %i\n", *outLength);
    printf("  In Output newVertex.x = %f\n", newVertex.x);
    printf("  In Output newVertex.y = %f\n", newVertex.y);

    printf("  Index is = %i\n", *outLength - 1);
    
	outVertexArray[*outLength - 1].x = newVertex.x;
	outVertexArray[*outLength - 1].y = newVertex.y;
}

/*takes in array inVertexArray, and creates outVertexArray/new polygon that has been clipped*/ 
/*s is the start of the edge, p is the end of the edge*/
void shClip(vertex *inVertexArray, vertex *outVertexArray, int inLength, int *outLength, vertex *clip_boundary)
{
	vertex s, vp, i;
	int j;
	cout << "sh1 in: " << inLength << " " << endl; //*outLength << endl;
	cout << "sh1 out: " << *outLength << " " << endl; //*outLength << endl;
	cout << "sh2" << endl;
    
	s = inVertexArray[inLength - 1];	/* Start with the last vertex in inVertexArray */
	for (j = 0; j < inLength; j++) {
		cout << "sh3" << endl;
		vp = inVertexArray[j];	/* Now s and p correspond to the vertices in Fig.3.33 */
		cout << "sh4" << endl;
		if (Inside(vp, clip_boundary)) {	/* Cases 1 and 4 */
			cout << "sh5" << endl;
			if (Inside(s, clip_boundary)){
				cout << "sh6" << endl;
                cout << vp.x << endl;
                cout << vp.y << endl;
				Output(vp, outLength, outVertexArray);	/* Case 1 */
				cout << "sh7" << endl;
			}else {						/* Case 4 */
				Intersect(s, vp, clip_boundary, &i);
				Output(i, outLength, outVertexArray);
				Output(vp, outLength, outVertexArray);
			}
		} else if(Inside(s, clip_boundary)) {			/* Cases 2 and 3 */
			Intersect(s, vp, clip_boundary, &i);		/* Case 2 */
			Output(i, outLength, outVertexArray);
		}							/* No action for case 3 */
		s = vp;					/* Advance to next pair of vertices */
	}
}

void Clip(vertex *inArray, vertex *outArray)
{
    int inputLength;
	extern int p;
	int outputLength = p;
	cout << " Size of P is " << p << endl;
	vertex *bb = (vertex *) malloc((2)*sizeof( vertex));
	vertex bbs, bbe;
	bbs.x = 100;
	bbs.y = 100;
	*(bb + 0) = bbs;
	bbe.x = 900;
	bbe.y = 900;
	*(bb + 1) = bbe;

    inputLength = p;

    cout << "Inside clipper, about to call shClip" << endl;
	
	shClip(inArray, outArray, inputLength, &outputLength, bb);
	shClip(outArray, inArray, outputLength, &inputLength, bb);
	shClip(inArray, outArray, inputLength, &outputLength, bb);
	shClip(outArray, inArray, outputLength, &inputLength, bb);

    p = inputLength;

/*	
	//right clip
 	 shClip(outputArray, inputArray, clipBoundary)	
	//shClip();
	//top clip
 	 shClip(inputArray, outputArray, clipBoundary)
	//shClip();
	/*left clip
 	 shClip(outputArray, inputArray, clipBoundary) 
	//shClip();
*/	

}

