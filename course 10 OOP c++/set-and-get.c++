/*
	 لازم تتعود انك تعدل المتغيرات عن طريق الخاصيات او بروبرتز 
	 لازم كل فريبل تعمل له اثنين فنكشنز وحدة عشان تعدل عليه وهي سات والاخرى ترجعو معدل و هي الغت
	 الغي من راسك البابليك فاريبل من الان ورايح لازم تستعمل البروبرتيز
	 استعملت الاندر سكور في الفيرست نيم هي عادة عشان اعرف المتغيرات الخاصة فتكتب فقط اندرسكور يخرجلك الكومبايلر كل البرايفت فاريبل

	 البرايفت فريبل تعدل عليهم من خلال البروبرتز

	 ليش نغلب حالنا ونستعمل الغت و الست؟
	 لانك تقدر تعمل بيهم حاجات عظيمة زي ما نشوف لما نتقدم في الكورس
	 مثلا لما تحب تعمل في البرنامج شغلة بنسميها 
	 audit trailing 
	 مرات انا اضطر خاصة في انظمة مثل البنوك
	 مثلا انت كمطور عدلت على الاسم الاول بدك تحفظ القيمة القديمة
	 وبعدين تعدل عليها
	 هذا تعمله تحط كود داخل الست و تحفظ كل اسم في فايل او داتا بيز

	 ممنوع تكتب كود في المين لازم تتعامل بالاوبجكت من هلا ورايح
	 مثلا اذا كنت كتبت برنامجك لتطبيق على الدسكتوب فلما تروح تعمل نفس الخاصية في الويب مثلا رح تضطر تعيد تكتب الكود 
	 خارج الكلاس لكن لما تكون كتبته داخل الكلاس من الاول رح توفر على نفسك اعادة كتابة الكود

	 في الاوبجكت اورينتد ممنوع تكتب كود برا كل شيء من خلال الكلاس و الاوبجكتس

	 لما تستعمل بريفت نمبرز و تعدل عليهم بالست والغت انت عملت سكيوريتي على البيانات الي هي 
	 البرايفت نمبرز فالاوبجكت اورينتد تعمل حوكمة للكود تخليك تتحكم في المطورين كيف يكتبوا كود
	 و تقلل الاخطاء و تقلل اعادة كتابة الكود ولها فوائد اخرى

*/

#include <iostream>
using namespace std;

class clsperson
{
private:
    string _firstname;
    string _secondname;

public:

    //Property Set to edit on private varibale
    void setFirstname(string firstname){
        _firstname = firstname;
    }

    //Property get to print variable
    string firstname(){
        return _firstname;
    }

    void setSecond(string secondname){
        _secondname = secondname;
    }

    //Property get
    string secondname(){
        return _secondname;
    }

    string fullname(){
        return _firstname + " " + _secondname;
    }
    

};

int main()
{
    clsperson person1;

    person1.setFirstname("ibraam");
    person1.setSecond("magdy");

    cout << "first name: " << person1.firstname() << endl;
    cout << "first name: " << person1.secondname() << endl;
    cout << "first name: " << person1.fullname() << endl;
    

    return 0;
}