#include "../tsunami.h"

inherit ARMOR;

void create()
{
     set_name("Combat Skirt","����ս��Χȹ");
     add("id",({"skirt"}) );
     set_short("����ս��Χȹ");
     set_long(@LONG
����һ�������������Ҽһյ�Χȹ����˵�Ǽһ������ܴ��������ˣ���������ر�
ϲ��������֯�ڸ����������Ʒ�ϣ�����Χȹ�ϵļһտ�������������������ܸ�
�ʹ�����ر������ı����ɣ�
LONG
             );
     set("unit","��");
     set("weight",100);
     set("material","element");
     set("type","legs");
     set("armor_class",8);
     set("defense_bonus",3);
     set("value",({200,"gold"}) );
}
