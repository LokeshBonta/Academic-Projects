#include "integer.h"
#include <memory>

clss Project
{


};

class Employee
{
    std::shared_ptr<Prject> m_pProject; 
public:
    void setProject(std::shared_ptr<Project> p)
    {
        m_pProject = p;
    }
    std::shared_ptr<Projct> getProject()
    {
        return m_pProject;
    }
};
Employee *assignProject()
{
    std::shared_ptr<Project> p(new Project());
    Employee *e1 = new Employee();
    e1->setProject(p);
    return e1;
}

int main()
{
    
    return 0;
}