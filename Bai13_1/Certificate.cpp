 #include "Certificate.h"


Certificate::Certificate(int CertificateID, string CertificateName, string CertificateRank, string CertificateDate) {
    this->CertificateID = CertificateID;
    this->CertificateName = CertificateName;
    this->CertificateRank = CertificateRank;
    this->CertificateDate = CertificateDate;
}

int Certificate::GetCertificateID() {
    return CertificateID;
}

void Certificate::setCertificateID(int CertificateID) {
    this->CertificateID = CertificateID;
}

string Certificate::getCertificateName() {
    return CertificateName;
}

void Certificate::setCertificateName(string CertificateName) {
    this->CertificateName = CertificateName;
}

string Certificate::getCertificateRank() {
    return CertificateRank;
}

void Certificate::setCertificateRank(string CertificateRank) {
    this->CertificateRank = CertificateRank;
}

string Certificate::getCertificateDate() {
    return CertificateDate;
}

void Certificate::setCertificateDate(string CertificateDate) {
    this->CertificateDate = CertificateDate;
}

