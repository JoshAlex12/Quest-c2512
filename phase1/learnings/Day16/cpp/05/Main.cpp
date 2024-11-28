#include <iostream>
#include <iomanip>

#include "Patient.h"
#include "HospitalStay.h"

#include "ArrayOperationsPatient.h"
#include "ArrayOperationsHospitalStay.h"

int main()
{
    Patient Patients[] = {
        Patient("P001", 45),
        Patient("P002", 50),
        Patient("P003", 15),
        Patient("P004", 20),
        Patient("P005", 30)};

    HospitalStay HospitalStays[] = {HospitalStay("D001", 15), HospitalStay("D002", 10), HospitalStay("D003", 20), HospitalStay("D004", 25), HospitalStay("D005", 18)};

    int n_Patients = sizeof(Patients) / sizeof(Patients[0]);

    std::cout << "HospitalStay with Min Stay: " << Patients[findMinStay(Patients, n_Patients)].GetStayID() << " with NumberOfDays " << Patients[findMinStay(Patients, n_Patients)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with Max Stay: " << Patients[findMaxStay(Patients, n_Patients)].GetStayID() << " with NumberOfDays " << Patients[findMaxStay(Patients, n_Patients)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with 2nd Min Stay: " << Patients[findSecondMinStay(Patients, n_Patients)].GetStayID() << " with NumberOfDays " << Patients[findSecondMinStay(Patients, n_Patients)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with 2nd Max Stay: " << Patients[findSecondMaxStay(Patients, n_Patients)].GetStayID() << " with NumberOfDays " << Patients[findSecondMaxStay(Patients, n_Patients)].GetNumberOfDays() << std::endl;

    int n_HospitalStays = sizeof(HospitalStays) / sizeof(HospitalStays[0]);

    std::cout << "HospitalStay with Min Stay: " << HospitalStays[findMinStay(HospitalStays, n_HospitalStays)].GetStayID() << " with NumberOfDays " << HospitalStays[findMinStay(HospitalStays, n_HospitalStays)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with Max Stay: " << HospitalStays[findMaxStay(HospitalStays, n_HospitalStays)].GetStayID() << " with NumberOfDays " << HospitalStays[findMaxStay(HospitalStays, n_HospitalStays)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with 2nd Min Stay: " << HospitalStays[findSecondMinStay(HospitalStays, n_HospitalStays)].GetStayID() << " with NumberOfDays " << HospitalStays[findSecondMinStay(HospitalStays, n_HospitalStays)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with 2nd Max Stay: " << HospitalStays[findSecondMaxStay(HospitalStays, n_HospitalStays)].GetStayID() << " with NumberOfDays " << HospitalStays[findSecondMaxStay(HospitalStays, n_HospitalStays)].GetNumberOfDays() << std::endl;

    return 0;
}
