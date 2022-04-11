#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
       //base case when no element is present in the heap
        if(pq.size()==0)
        {return INT_MIN;}
        int ans = pq[0];
        pq[0] = pq[pq.size()- 1];//put last element at the first position
        //now pop the last element
        pq.pop_back();
        int parentIndex = 0;
        int lcIndex = ((2*parentIndex) + 1);
        int rcIndex = ((2*parentIndex) + 2);
        while(lcIndex<pq.size())
        {
            int minIndex = parentIndex;
            //check the parent index value with lcindex if it is smaller change minindex
            if(pq[minIndex]>pq[lcIndex])
            {
                minIndex = lcIndex;
            }
            //check the parent index value with rcindex if it is smaller change minindex
            if(rcIndex<pq.size() && (pq[minIndex]>pq[rcIndex]))
            {
                minIndex = rcIndex;
            }
            if(minIndex==parentIndex){break;}
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            parentIndex = minIndex;
            lcIndex = ((2*parentIndex) + 1);
            rcIndex = ((2*parentIndex) + 2);
            }
        return ans;
    }
};
