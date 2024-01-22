#pragma once
#include <iostream>
#include <string>

using namespace std;

class Certificate {
private:
    int CertificateID;
    string CertificateName;
    string CertificateRank;
    string CertificateDate;

public:
    Certificate(int CertificateID, string CertificateName, string CertificateRank, string CertificateDate);

    int GetCertificateID();
    void setCertificateID(int CertificateID);

    string getCertificateName();
    void setCertificateName(string CertificateName);

    string getCertificateRank();
    void setCertificateRank(string CertificateRank);

    string getCertificateDate();
    void setCertificateDate(string CertificateDate);
};
