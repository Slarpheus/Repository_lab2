#include <iostream>
using namespace std;

class KomplexNum
{
protected:
    double num1;
    double num2;
public:
    void Init(double num1, double num2);
    KomplexNum(double num1, double num2);
    KomplexNum();
    void Display();
    double calcModule();
    int GetNum1();
    int GetNum2();
};


void KomplexNum::Init(double num1, double num2)
{
    this->num1 = num1;
    this->num2 = num2;
}

KomplexNum::KomplexNum(double num1, double num2) {
    this->num1 = num1;
    this->num2 = num2;
}
KomplexNum::KomplexNum() {};

int KomplexNum::GetNum1()
{
    return num1;
}

int KomplexNum::GetNum2()
{
    return num2;
}


void KomplexNum::Display()
{
    cout << "Комплексное число: " << num1 << " + " << num2 << "i" << endl;
}

double KomplexNum::calcModule() {
    double result = num1 + num2;

    return result;
}

class Z_komplexNum : public KomplexNum {	//производный класс
private:
    double num3;
    double num4;
public:
    double GetNum3();
    double GetNum4();
    void PutNum3(double value3);
    void PutNum4(double value4);
    void Init(double num1, double num2, double num3, double num4);
    Z_komplexNum(double num1, double num2, double num3, double num4);
    Z_komplexNum();
    void  operator =(KomplexNum b);
    void Display();
    double calcModule();
};

double Z_komplexNum::GetNum3() {
    return num3;
}

double Z_komplexNum::GetNum4() {
    return num4;
}

void Z_komplexNum::PutNum3(double value3) {
    this->num3 = value3;
}

void Z_komplexNum::PutNum4(double value4) {
    this->num4 = value4;
}

void Z_komplexNum::Init(double num1, double num2, double num3, double num4) {
    KomplexNum::Init(num1, num2);
    this->num3 = num3;
    this->num4 = num4;
}

Z_komplexNum::Z_komplexNum(double num1, double num2, double num3, double num4) : KomplexNum(num1, num2) {
    this->num3 = num3;
    this->num4 = num4;
}
Z_komplexNum::Z_komplexNum() {};

void Z_komplexNum::operator =(KomplexNum b) // перегрузка в классе Sprint
{
    this->num1 = b.GetNum1();
    this->num2 = b.GetNum2();
    //  this->min=b.min; // так ошибка !
    // min – protected, но b объект базового класса, созданный 
    // в производном,он  не имеет доступа ни к private ни к protected
    // подобное на Java бы прошло, на C# нет см. 5.4
    this->num3 = 0;        // задание значений недостающему полю производного класса
    this->num4 = 0;
}


void Z_komplexNum::Display() {
    cout << "(" << num1 << " + " << num2 << "i)" << " + (" << num3 << " + " << num4 << "i)" << " * j" << endl;
}

double Z_komplexNum::calcModule() {
    double result = num1 + num2 + num3 + num4;

    return result;
}

int main()
{
    system("chcp 1251>nul");  // RU
    KomplexNum x(2, 4);
    Z_komplexNum z(3, 5, 1, 5);
    z = x;
    cout << "Значения комплексных чисел двух обьектов, после того, как их приравняли:" << endl;
    z.Display();
    x.Display();
    cout << "Статический массив базового обьекта \"KomplexNum\":";
    int sum = 0;
    KomplexNum num1(1, 3);
    KomplexNum num2;
    num2.Init(3, 2);
    KomplexNum testStaticArr[2] = { num1, num2 };
    for (int i = 0; i < 2; i++) {
        cout << "\n";
        testStaticArr[i].Display();
        sum += testStaticArr[i].calcModule();
    }
    cout << "Сумма этих чисел: " << sum << endl;

    cout << "Статический массив производного обьекта \"Z_komplexNum\":";
    sum = 0;
    Z_komplexNum num3(4, 3, 4, 3);
    Z_komplexNum num4;
    num4.Init(3, 2, 5, 6);
    Z_komplexNum testStaticArr2[2] = { num3, num4 };
    for (int i = 0; i < 2; i++) {
        cout << "\n";
        testStaticArr2[i].Display();
        sum += testStaticArr[i].calcModule();
    }
    cout << "Сумма этих чисел: " << sum << endl;

    sum = 0;

    cout << "Рассмотрим динамический массив базового обьекта \"KomplexNum\": " << endl;
    int sumElDinamicArr = 0;
    KomplexNum* testDinamicArray = new KomplexNum[2];
    for (int i = 0; i < 2; i++) {
        testDinamicArray[i].Init(rand() % 1000, rand() % 1000);
        testDinamicArray[i].Display();
        sum += testDinamicArray[i].calcModule();
    }
    cout << "Сумма элементов динамического массива: " << sum << endl;
    delete[] testDinamicArray;

    sum = 0;

    cout << "Рассмотрим динамический массив производного обьекта \"Z_komplexNum\": " << endl;
    Z_komplexNum* testDinamicArray2 = new Z_komplexNum[2];
    for (int i = 0; i < 2; i++) {
        testDinamicArray2[i].Init(rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000);
        testDinamicArray2[i].Display();
        sum += testDinamicArray2[i].calcModule();
    }
    cout << "Сумма элементов динамического массива: " << sum << endl;
    delete[] testDinamicArray2;
}
