#include "includes.h"
#include "prototypes.h"

void Tess(void)
{
	extern struct vertex *treePants;
	extern struct vertex *tessPants;
	
	extern int p;
	//drawTTree(p);
	
	bool advanceStart = false;
	
	list <vertex> fl;
	list <linseg> LList;
	list <triangle> TList;

	vertex spot, prev;
	linseg l;
	int count = 0;
	while(count < p)	/*should turn treePants into a list named fl*/
	{
		if(fl.size() > 0)
		{
			prev = fl.back();
			spot = *(treePants + 0 + count);
			fl.push_back(spot);
			l.one = prev;
			l.two = spot;
			LList.push_back(l);
			count++;
		} else if(fl.size() == 0)
		{
			spot = *(treePants + 0 + count);
			fl.push_back(spot);
			count++;
		}
	}

	prev = fl.back();
	spot = fl.front();
	l.one = prev;
	l.two = spot;
	LList.push_back(l);

	/*now, the linseg list is built so intersection can happen*/

	list<vertex>::iterator its = fl.begin(); //keeps track of the 1st or starting vertex
    list<vertex>::iterator itn = fl.begin(); //keeps track of the 2nd vertex
    list<vertex>::iterator itnn = fl.begin();//keeps track of the 3rd vertex
    list<vertex>::iterator itl = fl.begin(); //keeps track of the 4th vertex

	while(fl.size() > 3)
	{
		vertex last = fl.back();  //keeps track of the last vertex in the list
        vertex start,a,b,c; //redeclares the vertices

		if(advanceStart == true)
        {
            if((*itl).x == last.x && (*itl).y == last.y)    //if the last iterator is pointing to the last element 
            {
				advanceStart = false;
                advance(its,1);
                start = *its;
                advance(itn,1);
                a = *itn;
                advance(itnn,1);
                b = *itnn;
                itl = fl.begin();
                c = *itl;
            } else if((*itnn).x == last.x && (*itnn).y == last.y)   //if the 2nd to last iterator is pointing to the last element
            {
                advanceStart = false;
                advance(its,1);
                start = *its;
                advance(itn,1);
                a = *itn;
                itnn = fl.begin();
                b = *itnn;
                advance(itl,1);
                c = *itl;
            } else if((*itn).x == last.x && (*itn).y == last.y)     //if the 3rd to last iterator is pointing to the last element
            {
                advanceStart = false;
                advance(its,1);
                start = *its;
                itn = fl.begin();
                a = *itn;
                advance(itnn,1);
                b = *itnn;
                advance(itl,1);
                c = *itl;
            } else if((*its).x == last.x && (*its).y == last.y)     //if the start iterator is pointing to the last element
            {
                advanceStart = false;
                its = fl.begin();
                start = *its;
                advance(itn,1);
                a = *itn;
                advance(itnn,1);
                b = *itnn;
                advance(itl,1);
                c = *itl;
            } else                  //advance the iterators all by 1
			{
				advanceStart = false;
                advance(its,1);
                start = *its;
                advance(itn,1);
                a = *itn;
                advance(itnn,1);
                b = *itnn;
                advance(itl,1);
                c = *itl;
            }
        } else                      //advanceStart = false, used for when the start does not need to move
        {
            //sets all of the iterators at the start
            its = fl.begin();
            itn = fl.begin();
            itnn = fl.begin();
            itl = fl.begin();
			
			start = *its;
            advance(itn,1);
            a = *itn;
            advance(itnn,2);
            b = *itnn;
            advance(itl,3);
            c = *itl;
        }
		
		//calculates the cross product for the given vertices
		vertex cpv = cp1(start,a,b);

		if(cpv.z < 0.0)
		{
			//create linseg for tess line can see if any intersect
			linseg tess;
			tess.one = start;
			tess.two = b;
			
			bool ib=false;
            for(list<linseg>::iterator t1=LList.begin(); t1!=LList.end(); t1++)
            {
                ib = linIntersect(tess,*t1);
                if(ib == true)
                {
                    cout << "Intersection with the tess linseg." << endl;
                    break;
				}
			}
			
			bool intAngle = AngleCheck(b,start,b,a,b,c);
			if(ib == false && intAngle == true)
			{
				triangle t;
                t.tone = start;
                t.ttwo = a;
                t.tthree = b;
                TList.push_back(t);
				
				itn = fl.erase(itn);
			} else
			{
				advanceStart = true;
			}
		} else
		{
			advanceStart = true;
		}
	}
	list<vertex>::iterator it1=fl.begin();
    vertex v1,v2,v3;
    v1 = *it1;
    advance(it1,1);
    v2 = *it1;
    advance(it1,1);
    v3 = *it1;

	triangle t;
    t.tone = v1;
    t.ttwo = v2;
    t.tthree = v3;
    TList.push_back(t);
	
	//convert list back to array, maybe?
	//int sizeCount = Tlist.size() + p;
	
	for(list<triangle>::iterator g=TList.begin(); g!=TList.end(); g++)
    {
        /*cout << "Triangle: " << endl;
        cout << (*g).tone.x << " " << (*g).tone.y << endl;
        cout << (*g).ttwo.x << " " << (*g).ttwo.y << endl;
        cout << (*g).tthree.x << " " << (*g).tthree.y << endl;*/

		drawLinSeg((*g).tone,(*g).ttwo);    //draws the tesselation line segment
        drawLinSeg((*g).tthree,(*g).ttwo);  //draws the line segment between vertices 2 and 3
        drawLinSeg((*g).tone,(*g).tthree);  //draws the line segment between vertices 1 and 3
	}
	
}

vertex cp1(vertex v1, vertex v2, vertex v3)
{
vertex a,b;
    a.x = v1.x - v2.x;
    a.y = v1.y - v2.y;
    a.z = 0.0;
    b.x = v3.x - v2.x;
    b.y = v3.y - v2.y;
    b.z = 0.0;

float t1 = a.y*b.z;
    float t2 = a.z*b.y;
    float x = (a.y*b.z) - (a.z*b.y);
    float y = (b.z*a.x) - (b.x*a.z);
    float z = (a.x*b.y) - (a.y*b.x);
 vertex cpv;
    cpv.x = x;
    cpv.y = y;
    cpv.z = z;
    
    return cpv;
}

bool AngleCheck(vertex a, vertex b, vertex c, vertex d, vertex e, vertex f)
{
    bool interior = true;
    
vertex v1,v2,v3;
    v1.x = b.x - a.x;
    v1.y = b.y - a.y;
    v2.x = d.x - c.x;
    v2.y = d.y - c.y;
    v3.x = f.x - e.x;
    v3.y = f.y - e.y;
	
float dpa = (v1.x*v2.x) + (v1.y*v2.y);
	float dpb = (v2.x*v3.x) + (v2.y*v3.y);

float v1m = sqrt((pow(v1.x,2.0))+(pow(v1.y,2.0)));
    float v2m = sqrt((pow(v2.x,2.0))+(pow(v2.y,2.0)));
	float v3m = sqrt((pow(v3.x,2.0))+(pow(v3.y,2.0)));
float alpha = acos((dpa/(v1m*v2m)));
    float beta = acos((dpb/(v2m*v3m)));
    
if(alpha > beta)
    {
        interior = false;
        cout << "angleCheck Failed" << endl;
    }

    return interior;
}	

void drawLinSeg(vertex old_v, vertex new_v)
{
    if(old_v.x == 0 && old_v.y == 0)
    {
    	old_v.x = new_v.x;
        old_v.y = new_v.y;
	}
    /*
    glBegin(GL_LINE_LOOP);
    glVertex2f(old_v.x,old_v.y);
    glVertex2f(new_v.x,new_v.y);
    glEnd();
    glFlush();
    */
}


bool linIntersect(linseg a, linseg b)
{
    bool intersect = false;
int P1 = b.one.x - a.one.x;
    int P2 = -(b.two.x - b.one.x);
    int P3 = b.one.y - a.one.y;
    int P4 = -(b.two.y - b.one.y);
    
    float P5 = a.two.x - a.one.x;
    float P6 = -(b.two.x - b.one.x);
    float P7 = a.two.y - a.one.y;
    float P8 = -(b.two.y - b.one.y);

    float P9 = a.two.x - a.one.x;
    float P10 = b.one.x - a.one.x;
    float P11 = a.two.y - a.one.y;
    float P12 = b.one.y - a.one.y;
float d1 = (P1*P4) - (P2*P3);
    float d2 = (P5*P8) - (P6*P7);	
float d3 = (P9*P12) - (P10*P11);

    float ua = d1/d2;
    float ub = d3/d2;
 if(((0.0 < ua) && (ua < 1.0)) && (((0.0 < ub) && (ub < 1.0))))
    {
		intersect = true;
    }
float x = a.one.x + ua*(a.two.x - a.one.x);
    float y = a.one.y + ua*(a.two.y - a.one.y);
    
    return intersect;
}

/*
void fillTessPolygon()
{
    glColor3f(0.0f,0.0f,0.0f);
    for(list<triangle>::iterator g=TList.begin(); g!=TList.end(); g++)
    {
        glColor3f(0.0f,0.0f,0.0f);

        glBegin(GL_POLYGON);
        glVertex2f((*g).tone.x,(*g).tone.y);
        glVertex2f((*g).ttwo.x,(*g).ttwo.y);
        glVertex2f((*g).tthree.x,(*g).tthree.y);
        glEnd();
        glFlush();
    }
}
*/
