#include "../tsunami.h"

inherit ARMOR;

void create()
{
     set_name("Practice cloth","�����");
     add("id",({"cloth"}) );
     set_short("�����");
     set_long(@LONG
������ͨ���������һ�����������˶��������ַ�װ�����䣡
LONG
             );
     set("unit","��");
     set("type","body");
     set("material","cloth");
     set("armor_class",10);
     set("defense_bonus",0);
     set("weight",100);
     set("value",({50,"silver"}) );
 }