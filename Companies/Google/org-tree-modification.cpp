// https://leetcode.com/discuss/post/1244429/google-phone-interview-org-structure-mod-rf2k/
#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string employeeId;
    bool isEngineer;
    vector<Employee *> reportees;

    Employee(string empId, bool isEng)
    {
        this->employeeId = empId;
        this->isEngineer = isEng;
    }

    Employee(Employee *other)
    {
        this->employeeId = other->employeeId;
        this->isEngineer = other->isEngineer;
    }
};

class SolutionCopy
{
private:
    void solveUtil(Employee *cur, Employee *par)
    {
        Employee *newParent = par;
        if (cur->isEngineer)
        {
            Employee *curClone = new Employee(cur);
            par->reportees.push_back(curClone);
            newParent = curClone;
        }
        for (auto rep : cur->reportees)
        {
            solveUtil(rep, newParent);
        }
    }

    void printHierarchyUtil(Employee *root, int depth)
    {
        cout << "(" << depth << ", " << root->employeeId << "), ";

        for (auto rep : root->reportees)
        {
            printHierarchyUtil(rep, depth + 1);
        }
    }

public:
    Employee *solve(Employee *root)
    {
        Employee *clonedRoot = new Employee(root);
        for (auto rep : root->reportees)
        {
            solveUtil(rep, clonedRoot);
        }
        return clonedRoot;
    }

    void printHierarchy(Employee *root)
    {
        printHierarchyUtil(root, 0);
        cout << endl;
    }
};

class SolutionInPlace
{
private:
    vector<Employee *> solveUtil(vector<Employee *> reportees)
    {
        vector<Employee *> newReportees;

        for (auto rep : reportees)
        {
            if (rep->isEngineer)
            {
                newReportees.push_back(rep);
                rep->reportees = solveUtil(rep->reportees);
            }
            else
            {
                vector<Employee *> sub = solveUtil(rep->reportees);
                newReportees.insert(newReportees.end(), sub.begin(), sub.end());
            }
        }
        return newReportees;
    }

    void printHierarchyUtil(Employee *root, int depth)
    {
        cout << "(" << depth << ", " << root->employeeId << "), ";

        for (auto rep : root->reportees)
        {
            printHierarchyUtil(rep, depth + 1);
        }
    }

public:
    Employee *solve(Employee *root)
    {
        Employee *clonedRoot = new Employee(root);

        vector<Employee *> modifiedReportees = solveUtil(root->reportees);
        clonedRoot->reportees = modifiedReportees;

        return clonedRoot;
    }

    void printHierarchy(Employee *root)
    {
        printHierarchyUtil(root, 0);
        cout << endl;
    }
};

int main()
{
    Employee *org1Head = new Employee("E1", true);
    org1Head->reportees.push_back(new Employee("E2", true));
    org1Head->reportees.push_back(new Employee("NE1", false));
    org1Head->reportees.push_back(new Employee("E3", true));
    org1Head->reportees[0]->reportees.push_back(new Employee("E4", true));
    org1Head->reportees[0]->reportees.push_back(new Employee("NE2", false));
    org1Head->reportees[1]->reportees.push_back(new Employee("E5", true));

    SolutionCopy s;
    // SolutionInPlace s;
    Employee *sol1 = s.solve(org1Head);

    s.printHierarchy(org1Head);
    cout << endl;

    s.printHierarchy(sol1);
    cout << endl;

    Employee *org2Head = new Employee("E1", true);
    org2Head->reportees.push_back(new Employee("NE1", false));
    org2Head->reportees.push_back(new Employee("E2", true));

    Employee *sol2 = s.solve(org2Head);

    s.printHierarchy(org2Head);
    cout << endl;

    s.printHierarchy(sol2);
    cout << endl;

    Employee *org3Head = new Employee("E1", true);
    Employee *sol3 = s.solve(org3Head);

    s.printHierarchy(org3Head);
    cout << endl;

    s.printHierarchy(sol3);
    cout << endl;

    return 0;
}