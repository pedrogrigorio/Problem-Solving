#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    char jobID;
    int deadline;
    int profit;
};

std::vector<char> jobSequencing(std::vector<Job> all_jobs) {

    std::vector<int> unique_deadlines;
    std::sort(all_jobs.begin(), all_jobs.end(), [](Job a, Job b){return a.deadline > b.deadline;});

    // unique_deadlines

    if (!all_jobs.empty()) {
        unique_deadlines.push_back(all_jobs[0].deadline);
    }

    for (Job job : all_jobs) {
        if (job.deadline != unique_deadlines.back()) {
            unique_deadlines.push_back(job.deadline);
        }
    }
    
    std::vector<char> result;

    for (int deadline : unique_deadlines) {
        char job_chosen_by_deadline;
        int maxProfit = 0;

        for (Job job : all_jobs) {
            if (job.deadline >= deadline && job.profit > maxProfit) {
                job_chosen_by_deadline = job.jobID;
                maxProfit = job.profit;
            }
        }
        result.push_back(job_chosen_by_deadline);
    }

    return result;
}

int main() {

    int n_jobs = 0;
    std::cin >> n_jobs;

    std::vector<Job> all_jobs;
    for (int i = 0; i < n_jobs; i++) {
        Job job;
        std::cin >> job.jobID >> job.deadline >> job.profit;
        all_jobs.push_back(job);
    }

    std::vector<char> result = jobSequencing(all_jobs);
    
    for (char job : result) {
        std::cout << job << (job == result.back() ? "" : ", ");
    }
}