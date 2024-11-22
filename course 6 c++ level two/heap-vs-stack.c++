
/**Ram memory

first source code and inctructions : it is main code to ranslate into machine code

second static and global variables : it is a variable save his value til program end and we can use in all program

third stck : store local variable , functions and pointers (used to access part of heap)


fourth heap: free store of memory */



/*
الذاكرة
 Memory يقصد بها في البرمجة : RAM
❖ البرنامج يقسم في RAM الى أربع ة أقسام هي
1
. يخزن فيه كود الأوامر Source Code / Instruction ) يأخذ مساحة قليلة (
2
. Static / Global هما Variables تكون دورة حياتهما طوال حياة كامل البرنامج
) يأخذ مساحة قليلة (
3
. Stack هو : الذاكرة Memory التي يخصصها Operating System
نظام الشغيل للبرنام ج - بعد معرفة حجمه - ) يأخذ مساحة على حسب البرنامج (
يخزن فيه Local : Variables / Function / Pointers ) )
4
. يستطيع Developer الوصول الى Heap بقية الذاكرة باستخدام Pointers
( Pointers يخزن Address في Stack ( أما الأشياء الديناميكية تخزن في Heap مثل
ptrX = new int;
يخزن فيه Heap : any dynamic Variables / Objects / Arrays …etc.
*/


