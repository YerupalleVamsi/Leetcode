for (int day=1; i<n || !pq.empty(); day++) {// day begins at 1
    if (pq.empty()) day=events[i][0];//if pq is empty jump day to event[i][0]

    // push all endtimes with start time<=day
    while (i<n && events[i][0]<=day) {
        pq.push(events[i][1]);
        i++;
    }

    // pop up the end time<day
    while (!pq.empty() && pq.top()<day) 
        pq.pop();
            
    // if pq  is not empty. pop it up and add 1 to maxEvent
    if (!pq.empty()) {
        pq.pop();
        maxEvents++;
    }
}