#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("chan letter","����");
        add( "id" , ({ "chan letter" }) );
        set_short( "����");
        set_long(@C_LONG
����һ���ɫ�ļ��顣
C_LONG  );      
        set("unit","��");
        set("weight",5);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
