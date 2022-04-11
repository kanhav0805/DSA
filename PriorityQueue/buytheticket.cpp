#include<queue>
class pairs{
    public:
    int first;
    int second;
    pairs(int first,int second)
    {
        this->first = first;
        this->second = second;
    }
};
int buyTicket(int *arr, int n, int k) 
{
    queue<pairs*> dibba;
    priority_queue<int> pq;
    //put the values making pair in queue as well as max heap individually
    for(int i=0;i<n;i++)
    {
        pairs *p = new pairs(arr[i],i);
        dibba.push(p);
        //pushing the value in priority queue
        pq.push(arr[i]);
    }
    //now traverse the whole queue and find the time to be taken
    int time = 0;
    while(dibba.size()!=0)
    {
        int frontVal = dibba.front()->first;
        int index = dibba.front()->second;
        if(frontVal==pq.top() && index==k) //case when our element is found
        {
            time = time + 1;
            break;
        }
        else if(frontVal==pq.top() && index!=k)//case when element with same value is found with different index
        {
            time = time + 1;
            dibba.pop();
            pq.pop();
        }
        else if(frontVal<pq.top())//case when element priotrity is less
        {
            //remove element from the queue an put at last
            pairs *np = dibba.front();
            dibba.pop();
            dibba.push(np);
            
        }
    }
    return time;
}
