#include "CurveEditor.h"

Node::Node(){
    pos[0]=0.0f;
    pos[1]=0.0f;
}

Node::Node(float x, float y){
    pos[0]=x;
    pos[1]=y;
}

Node::~Node(){
    
}

void Node::draw(void){
	glTranslatef(pos[0],pos[1], 0.0f);
	glutSolidSphere(0.05f,20,20);
}


Path::Path(){
    
    Node n(0.5f,0.25f);
    Node n1;
    v.push_back(n);
    v.push_back(n1);
    
//     cout << "\nSize of vector is now " << v.size() << endl;
//     pos = v.begin();
//     while ( pos != v.end() ){
//         cout << '['<<(*pos).pos[0]<<','<<(*pos).pos[1]<<']' << "\t";  
//         pos++;
//     }
//     cout << endl;
    
}
Path::~Path(){}


void Path::draw(void){
    
    auto pos = v.begin();
    while (pos!=v.end()){
        (*pos).draw();
        pos++;
    }
}
