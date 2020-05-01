#include "classroom.hpp"

///
Classroom::Classroom()
{

}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
Student* Classroom::find_student(unsigned int UID, bool &found)
{
    
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        
        Student* s = _classList.IterateItems();
      
        if(s->GetID() == UID)
        {
            
            found = true;
            return s;
        }
        
    }
    found = false;
    
}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
void Classroom::PrintClassroomInformation() const
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        std::cout << "****************************************" << std::endl;
        _classList.IterateItems()->PrintData();
        std::cout << std::endl;
    }
}

/// modify code below this line
// ========================================
bool Classroom::AddStudent(const std::string &firstName, const std::string &lastName, unsigned int UID)
{
    bool found;
    find_student(UID,found);
    if(found == false)
    {
        Student *student = new Student(firstName , lastName , UID);
        _classList.AppendItem(*student);
        delete student;
        return true;
    }
    else {
        return false; 
    }
    
}

bool Classroom::RemoveStudent(unsigned int UID)
{
    /// removes the student from the list based on UID.
    /// returns true if the student was successfully removed
    bool found;
    Student *student = find_student(UID,found);
    if(found == true){
        if(_classList.DeleteItem(*student)){
            delete student;
            return true;
        }
        else
        {
            return false;
        }
        
    }
  

}

void Classroom::AddProjects(const List<Assignment> &projects)
{
    /// adds the projects to the required student's list of projects
    bool found;
    projects.ResetIterator();
     
    while(!projects.AtEnd()){
    Assignment *temp = projects.IterateItems();
    Student *x = find_student(temp->StudentUID,found);
    if(found)
    {
    
      if ( x->GetID() == temp->StudentUID)
      {
          x->AddProject(temp->Grade);
       
        
          
      }
  
    }
    
    }
}

void Classroom::AddExams(const List<Assignment> &projects)
{
    bool found;
    projects.ResetIterator();
     
    while(!projects.AtEnd()){
        Assignment *temp = projects.IterateItems();
        Student *x = find_student(temp->StudentUID,found);
            if(found)
        {
                if ( x->GetID() == temp->StudentUID)
                    {
                        x->AddExam(temp->Grade);
                     
                        }
        }   
    
    }
}

void Classroom::SetFinalExams(const List<Assignment> &projects)
{
 bool found;
    projects.ResetIterator();
     
    while(!projects.AtEnd()){
    Assignment *temp = projects.IterateItems();
    Student *x = find_student(temp->StudentUID,found);
    if(found)
    {
    
      if ( x->GetID() == temp->StudentUID)
      {
          x->SetFinalExam(temp->Grade);
       
        
          
      }
  
    }
    
    }
   

}

