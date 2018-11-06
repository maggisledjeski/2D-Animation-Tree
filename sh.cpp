#include "includes.h"
#include "prototypes.h"
#include "structs.h"

int clip(vertex wMin, vertex wMax, int n, vertex * pIn, vertex * pOut)
{
	int c = polygonClipSuthHodg(wMin, wMax, n, pIn, pOut);
	glutPostRedisplay();
	return c;
}

//typedef enum { Left, Right, Bottom, Top }Boundary;
const int nClip = 4;

//wMin is the minimum point for a side
//wMax is the maximum point for a side
//n is the number of points in treePants
//pIn is a pointer to the array that has the input points we want to clip
//pOut is a pointer to the array that has the output points we get from the clip
//first is an array that has the first point to clip
//s is an array that has the previous point that was processed

//not sure what this does
int polygonClipSuthHodg(vertex wMin, vertex wMax, int n, vertex * pIn, vertex * pOut)
{
	extern struct vertex * treePants2;
/* Parameter "first" holds pointer to first point processed for
 *  * * a boundary; "s" holds most recent point processed for boundary.
 *   * */
	vertex * first[nClip] = { 0, 0, 0, 0 };//, treePants1[nClip];//s[nClip];
	
	int k, cnt = 0;
	for(k = 0; k < n; k++)
	{
		clipPoint(pIn[k], Left, wMin, wMax, pOut, &cnt, first, treePants2);
	}
	closeClip(wMin, wMax, pOut, &cnt, first, treePants2);
	return(cnt);
}

//calculates if the point being tested, for a certain boundary is inside the clipping window
int inside(vertex p, Boundary b, vertex wMin, vertex wMax)
{
	switch (b) {
    	case Left:   
			if(p.x < wMin.x)
			{
				return(false);
			}
			break;
      	case Right:  
			if(p.x > wMax.x)
			{
				return(false);
			}
			break;
      	case Bottom: 
			if(p.y < wMin.y)
			{
				return(false);
			}
			break;
      	case Top:    
			if(p.y > wMax.y)
			{
				return(false);
			}
			break;
   	}
   	return(true);
}

//tests if the vector made up of the current point and the previous point cross the boundary being tested
int cross(vertex p1, vertex p2, Boundary winEdge, vertex wMin, vertex wMax)
{
   	if(inside(p1, winEdge, wMin, wMax) == inside(p2, winEdge, wMin, wMax))
	{
    	return (false);
	}
   	else 
	{
		return (true);
	}
}

//will run if cross returns true
//calculates the intersection point with the vector and the boundary
//returns the intersection point
vertex intersect(vertex p1, vertex p2, Boundary winEdge, vertex wMin, vertex wMax)
{
	vertex iPt;	//intersection point
   	float m;	//slope

   	if (p1.x != p2.x) 
	{
		m = (p1.y - p2.y) / (p1.x - p2.x);
	}
   	switch(winEdge) {
    	case Left:
        	iPt.x = wMin.x;
           	iPt.y = p2.y + (wMin.x - p2.x) * m;
           	break;
      	case Right:
           	iPt.x = wMax.x;
           	iPt.y = p2.y + (wMax.x - p2.x) * m;
           	break;
      	case Bottom:
           	iPt.y = wMin.y;
           	if(p1.x != p2.x)
			{
				 iPt.x = p2.x + (wMin.y - p2.y) / m;
           	}
			else
			{
				iPt.x = p2.x;
           	}
			break;
      	case Top:
           	iPt.y = wMax.y;
           	if(p1.x != p2.x)
			{
				iPt.x = p2.x + (wMax.y - p2.y) / m;
           	}
			else 
			{
				iPt.x = p2.x;
           	}
			break;
   }

   return(iPt);
}

//the main clipping algorithm
void clipPoint(vertex p, Boundary w, vertex wMin, vertex wMax, vertex * pOut, int * cnt, vertex * first[], vertex * s)
{
	extern struct vertex * treePants2;

	vertex iPt;
	Boundary winEdge = w;
	
   /* If no previous point exists for this clipping boundary,
 *  * save this point.
 *   *         */
	if(!first[winEdge])
	{
		first[winEdge] = &p;
	} 
	else
	{
    /*  Previous point exists.  
 *  	If p and previous point cross this clipping boundary, find intersection.  
 *  	Clip against next boundary, if any.  
 *  	If no more clip boundaries, add intersection to output list.  
 *      */
		if(cross(p, s[winEdge], winEdge, wMin, wMax)) 
		{
    		iPt = intersect(p, s[winEdge], winEdge, wMin, wMax);
        	if(winEdge < Top)
			{
        		//b = Boundary((int)winEdge + 1);
				//clipPoint(iPt, b, wMin, wMax, pOut, cnt, first, s);
        		winEdge = Boundary((int)winEdge + 1);
                clipPoint(iPt, winEdge, wMin, wMax, pOut, cnt, first, treePants2);
			} 
			else 
			{
            	pOut[*cnt] = iPt;  
				(*cnt)++;
        	}	
    	}
	}
   /*  Save p as most recent point for this clip boundary.  */
   s[winEdge] = p;

   /*  For all, if point inside, proceed to next boundary, if any.  */
   if(inside(p, winEdge, wMin, wMax))
	{
      	if(winEdge < Top)
		{
         	winEdge = Boundary((int)winEdge + 1);
			clipPoint(p, winEdge, wMin, wMax, pOut, cnt, first, treePants2);
      	} 
		else 
		{
         	pOut[*cnt] = p;
			(*cnt)++;
      	}
	}
}

//not sure what this does
void closeClip(vertex wMin, vertex wMax, vertex * pOut, int * cnt, vertex * first [ ], vertex * s)
{
   	extern struct vertex *treePants2;
	vertex pt;
   	Boundary winEdge = Left;
	
	while(winEdge <= Top) 
	{
    	if(cross(s[winEdge], *first[winEdge], winEdge, wMin, wMax)) 
		{
        	pt = intersect (s[winEdge], *first[winEdge], winEdge, wMin, wMax);
         	if(winEdge < Top)
			{
            	//int w = Boundary(int(winEdge)+1);
				winEdge = Boundary((int)winEdge + 1);
				clipPoint(pt, winEdge, wMin, wMax, pOut, cnt, first, treePants2);
         	}
			else 
			{
            	pOut[*cnt] = pt;  
				(*cnt)++;
         	}
      	}
		winEdge = Boundary((int)winEdge + 1);
   	}
}