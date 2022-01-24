#include<iostream>
using namespace std;
class DataRender
{
private:
    string data;
public:
    void reder()
    {
        string data = readData();
        string processedData = processData(data);
        cout << "Here is the Processed Data = " << processedData << "\n";

    }
    virtual string readData() = 0;
    virtual string  processData(string data) = 0;


};

class XMLDataRender : public DataRender
{
public:
    string readData()
    {
        return "XMLData Read ";
    }

    string  processData(string data)
    {
        return "Processed " + data;
    }

};
class CSVDataRender : public DataRender
{
public:
    string readData()
    {
        return "CSVData Read ";
    }

    string  processData(string data)
    {
        return "Processed " + data;
    }

};