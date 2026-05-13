# Job Scheduling using Greedy Algorithm

def job_scheduling(jobs):
    
    # Sort jobs according to profit (descending)
    jobs.sort(key=lambda x: x[2], reverse=True)
    
    # Find maximum deadline
    max_deadline = max(job[1] for job in jobs)
    
    # Create slots
    slots = [-1] * max_deadline
    
    total_profit = 0
    
    print("Selected Jobs:")
    
    # Traverse all jobs
    for job in jobs:
        
        job_id = job[0]
        deadline = job[1]
        profit = job[2]
        
        # Check slots backward
        for i in range(deadline - 1, -1, -1):
            
            if slots[i] == -1:
                
                slots[i] = job_id
                total_profit += profit
                
                print(job_id, "Profit:", profit)
                
                break
    
    print("\nTotal Profit:", total_profit)

# Jobs Format:
# (Job ID, Deadline, Profit)

jobs = [
    ('J1', 2, 100),
    ('J2', 1, 19),
    ('J3', 2, 27),
    ('J4', 1, 25),
    ('J5', 3, 15)
]

# Function Call
job_scheduling(jobs)