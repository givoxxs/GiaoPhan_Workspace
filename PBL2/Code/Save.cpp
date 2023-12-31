#include "Save.h"
#include "Prepare.h"
#include <iostream>
using namespace std;

Save::Save() {}

Save::Save(string order_id, Date d, string id, string sdt_cus, vector<sold> s)
{
    this->order_id = order_id;
    this->d = d;
    this->emp_id = id;
    this->sdt_cus = sdt_cus;
    this->save = s;
}
void Save::setOrder_id(std::string order_id)
{
    this->order_id = order_id;
}

void Save::setDate(Date d)
{
    this->d = d;
}

void Save::setSave(vector<sold> s)
{
    this->save = s;
}

void Save::setEmp_id(string id)
{
    this->emp_id = id;
}
void Save::settSdt_cus(std::string sdt)
{
    this->sdt_cus = sdt;
}
void Save::display()
{
    canhtren(100);
    cout << char(179) << setw(100) << left << (" Ma hoa don: " + this->order_id) << char(179) << endl;
    cout << char(179) << " Ngay ban: ";
    d.display();
    cout << char(179) << endl;
    canhnoi(100);
    cout << char(179) << setw(100) << left << (" ID nhan vien thuc hien giao dich: " + this->emp_id) << char(179) << endl;
    cout << char(179) << setw(100) << left << (" SDT khach hang: " + this->sdt_cus) << char(179) << endl;
    canhnoi(100);
    cout << char(179) << setw(20) << " ID" << setw(50) << "Ten sach" << setw(15) << "Gia (VND)" << setw(15) << "So luong" << char(179) << endl;
    for (int i = 0; i < save.size(); i++)
   {
        cout <<char(179)<< " "<<setw(19) <<save[i].get_book_id();
        Node_Book *current = headBook;
        while(current != nullptr) {
            if(current->data.get_id() == save[i].get_book_id()) {
                cout<<setw(50)<<current->data.get_title();
                cout<<setw(15)<<current->data.get_price();
                break;
            }
            current = current->next;
        }
        cout<< setw(15)<<save[i].get_book_qtt() <<char(179)<< endl;
    }
    canhduoi(100);
    cout << endl
         << endl;
}

void Save::display_All()
{
    Node_Save *current = headSave;
    while(current!=nullptr) 
    {
        current->data.display();
        current = current->next;
    }
}

Date Save::getDate()
{
    return this->d;
}

string Save::getEmp_id()
{
    return this->emp_id;
}

string Save::getSdt_cus()
{
    return this->sdt_cus;
}

vector<sold> Save::getSave()
{
    return this->save;
}

string Save::getOrder_id()
{
    return this->order_id;
}