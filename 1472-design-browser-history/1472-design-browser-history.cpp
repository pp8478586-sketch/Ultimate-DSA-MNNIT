class Node{
public:
    string data;
    Node*next;
    Node*back;
    Node(string x){
        data=x;
        next=back=NULL;
    }
};
class BrowserHistory {
    Node*currentPage;
public:
    
    BrowserHistory(string homepage) {
        currentPage=new Node(homepage);
    }
    
    void visit(string url) {
        Node*newNode=new Node(url);
        currentPage->next=newNode;
        newNode->back=currentPage;
        currentPage=newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(currentPage->back){
                currentPage=currentPage->back;
                steps--;
            }
            else{
                break;
            } 
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(currentPage->next){
                currentPage=currentPage->next;
                steps--;
            }
            else{
                break;
            }
        }
        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */