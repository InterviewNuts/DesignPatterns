#include<iostream>
using namespace std;

class HttpClient
{
    string method;
    string url;
    string userName;
    string password;
    string headers;
    string body;

public:
    class HttpClientBuild
    {
        string method_i;
        string url_i;
        string userName_i;
        string password_i;
        string headers_i;
        string body_i;
    public:
        HttpClientBuild() = default;
        HttpClientBuild* method(string method)
        {
            this->method_i = method;
            return this;
        }
        HttpClientBuild* url(string url)
        {
            this->url_i = url;
            return this;
        }
        HttpClientBuild* userName(string userName)
        {
            this->userName_i = userName;
            return this;
        }
        HttpClientBuild* password(string password)
        {
            this->password_i = password;
            return this;
        }
        HttpClientBuild* headers(string headers)
        {
            this->headers_i = headers;
            return this;
        }
        HttpClientBuild* body(string body)
        {
            this->body_i = body;
            return this;
        }
        string getMethod()
        {
            return method_i;
        }
        string getUrl()
        {
            return url_i;
        }
        string getUserName()
        {
            return userName_i;
        }
        string getPassword()
        {
            return password_i;
        }
        string getHeaders()
        {
            return headers_i;
        }
        string getBody()
        {
            return body_i;
        }
        HttpClient* build()
        {
            return new HttpClient(this);
        }
    };
    HttpClient(HttpClientBuild* hcb)
    {
        this->method = hcb->getMethod();
        this->url = hcb->getUrl();
        this->userName = hcb->getUserName();
        this->password = hcb->getPassword();
        this->headers = hcb->getHeaders();
        this->body = hcb->getBody();
    }
    // HttpClient(string method, string url, string userName, string password, string headers, string body) :
    //     method(method), url(url), userName(userName), password(password), headers(headers), body(body)
    // {
    //     std::cout << " HttpClient Cotr called\n";
    // }
    HttpClient() = default;
    ~HttpClient() = default;
    void toString()
    {
        cout << "Method = " << method << ", URL = " << url << ", User Name =" << userName << ", Password = " << password << \
            ", Headers= " << headers << ", Body = " << body << "\n";
    }


};

int main()
{
    //  The commented code is the problem, it is has been solved by builder pattern below
    // HttpClient* hc = new HttpClient("GET", "testurl.com", "user", "pass", "{}", "nothing");
     //! here it is not more readable for user to know what these parameter used for.
     //! Had we use Builder pattre, this makes final object , But with step by step.
     //! which is more redable and configurable, like if we dont pass any argument, then we 
     //! simple can ignore it.
    // HttpClient* hc1 = new HttpClient("GET", "testurl.com", "null", "null", "{}", "nothing");
    // hc->toString();

    HttpClient* hc = HttpClient::HttpClientBuild().method("POST")->url("TestUrl.com")->userName("Hara")->password("pass123")->headers("{}")->body("NOTHING")->build();
    hc->toString();

}